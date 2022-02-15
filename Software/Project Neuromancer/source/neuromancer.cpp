#include "neuromancer.h"
using namespace std;

//PRIVATE

//multiply two matrices
void Neuromancer::multiply(Matrix matA, Matrix matB) {
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

void Neuromancer::multiply(vector< vector<float> >& matA, float factor) {

}


//public
Neuromancer::Neuromancer() {
    //just as a test
    //set some matrix values in order to mulitply
    vector< vector<float> > a = { {2, 4, 6} , {2, 3, 5} , {3, 1, 4} };
    vector< vector<float> > b = { {1, 2, 3} , {3, 6, 1}, {3, 1, 4} };
    matA.set_data(a);
    matB.set_data(b);
    matA.disp_data();
    matB.disp_data();
    multiply(matA, matB);

}