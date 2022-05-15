#ifndef __MATRIX_DEPLOY_H__
#define __MATRIX_DEPLOY_H__

#ifndef __DEBUG_MODE__
#define __DEBUG_MODE__ 0        //debug mode macro
#endif

#include "mbed.h"
#include "string"
struct dimensions{
    int rows = 0;
    int columns = 0;
    dimensions();
    dimensions(int row_input, int col_input);
    void set_dims(int row_input, int col_input);
    dimensions mult_size(dimensions input_dims);
    int square_check();
    void print_dims();

    dimensions operator*(dimensions input_dims);
    void operator*=(dimensions& input_dims);
    void operator=(int input[2]);
};

class matrix {
    private:
    dimensions dims;
    public:
    matrix();
    matrix(int m, int n);
    matrix(int m, int n, float x);			//fill value
    // matrix(int m, int n, int x);			//fill value
    // matrix(dimensions input_dims);
    // matrix(dimensions input_dims, float x);	//fill value
    // matrix(dimensions input_dims, int x);	//fill value
    // matrix(const matrix& obj);				//copy constructor
    ~matrix();

    void print();

    

//     //a pointer to an array. This will be the matrix once the dma is done
    float *data;

    void    set_data(float *data_in, dimensions dimensions_in);
    dimensions  get_dims();
    matrix	multiply(matrix matB);						//standard
    void    sine();
    int index(int row, int col);
};



#endif