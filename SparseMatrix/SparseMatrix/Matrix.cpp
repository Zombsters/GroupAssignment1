#include "Matrix.h"


Matrix::Matrix(int nRows, int nCols) {
	numRows = nRows;
	numCols = nCols;

	//dynamic allocation //negative numbers cause crash...
	values = new int* [numRows];
	for (int i = 0; i < numRows; i++) {
		values[i] = new int[numCols]; //each row contains entries of columns...
	}

	//initializing values to 0
	for (int row = 0; row < numRows; row++) {
		for (int col = 0; col < numCols; col++) {
			values[row][col] = 0;
		}
	}

}

Matrix::Matrix(const Matrix& rhs) {
	this->numCols = rhs.numCols;
	this->numRows = rhs.numRows;
	

	//dynamic allocation //negative numbers cause crash...
	values = new int* [numRows];
	for (int i = 0; i < numRows; i++) {
		values[i] = new int[numCols]; //each row contains entries of columns...
	}

	//initializing values to 0
	for (int row = 0; row < numRows; row++) {
		for (int col = 0; col < numCols; col++) {
			values[row][col] = 0;
		}
	}
	

	int temp = 0;
	for (int row = 0; row < numRows; row++) {
		for (int col = 0; col < numCols; col++) {
			temp = this->values[row][col] + rhs.values[row][col];
			this->Insert(row, col, temp);
		}
	}
	
}

Matrix Matrix::operator=(const Matrix& rhs) {
	if (this->numRows != rhs.numRows || this->numCols != rhs.numCols) {

	}
	
	Matrix result(numRows, numCols);

	
	for (int row = 0; row < numRows; row++) {
		for (int col = 0; col < numCols; col++) {
			result.Insert(row, col, rhs.values[row][col]);
		}
	}

	return result;
}

Matrix::~Matrix() {
	//deallocting...
	for (int i = 0; i < numRows; i++) {
		delete values[i]; // deallocating each row contains entries of columns...
	}

	delete[] values; //deallocating the actual values
}


void Matrix::Insert(int row, int col, int value) {
	for (int i = 0; i < numRows; i++) {
		for (int j = 0; j < numCols; j++) {
			if (i == row && j == col) {
				values[row][col] = value;
			}
		}
	}
	
}

Matrix Matrix::operator+(const Matrix& rhs) {
	//todo: check size of matrices beforehand

	Matrix result(numRows, numCols); //same size when adding
	int temp = 0;
	for (int row = 0; row < numRows; row++) {
		for (int col = 0; col < numCols; col++) {
			temp = values[row][col] + rhs.values[row][col];
			result.Insert(row, col, temp);
		}
	}
	return result;
}

Matrix Matrix::transpose() {
	Matrix result(numCols, numRows);
	int temp = 0;
	for (int row = 0; row < numRows; row++) {
		for (int col = 0; col < numCols; col++) {
			temp = values[row][col];
			result.Insert(col, row, temp);
		}
	}

	return result;
}

void Matrix::Print(ostream &out) {
	
	for (int row = 0; row < numRows; row++) {
		for (int col = 0; col < numCols; col++) {
			out << values[row][col] << " ";
		}
		out << endl;
	}
}