%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% all rights reserved
% Author: Dr. Ian Howard
% Associate Professor (Senior Lecturer) in Computational Neuroscience
% Centre for Robotics and Neural Systems
% Plymouth University
% A324 Portland Square
% PL4 8AA
% Plymouth, Devon, UK
% howardlab.com
% 14/10/2020
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

% Train a neural network to implement inverse model
% you need to implement this script to run the assignment section 2

close all
clear all
clc

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% your script from here onwards

%Set up episode variables
alpha = 0.025;
trials = 10000;
episodes = 1000;
hiddenUnits = 10;

%Generate Arm Training Data
L1 = 0.4;
L2 = 0.4;
armLen = [L1, L2];
origin = [0,0];
Theta = GenerateUniformDataset(episodes,0,pi,2);
[P1, P2] = RevoluteForwardKinematics2D(armLen,Theta,origin);
%Organise training data
X = P2;                                                                     %Raw end effector positions
Xhat = [X; ones(1,episodes);];                                            %Augmented Inputs
T = Theta;                                                                  %Set correct joint angles as targets
output_vec = zeros(2,episodes);                                           %Preallocate the output vector


%differentials
DeDw1= zeros(3,2);
DeDw2= zeros(1,3);

%initialise weights to non-zero
W1 = GenerateUniformDataset(3,-0.1,0.1,hiddenUnits);
W2 = GenerateUniformDataset((hiddenUnits+1),-0.1,0.1,2);


% randomize data

XHat_constant = Xhat;
T_constant = T;
fprintf("Starting training...\n");
errorvec = zeros(2,trials);

for c = 1:trials
    error1=0;
    for i = 1:episodes
        x = Xhat(:,i);                          %extract input
        t = T(:,i);                             %extract target
        net = W1 *x;                            %generate first net
        a2 = 1./(1+exp(-net));                  %calculate A2
        a2hat = [a2;1;];                        %a2 augmented
        %Second Layer
        net2 = W2 * a2hat;
        o = net2;
        %calculate delta terms
        delta3 = -(t-o);
        W2bar = W2(:,1:hiddenUnits);
        delta2 = (W2bar' * delta3).*a2.*(1-a2); %backpropagate error
        %differential terms
        DeDw2 = delta3 * a2hat';                %de/DW
        DeDw1 = delta2 * x';                    %de/DW
        error1 = error1 + (t - o)' * (t - o);   %sum of squared error terms
        W1 = W1 - alpha*DeDw1;                  %update weight 1
        W2 = W2 - alpha*DeDw2;                  %update weight 2
        output_vec(:,i)=o;                      %append output to vector
    end
    errorvec(:,c)=error1;
    if (mod(c,1000) == 0)
        %disp(c)
        fprintf("%d%% \n", c/100);
    end
end
fprintf("Training complete\n");
%average the errors/iteration
errorvec = errorvec/episodes; 


% % calc output of net
% net2 = W1 * Xhat;
% a2 = 1 ./(1 + exp(-net2));
% len = length(a2);
% a2Hat = [a2; ones(1,len)];
% output_vec = W2 * a2Hat;

% figure
% hold on
% plot(T(1,:), T(2,:),'b.')
% plot(output_vec(1,:), output_vec(2,:),'r.')


figure
hold on
plot(errorvec(1,:),'b.-')
legend('Error')
title("10613591 - P2 Error Over Iterations")
ylabel("Error Value")
xlabel("Iteration #")
%set(gca, 'YScale', 'log')

% figure
% t = tiledlayout(2,2);
% title(t,'10613591 - Inverse Kinematic Model Testing')
% nexttile
% plot(XHat_constant(1,:),XHat_constant(2,:),'b.' )
% title('Random Endpoint Data')
% %top right
% nexttile
% plot(T_constant(1,:),T_constant(2,:),'b.' )
% title('Random Joint Angle Data')
% axis([-0.5 3.5 0 3.5])
% %bottom left
% nexttile
% %calc end kinematics
% [P1_2,P2_2] = RevoluteForwardKinematics2D(armLen, output_vec, origin);
% plot(P2_2(1,:),P2_2(2,:),'r.')
% title("Regenerated Endpoint Data")
% axis([-0.8 0.8 -0.4 0.8])
% %bottom right
% nexttile
% plot(output_vec(1,:),output_vec(2,:),'r+')
% title("Inverse Model Joint Angles")


save("P2_10613591")


