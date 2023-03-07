#pragma once

#include<iostream>
#include<fstream>
#include<iomanip>
#include<string>
#include<sstream>
using namespace std;

class Matrix {
public:
    Matrix(const Matrix& rhs);
    Matrix(int rows, int cols);
    ~Matrix();

    void Insert(int row, int col, int value);
    void Print(ostream &out);

    Matrix operator+(const Matrix& rhs);
    Matrix operator=(const Matrix& rhs);

    Matrix transpose();
private:
    int numRows = 0; int numCols = 0;
    int** values = NULL;

};
