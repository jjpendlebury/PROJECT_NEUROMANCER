#pragma once
#ifndef MATRIX_H
#define MATRIX_H
#include <vector>
#include <iostream>


using std::vector;

//class for matrix stuff
//vector of vectors as a backbone
//need to write a multiplication method
class Matrix {
private:

public:
	Matrix();
	vector<vector<float>> data;	//a vector of vectors of floats. Because that's not confusing at all
	void set_data(vector< vector<float> >& inputData);
	void get_data(vector<float>* data_vec);
	void disp_data();
};



#endif
