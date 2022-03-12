#include "RevoluteForwardKinematics2D.h"
float randomValue(float upper, float lower) {
	static std::default_random_engine e;
	static std::uniform_real_distribution<> dis(lower, upper); 
	return dis(e);
}
vector<float> GenRandVec(float upper, float lower, int size) {
	std::vector<float> nums;
	for (int i{}; i != size; ++i) // Generate 5 random floats
		nums.emplace_back(randomValue(lower,upper));

	return nums;
}

vector<Matrix> ForwardKinematics(float armLen[2], Matrix theta, float origin[2]) {
	vector<Matrix> blank;
	Matrix theta1, theta2;
	vector<float> test;
	Matrix xMat(1, 1000);
	Matrix yMat(1, 1000);
	theta1=theta(0, ':'); //need set method for a single vector 
	theta2=theta(1,':');
	float armlen1 = armLen[0];
	float armlen2 = armLen[1];
	


	return blank;
}