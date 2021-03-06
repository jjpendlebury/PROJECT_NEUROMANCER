close all
clear all
clc

%This is a model based on the Neuromancer software with 1000 episodes and 10 trials
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%Set up episode variables
alpha = 0.025;
trials = 10000;
episodes = 1;
hiddenUnits = 10;
%Organise training data                                                           %Raw end effector positions
output_vec = zeros(2,episodes);                                           %Preallocate the output vector
W1= [       -0.908127,-0.767684,-0.133879;
            -0.174134,-1.88322,0.23203;
            -1.71668,-1.10146,-1.04194;
            -0.442175,-1.11105,-0.235124;
            -0.387182,-1.82566,0.168061;
            -0.135698,-1.77371,0.207188;
            -0.338738,-0.192463,-0.344092;
            -0.282729,-1.35214,-0.171054;
            0.486259,-1.29128,0.124648;
            -3.51269,-1.90169,-1.86282;
            ];
W2 = [0.929358,0.00612833,1.445,0.615308,0.520298,-0.118593,0.377389,0.449987,-0.8806,1.65691,-0.235082;
    0.468984,1.68531,-0.674808,0.756938,1.53916,1.52939,-0.0542583,1.01692,0.773401,-2.74337,-0.77608,
    ];

Inputs= [                           -0.706528,  -0.143219,  -0.135306,- 0.351626,   -0.275628;  
                                     0.351488,   -0.136183,  0.609451,   0.0871665,  -0.110546;  
                                     1,          1,          1,          1,          1,          
    ];
%differentials
DeDw1= zeros(3,2);
DeDw2= zeros(1,3);

%initialise weights to non-zero

% randomize data
i = 1;
fprintf("Starting training...\n");
% errorvec = zeros(2,trials); 
% error1=0;
for i = 1:2
        x = Inputs(:,i);                          %extract input
        %t = T(:,i);                             %extract target
        net = W1 *x;                            %generate first net
        a2 = 1./(1+exp(-net));                  %calculate A2
        a2hat = [a2;1;];                        %a2 augmented
        %Second Layer
        net2 = W2 * a2hat;
        o = net2;
        output_vec(:,i)=o;                      %append output to vector
end
fprintf("Complete\n");


save("DeployModel");
%write to CSV fileS
% filename = 'nm.csv';
% try
%     delete nm.csv;
% catch ME
%     warning('File not present, creating...');
% end
%     
% writematrix(x,filename, 'WriteMode','append');      %input slice
% writematrix(net,filename, 'WriteMode','append');    %net1
% writematrix(a2hat,filename, 'WriteMode','append');  %a2hat
% writematrix(net2,filename, 'WriteMode','append');   %net2
% 
% writematrix(delta3,filename, 'WriteMode','append');      %delta3
% writematrix(W2bar,filename, 'WriteMode','append');      %W2bar
% writematrix(delta2,filename, 'WriteMode','append'); %delta2
% writematrix(DeDw2,filename, 'WriteMode','append');  %DeDw2
% writematrix(DeDw1,filename, 'WriteMode','append');  %DeDw1
% writematrix(error1,filename, 'WriteMode','append'); %error
% writematrix(t,filename, 'WriteMode','append');      %target slice




