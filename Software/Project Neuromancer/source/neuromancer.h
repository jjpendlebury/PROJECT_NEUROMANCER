#pragma once
#ifndef NEUROMANCER_H
#define NEUROMANCER_H

#include "matrix.h"
#include "RevoluteForwardKinematics2D.h"
#include <random>
#include <iostream>
#include <math.h>

enum class layer_type {
	LINEAR,
	SIGMOID,
	RELU
};
vector<float>	GenRandVec(float upper, float lower, int size);
float			randomValue(float upper, float lower);


class Neuromancer {
private:
	//Network Parameters
	float alpha = 0.025;
	int trials = 100, episodes = 100, hiddenUnits = 10;
	dimensions InputDims = { 3,1 }, OutputDims = { 2,1 };			//default values for testing
	Matrix targets, target_slice, inputs, input_slice;
	float error;

	void	Test();													//test routine

	vector<layer_type> network_layout = { layer_type::LINEAR, layer_type::SIGMOID, layer_type::LINEAR };
	vector<Matrix> network;					//forward network
	vector<Matrix> back_network;			//backwards network

	//network initialisers
	void init_network_351();
	void init_weights();
	void init_back_351();

	//non-linearities 
	void sigmoid(Matrix* input, Matrix* output);
	void sigmoid(Matrix* input, Matrix* output, int debug);	//debug
	Matrix sigmoid(Matrix input, int debug);	//debug

	//forward pass
	void forward_pass();

	//backpropogation
	void back_propogation_351(int debug); //debug variant
	void back_propogation_351();
	//random functions
	Matrix					GenRandMat(dimensions dims, float upper, float lower );
	friend float			randomValue(float upper, float lower);
	friend vector<float>	GenRandVec(float upper, float lower, int size);
	
	//Overloads
	friend std::ostream& operator<<(std::ostream& os, const vector<float>& vec);

	friend std::ostream& operator<<(std::ostream& os, const vector<int>& vec);



public:
	Neuromancer();
	Neuromancer(int test = 0);
	
	void	execute();
	Matrix	get_inputs();
	void	set_inputs(Matrix new_inputs);
	Matrix	get_targets();
	void	set_targets(Matrix new_targets);
	float	get_alpha();
	void	set_alpha(float new_learning_rate);
	int		get_episodes();
	void	set_episodes(int new_episodes);
	int		get_trials();
	void	set_trials(int new_trials);

	vector<layer_type>	get_layout();
	void				set_layout(vector<layer_type> input);

	void				display_network();
	void				display_back_network();


};

void	disp_vec(vector<float> input_vec);
void	disp_vec(vector<int> input_vec);
std::ostream& operator<<(std::ostream& os, const vector<float>& vec);

#endif