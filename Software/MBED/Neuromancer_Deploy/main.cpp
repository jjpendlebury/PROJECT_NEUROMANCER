/* mbed Microcontroller Library
 * Copyright (c) 2019 ARM Limited
 * SPDX-License-Identifier: Apache-2.0
 */

#include "mbed.h"
//#include "NetworkWeights.h"
//#include "neuromancer_deploy.h"
#include "Matrix_Deploy.h"
#define BLINKING_RATE     500ms

//neuromancer Case;
matrix inputs(3,10);
matrix targets(2,10);
matrix input_slice(3,1);
matrix W1(10,3);
matrix net1(10,1);
//second layer
matrix a2(10,1);
matrix a2hat(11,1,1);
//third layer
matrix W2(2,11);
matrix net2(2,1);
float W1_output[30] = {-0.908127,-0.767684,-0.133879,
    -0.174134,-1.88322,0.23203,
    -1.71668,-1.10146,-1.04194,
    -0.442175,-1.11105,-0.235124,
    -0.387182,-1.82566,0.168061,
    -0.135698,-1.77371,0.207188,
    -0.338738,-0.192463,-0.344092,
    -0.282729,-1.35214,-0.171054,
    0.486259,-1.29128,0.124648,
    -3.51269,-1.90169,-1.86282,
    };
    float W2_output[22] = {0.929358,0.00612833,1.445,0.615308,0.520298,-0.118593,0.377389,0.449987,-0.8806,1.65691,-0.235082,
    0.468984,1.68531,-0.674808,0.756938,1.53916,1.52939,-0.0542583,1.01692,0.773401,-2.74337,-0.77608,
    };
    float Inputs_output[15] = {    -0.706528,  -0.143219,  -0.135306,- 0.351626,   -0.275628,  
                                     0.351488,   -0.136183,  0.609451,   0.0871665,  -0.110546,  
                                     1,          1,          1,          1,          1,          
    };
    float Targets_outputs[10] = {  2.51492,    2.58064,    1.11371,    1.79774,    2.33254,
                                     0.330083,   2.64235,    1.3511,     2.20171,    2.38096,
    };
void display_network();
void grab_input(int column);
void first_layer();
void forward_pass();
void clear_matrix(matrix mat_in);



int main()
{
    printf("START-UP\n");
    printf("load weights\n");
    W1.set_data(W1_output,dimensions(10,3));
    W2.set_data(W2_output,dimensions(2,11));
    printf("load inputs\n");
    inputs.set_data(Inputs_output,dimensions(3,10));
    targets.set_data(Targets_outputs,dimensions(2,10));
    for(int i = 0;i < 5; i++){
        grab_input(0);
        forward_pass();
        first_layer();
        printf("\ninput %d:\n",i);
        input_slice.print();
        printf("\noutput %d:\n",i);
        net2.print();
        //net1.clear_data();
        //net2.clear_data();
        display_network();
    }
    printf("W1:\n");
    W1.print();
    printf("W2: \n");
    W2.print();
    // W2.dims.print_dims();
    // printf("no crash\n");
    // a2hat.dims.print_dims();
    // net2.dims.print_dims();
    // display_network();

}

void display_network(){
    printf("\nmatrix 0\n");
    input_slice.print();
    printf("\nmatrix 1\n");
    W1.print();
    printf("\nmatrix 2\n");
    net1.print();
    printf("\nmatrix 3\n");
    a2.print();
    printf("\nmatrix 4\n");
    a2hat.print();
    printf("\nmatrix 5\n");
    W2.print();
    printf("\nmatrix 6\n");
    net2.print();
}

void grab_input(int column){
    input_slice.data[0]=inputs.data[column];
    input_slice.data[1]=inputs.data[column+5];
    input_slice.data[2]=inputs.data[column+10];
}

void first_layer(){
    //net2=W2.multiply(a2hat);
    net2.mult(&W2, &a2hat);
}

void forward_pass(){
    //net1 = W1.multiply(input_slice);
    
    net1.mult(&W1,&input_slice);
    a2 = net1;
    a2.sigmoid();
    //add bias term back
    for(int i = 0; i<10;i++){
        a2hat.data[i]=a2.data[i];
    }
    //net2=W2.multiply(a2hat);
    //net1 = W1.multiply(input_slice);
}

