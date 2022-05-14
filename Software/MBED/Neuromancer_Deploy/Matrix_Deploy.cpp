#include "Matrix_Deploy.h"

//Dimensions method
//default contructor
dimensions::dimensions(){ 

}

dimensions::dimensions(int row_input, int col_input){
    rows = row_input;
    columns = col_input;
}

void dimensions::set_dims(int row_input, int col_input) {
    rows = row_input;
    columns = col_input;
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