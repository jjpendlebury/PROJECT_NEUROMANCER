/* mbed Microcontroller Library
 * Copyright (c) 2019 ARM Limited
 * SPDX-License-Identifier: Apache-2.0
 */

#include "mbed.h"
#include "Matrix_Deploy.h"
#include <chrono>


// Blinking rate in milliseconds
#define BLINKING_RATE     500ms
Timer t;
using namespace std::chrono;

void test_routine();
void Create_test_vector_m(matrix* input, int m, int n);
int main()
{
    // Initialise the digital pin LED1 as an output
    printf("Initialising...\n");
    test_routine();
    printf("Complete.\n");
}

void test_routine(){
    int iterations = 21;
    int trials = 1000;
    for (int k = 1; k < iterations; k++) {
        //printf("Iteration: %d\n", k);
        matrix test(k,k);
        Create_test_vector_m(&test, k, k);
        matrix test2(k, k);
        Create_test_vector_m(&test2, k, k);
        matrix result(k, k);
        t.start();
        for (int i = 0; i <= trials; i++) {
            result.mult(&test, &test2);
        }
        t.stop();
        //printf("The time taken was %llu microseconds\n", duration_cast<microseconds>(t.elapsed_time()).count());
        printf("%llu\n", duration_cast<microseconds>(t.elapsed_time()).count());
        t.reset();
}
}

 void Create_test_vector_m(matrix *input,int m, int n) {
    float count = 1;
    for (int i = 0; i < m*n; i++) {
        input->data[i] = count;
        count++;
    }
}