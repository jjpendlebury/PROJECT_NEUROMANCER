#include "matrix.h"

using namespace std;

//constructor
//need to write an assign loop to iterate through an array of arrays, and assign values like that
Matrix::Matrix() { //blank matrix
    std::vector<std::vector<float> > temp(1, std::vector<float>(1, 0));
    data = temp;
    dims.rows = 0;
    dims.columns = 0;
};

//preallocated matrix
Matrix::Matrix(int m, int n) {

    std::vector<std::vector<float> > temp(m,std::vector<float>(n, 0));
    data = temp;
    dims.rows = m;
    dims.columns = n;
}

//
void Matrix::set_data(vector< vector<float> > &inputData) {
    data = inputData;
    this->dims.rows = this->data.size();
    this->dims.columns = this->data[0].size();
}

void Matrix::set_data(vector<float> inputVec) {
    data[0].reserve(inputVec.size());
    data[0]=(inputVec);
    this->dims.rows = this->data.size();
    this->dims.columns = this->data[0].size();
}

//method to extract the data from a matrix
vector<vector<float>> Matrix::get_data() {
    return data;
}

//method to display a matrix on to the terminal 
void Matrix::disp_data() {
    for (auto i = 0; i < data.size(); i++) {
        for (
            auto it = data[i].begin(); it != data[i].end(); it++)
            cout << *it << " ";
        cout << endl;
    }
}

void Matrix::disp_vec() {
    for (auto i = 0; i < data.size(); i++) {
        for (
            auto it = data[i].begin(); it != data[i].end(); it++)
            cout << *it << " ";
        cout << endl;
    }
}

void Matrix::update_dims() {
    this->dims.rows = data.size();
    this->dims.columns = data[0].size();
}

dimensions Matrix::get_dims() {
    dimensions output = this->dims;
    return output;
}

int Matrix::get_rows() {
    int output = this->dims.rows;
    return output;
}

int Matrix::get_cols() {
    int output = this->dims.columns;
    return output;
}

//access methods

float Matrix::access(int i, int j) {
    float output = this->data.at(i).at(j);
    return output;
}

vector<float> Matrix::access(int i, char all) {
    //row access
    vector<float> output;
    output.reserve(this->get_cols());             //preallocate the new vector for speed
    output = this->data.at(i);
    return output;
}

vector<float> Matrix::access(char all, int j) {
    vector<float> output;
    output.reserve(this->get_rows());
    for (auto i = 0; i < this->data.size(); i++) {
        output.push_back(this->access(i, j));
    }
    return output;
}

//multiply two matrices
//DEBUG variant, prints matrices out
void Matrix::multiply(Matrix matB, int debug) {
    int product[10][10], r1 = 3, c1 = 2, r2 = 2, c2 = 3, i, j, k;
    vector< vector<float> > a = this->get_data();
    vector< vector<float> > b = matB.get_data();
    r1 = a.size();
    r2 = b.size();
    c1 = a[0].size();
    c2 = b[0].size();

    if (c1 != r2) {
        cout << "Column of first matrix should be equal to row of second matrix";
    }
    else {
        cout << "The first matrix is:" << endl;
        for (i = 0; i < r1; ++i) {
            for (j = 0; j < c1; ++j)
                cout << a[i][j] << " ";
            cout << endl;
        }
        cout << endl;
        cout << "The second matrix is:" << endl;
        for (i = 0; i < r2; ++i) {
            for (j = 0; j < c2; ++j)
                cout << b[i][j] << " ";
            cout << endl;
        }
        cout << endl;
        for (i = 0; i < r1; ++i)
            for (j = 0; j < c2; ++j) {
                product[i][j] = 0;
            }
        for (i = 0; i < r1; ++i)
            for (j = 0; j < c2; ++j)
                for (k = 0; k < c1; ++k) {
                    product[i][j] += a[i][k] * b[k][j];
                }
        cout << "Product of the two matrices is:" << endl;
        for (i = 0; i < r1; ++i) {
            for (j = 0; j < c2; ++j)
                cout << product[i][j] << " ";
            cout << endl;
        }
    }
}

//Standard variant
Matrix Matrix::multiply(Matrix matB) {
    //Matrix result;
    int r1 = 3, c1 = 2, r2 = 2, c2 = 3, i, j, k;
    vector< vector<float> > a = this->get_data();
    vector< vector<float> > b = matB.get_data();
    vector< vector<float> > product(r1, vector<float>(c2, 0));
    r1 = a.size();
    r2 = b.size();
    c1 = a[0].size();
    c2 = b[0].size();

    if (c1 != r2) {
        cout << "Column of first matrix should be equal to row of second matrix";
    }
    else {

        for (i = 0; i < r1; ++i)
            for (j = 0; j < c2; ++j) {
                product[i][j] = 0;
            }
        for (i = 0; i < r1; ++i)
            for (j = 0; j < c2; ++j)
                for (k = 0; k < c1; ++k) {
                    product[i][j] += a[i][k] * b[k][j];
                }
        //cout << "Product of the two matrices is:" << endl;
        for (i = 0; i < r1; ++i) {
            for (j = 0; j < c2; ++j)
                cout << product[i][j] << " ";
            cout << endl;
        }
    }
    Matrix result(r1, c2);
    result.set_data(product);
    return result;
}

//multiply by a factor
Matrix Matrix::multiply(float factor) {
    vector<vector<float>> dataA = this->get_data();;
    for (auto i = 0; i < dataA.size(); i++) {
        for (
            auto it = dataA[i].begin(); it != dataA[i].end(); it++)
            *it *= factor;
        //cout << *it << " ";
        cout << endl;
    }
    Matrix blank(this->get_rows(),this->get_cols());
    blank.set_data(dataA);
    return blank;
}
Matrix Matrix::multiply(int factor) {
    vector<vector<float>> dataA = this->get_data();
    for (auto i = 0; i < dataA.size(); i++) {
        for (
            auto it = dataA[i].begin(); it != dataA[i].end(); it++)
            *it *= factor;
        //cout << *it << " ";
        cout << endl;
    }
    Matrix blank(this->get_rows(), this->get_cols());
    blank.set_data(dataA);
    return blank;
}

//addition
Matrix Matrix::addition(Matrix input) {
    vector<vector<float>> dataA = this->get_data();
    vector<vector<float>> dataB = input.get_data();
    int r1 = dataA.size();
    int r2 = dataB.size();
    int c1 = dataA[0].size();
    int c2 = dataB[0].size();
    cout << "MatA - " << r1 << "," << c1 << endl;
    cout << "MatB - " << r2 << "," << c2 << endl;
    Matrix blank(this->get_rows(), this->get_cols());
    if ((c1 != c2) || (r1 != r2)) {
        cout << "For matrix elementwise addition, matrix dimensions must be the same" << endl;
    }
    else {
        for (auto i = 0; i < dataA.size(); i++) {
            for (
                auto it = 0; it < dataA[i].size(); it++)
                //cout << dataA[i][it] << "+" << dataB[i][it] << endl;
                dataA[i][it] += dataB[i][it];
            //cout << *it << " ";
            cout << endl;
        }
        blank.set_data(dataA);
    }
    return blank;
}

Matrix Matrix::addition(int offset) {
    vector<vector<float>> dataA = this->get_data();
    vector<vector<float>> dataB = this->get_data();
    for (auto i = 0; i < dataA.size(); i++) {
        for (
            auto it = 0; it < dataB.size(); it++)
            dataA[i][it] += offset;
        //cout << *it << " ";
        cout << endl;
    }
    Matrix blank(this->get_rows(), this->get_cols());
    blank.set_data(dataA);
    return blank;
}

Matrix Matrix::addition(float offset) {
    vector<vector<float>> dataA = this->get_data();
    vector<vector<float>> dataB = this->get_data();
    for (auto i = 0; i < dataA.size(); i++) {
        for (
            auto it = 0; it < dataB.size(); it++)
            dataA[i][it] += offset;
        //cout << *it << " ";
        cout << endl;
    }
    Matrix blank(this->get_rows(), this->get_cols());
    blank.set_data(dataA);
    return blank;
}

//trig functions
Matrix Matrix::sine() {
    vector<vector<float>> dataA = this->get_data();;
    for (auto i = 0; i < dataA.size(); i++) {
        for (
            auto it = dataA[i].begin(); it != dataA[i].end(); it++)
            *it *= sin(*it);
        //cout << *it << " ";
        cout << endl;
    }
    Matrix blank(this->get_rows(), this->get_cols());
    blank.set_data(dataA);
    return blank;
}

Matrix Matrix::cosine() {
    vector<vector<float>> dataA = this->get_data();;
    for (auto i = 0; i < dataA.size(); i++) {
        for (
            auto it = dataA[i].begin(); it != dataA[i].end(); it++)
            *it *= cos(*it);
        //cout << *it << " ";
        cout << endl;
    }
    Matrix blank(this->get_rows(), this->get_cols());
    blank.set_data(dataA);
    return blank;
}

Matrix Matrix::tangent() {
    vector<vector<float>> dataA = this->get_data();;
    for (auto i = 0; i < dataA.size(); i++) {
        for (
            auto it = dataA[i].begin(); it != dataA[i].end(); it++)
            *it *= tan(*it);
        //cout << *it << " ";
        cout << endl;
    }
    Matrix blank(this->get_rows(), this->get_cols());
    blank.set_data(dataA);
    return blank;
}

//Matrix processing functions
Matrix Matrix::transpose() {
    int t_rows = this->get_cols();      //flip dimensions for transpose
    int t_cols = this->get_rows();
    vector< vector<float> > dataA = this->get_data();
    Matrix output(t_rows, t_cols);                      //pre-alloc constructor
    for (auto i = 0; i < dataA.size(); i++) {
        for (
            auto it = 0; it < dataA[i].size(); it++)
            output.data[it][i] = dataA[i][it];
        //cout << *it << " ";
        cout << endl;
    }
    
    return output;
};

//Debug variant
float Matrix::determinant(int debug) {
    float output= 0;
    int is_square = 0, mat_size = 0;
    //check dims
    if (!(this->dims.square_check())) {
        cout << "Error, non-square matrix" << endl;
        output = 0xDEAD;
        return output;
    }
    mat_size = this->dims.columns;
    if (mat_size > 3) {
        cout << "Error, too large" << endl;
        output = 0xDEAD;
        return output;
    }

    if (mat_size == 2) {
        output = (this->access(0, 0) * this->access(1, 1)) - (this->access(0, 1) * this->access(1, 0));
        return output;
    }
   
    if (mat_size == 3) {
        float a, b, c;
        a =(this->access(1, 1) * this->access(2, 2)) - (this->access(1, 2) * this->access(2, 1));
        b = (this->access(1, 0) * this->access(2, 2)) - (this->access(1, 2) * this->access(2, 0));
        c =  (this->access(1, 0) * this->access(2, 1)) - (this->access(1, 1) * this->access(2, 0));
        cout << this->access(0, 0) << " *( " <<this->access(1, 1) << " * " << this->access(2, 2) << " - " << this->access(1, 2) << " * " << this->access(2, 1) << ")" << endl;
        cout << this->access(0, 1) << " *( " << this->access(1, 0) << " * " << this->access(2, 2) << " - " << this->access(1, 2) << " * " << this->access(2, 0) << ")" << endl;
        cout << this->access(0, 2) << " *( " << this->access(1, 0) << " * " << this->access(2, 1) << " - " << this->access(1, 1) << " * " << this->access(2, 0) << ")" << endl;
        cout << a << endl;
        cout << b << endl;
        cout << c << endl;
        output = (this->access(0, 0) * a) -(this->access(0, 1) * b) +(this->access(0, 2) * c);
        return output;
    }


    return output;
}

//standard variant
float Matrix::determinant() {
    float output = 0;
    int is_square = 0, mat_size = 0;
    //check dims
    if (!(this->dims.square_check())) {
        cout << "Error, non-square matrix" << endl;
        output = 0xDEAD;
        return output;
    }
    mat_size = this->dims.columns;
    if (mat_size > 3) {
        cout << "Error, too large" << endl;
        output = 0xDEAD;
        return output;
    }

    if (mat_size == 2) {
        output = (this->access(0, 0) * this->access(1, 1)) - (this->access(0, 1) * this->access(1, 0));
        return output;
    }

    if (mat_size == 3) {
        float a, b, c;
        a = (this->access(1, 1) * this->access(2, 2)) - (this->access(1, 2) * this->access(2, 1));
        b = (this->access(1, 0) * this->access(2, 2)) - (this->access(1, 2) * this->access(2, 0));
        c = (this->access(1, 0) * this->access(2, 1)) - (this->access(1, 1) * this->access(2, 0));
        output = (this->access(0, 0) * a) - (this->access(0, 1) * b) + (this->access(0, 2) * c);
        return output;
    }


    return output;
}

//overloads
Matrix Matrix::operator*(Matrix& matB) {
     Matrix result = this->multiply(matB);
     return result;
}

Matrix Matrix::operator*(float multiplier) {
    Matrix result = this->multiply(multiplier);
    return result;
}


Matrix Matrix::operator*(int int_multiplier) {
    Matrix result = this->multiply(int(int_multiplier));
    return result;
}

Matrix Matrix::operator*(double double_multiplier) {
    float multiplier = double_multiplier;
    Matrix result = this->multiply(multiplier);
    return result;
}

void Matrix::operator=(vector<vector<float>> input) {
    this->set_data(input);
}

void Matrix::operator=(vector<float> inputVec) {
    this->set_data(inputVec);
}

Matrix Matrix::operator+(Matrix input) {
    Matrix result = this->addition(input);
    return result;
}

Matrix Matrix::operator+(int offset) {
    Matrix result = this->addition(offset);
    return result;
}

Matrix Matrix::operator+(float offset) {

    Matrix result = this->addition(offset);
    return result;
}

float Matrix::operator()(int i, int j) {
    float output = this->access(i, j);
    return output;
}

vector<float> Matrix::operator()(int i, char all) {
    vector<float> output = this->access(i, all);
    return output;
}

vector<float> Matrix::operator()(char all, int j) {
    vector<float> output = this->access(all, j);
    return output;
}