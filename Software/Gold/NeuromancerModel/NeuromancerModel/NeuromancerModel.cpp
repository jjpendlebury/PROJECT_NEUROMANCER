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
    read_csv(path);
    std::cout << "Hello World!\n";
    
}
