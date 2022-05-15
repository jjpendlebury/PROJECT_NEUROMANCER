/* mbed Microcontroller Library
 * Copyright (c) 2019 ARM Limited
 * SPDX-License-Identifier: Apache-2.0
 */

#include "mbed.h"
#include "NetworkWeights.h"
#include "Matrix_Deploy.h"
#define BLINKING_RATE     500ms


int main()
{
    // Initialise the digital pin LED1 as an output
    
    printf("START-UP\n");
    DigitalOut led(LED1);
    led = 1;
    float cheese[4] = {1,2,3,4};
    
    dimensions test(2,2);
    //dimensions test2(2,1);
    //dimensions result;
    //matrix test_mat(2,2,1);
    //printf("mat1\n");
    //test_mat.print();
    matrix test_mat2(2,1,1);
    printf("mat2 \n");
    test_mat2.print();
    test_mat2.set_data(cheese, test);
    test_mat2.print();
    test_mat2.dims.print_dims();
    matrix test_mat3(test_mat2);
    test_mat3.sigmoid();
    printf("testmat 3\n");
    test_mat3.print();
    //matrix mult_result = test_mat.multiply(test_mat2);
    //printf("result \n");
    //mult_result.print();
    // printf("%f\n",sin(0));
    // printf("mat 2 again \n");
    // test_mat2.print();
    // matrix sin_result(test_mat2);
    // sin_result.sine();
    // sin_result.print();
    // matrix cos_result(test_mat2);
    // cos_result.cosine();
    // cos_result.print();
    // matrix sig_result(test_mat2);
    // sig_result.sigmoid();
    // printf("sigmoid\n");
    // sig_result.print();
    // printf("%f\n",sig(1.0));
}
