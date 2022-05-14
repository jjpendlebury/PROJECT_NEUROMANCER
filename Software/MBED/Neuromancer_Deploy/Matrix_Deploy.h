#ifndef __MATRIX_DEPLOY_H__
#define __MATRIX_DEPLOY_H__

#ifndef __DEBUG_MODE__
#define __DEBUG_MODE__ 0        //debug mode macro
#endif

#include "mbed.h"

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




#endif