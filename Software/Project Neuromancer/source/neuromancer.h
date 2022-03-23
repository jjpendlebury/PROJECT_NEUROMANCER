#pragma once
#ifndef NEUROMANCER_H
#define NEUROMANCER_H

#include "matrix.h"
#include "RevoluteForwardKinematics2D.h"
#include <random>
#include <iostream>
#include "windows.h"

enum class layer_type {
	LINEAR,
	SIGMOID,
	RELU
};
vector<float>	GenRandVec(float upper=1, float lower=0, int size=5);
float			randomValue(float upper, float lower);

class Neuromancer {
private:
	//Network Parameters
	float alpha = 0.025;
	int trials = 100, episodes = 100, hiddenUnits = 10;
	dimensions InputDims = { 3,1 }, OutputDims = { 2,1 };			//default values for testing
	void	Test();													//test routine
	void	disp_vec(vector<float> input_vec);
	void	disp_vec(vector<int> input_vec);
	vector<layer_type> network_layout = { layer_type::LINEAR, layer_type::SIGMOID, layer_type::LINEAR };
	vector<Matrix> network;

	void init_network();
	void init_weights();
	Matrix					GenRandMat(dimensions dims, float upper, float lower );
	friend float			randomValue(float upper, float lower);
	friend vector<float>	GenRandVec(float upper, float lower, int size);
	
	//Overloads




public:
	Neuromancer();
	Neuromancer(int test = 0);
	float	get_alpha();
	void	set_alpha(float new_learning_rate);

	vector<layer_type>	get_layout();
	void				set_layout(vector<layer_type> input);

	void				display_network();


};

#endif