#include "Matrix_Deploy.h"

//Dimensions method
//default contructor
dimensions::dimensions(){ 
    rows = 1;
    columns = 1;
}

dimensions::dimensions(int row_input, int col_input){
    this->rows = row_input;
    this->columns = col_input;
}

void dimensions::set_dims(int row_input, int col_input) {
    this->rows = row_input;
    this->columns = col_input;
}
dimensions dimensions::mult_size(dimensions input_dims) {
    dimensions output;
    if (this->columns != input_dims.rows) { //dims error
        output.rows = -1;
        output.columns = -1;
        return output;
    }
    else {
        output.rows = this->rows;
        output.columns = input_dims.columns;
        return output;
    }
}

int dimensions::square_check() {
    if (rows == columns) {
        return 1;
    }
    else {
        return 0;
    }
}

void dimensions::print_dims(){
    printf("Rows %d, Cols %d\n", this->rows, this->columns);
}

dimensions dimensions::operator*(dimensions input_dims) {
    dimensions multiplier = input_dims;
    dimensions result = this->mult_size(multiplier);
    return result;
}

void dimensions::operator*=(dimensions& input_dims) {
    dimensions result = this->mult_size(input_dims);
    this->rows = result.rows;
    this->columns = result.columns;
}

void dimensions::operator=(int input[2]) {
    this->set_dims(input[0], input[1]);
}

matrix::matrix(){
    //default to 1x1
    printf("fleaugh\n");
    data = new float* [1];
    data[0] = new float[1];
    memset(data[0], 0, sizeof(float));
}

matrix::matrix(int m, int n){
    //default to 1x1
    data = new float* [m];
    //data[0] = new float[n];
    for(int i = 0; i < m; i++){
        data[i] = new float[n];
        memset(data[i], 0, n*sizeof(float)); 
    }
    dims.set_dims(m,n);
}


matrix::~matrix(){
    for(int i=0; i < dims.rows; i++){
        delete[] data[i];
    }
    delete[] data;
}
void matrix::print(){
    for(int i = 0; i < dims.rows; i++){
        for(int j = 0; j < dims.columns; j++){
            printf("%f\n", data[i][j]);
        }
    }
}