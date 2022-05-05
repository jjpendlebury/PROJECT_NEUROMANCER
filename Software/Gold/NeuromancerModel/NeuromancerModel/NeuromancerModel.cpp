// NeuromancerModel.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <neuromancer.h>
#include <fstream>
#include <sstream>

using namespace std;
//csv read test
void read_csv() {
    std::fstream fin; //file pointer
    cout << "opening file..." << endl;
    fin.open("test.csv");
    cout << "file open" << endl;
    vector<float> row;
    std::string temp,line,entry;
    while (getline(fin, line)) {
        //row.clear();
        cout << line << endl;
        stringstream s(line);
        while (getline(s, entry, ',')) {
            cout << entry << endl;
            row.push_back(stof(entry));
        }
        
    }
    cout << row[0] << " " << row[1] << " " << row[2] << " " << row[3] << endl;
}


int main()
{
    read_csv();
    std::cout << "Hello World!\n";
    
}
