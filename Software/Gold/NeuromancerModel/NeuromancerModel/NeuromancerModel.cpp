// NeuromancerModel.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <neuromancer.h>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;
//csv read test
vector<vector<float>> read_csv() {
    std::fstream fin; //file pointer
    cout << "opening file..." << endl;
    fin.open("test.csv");
    cout << "file open" << endl;
    vector<vector<float>> content;
    vector<float> row;
    std::string temp,line,entry;
    dimensions dims(2, 2);
    Matrix MatA(dims);
    int count = 0;
    while (getline(fin, line)) {
        row.clear();
        stringstream s(line);
        while (getline(s, entry, ',')) {
            row.push_back(stof(entry));
        }
        cout << row[0] << " " << row[1] << endl;
        content.push_back(row);
        count++;
    }
}

Neuromancer test_network(0);


int main()
{
    read_csv();
    std::cout << "Hello World!\n";
    
}
