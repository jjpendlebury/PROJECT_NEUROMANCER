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

Matrix Create_test_vector(dimensions dims_in);

int main()
{
    Matrix test;
    test = Create_test_vector(dimensions(4, 4));
    cout << test << endl;
}

Matrix Create_test_vector(dimensions dims_in) {
    Matrix output(dims_in);
    int count = 1;
    for (int i = 0; i < dims_in.rows; i++) {
        for (int j = 0; j < dims_in.columns; j++) {
            output.data[i][j] = count;
            count++;
        }
    }
    return output;
}
