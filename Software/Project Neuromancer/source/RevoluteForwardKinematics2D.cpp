#include "RevoluteForwardKinematics2D.h"

Matrix ForwardKinematics(float armLen[2], Matrix theta, float origin[2] = {0}) {
	vector<float> theta1, theta2;
	theta1 = theta[0];
	theta2 = theta[1];
	float armlen1 = armLen[0];
	float armlen2 = armLen[1];
}