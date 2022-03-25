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
    random_vec = GenRandVec(-0.1,0.1,5);
    for (const auto& i : random_vec) std::cout << i << " ";
    cout << endl << "addition test" << endl;
     Matrix result4 = matA + matB;
    result4.disp_data();
    result4 = matC + matD;
    result4.disp_data();
    Matrix result4t = result4.transpose();
    result4t.disp_data();
    Matrix test2(10, 3);
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
    cout << "sigmoid test" << endl;
    dimensions sig_dims(10, 2);
    Matrix rand_mat = GenRandMat(sig_dims, 1, 2);
    cout << "Random Matrix:" << endl << rand_mat << endl;
    Matrix sig_mat(sig_dims, 1);
    cout << "Ones Matrix:" << endl << sig_mat << endl;
    Matrix sig_mat_out(sig_dims);
    sigmoid(&sig_mat, &sig_mat_out);
    cout << "output:" << endl << sig_mat_out << endl;
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
//void Neuromancer::init_network() {
//    //For every entry in the layout vector, pushback a preallocated matrix onto the network vector
//    int current_offset = 0;
//    for (int i = 0; i < network.size(); i++) {
//        cout << "cheese" << endl;
//        //edge case for inputs
//        if (i == 0) {
//            Matrix input(InputDims);
//            network.push_back(input);
//        }
//        else if (i == 1) {   //second layer
//            Matrix W1(hiddenUnits, InputDims.rows);
//            Matrix Net(hiddenUnits, InputDims.columns);
//            network.push_back(W1);
//            network.push_back(Net);
//        }
//        else if (i == (network.size()-2)) {                         //1 before output layer
//            Matrix W2(OutputDims.rows, network[i - 1].dims.rows);   //this is rotated, so the transpose needs to be taken
//            Matrix Net2(OutputDims);
//            network.push_back(W2);
//            network.push_back(Net2);
//        }
//        else if (i == (network.size() - 1)) {   //output layer
//            Matrix output(OutputDims);
//            network.push_back(output);
//        }
//        else {  //every other layer
//            Matrix weight(hiddenUnits+current_offset, network[i-1].dims.rows);
//            Matrix net(network[i - 1].dims.rows, network[i - 1].dims.columns);
//        }
//        //adjust offset
//        if (i > (network.size() / 2)) {
//            current_offset -= 1;
//        }
//        else {
//            current_offset += 1;
//        }
//    }
//
//}

//copy of the aint351 network
void Neuromancer::init_network() {
    //input layer
    Matrix inputLayer(InputDims);
    network.push_back(inputLayer);
    //First layer
    //Weight
    Matrix W1(10, 3);
    Matrix net1(10, 1);
    network.push_back(W1);
    network.push_back(net1);
    //second layer
    Matrix a2(10, 1);
    Matrix a2_hat(11, 1);
    network.push_back(a2);
    network.push_back(a2_hat);
    //third layer
    Matrix W2(2, 11);
    Matrix net2(2, 1);
    network.push_back(W2);
    network.push_back(net2);
    init_weights();
    //display_network();
}

void Neuromancer::init_weights() {
    //find weight matrices
    cout << "Performing weight initialisation..." << endl;
    for (int i = 0;i < network_layout.size();i++) {
        if (network_layout[i] == layer_type::LINEAR) {
            network[(2 * (i + 1)) - 1] = GenRandMat(network[(2 * (i + 1)) - 1].get_dims(), 0.1, -0.1);
        }
    }
}

void Neuromancer::sigmoid(Matrix* input, Matrix* output) {
    cout << "Sigmoid" << endl;
    //this layer is the layer before, sigmoid-ed 
    for (auto i = 0; i < input->data.size(); i++) {
        for (auto it = 0; it < input->data[i].size(); it++){
            output->data[i][it] = 1 / (1 + exp(-(input->data[i][it])));
            cout <<i<<","<<it<<" = " << output->data[i][it] << endl;
        }
    }

}

Matrix  Neuromancer::GenRandMat(dimensions dims, float upper, float lower){
    Matrix output(dims);
    for (int i = 0; i < output.dims.rows; i++) {
        output.data[i] = GenRandVec(upper, lower, output.dims.columns);
    }
    return output;
}

//public
Neuromancer::Neuromancer() {
    init_network();
    init_weights();
    display_network();
}
//test run
Neuromancer::Neuromancer(int test) {
    cout << "test = " << test << endl;
    //Matrix test routine
    if (test == 1) {
        Test();
        init_network();
        display_network();
    }
    else {
        cout << "no test" << endl;
        init_network();
        display_network();
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

void Neuromancer::display_network() {
    for (int i = 0; i < network.size(); i++) {
        cout << "Matrix #" << i<< endl<< network[i] << endl << endl;
    }
}

//float randomValue(float upper=1, float lower=0) {
//    static std::default_random_engine e;
//    static std::uniform_real_distribution<> dis(lower, upper);
//    return dis(e);
//}
//lower precision
float randomValue(float lower, float upper)
{
    return lower + (rand() / (RAND_MAX / (upper - lower)));
}
vector<float> GenRandVec(float upper=1, float lower=0, int size=5) {
    std::vector<float> nums;
    for (int i{}; i != size; ++i) // Generate 5 random floats
        nums.emplace_back(randomValue(lower, upper));

    return nums;
}
