#include "matrix.h"

using namespace std;

//constructor
//need to write an assign loop to iterate through an array of arrays, and assign values like that
Matrix::Matrix() {
};

//
void Matrix::set_data(vector< vector<float> > &inputData) {
    data = inputData;
}

//method to 
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
    Matrix result;
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
        //cout << "Product of the two matrices is:" << endl;
        for (i = 0; i < r1; ++i) {
            for (j = 0; j < c2; ++j)
                cout << product[i][j] << " ";
            cout << endl;
        }
    }
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
    Matrix blank;
    blank.set_data(dataA);
    return blank;
}
Matrix Matrix::multiply(int factor) {
    vector<vector<float>> dataA = this->get_data();;
    for (auto i = 0; i < dataA.size(); i++) {
        for (
            auto it = dataA[i].begin(); it != dataA[i].end(); it++)
            *it *= factor;
        //cout << *it << " ";
        cout << endl;
    }
    Matrix blank;
    blank.set_data(dataA);
    return blank;
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
