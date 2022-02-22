#pragma once
#ifndef REVOLUTEFORWARDKINEMATICS2D_H
#define REVOLUTEFORWARDKINEMATICS2D_H

#include <vector>
#include <random>
#include "matrix.h"

float			randomValue(float upper = 1, float lower = 0);
vector<float>	GenRandVec(float upper = 1, float lower = 0, int size = 5);
Matrix			ForwardKinematics(float armLen[2], Matrix theta, float origin[2] = {0});




#endif // !REVOLUTEFORWARDKINEMATICS2D_H

