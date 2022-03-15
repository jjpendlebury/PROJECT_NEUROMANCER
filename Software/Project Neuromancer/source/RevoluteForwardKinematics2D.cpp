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
	Matrix theta1, theta2, theta_both;
	vector<float> test;
	Matrix xMat(1, 1000);
	Matrix yMat(1, 1000);
	theta1=theta(0, ':');
	theta2=theta(1,':');
	std::cout << "theta 1: " << std::endl << theta1 << std::endl;
	std::cout << "theta 2: " << std::endl << theta2 << std::endl;
	float armlen1 = armLen[0];
	float armlen2 = armLen[1];
	xMat = (theta1.cosine() * armlen1) + origin[0];
	yMat = (theta2.sine() * armlen1) + origin[1];
	std::cout << xMat << std::endl;
	std::cout << yMat << std::endl;
	Matrix p1(2, xMat.get_cols());
	p1.data[0] = xMat.data[0];
	p1.data[1] = yMat.data[0];
	std::cout << std::endl << "P1:" << std::endl << p1 << std::endl;
	blank.push_back(p1);

	//P2
	theta_both = theta1.addition(theta2);
	std::cout << "cheese" << std::endl;
	xMat = (theta1.cosine() * armlen1) + (theta_both.cosine() * armlen2) + origin[0];
	yMat = (theta1.sine() * armlen1) + (theta_both.sine() * armlen2) + origin[1];
	Matrix p2(2, 1000);
	p2.data[0] = xMat.data[0];
	p2.data[1] = yMat.data[0];
	std::cout << std::endl << "P2:" << std::endl << p2 << std::endl;
	blank.push_back(p2);

	return blank;
}