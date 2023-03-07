#include<iostream>
#include<fstream>
#include<iomanip>
#include<string>
#include<sstream>
#include "ArgumentManager.h"
#include "Matrix.h"
using namespace std;

int main(int argc, char* argv[]) {
    ArgumentManager am(argc, argv);


    ifstream fin(am.get("input"));
    ofstream fout(am.get("output"));
    /*string in_filename;
    string out_filename;
    cout << "Enter the name of the input file:\n";
    cin >> in_filename;
    cout << "Enter the name of the output file:\n";
    cin >> out_filename;

    ifstream fin(in_filename);
    ofstream fout(out_filename);*/
    char operation;
    int numRows = 0; int numCols = 0;
    int row = 0; int col = 0; int value = 0;
    string line; stringstream st(line);

    fin >> operation;
    cout << operation << endl;

    //first matrix
    fin >> numRows >> numCols;
    cout << numRows << " " << numCols << endl;
    fin.ignore();

    Matrix m1(numRows, numCols);
    /*while (getline(fin, line)) {
        if (line.length() == 0) {
            break;
        }
        st >> row >> col >> value;
        cout << line << endl;
        m1.Insert(row, col, value);
    }*/
    
    /*fin >> numRows >> numCols;
    fin.ignore();*/
    Matrix m2(4, 4);
    
    

    m1.Print(fout);
    cout << endl;
    Matrix m2(m1);
    m2.Print(fout);
    cout << endl;

    Matrix m3 = m1;
    m3.Print(fout);
    cout << endl;

    Matrix m4 = m1 + m3;
    m4.Print(fout);

    return 0;
}