/* mbed Microcontroller Library
 * Copyright (c) 2019 ARM Limited
 * SPDX-License-Identifier: Apache-2.0
 */

#include "mbed.h"
#include "NetworkWeights.h"
#include "neuromancer_deploy.h"
//#include "Matrix_Deploy.h"
#define BLINKING_RATE     500ms

neuromancer Case;

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
    test_mat2.set_data(cheese, test);
    test_mat2.print();
    test_mat2.dims.print_dims();
    matrix test_mat3(test_mat2);
    //test_mat3.sigmoid();
    printf("testmat 3\n");
    test_mat3.print();
    matrix mult_result = test_mat2.multiply(test_mat3);
    printf("result \n");
    mult_result.print();
    matrix boop(2,2,5);
    printf("boop:\n");
    boop.print();
    boop=mult_result;
    printf("boop again:\n");
    boop.print();
    matrix boopslice(2,1);
    //boopslice = boop.column_slice(1);
    boopslice.column_slice(boop,1);
    printf("slice\n");
    boopslice.print();
}
