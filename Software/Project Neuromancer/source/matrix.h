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
	vector<vector<float>> data;	//a vector of vectors of floats. Because that's not confusing at all
	void set_data(vector< vector<float> >& inputData);
	vector<vector<float>> get_data();
	void disp_data();
	Matrix	multiply(Matrix matB);						//standard
	Matrix	multiply(float factor);					//multiply by scalar
	void	multiply(Matrix matB, int debug);			//debug

	Matrix	operator*(Matrix& matB);
	Matrix	operator*(float multiplier);
	void	operator=(vector<vector<float>> input);
};



#endif
