#pragma once
#ifndef MATRIX_H
#define MATRIX_H
#include <vector>
#include <iostream>


using std::vector;

//class for matrix stuff
//vector of vectors as a backbone
//need to write a multiplication method - see neuromancer

// 0 = EXECUTION / 1 = DEBUG
#ifndef DEBUG_MODE
#define DEBUG_MODE 0
#endif

struct dimensions {
	int rows=0;
	int columns=0;
	dimensions();		//default constructor
	dimensions(int row_input, int col_input);
	void set_dims(int row_input, int col_input);
	dimensions mult_size(dimensions input_dims);
	int square_check();

	dimensions	operator*(dimensions input_dims);	// dims x dims
	void	operator*=(dimensions& input_dims);				// dims x dims
	void	operator=(int input[2]);

	friend std::ostream& operator<<(std::ostream& os, const dimensions& dims);
};



class Matrix {
private:

public:
	Matrix();
	Matrix(int m, int n);
	Matrix(int m, int n, float x);			//fill value
	Matrix(int m, int n, int x);			//fill value
	Matrix(dimensions input_dims);
	Matrix(dimensions input_dims, float x);	//fill value
	Matrix(dimensions input_dims, int x);	//fill value
	Matrix(const Matrix& obj);				//copy constructor

	dimensions dims;

	vector<vector<float>> data;	//a vector of vectors of floats.
	void set_data(vector< vector<float> >& inputData);	//set data using 2d array
	void set_data(vector<float> inputVec);				//set data as a row vector
	vector<vector<float>> get_data();					//return data
	void		disp_data();							//print the matrix using cout
	void		update_dims();							//update the dimensions
	dimensions	get_dims();								//return dimensions 
	int			get_rows();								//return # of rows
	int			get_cols();								//return # of cols
	
	//access methods
	float			access(int i, int j);
	vector<float>	access(int i, char all); // row 
	vector<float>	access(char all, int j); // column


	//Multiplication methods
	Matrix	multiply(Matrix matB);						//standard
	Matrix	multiply(float factor);						//multiply by scalar
	Matrix	multiply(int int_factor);					//multiply by scalar (int)
	void	multiply(Matrix matB, int debug);			//debug

	Matrix mult_element(Matrix matB);
	

	//addition
	Matrix addition(Matrix input, int debug);
	Matrix addition(Matrix input);
	Matrix addition(int offset);
	Matrix addition(float offset);

	//subtraction
	Matrix subtraction(Matrix input, int debug);
	Matrix subtraction(Matrix input);
	Matrix subtraction(int offset);
	Matrix subtraction(float offset);

	//trig functions
	Matrix sine();
	Matrix cosine();
	Matrix tangent();

	//Matrix processing funtions
	Matrix transpose();
	float determinant(int debug);
	float determinant();
	Matrix inverse();

	//overloads
	Matrix	operator*(Matrix& matB);				// Matrix X Matrix
	Matrix	operator*(float multiplier);			// Matrix X float
	Matrix	operator*(int int_multiplier);			// Matrix X int
	Matrix	operator*(double double_multiplier);	// Matrix X double
	void	operator*=(Matrix& matB);				// Matrix X Matrix
	void	operator*=(float multiplier);			// Matrix X float
	void	operator*=(int int_multiplier);			// Matrix X int
	void	operator*=(double double_multiplier);	// Matrix X double

	void	operator=(vector<vector<float>> input);	// Matrix set
	void	operator=(vector<float> inputVec);

	Matrix	operator+(Matrix input);				// Matrix + Matrix
	Matrix	operator+(int offset);					// Matrix + int
	Matrix	operator+(float offset);				// Matrix + float
	void	operator+=(Matrix input);				// Matrix + Matrix
	void	operator+=(int offset);					// Matrix + int
	void	operator+=(float offset);				// Matrix + float

	Matrix	operator-(Matrix input);				// Matrix + Matrix
	Matrix	operator-(int offset);					// Matrix + int
	Matrix	operator-(float offset);				// Matrix + float
	void	operator-=(Matrix input);				// Matrix + Matrix
	void	operator-=(int offset);					// Matrix + int
	void	operator-=(float offset);				// Matrix + float

	float	operator()(int i, int j);				// Access(i,j)
	Matrix	operator()(int i, char all);			// Access(row)
	Matrix	operator()(char all, int j);			// Access(column)

	friend std::ostream& operator<<(std::ostream& os, const Matrix& mat);
};

void	disp_vec(vector<float> input_vec);
void	disp_vec(vector<int> input_vec);



#endif
