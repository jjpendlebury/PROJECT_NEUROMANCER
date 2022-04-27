// Project_Neuromancer.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include "neuromancer.h"
using namespace std;
Neuromancer cheese(1);

int main()
{
    vector<Matrix> kin_test;
    float lengths[2] = { 0.4,0.4 };
    float origin[2] = { 0,0 };
    Matrix angles(2,1000);
    angles.data[0] = GenRandVec(0.0f, 3.14f, 1000);
    angles.data[1] = GenRandVec(0.0f, 3.14f, 1000);
    kin_test = ForwardKinematics(lengths, angles, origin);

    //TEST
   /* Matrix angles_test(2, 10);
    angles_test.data[0] = GenRandVec(0.0f, 3.14f, 10);
    angles_test.data[1] = GenRandVec(0.0f, 3.14f, 10);
    Matrix angles_slice1, angles_slice2;
    angles_slice1 = angles_test(0, ':');
    angles_slice2 = angles_test(':', 0);
    cout << "slice 1 - first row" << endl << angles_slice1 << endl;
    cout << "slice 2 - first col" << endl << angles_slice2 << endl;
    cout << angles_test << endl;*/
    //cout << angles << endl << endl;

    /*for (int i = 0; i < kin_test.size(); i++) {
        cout << kin_test[i].dims << endl;
        cout << kin_test[i] << endl << endl;
    }*/
    cheese.set_inputs(kin_test[1]); //P2 angles
    cheese.set_targets(angles);
    cout << angles.dims << endl;
    
    cheese.execute();
    
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
