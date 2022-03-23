#pragma once
#ifndef REVOLUTEFORWARDKINEMATICS2D_H
#define REVOLUTEFORWARDKINEMATICS2D_H

#include <vector>
#include <random>
#include <iostream>
#include<math.h>
#include "matrix.h"


vector<Matrix>	ForwardKinematics(int debug, float armLen[2], Matrix theta, float origin[2] = { 0 }); //returns a vector of matrices
vector<Matrix>	ForwardKinematics(float armLen[2], Matrix theta, float origin[2] = { 0 });




#endif // !REVOLUTEFORWARDKINEMATICS2D_H

