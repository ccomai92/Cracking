/*
    Given an image represented by an NxN matrix, where each 
    pixel in the image is 4 bytes, write a method to rotate 
    the image by 90 degrees. Can you do this in place? 
*/ 

#include <iostream> 
#include <string> 
using namespace std; 

const int row = 4;
const int col = 4; 

void rotate(int **matrix, int row, int col); 
void print(int **matrix, int row, int col); 
int main() {
    int **matrix = new int*[row];
    for (int i = 0; i < 5; i++) {
        matrix[i] = new int[col]; 
    } 
    int count = 1; 
    for (int i = 0; i < row; i++) { // row
        for (int j = 0; j < col; j++) { // col
            matrix[i][j] = count++; 
        }
    }

    rotate(matrix, row, col); 

    return 0; 
}



void rotate(int **matrix, int row, int col) {
    if (row != col) {
        cout << "num_row != num_col" << endl;
        return;
    }
    
    print(matrix, row, col); 
    cout << endl;
    for (int i = 0; i < row / 2; i++) { // layers 
        int start = i; 
        int last = col - 1 - i;
        for (int j = 0; j < last - start; j++) { // though column is N, should move N - 1 element per layer
            int temp = matrix[start][start + j]; 
            matrix[start][start + j] = matrix[last - j][start]; 
            matrix[last - j][start] = matrix[last][last - j];
            matrix[last][last - j] = matrix[start + j][last]; 
            matrix[start + j][last] = temp; 
            print(matrix, row, col); 
            cout << endl;
        }
    }
    print(matrix, row, col); 
}

void print(int **matrix, int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cout << matrix[i][j] << " "; 
        }
        cout << endl; 
    }    
}