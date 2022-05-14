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
    ThisThread::sleep_for(BLINKING_RATE);
    led=0;
    ThisThread::sleep_for(BLINKING_RATE);
    
    dimensions test(1,2);
    dimensions test2(2,1);
    test.print_dims();
    test2.print_dims();
    dimensions result;
    result = test*test2;
    result.print_dims();
    matrix test_mat;
    test_mat.cheese();
    printf("bah\n");
    
}
