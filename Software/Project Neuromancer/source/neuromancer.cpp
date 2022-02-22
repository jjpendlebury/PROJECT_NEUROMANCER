#include "neuromancer.h"
using namespace std;

//PRIVATE

float d_mult = 3.33;

void Neuromancer::Test() {
    vector< vector<float> > a = { {2, 4, 6} , {2, 3, 5} , {3, 1, 4} };
    vector< vector<float> > b = { {1, 2, 3} , {3, 6, 1}, {3, 1, 4} };
    cout << "SET MATRIX A:" << endl;
    matA.set_data(a);
    cout << "SET MATRIX B:" << endl;
    matB=b;                   //overload test
    cout << "DISPLAY A" << endl;
    matA.disp_data();
    cout << "DISPLAY B" << endl;
    matB.disp_data();
    cout << "MULTIPLY A*B:" << endl;
    matA.multiply(matB, 1);
    cout << endl;
    Matrix result2 = matA*2;
    result2.disp_data();
    Matrix result3 = matA*d_mult;
    result3.disp_data();
    cout << "10 random numbers between 0 and 100" << endl;
    vector<float> random_vec = GenRandVec(0,100,10);
    for (const auto& i : random_vec) std::cout << i << " ";
    cout << endl << "Default parameters" << endl;
    random_vec = GenRandVec();
    for (const auto& i : random_vec) std::cout << i << " ";
}




//public
Neuromancer::Neuromancer(int test) {
    cout << "test = " << test << endl;
    //Matrix test routine
    if (test == 1) {
        Test();
    }
}