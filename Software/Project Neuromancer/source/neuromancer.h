#pragma once
#ifndef NEUROMANCER_H
#define NEUROMANCER_H

#include "matrix.h"
#include "RevoluteForwardKinematics2D.h"
#include <iostream>

class Neuromancer {
private:
	//Network Parameters
	float alpha = 0.025;
	int trials = 100, episodes = 100, hiddenUnits = 10;
	void	Test();													//test routine
	Matrix	matA;
	Matrix	matB;
	//Overloads


public:
	Neuromancer(int test = 0);
};

#endif