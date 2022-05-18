#include "Matrix_Deploy.h"

//Dimensions method
//default contructor
dimensions_m::dimensions_m(){ 
    rows = 1;
    columns = 1;
    total = 1;
}

dimensions_m::dimensions_m(int row_input, int col_input){
    this->rows = row_input;
    this->columns = col_input;
    update_total();
}

void dimensions_m::set_dims(int row_input, int col_input) {
    this->rows = row_input;
    this->columns = col_input;
    update_total();
}
dimensions_m dimensions_m::mult_size(dimensions_m input_dims) {
    dimensions_m output;
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

void dimensions_m::update_total(){
    total = rows*columns;
}

int dimensions_m::square_check() {
    if (rows == columns) {
        return 1;
    }
    else {
        return 0;
    }
}

void dimensions_m::print_dims(){
    printf("Rows %d, Cols %d\n", this->rows, this->columns);
}

dimensions_m dimensions_m::operator*(dimensions_m input_dims) {
    dimensions_m multiplier = input_dims;
    dimensions_m result = this->mult_size(multiplier);
    return result;
}

void dimensions_m::operator*=(dimensions_m& input_dims) {
    dimensions_m result = this->mult_size(input_dims);
    this->rows = result.rows;
    this->columns = result.columns;
}

void dimensions_m::operator=(int input[2]) {
    this->set_dims(input[0], input[1]);
}
//-------------------------------------------------------------------//
matrix_m::matrix_m(){
    //default to 1x1
    printf("fleaugh\n");
    data = new float[1];
    memset(data, 0, sizeof(float));
}

matrix_m::matrix_m(int m, int n){
    data = new float [m*n];
    dims.set_dims(m,n);
    memset(data, 0, (m*n)*sizeof(float));
}

matrix_m::matrix_m(int m, int n, float x){
    //default to 1x1
    data = new float [m*n];
    dims.set_dims(m,n);
    memset(data, 0, (m*n)*sizeof(float));
    for(int i = 0; i < dims.rows; i++){
        for(int j = 0; j < dims.columns; j++){
            data[this->index(i,j)] = x;
        }
    }
}

// matrix_m::matrix_m(int m, int n, int x){
//     float val = (float)x;
//     printf("%f\n",val);
//     //default to 1x1
//     data = new float* [m];
//     //data[0] = new float[n];
//     for(int i = 0; i < m; i++){
//         data[i] = new float[n];
//         memset(data[i], val, n*sizeof(float)); 
//     }
//     dims.set_dims(m,n);
//     for(int i = 0; i < dims.rows; i++){
//         for(int j = 0; j < dims.columns; j++){
//             data[i][j]=val;
//         }
//     }
// }

// matrix_m::matrix_m(dimensions_m input_dims){
//     int m = input_dims.rows;
//     int n = input_dims.columns;
//     //default to 1x1
//     data = new float* [m];
//     //data[0] = new float[n];
//     for(int i = 0; i < m; i++){
//         data[i] = new float[n];
//         memset(data[i], 0, n*sizeof(float)); 
//     }
//     dims.set_dims(m,n);
// }

// matrix_m::matrix_m(dimensions_m input_dims, float x){
//     int m = input_dims.rows;
//     int n = input_dims.columns;
//     //default to 1x1
//     data = new float* [m];
//     //data[0] = new float[n];
//     for(int i = 0; i < m; i++){
//         data[i] = new float[n];
//         memset(data[i], x, n*sizeof(float)); 
//     }
//     dims.set_dims(m,n);
//     for(int i = 0; i < dims.rows; i++){
//         for(int j = 0; j < dims.columns; j++){
//             data[i][j]=x;
//         }
//     }
// }

// matrix_m::matrix_m(dimensions_m input_dims, int x){
//     float val = (float)x;
//     int m = input_dims.rows;
//     int n = input_dims.columns;
//     //default to 1x1
//     data = new float* [m];
//     //data[0] = new float[n];
//     for(int i = 0; i < m; i++){
//         data[i] = new float[n];
//         memset(data[i], val, n*sizeof(float)); 
//     }
//     dims.set_dims(m,n);
//     for(int i = 0; i < dims.rows; i++){
//         for(int j = 0; j < dims.columns; j++){
//             data[i][j]=val;
//         }
//     }
// }

matrix_m::matrix_m(const matrix_m& obj) { //blank matrix_m
     this->set_data(obj.data, obj.dims);
};

matrix_m::~matrix_m(){
    delete[] data;
}
void matrix_m::print(){
    for(int i = 0; i < dims.rows; i++){
        printf("Row %d\n",i);
        for(int j = 0; j < dims.columns; j++){
            printf("%f\n", data[this->index(i,j)]);
            
        }
    }
}

void matrix_m::column_slice(matrix_m in_mat, int column){
    for(int i = 0; i < this->dims.rows; i++){
        //printf("row %d = %f\n",i,in_mat.data[index(i,column)]);
        this->data[i] = in_mat.data[in_mat.index(i,column)] ;
    }
}

void matrix_m::data_copy(matrix_m in_mat){
    for(int i = 0; i < in_mat.dims.rows; i++){
        for(int j = 0; j < in_mat.dims.columns; j++){
        //printf("row %d = %f\n",i,in_mat.data[index(i,column)]);
            this->data[this->index(i,j)] = in_mat.data[in_mat.index(i,j)] ;
        }
    }
}

void matrix_m::set_data(float *data_in, dimensions_m dimensions_m_in){
    delete[] this->data; // clear data.
    this -> data = new float[dimensions_m_in.total]; //declare new array
    this -> dims = dimensions_m_in;   //update dims
    for(int i = 0; i < this->dims.total; i++){  //copy data across
        data[i] = data_in[i];
    }
}
void matrix_m::clear_data(){
    memset(data, 0, (dims.rows*dims.columns)*sizeof(float));
}
dimensions_m matrix_m::get_dims(){
    return this->dims;
}
matrix_m matrix_m::multiply(matrix_m matB) {
    int r1 = 3, c1 = 2, r2 = 2, c2 = 3, i, j, k;
    r1 = this->dims.rows;
    r2 = matB.dims.rows;
    c1 = this->dims.columns;
    c2 = matB.dims.columns;

    if (c1 != r2) {
        printf("Column of first matrix_m should be equal to row of second matrix_m\n");
    }
    else {
        matrix_m product(r1,c2);
        for (i = 0; i < r1; ++i)
            for (j = 0; j < c2; ++j)
                for (k = 0; k < c1; ++k) {
                    product.data[product.index(i,j)] += this->data[this->index(i,k)] * matB.data[matB.index(k,j)];
                }
                return product;
    
    }
    matrix_m error;
    return error;
}

void matrix_m::mult(matrix_m *matA, matrix_m *matB){
    float temp;
        for (int i = 0; i < matA->dims.rows; ++i)
            for (int j = 0; j < matB->dims.columns; ++j)
            
                for (int k = 0; k < matA->dims.columns; ++k) {
                    temp = matA->data[matA->index(i,k)] * matB->data[matB->index(k,j)];
                    this->data[this->index(i,j)] += temp;
                }
        int a = 0;
}


void matrix_m::sine() {
    for (int i = 0; i < (this->dims.rows*this->dims.columns); i++) {
        //printf("index %d: %f\n",i,this->data[i]);
        this->data[i] = sin(this->data[i]);
        //printf("index %d: %f\n",i,this->data[i]);
    }
}

void matrix_m::sigmoid(){
    for (int i = 0; i < (this->dims.rows*this->dims.columns); i++) {
        //printf("index %d: %f\n",i,this->data[i]);
        this->data[i] = sig(this->data[i]);
        //printf("index %d: %f\n",i,this->data[i]);
    }
}

void matrix_m::cosine() {
    for (int i = 0; i < (this->dims.rows*this->dims.columns); i++) {
        //printf("index %d: %f\n",i,this->data[i]);
        this->data[i] = cos(this->data[i]);
        //printf("index %d: %f\n",i,this->data[i]);
    }
}

int matrix_m::index(int row, int col){
    return (row *this->dims.columns + col);
}

float sig(float input){
    return 1/(1+exp(-1 * input));
}