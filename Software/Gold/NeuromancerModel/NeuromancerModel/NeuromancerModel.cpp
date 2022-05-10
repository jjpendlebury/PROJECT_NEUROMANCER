// NeuromancerModel.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <neuromancer.h>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;
//csv read test

Neuromancer test_network(0);


int main()
{
    string path = "../../MATLAB/ModelTrainingData.csv";
    test_network.set_setup_path(path);
    test_network.load_setup();
    test_network.display_network();
    test_network.set_episodes(1000);
    test_network.set_trials(5);
    test_network.execute();
    /*test_network.set_model_path(verification_path);
    test_network.verify_model();*/
    
}
