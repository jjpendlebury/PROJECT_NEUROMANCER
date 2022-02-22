#pragma once
#ifndef MATRIX_H
#define MATRIX_H
#include <vector>
#include <iostream>


using std::vector;

//class for matrix stuff
//vector of vectors as a backbone
//need to write a multiplication method - see neuromancer
class Matrix {
private:

public:
	Matrix();
	Matrix(int m, int n);
	vector<vector<float>> data;	//a vector of vectors of floats. Because that's not confusing at all
	void set_data(vector< vector<float> >& inputData);
	vector<vector<float>> get_data();
	void disp_data();
	Matrix	multiply(Matrix matB);						//standard
	Matrix	multiply(float factor);					//multiply by scalar
	Matrix	multiply(int int_factor);					//multiply by scalar (int)
	void	multiply(Matrix matB, int debug);			//debug

	Matrix	operator*(Matrix& matB);
	Matrix	operator*(float multiplier);
	Matrix	operator*(int int_multiplier);
	Matrix	operator*(double double_multiplier);
	void	operator=(vector<vector<float>> input);
};




#endif
