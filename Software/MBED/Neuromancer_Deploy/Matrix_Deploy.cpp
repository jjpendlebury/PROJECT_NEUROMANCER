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

matrix::matrix(int m, int n, float x){
    //default to 1x1
    printf("%f\n",x);
    data = new float* [m];
    //data[0] = new float[n];
    for(int i = 0; i < m; i++){
        data[i] = new float[n];
        memset(data[i], x, n*sizeof(float)); 
    }
    dims.set_dims(m,n);
    for(int i = 0; i < dims.rows; i++){
        for(int j = 0; j < dims.columns; j++){
            data[i][j] = x;
        }
    }
}

matrix::matrix(int m, int n, int x){
    float val = (float)x;
    printf("%f\n",val);
    //default to 1x1
    data = new float* [m];
    //data[0] = new float[n];
    for(int i = 0; i < m; i++){
        data[i] = new float[n];
        memset(data[i], val, n*sizeof(float)); 
    }
    dims.set_dims(m,n);
    for(int i = 0; i < dims.rows; i++){
        for(int j = 0; j < dims.columns; j++){
            data[i][j]=val;
        }
    }
}

matrix::matrix(dimensions input_dims){
    int m = input_dims.rows;
    int n = input_dims.columns;
    //default to 1x1
    data = new float* [m];
    //data[0] = new float[n];
    for(int i = 0; i < m; i++){
        data[i] = new float[n];
        memset(data[i], 0, n*sizeof(float)); 
    }
    dims.set_dims(m,n);
}

matrix::matrix(dimensions input_dims, float x){
    int m = input_dims.rows;
    int n = input_dims.columns;
    //default to 1x1
    data = new float* [m];
    //data[0] = new float[n];
    for(int i = 0; i < m; i++){
        data[i] = new float[n];
        memset(data[i], x, n*sizeof(float)); 
    }
    dims.set_dims(m,n);
    for(int i = 0; i < dims.rows; i++){
        for(int j = 0; j < dims.columns; j++){
            data[i][j]=x;
        }
    }
}

matrix::matrix(dimensions input_dims, int x){
    float val = (float)x;
    int m = input_dims.rows;
    int n = input_dims.columns;
    //default to 1x1
    data = new float* [m];
    //data[0] = new float[n];
    for(int i = 0; i < m; i++){
        data[i] = new float[n];
        memset(data[i], val, n*sizeof(float)); 
    }
    dims.set_dims(m,n);
    for(int i = 0; i < dims.rows; i++){
        for(int j = 0; j < dims.columns; j++){
            data[i][j]=val;
        }
    }
}

matrix::matrix(const matrix& obj) { //blank matrix
    data = obj.data;
    dims = obj.dims;
};

matrix::~matrix(){
    for(int i=0; i < dims.rows; i++){
        delete[] data[i];
    }
    delete[] data;
}
void matrix::print(){
    for(int i = 0; i < dims.rows; i++){
        printf("Row %d\n",i);
        for(int j = 0; j < dims.columns; j++){
            printf("%f\n", data[i][j]);
            
        }
    }
}

void matrix::set_data(float **data_in, dimensions dimensions_in){
    this->data = data_in;
    this->dims = dimensions_in;
}

matrix matrix::multiply(matrix matB) {
    int r1 = 3, c1 = 2, r2 = 2, c2 = 3, i, j, k;
    r1 = this->dims.rows;
    r2 = matB.dims.rows;
    c1 = this->dims.columns;
    c2 = matB.dims.columns;

    if (c1 != r2) {
        printf("Column of first matrix should be equal to row of second matrix\n");
    }
    else {
        matrix product(r1,c2);
        for (i = 0; i < r1; ++i)
            for (j = 0; j < c2; ++j) {
                product.data[i][j] = 0;
            }
        for (i = 0; i < r1; ++i)
            for (j = 0; j < c2; ++j)
                for (k = 0; k < c1; ++k) {
                    product.data[i][j] += this->data[i][k] * matB.data[k][j];
                }
                return product;
    
    }
    matrix error;
    return error;
}