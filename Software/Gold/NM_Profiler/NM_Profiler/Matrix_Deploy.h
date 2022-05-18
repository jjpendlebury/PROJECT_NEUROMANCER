#ifndef __matrix_m_DEPLOY_H__
#define __matrix_m_DEPLOY_H__

#ifndef __DEBUG_MODE__
#define __DEBUG_MODE__ 0        //debug mode macro
#endif

#include <stdio.h>
#include <string.h>
#include <math.h>
struct dimensions_m{
    int rows = 0;
    int columns = 0;
    int total = 0;
    dimensions_m();
    dimensions_m(int row_input, int col_input);
    void set_dims(int row_input, int col_input);
    dimensions_m mult_size(dimensions_m input_dims);
    void update_total();
    int square_check();
    void print_dims();

    dimensions_m operator*(dimensions_m input_dims);
    void operator*=(dimensions_m& input_dims);
    void operator=(int input[2]);
};

class matrix_m {
    private:
    
    public:
    dimensions_m dims;
    matrix_m();
    matrix_m(int m, int n);
    matrix_m(int m, int n, float x);			//fill value
    // matrix_m(int m, int n, int x);			//fill value
    // matrix_m(dimensions_m input_dims);
    // matrix_m(dimensions_m input_dims, float x);	//fill value
    // matrix_m(dimensions_m input_dims, int x);	//fill value
    matrix_m(const matrix_m& obj);				//copy constructor
    ~matrix_m();

    void print();
    void column_slice(matrix_m in_mat, int column);
    void data_copy(matrix_m in_mat);
    

//     //a pointer to an array. This will be the matrix_m once the dma is done
    float *data;

    void    set_data(float *data_in, dimensions_m dimensions_m_in);
    void    clear_data();
    dimensions_m  get_dims();
    matrix_m	multiply(matrix_m matB);						//standard
    void    mult(matrix_m *matA, matrix_m *matB);
    void    sine();
    void    sigmoid();
    void    cosine(); //untested
    int index(int row, int col);
};

float sig(float input);

#endif