#include "neuromancer.h"
using namespace std;

//PRIVATE

//multiply two matrices
//DEBUG variant, prints matrices out
void Neuromancer::multiply(Matrix matA, Matrix matB, int debug) {
        int product[10][10], r1 = 3, c1 = 2, r2 = 2, c2 = 3, i, j, k;
        vector< vector<float> > a = matA.get_data();
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
Matrix Neuromancer::multiply(Matrix matA, Matrix matB) {
    Matrix result;
    int r1 = 3, c1 = 2, r2 = 2, c2 = 3, i, j, k;
    vector< vector<float> > a = matA.get_data();
    vector< vector<float> > b = matB.get_data();
    vector< vector<float> > product( r1, vector<float> (c2, 0));
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
Matrix Neuromancer::multiply(Matrix& matA, float factor) {
    vector<vector<float>> dataA = matA.get_data();;
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

void Neuromancer::Test() {
    vector< vector<float> > a = { {2, 4, 6} , {2, 3, 5} , {3, 1, 4} };
    vector< vector<float> > b = { {1, 2, 3} , {3, 6, 1}, {3, 1, 4} };
    cout << "SET MATRIX A:" << endl;
    matA.set_data(a);
    cout << "SET MATRIX B:" << endl;
    matB.set_data(b);
    cout << "DISPLAY A" << endl;
    matA.disp_data();
    cout << "DISPLAY B" << endl;
    matB.disp_data();
    cout << "MULTIPLY A*B:" << endl;
    multiply(matA, matB, 1);
    cout << endl;
    Matrix result2 = multiply(matA, 2.0);
    result2.disp_data();
    Matrix result3 = multiply(matA, 3.4);
    result3.disp_data();
}

//overloads
Matrix Neuromancer::operator*(Matrix& matB) {
    Matrix multiplicand, multiplier;
    return multiplier;
}



//public
Neuromancer::Neuromancer(int test) {
    cout << "test = " << test << endl;
    //Matrix test routine
    if (test == 1) {
        Test();
    }
}