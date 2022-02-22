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

Matrix ForwardKinematics(float armLen[2], Matrix theta, float origin[2]) {
	Matrix blank;
	vector<float> theta1, theta2;
	theta1 = theta.data[0];
	theta2 = theta.data[1];
	float armlen1 = armLen[0];
	float armlen2 = armLen[1];
	return blank;
}