close all
clear all
clc

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%Set up episode variables
alpha = 0.025;
trials = 10000;
episodes = 1000;
hiddenUnits = 10;

%Load training data
load("Model_Training_Data");
%Organise training data
X = P2;                                                                     %Raw end effector positions
Xhat = [X; ones(1,episodes);];                                            %Augmented Inputs
T = Theta;                                                                  %Set correct joint angles as targets
output_vec = zeros(2,episodes);                                           %Preallocate the output vector


%differentials
DeDw1= zeros(3,2);
DeDw2= zeros(1,3);

%initialise weights to non-zero

% randomize data
i = 1;
XHat_constant = Xhat;
T_constant = T;
fprintf("Starting training...\n");
errorvec = zeros(2,trials);
error1=0;
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
fprintf("Training complete\n");


save("P2_10613591");
%write to CSV file
filename = 'nm.csv';
try
    delete nm.csv;
catch ME
    warning('File not present, creating...');
end
    
writematrix(x,filename, 'WriteMode','append');      %input slice
writematrix(net,filename, 'WriteMode','append');    %net1
writematrix(a2hat,filename, 'WriteMode','append');  %a2hat
writematrix(net2,filename, 'WriteMode','append');   %net2

writematrix(delta3,filename, 'WriteMode','append');      %delta3
writematrix(W2bar,filename, 'WriteMode','append');      %W2bar
writematrix(delta2,filename, 'WriteMode','append'); %delta2
writematrix(DeDw2,filename, 'WriteMode','append');  %DeDw2
writematrix(DeDw1,filename, 'WriteMode','append');  %DeDw1
writematrix(error1,filename, 'WriteMode','append'); %error
writematrix(t,filename, 'WriteMode','append');      %target slice




