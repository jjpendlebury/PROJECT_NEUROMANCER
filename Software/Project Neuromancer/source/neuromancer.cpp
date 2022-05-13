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
	cout << endl << matA(':', 1) << endl;
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

	dims_a = { 1, 3 };
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
	Matrix inputLayer(InputDims); //0
	network.push_back(inputLayer);
	//First layer
	//Weight
	Matrix W1(10, 3);               //1
	Matrix net1(10, 1);             //2
	network.push_back(W1);
	network.push_back(net1);
	//second layer
	Matrix a2(10, 1);               //3
	Matrix a2_hat(11, 1);           //4
	network.push_back(a2);
	network.push_back(a2_hat);
	//third layer
	Matrix W2(2, 11);               //5
	Matrix net2(2, 1);              //6
	network.push_back(W2);
	network.push_back(net2);
	//init_weights();
	//display_network();
}

void Neuromancer::init_weights() {
	//find weight matrices
	cout << "Performing weight initialisation..." << endl;
	for (int i = 0; i < network_layout.size(); i++) {
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
		for (auto it = 0; it < input->data[i].size(); it++) {
			output->data[i][it] = 1 / (1 + exp(-(input->data[i][it])));
		}
	}

}

void Neuromancer::sigmoid(Matrix* input, Matrix* output, int debug) {
#if DEBUG_MODE == 1
	cout << "Sigmoid" << endl;
#endif
	//Dimensions change test
	#if DEBUG_MODE == 1
	cout << "cheese" << endl;
	#endif
	input->data.pop_back();
	input->update_dims();
	#if DEBUG_MODE == 1
	cout << input->dims << " " << output->dims << endl;
	#endif
	//this layer is the layer before, sigmoid-ed 
	for (auto i = 0; i < output->data.size(); i++) {
		for (auto it = 0; it < output->data[i].size(); it++) {
			#if DEBUG_MODE == 1
			cout << "Accessing (" << i << "," << it << ")" << endl;
			#endif
			output->data[i][it] = 1 / (1 + exp(-(input->data[i][it])));
			#if DEBUG_MODE == 1
			cout << i << "," << it << " = " << output->data[i][it] << endl;
			#endif
		}
	}

}

Matrix Neuromancer::sigmoid(Matrix input, int debug) {
	Matrix output;
	Matrix inputMat = input;
	#if DEBUG_MODE == 1
	cout << "Input :" << endl << inputMat << endl;
	#endif
	vector<vector<float>> dataA = input.data;
	vector<vector<float>> dataB;
	#if DEBUG_MODE == 1
	cout << "Sigmoid" << endl;
	#endif
	dataB = dataA;
	//this layer is the layer before, sigmoid-ed 
	for (auto i = 0; i < dataA.size(); i++) {
		for (auto it = 0; it < dataA[i].size(); it++) {
			#if DEBUG_MODE == 1
			cout << "Accessing (" << i << "," << it << ")" << endl;
			#endif
			dataB[i][it] = i * it;
			#if DEBUG_MODE == 1
			cout << dataB[i][it] << endl;
			#endif
			dataB[i][it] = 1 / (1 + exp(-(dataA[i][it])));
#if DEBUG_MODE == 1
			cout << i << "," << it << " = " << dataB[i][it] << endl;
#endif
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
			#if DEBUG_MODE == 1
			cout << "Layer #" << i << " LAYER TYPE - LINEAR" << endl;
			cout << "Network Index = " << network_index << endl;
			cout << "GOAL RESULT - " << network[network_index].get_dims() << endl;
			cout << "CALCULATION =" << network[network_index - 1].get_dims() << " * " << network[network_index - 2].get_dims() << " = " << (network[network_index - 1].get_dims() * network[network_index - 2].get_dims()) << endl;
			cout << "A = " << endl << network[network_index - 1] << endl << "B = " << endl << network[network_index - 2] << endl;
			#endif
			network[network_index] = network[network_index - 1] * network[network_index - 2];
			#if DEBUG_MODE == 1
			cout << "LAYER COMPLETE" << endl;
			#endif      
		}
		else if (network_layout[i] == layer_type::SIGMOID) {
			#if DEBUG_MODE == 1
			cout << "Layer #" << i << " LAYER TYPE - SIGMOID" << endl;
			cout << "Network Index = " << network_index << endl;
			cout << network[network_index] << endl << endl << network[network_index - 1] << endl;
			#endif
			network[network_index - 1] = network[network_index - 2];
			network[network_index] = sigmoid(network[network_index - 1], 1);
			//sigmoid(&network[network_index - 1], &network[network_index]);
			//re-add removed bias term.
			vector<float> bias(network[network_index].dims.columns, 1);
			network[network_index].data.push_back(bias);
			network[network_index].update_dims();
		}
	}
};
void Neuromancer::back_propogation_351(int debug) {
#if DEBUG_MODE == 1
	cout << "BACKPROP BEGINS" << endl;
	//delta3
	cout << "delta 3 " << "target_slice " << target_slice.dims << " - " << network[network.size() - 1].dims << endl;
#endif
	back_network[0] = (target_slice - network[network.size() - 1]) * -1;

	//delta 2
	Matrix W2bar;
	W2bar = network[(network.size() - 2)].data;
#if DEBUG_MODE == 1
	cout << "W2" << endl << W2bar << endl;
#endif
	W2bar = W2bar.transpose();
	W2bar.data.pop_back();                          //remove last row, dropping bias terms, and transpose
#if DEBUG_MODE == 1
	cout << "W2bar:" << endl << W2bar << endl;
#endif

	Matrix a2error(network[2].get_dims(), 1);
	Matrix a2errorTemp(network[2].get_dims(), 1);
	//cout << "a2error" << endl << a2error << endl << "a2errorTemp:" << endl << a2errorTemp << endl;
	//correct up to here

	Matrix foo = network[4];    //a2hat
	foo.data.pop_back();        //a2
	Matrix cheese = (a2errorTemp - foo);
#if DEBUG_MODE == 1
	cout << "1-a2" << endl << "= 1-" << endl << network[4] << endl << cheese << endl;
	cout << "a2 .*(1-a2) =" << endl;
#endif
	a2error = (foo.mult_element(cheese));
#if DEBUG_MODE == 1
	cout << a2error << endl;
#endif
	Matrix bar = (W2bar * back_network[0]);
#if DEBUG_MODE == 1
	cout << "bar: " << bar << endl;
#endif

	Matrix zub = bar.mult_element(a2error);
#if DEBUG_MODE == 1
	cout << "zub:" << zub << endl;
#endif
	back_network[1] = bar.mult_element(a2error);
#if DEBUG_MODE == 1
	cout << "Delta 2" << endl << back_network[1] << endl;
#endif

	//diff2
	Matrix a2hat_t = network[4].transpose();
	back_network[2] = back_network[0] * a2hat_t;

	//diff 1
	Matrix x_t = network[0].transpose();
	back_network[3] = back_network[1] * x_t;

	Matrix error_temp1, error_temp2;
	error_temp1 = network[6] - target_slice;
#if DEBUG_MODE == 1
	cout << "error_Temp1" << error_temp1 << endl;
#endif
	error_temp2 = error_temp1;
	error_temp1 = error_temp1.transpose();
#if DEBUG_MODE == 1
	cout << "2 Dims: " << error_temp2.dims << " 1 Dims: " << error_temp1.dims << endl;
#endif
	Matrix error_temp3 = error_temp1 * error_temp2;
#if DEBUG_MODE == 1
	cout << "errortemp3" << error_temp3 << endl;
#endif
	error = error + error_temp3(0, 0);
#if DEBUG_MODE == 1
	cout << "error: " << error;
#endif
	error_vec.push_back(error);

	//adjust network weights
	network[5] = network[5] - back_network[2] * alpha;
	network[1] = network[1] - back_network[3] * alpha;
#if DEBUG_MODE == 1
	cout << "BACKPROP ENDS" << endl;
#endif
};


Matrix  Neuromancer::GenRandMat(dimensions dims, float upper, float lower) {
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

void Neuromancer::load_setup() {
	//read in a CSV file
	vector<vector<float>> setup_in;
	setup_in = read_csv(setup_path);  //read the setup CSV into data_in
	cout << "File read." << endl;
	//retrieve the row counts of the matrices to be loaded
	vector<int> input_rows;
	vector<Matrix*> Mat_Pointers; //pointers to the matrices to be pushed to
	input_rows.push_back(InputDims.rows - 1);           //inputs, AKA 'X'
	Mat_Pointers.push_back(&inputs);
	input_rows.push_back(OutputDims.rows);          //targets, AKA 'T'
	Mat_Pointers.push_back(&targets);
	input_rows.push_back(network[1].get_rows());    //W1
	Mat_Pointers.push_back(&network[1]);
	input_rows.push_back(network[5].get_rows());    //W2
	Mat_Pointers.push_back(&network[5]);
	//iterate through
	int linecount = 0;
	for (int i = 0; i < input_rows.size(); i++) {
		cout << i << endl;
		//clear each matrix
		Mat_Pointers[i]->data.clear();
		vector<vector<float>> temp;
		for (int j = 0; j < input_rows[i]; j++) {
			//now the matrix is clear, push each row of setup data to the matrix

			cout << "Grabbing line " << (linecount + j) << endl;
			disp_vec(setup_in[linecount + j]);

			temp.push_back(setup_in[linecount + j]);
			//Mat_Pointers[i]->data.push_back(setup_in[linecount + j]);

		}
		Mat_Pointers[i]->set_data(temp);
		linecount += input_rows[i];
	}
	cout << "Load Complete" << endl << "Displaying Matrices:" << endl;
	for (int l = 0; l < Mat_Pointers.size(); l++) {
		cout << Mat_Pointers[l] << endl;
	}
	cout << "Display Complete" << endl;
}

//void Neuromancer::verify_model() {
//    vector<vector<float>> model_in; //vector to store the loaded model
//    model_in = read_csv(model_path);
//    //check if the model loaded correctly
//    cout << model_in.size() << endl;
//    for (int k = 0; k < model_in.size(); k++) {
//        disp_vec(model_in[k]);
//    }
//    if (model_in.size() == 0) {
//        cout << "Model failed to load." << endl << "check the model path is set correctly." << endl;
//        return;
//    }
//    else {
//        cout << "Model loaded." << endl;
//    }
//
//    //pull error into placeholder matrix
//    Matrix error_temp;
//    error_temp.data.push_back({ error });
//    //do the same with W2 to get W2 bar
//    Matrix W2bar;
//    W2bar = network[(network.size() - 2)].data;
//    W2bar = W2bar.transpose();
//    W2bar.data.pop_back();
//    vector<Matrix*> mat_pointers; //vector of pointers, to point to the matrices to be used for comparison
//    //push matrices in the CORRECT ORDER - MUST MATCH CSV FILE
//    mat_pointers.push_back(&network[0]);        //input
//    mat_pointers.push_back(&network[2]);        //net1
//    mat_pointers.push_back(&network[4]);        //A2hat
//    mat_pointers.push_back(&network[6]);        //net2/output
//    mat_pointers.push_back(&back_network[0]);   //delta 3
//    mat_pointers.push_back(&W2bar);             //W2bar
//    mat_pointers.push_back(&back_network[1]);   //delta 2
//    mat_pointers.push_back(&back_network[2]);   //dedw2
//    mat_pointers.push_back(&back_network[3]);   //dedw1
//    mat_pointers.push_back(&error_temp);        //error (via error temp)
//    mat_pointers.push_back(&target_slice);      //target slice
//
//    //vectors to hold comparison result
//    vector<int> test_results;
//
//    int linecount = 0;
//    for (int i = 0; i < mat_pointers.size(); i++) {
//        Matrix temp(mat_pointers[i]->get_dims());       //temp matrix to hold the model data
//        for (int j = linecount; j < mat_pointers[i]->dims.rows; j++) {  //extract data from model input
//            temp.data.push_back(model_in[j]);
//        }
//        linecount += mat_pointers[i]->dims.rows;
//        //compare temp and actual dims
//        temp.update_dims();
//        if ((temp.dims.rows == mat_pointers[i]->dims.rows) && (temp.dims.columns == mat_pointers[i]->dims.columns)) {
//            test_results.push_back(1);
//        }
//
//    }
//    for (int l = 0; l < test_results.size(); l++) {
//        cout << test_results[l] << endl;
//    }
//
//
//
//}

void Neuromancer::execute() {
	cout << "Executing..." << endl;
	vector<float> ones_vec(1000, 1);
	vector<float> err_avg;
	inputs.data.push_back(ones_vec);
	inputs.update_dims();
	int count = 0;
	for (int j = 0; j < trials; j++) {
		error = 0;
		for (int i = 0; i < episodes; i++) {

			input_slice = inputs(':', i);       //load inputs into input slice
			#if DEBUG_MODE == 1
			cout << "INPUT SLICE: " << input_slice.dims << endl << input_slice << endl;
			#endif
			//input_slice.data.push_back({ 1 });
			target_slice = targets(':', i);
			#if DEBUG_MODE == 1
			cout << "TARGET SLICE: " << target_slice.dims << endl << target_slice << endl;
			#endif
			network[0] = input_slice;
			forward_pass();
			if (current_mode == network_mode::TRAINING) {
				back_propogation_351(1);
			}
			#if DEBUG_MODE == 1
			display_network();
			display_back_network();
			#endif
			#if DEBUG_MODE == 1
			cout << "TARGET SLICE: " << target_slice.dims << endl << target_slice << endl;
			#endif
		}
		//float trial_avg = vec_avg(error_vec);
		float trial_avg = error_vec[error_vec.size() - 1];
		#if DEBUG_MODE == 1
		disp_vec(error_vec);
		#endif
		err_avg.push_back(trial_avg);
		if (j % (trials / 10) == 0) {
			cout << count * 10 << "%" << endl;
			count++;
		}
	}
	disp_vec(err_avg);
	cout << "Complete." << endl;
	if (current_mode == network_mode::TRAINING) {
		back_propogation_351(1);
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

void Neuromancer::set_weights(vector < vector<float>> vec_a, vector<vector<float>> vec_b) {
	network[1] = vec_a;
	network[5] = vec_b;
}

network_mode	Neuromancer::get_current_mode() {
	return current_mode;
}
void			Neuromancer::set_current_mode(network_mode new_mode) {
	current_mode = new_mode;
}

std::string Neuromancer::get_setup_path() {
	return setup_path;
}

void Neuromancer::set_setup_path(std::string new_path) {
	setup_path = new_path;
}

std::string Neuromancer::get_model_path() {
	return setup_path;
}

void Neuromancer::set_model_path(std::string new_path) {
	setup_path = new_path;
}

std::string	Neuromancer::get_output_path() {
	return output_path;
}
void	Neuromancer::set_output_path(std::string new_path) {
	output_path = new_path;
}
void	Neuromancer::output_network() {
	//clear the file
	std::ofstream myfile;
	myfile.open(output_path);
	myfile.close();
	//write relevant matrices
	write_mat_csv(network[1], output_path);
	write_mat_csv(network[5], output_path);
	//Write to Header
	create_header("output.h");
	write_mat_header(network[1], "W1_output", "output.h");
	write_mat_header(network[5], "W2_output", "output.h");
	write_mat_header(inputs, "Inputs_output", "output.h");
	write_mat_header(targets, "Targets_outputs", "output.h");
	close_header("output.h");

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
		cout << "Matrix #" << i << endl << network[i] << endl << endl;
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
vector<float> GenRandVec(float upper = 1, float lower = 0, int size = 5) {
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

vector<vector<float>> read_csv(string path) {
	std::fstream fin; //file pointer
	cout << "opening file..." << endl;
	//try {
	fin.open(path);
	cout << "file open" << endl;
	vector<vector<float>> content;
	vector<float> row;
	std::string temp, line, entry;
	dimensions dims(2, 2);
	Matrix MatA(dims);
	int count = 0;
	while (getline(fin, line)) {
		row.clear();
		stringstream s(line);
		while (getline(s, entry, ',')) {
			row.push_back(stof(entry));
		}
		cout << row[0] << " " << row[1] << endl;
		content.push_back(row);
		count++;
	}
	return content;
	//}
	/*catch (...) {
		cout << "File failed to open." << endl;
		vector<vector<float>> error;
		return error;
	}*/
}

int write_mat_csv(Matrix in_mat, std::string filename) {
	std::ofstream myfile;
	myfile.open(filename, std::ios_base::app);
	for (int i = 0; i < in_mat.dims.rows; i++) {
		for (int j = 0; j < in_mat.dims.columns; j++) {
			myfile << in_mat(i, j);
			if (j != in_mat.dims.columns - 1) {
				myfile << ',';
			}
			else {
				myfile << endl;
			}
		}
	}
	myfile.close();
	return 0;
}

int write_mat_header(Matrix in_mat, std::string vec_name, std::string filename) {
	std::ofstream myfile;
	myfile.open(filename, std::ios_base::app);
	myfile << "vector<vector<float>> " << vec_name << "= {" << endl;
	for (int i = 0; i < in_mat.dims.rows; i++) {
		myfile << "{";
		for (int j = 0; j < in_mat.dims.columns; j++) {
			myfile << in_mat(i, j);
			if (j != in_mat.dims.columns - 1) {
				myfile << ',';
			}
			else {
				myfile << "},"<< endl;
			}
		}
	}
	myfile << "};" << endl;
	myfile.close();
	return 0;
}

int write_vec_csv(vector<float> in_vec, std::string filename) {
	std::ofstream myfile;
	myfile.open(filename, std::ios_base::app);
	for (int i = 0; i < in_vec.size(); i++) {
		myfile << in_vec[i];
		if (i != in_vec.size() - 1) {
			myfile << ',';
		}
		else {
			myfile << endl;
		}
	}
	myfile.close();
	return 0;
}

float vec_avg(vector<float> vec_in) {
	float total = 0;
	for (int i = 0; i < vec_in.size(); i++) {
		total += vec_in[i];
	}
	total = total / vec_in.size();
	return total;
}

int create_header(std::string header_name) {
	std::ofstream myfile;
	myfile.open(header_name);
	myfile << "//THIS FILE IS AUTOGENERATED" << endl;
	//header has been created
	//generate header guard reference
	std::string header_ref;
	int index = header_name.find('.');
	header_ref = header_name.substr(0, index);
	std::for_each(header_ref.begin(), header_ref.end(), [](char& c) {	//lambda function
		c = ::toupper(c);
		});
	header_ref ="__" + header_ref + "_H__";
	cout << header_ref;
	//write header guards to file
	myfile << "#pragma once" << endl << "#ifndef "<<header_ref<<endl;
	myfile << "#define " << header_ref << endl << endl;
	myfile << "#include <vector>" << endl;
	myfile.close();
	return 0;
}

int close_header(std::string header_path) {
	std::ofstream myfile;
	myfile.open(header_path, std::ios_base::app);
	myfile << endl << "#endif" << endl;
	myfile.close();
	return 0;
}
