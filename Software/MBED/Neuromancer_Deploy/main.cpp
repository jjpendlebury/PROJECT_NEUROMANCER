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
    
    printf("beans\n");
    DigitalOut led(LED1);
    led = 1;
    
    dimensions test(1,2);
    dimensions test2(2,1);
    dimensions result;
    matrix test_mat(2,2,1);
    printf("mat1\n");
    test_mat.print();
    matrix test_mat2(2,2,4);
    printf("mat2 \n");
    test_mat2.print();
    matrix mult_result = test_mat.multiply(test_mat2);
    printf("result \n");
    mult_result.print();
    // printf("%f\n",sin(0));
    // printf("mat 2 again \n");
    // test_mat2.print();
    //matrix sin_result(test_mat2);
    //sin_result = test_mat2.sine();
    //sin_result.print();
}
