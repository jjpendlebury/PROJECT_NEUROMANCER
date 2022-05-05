%Model Data Generation

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
Xhat = [X; ones(1,episodes);];                                              %Augmented Inputs
T = Theta;                                                                  %Set correct joint angles as targets
output_vec = zeros(2,episodes);

W1 = GenerateUniformDataset(3,-0.1,0.1,hiddenUnits);
W2 = GenerateUniformDataset((hiddenUnits+1),-0.1,0.1,2);


filename = 'ModelTrainingData.csv';
save("Model_Training_Data");
%clear old model data
delete ModelData.csv;
writematrix(X,filename, 'WriteMode','append');
writematrix(T,filename, 'WriteMode','append');
writematrix(W1,filename, 'WriteMode','append');
writematrix(W2,filename, 'WriteMode','append');