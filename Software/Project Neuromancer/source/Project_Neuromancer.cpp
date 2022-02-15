// Project_Neuromancer.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include "neuromancer.h"
using namespace std;
Matrix test_matrix;
Matrix test_matrix2;
Neuromancer test;
int ROW_COUNT = 5;
int COLUMN_COUNT = 5;

//2d vector initialisaiton with a default value
std::vector<std::vector<float> > fog(ROW_COUNT, std::vector<float>(COLUMN_COUNT, 4));
vector< vector<float> > bar = { { 1, 1 }, {2, 2}    };  
vector< vector<float> > zog = { { 3, 3 }, {4,4}     };

int main()
{
    //this also works post-init
    //bar = { { 1, 1, 1 }, { 2, 2, 2 } };
    //cout << "Hello World!\n";
    //test_matrix.set_data(fog);
    //test_matrix.disp_data();
    //test_matrix2.set_data(bar);
    //test_matrix2.disp_data();
}



// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
