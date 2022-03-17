#pragma once
#ifndef NEUROMANCER_H
#define NEUROMANCER_H

#include "matrix.h"
#include "RevoluteForwardKinematics2D.h"
#include <iostream>

enum layer_type {
	LINEAR,
	SIGMOID,
	RELU
};

class Neuromancer {
private:
	//Network Parameters
	float alpha = 0.025;
	int trials = 100, episodes = 100, hiddenUnits = 10;
	dimensions InputDims = { 3,1 }, OutputDims = { 2,1 };			//default values for testing
	void	Test();													//test routine
	void	disp_vec(vector<float> input_vec);
	void	disp_vec(vector<int> input_vec);
	vector<layer_type> network_layout = { LINEAR, SIGMOID, LINEAR };
	vector<Matrix> network;

	void init_network();

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