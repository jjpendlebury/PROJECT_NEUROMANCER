#pragma once
#ifndef MATRIX_H
#define MATRIX_H
#include <vector>
#include <iostream>


using std::vector;

//class for matrix stuff
//vector of vectors as a backbone
//need to write a multiplication method - see neuromancer

struct dimensions {
	int rows=0;
	int columns=0;
};



class Matrix {
private:

public:
	Matrix();
	Matrix(int m, int n);

	dimensions dims;

	vector<vector<float>> data;	//a vector of vectors of floats. Because that's not confusing at all
	void set_data(vector< vector<float> >& inputData);
	vector<vector<float>> get_data();
	void		disp_data();
	void		disp_vec();
	dimensions	get_dims();
	int			get_rows();
	int			get_cols();
	
	//access methods
	float			access(int i, int j);
	vector<float>	access(int i, char all); // row 
	vector<float>	access(char all, int j); // column


	//Multiplication methods
	Matrix	multiply(Matrix matB);						//standard
	Matrix	multiply(float factor);						//multiply by scalar
	Matrix	multiply(int int_factor);					//multiply by scalar (int)
	void	multiply(Matrix matB, int debug);			//debug

	//addition
	Matrix addition(Matrix input);
	Matrix addition(int offset);
	Matrix addition(float offset);

	//trig functions
	Matrix sine();
	Matrix cosine();
	Matrix tangent();

	//Matrix processing funtions
	Matrix transpose();

	//overloads
	Matrix	operator*(Matrix& matB);
	Matrix	operator*(float multiplier);
	Matrix	operator*(int int_multiplier);
	Matrix	operator*(double double_multiplier);
	void	operator=(vector<vector<float>> input);
	Matrix	operator+(Matrix input);
	Matrix	operator+(int offset);
	Matrix	operator+(float offset);
	float			operator()(int i, int j);
	vector<float>	operator()(int i, char all);
	vector<float>	operator()(char all, int j);
};




#endif
