//Elizabeth Channel//
//Lab 6//
//Matrix manipulation in C++//

#include <iostream>
#include <fstream>
#include <iomanip>


//set constant for size
const int MAX_SIZE = 100;

//functions//

//reading file
void readMatrixFromFile(int matrixA[MAX_SIZE][MAX_SIZE], int matrixB[MAX_SIZE][MAX_SIZE], int& size, const char* filename);

//print the matrices
void printMatrix(const int matrix[MAX_SIZE][MAX_SIZE], int size);

//add the matrices
void addMatrices(const int matrixA[MAX_SIZE][MAX_SIZE], const int matrixB[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int size);

//multiply the matrices
void multiplyMatrices(const int matrixA[MAX_SIZE][MAX_SIZE], const int matrixB[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int size);

//subtract the matrices
void subtractMatrices(const int matrixA[MAX_SIZE][MAX_SIZE], const int matrixB[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int size);

//main function
int main() {
    //make variable for size, matrices, and results
    int size;
    int matrixA[MAX_SIZE][MAX_SIZE];
    int matrixB[MAX_SIZE][MAX_SIZE];
    int result[MAX_SIZE][MAX_SIZE];

    //call read file function for the gven file "matrx_input"
    readMatrixFromFile(matrixA, matrixB, size, "matrix_input.txt");

    //title: name, subtitle: lab
    std::cout << "Elizabeth Channel" << std::endl;
    std::cout << "Lab #6: Matrix Manipulation" << std::endl;

    //title: matrix a
    std::cout << "Matrix A:" << std::endl;
    printMatrix(matrixA, size); //print the matrix using print matrix function

    //title: matrix b
    std::cout << "Matrix B:" << std::endl;
    printMatrix(matrixB, size); //print the matrix using print matrix function

    //add matrices
    addMatrices(matrixA, matrixB, result, size);
    //title: matrix sum
    std::cout << "Matrix Sum (A + B):" << std::endl;
    printMatrix(result, size); //print sum if matrices using print matrix function

    //multiply matrices
    multiplyMatrices(matrixA, matrixB, result, size);
    //title: matrix product
    std::cout << "Matrix Product (A * B):" << std::endl;
    printMatrix(result, size); //print product of matrices using print matrix function

    //subtract matrices
    subtractMatrices(matrixA, matrixB, result, size);
    //title: matrix difference
    std::cout << "Matrix Difference (A - B):" << std::endl;
    printMatrix(result, size); //print subtracted matrix using print matrix function

    return 0;
}


//setting up the functions

//read file function
void readMatrixFromFile(int matrixA[MAX_SIZE][MAX_SIZE], int matrixB[MAX_SIZE][MAX_SIZE], int& size, const char* filename) {
    std::ifstream file(filename);
    //if the file is unable to be/isnt open, print error message
    if (!file.is_open()) { 
        std::cerr << "Error: Unable to open the file " << filename << std::endl; //print error message
        exit(1); //exit program
    }

    file >> size; //read file lines

    //put values into matrixA
    //read the lines of the file and input them into matrix a index
    for (int i = 0; i < size; i++) { 
        for (int j = 0; j < size; j++) {
            file >> matrixA[i][j]; //index insertion
        }
    }

    //pead values into matrixB starting from the last 9 values
    int row = size - 3; //last 3 lines
    //read the lines of the file and input them into matrix a index
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < size; j++) {
            file >> matrixB[i][j]; //index insertion
        }
        row++; //next row
    }

    file.close(); //close the file
}


//print matrix function
void printMatrix(const int matrix[MAX_SIZE][MAX_SIZE], int size) {
    //for each line in file, print the value to the matrix
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            std::cout << std::setw(3) << matrix[i][j] << " "; //print 
        }
        std::cout << std::endl;
    }
}


//add matrices function
void addMatrices(const int matrixA[MAX_SIZE][MAX_SIZE], const int matrixB[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int size) {
    //for each line in the file, add the values and put into new matrix
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            result[i][j] = matrixA[i][j] + matrixB[i][j]; //index insertion of the new values
        }
    }
}


//multiply matrices function
void multiplyMatrices(const int matrixA[MAX_SIZE][MAX_SIZE], const int matrixB[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int size) {
    //for each line in the file, add the values and put into new matrix
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            result[i][j] = 0; //set index value to zero
            for (int k = 0; k < size; k++) { //k constraints
                result[i][j] += matrixA[i][k] * matrixB[k][j]; //multiply the values of each matrix and add to value (0) at same index
            }
        }
    }
}


//subtract matrices function
void subtractMatrices(const int matrixA[MAX_SIZE][MAX_SIZE], const int matrixB[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int size) {
    //for each line in the file, add the values and put into new matrix
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            result[i][j] = matrixA[i][j] - matrixB[i][j]; //subtract each value and add to new matrix at same index
        }
    }
}
