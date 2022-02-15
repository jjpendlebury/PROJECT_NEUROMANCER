#include "matrix.h"

using namespace std;

//comstructor
//need to write an assign loop to iterate through an array of arrays, and assign values like that
Matrix::Matrix() {
};

//
void Matrix::set_data(vector< vector<float> > &inputData) {
    data = inputData;
}

//method to 
void Matrix::get_data(vector<float>* data_vec) {

}

//method to display a matrix on to the terminal
void Matrix::disp_data() {
    for (auto i = 0; i < data.size(); i++) {
        for (
            auto it = data[i].begin(); it != data[i].end(); it++)
            cout << *it << " ";
        cout << endl;
    }
}