#pragma once
#ifndef NEUROMANCER_H
#define NEUROMANCER_H

#include "matrix.h"
#include <iostream>

class Neuromancer {
private:
	Matrix multiply(Matrix matA, Matrix matB);
	Matrix multiply(vector< vector<float> >& matA, float factor);
	Matrix matA;
	Matrix matB;

public:
	Neuromancer();
};

#endif