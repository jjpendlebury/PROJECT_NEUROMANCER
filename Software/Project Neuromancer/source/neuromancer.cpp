#include "neuromancer.h"
using namespace std;

//PRIVATE

float d_mult = 3.33;

void Neuromancer::Test() {
    Matrix matA, matB;
    vector< vector<float> > a = { {2, 4, 6} , {2, 3, 5} , {3, 1, 4} };
    vector< vector<float> > b = { {1, 2, 3} , {3, 6, 1} , {3, 1, 4} };
    vector< vector<float> > c = { {1,2}     , {3 , 4  } , { 5, 6 } };
    vector< vector<float> > d = { {7,8}     , {9 , 10 } , { 11, 12} };
    vector<float>           e = { 1,2,3 };
    cout << "SET MATRIX A:" << endl;
    matA.set_data(a);
    cout << "SET MATRIX B:" << endl;
    matB = b;                   //overload test
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
    Matrix result2 = matA * 2;
    result2.disp_data();
    Matrix result3 = matA * d_mult;
    result3.disp_data();
    cout << "10 random numbers between 0 and 100" << endl;
    vector<float> random_vec = GenRandVec(0, 100, 10);
    for (const auto& i : random_vec) std::cout << i << " ";
    cout << endl << "Default parameters" << endl;
    random_vec = GenRandVec(-0.1, 0.1, 5);
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
    cout << matA(0, ':') << endl;
    cout << endl << "matA col 1: ";
    cout <<endl << matA(':', 1) << endl;
    cout << "MatA Coloumns: " << matA.dims.columns << endl;
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

    cout << "test flaugh" << endl;
    Matrix mat10(10, 3, 1);
    Matrix mat3(3, 1, 2);
    mat10.multiply(mat3, 1);

    cout << "Dimensions multiplication test" << endl;
    dimensions dims_a(2, 3), dims_b(3, 2);
    dimensions dims_c = dims_a * dims_b;
    cout << "A = " << dims_a << " * B = " << dims_b << endl;
    cout << "result = " << dims_c << endl;

    dims_a = { 4, 2 };
    dims_b = { 2,3 };
    dims_c = dims_a * dims_b;
    cout << "A = " << dims_a << " * B = " << dims_b << endl;
    cout << "result = " << dims_c << endl;

    dims_a = {1, 3};
    dims_b = { 1,3 };
    dims_c = dims_a * dims_b;
    cout << "A = " << dims_a << " * B = " << dims_b << endl;
    cout << "result = " << dims_c << endl;

    cout << "END OF TESTS" << endl;
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
void Neuromancer::init_network_351() {
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

void Neuromancer::init_back_351() {
    //Static backprop for the 351 network
    //delta 3 - same size as output layer
    Matrix delta3(network[(network.size() - 1)].get_dims());
    back_network.push_back(delta3);
    //delta 2 - W2bar
    Matrix delta2(network[(network.size() - 2)].get_rows(), network[(network.size() - 2)].get_cols() - 1);
    back_network.push_back(delta2);
    //de/dw2 - same as W2
    Matrix dedw2(network[(network.size() - 2)].get_dims());
    back_network.push_back(dedw2);
    // de/dw1 - same as W1
    Matrix dedw1(network[1].get_dims());
    back_network.push_back(dedw1);
}

void Neuromancer::sigmoid(Matrix* input, Matrix* output) {
    //this layer is the layer before, sigmoid-ed 
    for (auto i = 0; i < input->data.size(); i++) {
        for (auto it = 0; it < input->data[i].size(); it++){
            output->data[i][it] = 1 / (1 + exp(-(input->data[i][it])));
        }
    }

}

void Neuromancer::sigmoid(Matrix* input, Matrix* output, int debug) {
    cout << "Sigmoid" << endl;
    //Dimensions change test
    cout << "cheese" << endl;
    input->data.pop_back();
    input->update_dims();
    cout << input->dims << " " << output->dims << endl;
    //this layer is the layer before, sigmoid-ed 
    for (auto i = 0; i < output->data.size(); i++) {
        for (auto it = 0; it < output->data[i].size(); it++) {
            cout << "Accessing (" << i << "," << it << ")" << endl;
            output->data[i][it] = 1 / (1 + exp(-(input->data[i][it])));
            cout << i << "," << it << " = " << output->data[i][it] << endl;
        }
    }

}

Matrix Neuromancer::sigmoid(Matrix input, int debug) {
    Matrix output;
    Matrix inputMat = input;
    cout << "Input :" << endl << inputMat << endl;
    vector<vector<float>> dataA = input.data;
    vector<vector<float>> dataB;
    cout << "Sigmoid" << endl;
    //Dimensions change test
    cout << "cheese" << endl;
    //dataA.pop_back();
    dataB = dataA;
    cout << "cheese2" << endl;
    //this layer is the layer before, sigmoid-ed 
    for (auto i = 0; i < dataA.size(); i++) {
        for (auto it = 0; it < dataA[i].size(); it++) {
            cout << "Accessing (" << i << "," << it << ")" << endl;
            dataB[i][it] = i*it;
            cout << dataB[i][it] << endl;
            dataB[i][it] = 1 / (1 + exp(-(dataA[i][it])));
            cout << i << "," << it << " = " << dataB[i][it] << endl;
        }
    }
    output.set_data(dataB);
    return output;

}

void Neuromancer::forward_pass() {
    //iterate through the network, performing multiplications
    for (int i = 0; i < network_layout.size(); i++) {
        int network_index = 2 * (i + 1);                    //network layout -> network
        if (network_layout[i] == layer_type::LINEAR) {
            //linear layer, so just multiply the matrices
            cout << "Layer #" << i << " LAYER TYPE - LINEAR" << endl;
            cout << "Network Index = " << network_index << endl;
            cout << "GOAL RESULT - " << network[network_index].get_dims() << endl;
            cout << "CALCULATION =" << network[network_index - 1].get_dims() << " * " << network[network_index - 2].get_dims() << " = " << (network[network_index - 1].get_dims() * network[network_index - 2].get_dims()) << endl;
            cout << "A = " << endl << network[network_index - 1] << endl << "B = " <<endl<< network[network_index - 2] << endl;
            network[network_index] = network[network_index - 1] * network[network_index - 2];
            cout << "LAYER COMPLETE" << endl;
        }
        else if (network_layout[i] == layer_type::SIGMOID) {
            cout << "Layer #" << i << " LAYER TYPE - SIGMOID" << endl;
            cout << "Network Index = " << network_index << endl;
            cout << network[network_index] << endl << endl << network[network_index - 1] << endl;
            network[network_index - 1] = network[network_index - 2];
            network[network_index] = sigmoid(network[network_index-1],1);
            //sigmoid(&network[network_index - 1], &network[network_index]);
            //re-add removed bias term.
            vector<float> bias(network[network_index].dims.columns, 1);
            network[network_index].data.push_back(bias);
            network[network_index].update_dims();
        }
    }
};
void Neuromancer::back_propogation_351(int debug) {
    //delta3
    cout << "delta 3 " << "target_slice " << target_slice.dims << " - " << network[network.size() - 1].dims << endl;
    back_network[0] = (target_slice - network[network.size() - 1]) * -1;
    //delta 2
    Matrix W2bar;
    W2bar = network[(network.size() - 2)].data;
    W2bar.data.pop_back();                          //remove last row, dropping bias terms, and transpose
    W2bar = W2bar.transpose();
    Matrix a2error(network[3].get_dims(), 1);
    a2error = (network[3].mult_element(a2error - network[3]));
    back_network[1] = (W2bar * back_network[0]).mult_element(a2error);
    //diff2
    Matrix a2hat_t = network[4].transpose();
    back_network[2] = back_network[0] * a2hat_t;
    //diff 1
    Matrix x_t = network[0].transpose();
    back_network[3] = back_network[1] * x_t;
    //Sum of Squared error terms
    Matrix error_temp = back_network[0] * -1;
    Matrix error_temp2 = (error_temp.transpose() * error_temp);
    error = error + error_temp2(0, 0); //error temp2 is a 1x1, there has to be a more elegant way to do this
    //adjust network weights
    network[5] = network[5] - back_network[2] * alpha;
    network[1] = network[1] - back_network[3] * alpha;
};
void Neuromancer::back_propogation_351() {
    //delta3
    back_network[0] = (target_slice - network[network.size() - 1])*-1;
    //delta 2
    Matrix W2bar;
    W2bar = network[(network.size() - 2)].data;
    W2bar.data.pop_back();                          //remove last row, dropping bias terms, and transpose
    W2bar = W2bar.transpose();
    Matrix a2error(network[3].get_dims(), 1);
    a2error = (network[3].mult_element(a2error - network[3]));
    back_network[1] = (W2bar * back_network[0]).mult_element(a2error);
    //diff2
    Matrix a2hat_t = network[4].transpose();
    back_network[2] = back_network[0] * a2hat_t;
    //diff 1
    Matrix x_t = network[0].transpose();
    back_network[3] = back_network[1] * x_t;
    //Sum of Squared error terms
    Matrix error_temp = back_network[0] * -1;
    Matrix error_temp2 = (error_temp.transpose() * error_temp);
    error = error + error_temp2(0, 0); //error temp2 is a 1x1, there has to be a more elegant way to do this
    //adjust network weights
    network[5] = network[5] - back_network[2] * alpha;
    network[1] = network[1] - back_network[3] * alpha;
};

Matrix  Neuromancer::GenRandMat(dimensions dims, float upper, float lower){
    Matrix output(dims);
    for (int i = 0; i < output.dims.rows; i++) {
        output.data[i] = GenRandVec(upper, lower, output.dims.columns);
    }
    return output;
}

//public
Neuromancer::Neuromancer() {
    cout << "Initialising network..." << endl;
    init_network_351();
    cout << "Initialising weights..." << endl;
    init_weights();
    cout << "NETWORK LAYOUT:" << endl;
    display_network();
    cout << "Initialising backpropogation network..." << endl;
    init_back_351();
    cout << "BACKPROP NETWORK: " << endl;
    display_back_network();
}
//test run
Neuromancer::Neuromancer(int test) {
    cout << "test = " << test << endl;
    //Matrix test routine
    if (test == 1) {
        Test();
    }
    else {
        cout << "no test" << endl;
    }
    cout << "Initialising network..." << endl;
    init_network_351();
    cout << "Initialising weights..." << endl;
    init_weights();
    cout << "NETWORK LAYOUT:" << endl;
    display_network();
    cout << "Initialising backpropogation network..." << endl;
    init_back_351();
    cout << "BACKPROP NETWORK: " << endl;
    display_back_network();
    //execute();
}

void Neuromancer::execute() {
    cout << "Executing..." << endl;
    vector<float> ones_vec(1000, 1);
    inputs.data.push_back(ones_vec);
    inputs.update_dims();
    for (int i = 0; i < episodes; i++) {
        input_slice = inputs(':', i);       //load inputs into input slice
        cout << "INPUT SLICE: " << input_slice.dims << endl << input_slice << endl;
        //input_slice.data.push_back({ 1 });
        target_slice = targets(':',i);
        cout << "TARGET SLICE: " << target_slice.dims << endl << target_slice << endl;
        network[0] = input_slice;
        forward_pass();
        //back_propogation_351(1);
        display_network();
    }
}

Matrix Neuromancer::get_inputs() {
    return inputs;
}

void Neuromancer::set_inputs(Matrix new_inputs) {
    inputs = new_inputs;
}

Matrix Neuromancer::get_targets() {
    return targets;
}

void Neuromancer::set_targets(Matrix new_targets) {
    targets = new_targets;
}

float Neuromancer::get_alpha() {
    float output = alpha;
    return output;
}

void Neuromancer::set_alpha(float new_learning_rate) {
    this->alpha = new_learning_rate;
}

int Neuromancer::get_episodes() {
    float output = episodes;
    return output;
}

void Neuromancer::set_episodes(int new_episodes) {
    this->episodes = new_episodes;
}
int Neuromancer::get_trials() {
    float output = trials;
    return output;
}

void Neuromancer::set_trials(int new_trials) {
    this->trials = new_trials;
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

void Neuromancer::display_back_network() {
    for (int i = 0; i < back_network.size(); i++) {
        cout << "Matrix #" << i << endl << back_network[i] << endl << endl;
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



std::ostream& operator<<(std::ostream& os, const vector<float>& vec) {
    for (auto it = vec.begin(); it != vec.end(); it++)
        os << *it << " ";
    os << endl;
    return os;
};

std::ostream& operator<<(std::ostream& os, const vector<int>& vec) {
    for (auto it = vec.begin(); it != vec.end(); it++)
        os << *it << " ";
    os << endl;
    return os;
};
