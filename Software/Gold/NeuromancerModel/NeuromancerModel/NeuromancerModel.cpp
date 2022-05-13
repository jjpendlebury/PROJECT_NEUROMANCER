// NeuromancerModel.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <neuromancer.h>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <chrono>
#include "test.h"
using namespace std;
//csv read test

Neuromancer test_network(0);


int main()
{
    string path = "../../MATLAB/ModelTrainingData.csv";
    string output = "output.csv";
    Matrix test(2, 2, 10);
    vector<float> test_vec = { 1,2,3 };
    write_mat_csv(test, output);
    write_vec_csv(test_vec, output);
    test_network.set_setup_path(path);
    test_network.load_setup();
    test_network.display_network();
    test_network.set_episodes(1000);
    test_network.set_trials(10);
    test_network.set_output_path(output);
    auto start = chrono::high_resolution_clock::now();
    test_network.execute();
    auto stop = chrono::high_resolution_clock::now();
    test_network.output_network();
    auto duration = chrono::duration_cast<chrono::seconds>(stop - start);
    cout << "duration: " << duration.count()<< " seconds " << endl;
    Matrix fleugh;
    fleugh = first_mat;
    cout << fleugh;
    create_header("test.h");
    write_mat_header(test, "first_mat", "test.h");
    close_header("test.h");
    
}
