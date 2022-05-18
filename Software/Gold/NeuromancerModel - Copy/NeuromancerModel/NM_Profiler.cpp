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
void test_routine();

int main()
{
    test_routine();
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

void test_routine() {
    int iterations = 21;
    int trials = 100000;

    Matrix outputs(dimensions(iterations-1,4));
    for (int k = 1; k < iterations; k++) {
        Matrix test;
        test = Create_test_vector(dimensions(k, k));
        cout << test << endl;
        Matrix test2 = Create_test_vector(dimensions(k, k));
        Matrix result = test.multiply(test2);
        cout << result << endl;
        auto start = chrono::high_resolution_clock::now();
        for (int i = 0; i <= trials; i++) {
            Matrix result = test.multiply(test2);
        }
        auto stop = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
        auto duration_ms = chrono::duration_cast<chrono::milliseconds>(stop - start);
        auto duration_s = chrono::duration_cast<chrono::seconds>(duration);
        cout << k <<"x" <<k << " duration: " << duration.count() << "ms" << endl << duration_s.count() << "s" << endl;
        vector<float> output_row;
        output_row.push_back(k);
        output_row.push_back(float(duration.count()));
        output_row.push_back(float(duration_ms.count()));
        output_row.push_back(float(duration_s.count()));
        outputs.data[k - 1] = output_row;
    }
    cout << "OUTPUT:" << endl << outputs << endl;
    std::ofstream myfile;
    myfile.open("test_results.csv");
    myfile.close();
    //write relevant matrices
    write_mat_csv(outputs, "test_results.csv");
}
