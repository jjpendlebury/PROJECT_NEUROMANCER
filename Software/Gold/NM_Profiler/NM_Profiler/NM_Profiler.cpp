// NeuromancerModel.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <neuromancer.h>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <chrono>
#include "test.h"
#include "Matrix_Deploy.h"
using namespace std;
//csv read test

Matrix Create_test_vector(dimensions dims_in);
void Create_test_vector_m(matrix_m* input, int m, int n);
void test_routine();
void test_routine_inplace();
void test_routine_m();
matrix_m test_m;

int main()
{
    //Neuromancer matrices
    /*Matrix test(20, 20);
    test = Create_test_vector(dimensions(20, 20));
    Matrix test2(20, 20);
    test2 = Create_test_vector(dimensions(20, 20));
    Matrix result_p(20, 20);
    int a = 0;
    Matrix result = test.multiply(test2);
    int b = 0;
    result.multiply_place(&test, &test2);
    int c = 0;
    matrix_m testm(20,20);
    Create_test_vector_m(&testm, 20,20);
    matrix_m testm2(20, 20);
    Create_test_vector_m(&testm2, 20,20);
    matrix_m resultm(20, 20);
    c = 0;
    resultm.mult(&testm, &testm2);
    c = 0;*/
    int a = 0;
    matrix_m test(20, 20);
    return 0;
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

 void Create_test_vector_m(matrix_m *input,int m, int n) {
    float count = 1;
    for (int i = 0; i < m*n; i++) {
        input->data[i] = count;
        count++;
    }
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

void test_routine_inplace() {
    int iterations = 21;
    int trials = 100000;

    Matrix outputs(dimensions(iterations - 1, 4));
    for (int k = 1; k < iterations; k++) {
        Matrix test;
        test = Create_test_vector(dimensions(k, k));
        cout << test << endl;
        Matrix test2 = Create_test_vector(dimensions(k, k));
        Matrix result(k, k);
        
        auto start = chrono::high_resolution_clock::now();
        for (int i = 0; i <= trials; i++) {
            result.multiply_place(&test, &test2);
        }
        auto stop = chrono::high_resolution_clock::now();
        cout << result << endl;

        auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
        auto duration_ms = chrono::duration_cast<chrono::milliseconds>(stop - start);
        auto duration_s = chrono::duration_cast<chrono::seconds>(duration);
        cout << k << "x" << k << " duration: " << duration.count() << "ms" << endl << duration_s.count() << "s" << endl;
        vector<float> output_row;
        output_row.push_back(k);
        output_row.push_back(float(duration.count()));
        output_row.push_back(float(duration_ms.count()));
        output_row.push_back(float(duration_s.count()));
        outputs.data[k - 1] = output_row;
    }
    cout << "OUTPUT:" << endl << outputs << endl;
    std::ofstream myfile;
    myfile.open("test_results_in_place.csv");
    myfile.close();
    //write relevant matrices
    write_mat_csv(outputs, "test_results_in_place.csv");
}

void test_routine_m() {
    int iterations = 21;
    int trials = 100000;

    Matrix outputs(iterations - 1, 4);
    for (int k = 1; k < iterations; k++) {
        matrix_m test(k,k);
        Create_test_vector_m(&test, k, k);
        matrix_m test2(k, k);
        Create_test_vector_m(&test2, k, k);
        matrix_m result(k, k);

        auto start = chrono::high_resolution_clock::now();
        for (int i = 0; i <= trials; i++) {
            result.mult(&test, &test2);
        }
        auto stop = chrono::high_resolution_clock::now();

        auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
        auto duration_ms = chrono::duration_cast<chrono::milliseconds>(stop - start);
        auto duration_s = chrono::duration_cast<chrono::seconds>(duration);
        result.print();
        cout << k << "x" << k << " duration: " << duration.count() << "ms" << endl << duration_s.count() << "s" << endl;
        vector<float> output_row;
        output_row.push_back(k);
        output_row.push_back(float(duration.count()));
        output_row.push_back(float(duration_ms.count()));
        output_row.push_back(float(duration_s.count()));
        outputs.data[k - 1] = output_row;
    }
    cout << "OUTPUT:" << endl << outputs << endl;
    std::ofstream myfile;
    myfile.open("test_results_m.csv");
    myfile.close();
    //write relevant matrices
    write_mat_csv(outputs, "test_results_m.csv");
}
