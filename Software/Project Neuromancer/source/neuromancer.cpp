#include "neuromancer.h"
using namespace std;

//PRIVATE

float d_mult = 3.33;

void Neuromancer::Test() {
    Matrix matA, matB;
    vector< vector<float> > a = { {2, 4, 6} , {2, 3, 5} , {3, 1, 4} };
    vector< vector<float> > b = { {1, 2, 3} , {3, 6, 1} , {3, 1, 4} };
    vector< vector<float> > c = { {1,2}     , {3 , 4  } , { 5, 6 }  };
    vector< vector<float> > d = { {7,8}     , {9 , 10 } , { 11, 12} };
    vector<float>           e = { 1,2,3 };
    cout << "SET MATRIX A:" << endl;
    matA.set_data(a);
    cout << "SET MATRIX B:" << endl;
    matB=b;                   //overload test
    Matrix matC;
    matC = c;
    Matrix matD;
    matD = d;
    cout << "DISPLAY A" << endl;
    matA.disp_data();
    cout << "DISPLAY B" << endl;
    matB.disp_data();
    cout << "TRANSPOSE" << endl;
    Matrix matAt = matA.transpose();
    matAt.disp_data();
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
    cout << endl << "addition test" << endl;
     Matrix result4 = matA + matB;
    result4.disp_data();
    result4 = matC + matD;
    result4.disp_data();
    Matrix result4t = result4.transpose();
    result4t.disp_data();
    Matrix test2(1000, 3);
    test2.disp_data();
    cout << "rows: " << test2.get_rows() << endl;
    cout << "cols: " << test2.get_cols() << endl;

    matA.disp_data();
    cout << "matA at (0,0): " << matA(0, 0) << endl;
    cout << "matA row 1: ";
    disp_vec(matA(0, ':'));
    cout << endl << "matA col 1: ";
    disp_vec(matA(':', 1));
    cout << matA.dims.columns << endl;
    cout << "det(a) =" << matA.determinant() << endl;
    Matrix mat2(2, 2);
    mat2 = { {1,2}, {3,4} };
    mat2.disp_data();
    cout << mat2.dims.columns << endl;
    mat2.determinant();
    cout << "det(Mat2) =" << mat2.determinant() << endl;
    Matrix singleVector;
    singleVector.set_data(e);
    singleVector.disp_data();
    singleVector *= 2;
    singleVector.disp_data();
    singleVector += 5.00f;
    singleVector.disp_data();
    cout << "Copy constructor test:" << endl;
    Matrix singleVector2 = singleVector;
    singleVector2.disp_data();
    singleVector += singleVector2;
    cout << singleVector << endl;
    cout << "END OF TESTS" << endl;
}

void Neuromancer::disp_vec(vector<float> input_vec) {
    for (auto it = input_vec.begin(); it != input_vec.end(); it++)
        cout << *it << " ";
    cout << endl;
}

void Neuromancer::disp_vec(vector<int> input_vec) {
    for (auto it = input_vec.begin(); it != input_vec.end(); it++)
        cout << *it << " ";
    cout << endl;
}

//Function to set up the network matrices based on the layout
void Neuromancer::init_network() {
    //For every entry in the layout vector, pushback a preallocated matrix onto the network vector
    for (int i = 0; i < network.size(); i++) {
        //edge case for inputs
        if (i == 0) {
            Matrix input(InputDims);
            network.push_back(input);
        }
        else if (i == 1) {   //second layer
            Matrix W1(hiddenUnits, InputDims.rows);
            Matrix Net(hiddenUnits, InputDims.columns);
            network.push_back(W1);
            network.push_back(Net);
        }
        else if (i == (network.size()-2)) {                         //1 before output layer
            Matrix W2(OutputDims.rows, network[i - 1].dims.rows);   //this is rotated, so the transpose needs to be taken
            Matrix Net2(OutputDims);
            network.push_back(W2);
            network.push_back(Net2);
        }
        else if (i == (network.size() - 1)) {   //output layer
            Matrix output(OutputDims);
            network.push_back(output);
        }
        else {  //every other layer
            Matrix weight()
        }
    }

}


//public
Neuromancer::Neuromancer() {
}
//test run
Neuromancer::Neuromancer(int test) {
    cout << "test = " << test << endl;
    //Matrix test routine
    if (test == 1) {
        Test();
    }
}

float Neuromancer::get_alpha() {
    float output = alpha;
    return output;
}

void Neuromancer::set_alpha(float new_learning_rate) {
    this->alpha = new_learning_rate;
}

vector<layer_type> Neuromancer::get_layout() {
    vector<layer_type> layout = this->network_layout;
    return layout; 
}

void Neuromancer::set_layout(vector<layer_type> input) {
    this->network_layout = input;
}

void display_network() {

}


