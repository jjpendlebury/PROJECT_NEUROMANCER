/* mbed Microcontroller Library
 * Copyright (c) 2019 ARM Limited
 * SPDX-License-Identifier: Apache-2.0
 */

#include "mbed.h"
//#include "../../Project Neuromancer/source/neuromancer.h"
#include "NetworkWeights.h"
#include "neuromancer.h"
#include <vector>
// Blinking rate in milliseconds
#define BLINKING_RATE     500ms

Neuromancer Case(0);
int main()
{
    // Initialise the digital pin LED1 as an output
    DigitalOut led(LED1);
    led = 1;
    Case.set_current_mode(network_mode::DEPLOYMENT);
    Case.set_episodes(1000);
    Case.set_trials(1);
    Case.set_weights(W1_output, W2_output);
    Matrix new_inputs;
    Matrix new_targets;
    vector<vector<float>> cheese = Inputs_output;
    cheese.pop_back();
    new_inputs = cheese;
    new_targets = Targets_outputs;
    Case.set_inputs(new_inputs);
    Case.set_targets(new_targets);
    Case.execute();
    
}
