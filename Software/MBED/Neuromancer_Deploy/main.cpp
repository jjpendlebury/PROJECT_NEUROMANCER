/* mbed Microcontroller Library
 * Copyright (c) 2019 ARM Limited
 * SPDX-License-Identifier: Apache-2.0
 */

#include "mbed.h"
#include "../../Project Neuromancer/source/neuromancer.h"
#include "NetworkWeights.h"

// Blinking rate in milliseconds
#define BLINKING_RATE     500ms

Neuromancer Case(0);
int main()
{
    // Initialise the digital pin LED1 as an output
    DigitalOut led(LED1);
    led = 1;
    Case.set_current_mode(network_mode::DEPLOYMENT);
    Case.set_episodes(100);
    Case.set_trials(1);
    
}
