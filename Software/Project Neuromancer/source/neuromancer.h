#pragma once
#ifndef NEUROMANCER_H
#define NEUROMANCER_H

#include "matrix.h"
#include <iostream>

class Neuromancer {
private:
	Matrix	multiply(Matrix matA, Matrix matB);						//standard
	Matrix	multiply(Matrix& matA, float factor);					//multiply by scalar
	void	multiply(Matrix matA, Matrix matB, int debug);			//debug
	void	Test();													//test routine
	Matrix	matA;
	Matrix	matB;
	//Overloads
	Matrix operator*(Matrix& matB);

public:
	Neuromancer(int test = 0);
};

#endif