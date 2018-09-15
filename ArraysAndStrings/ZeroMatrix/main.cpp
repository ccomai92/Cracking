/*
    Write an algorithm such that if an element in an M*N
    matrix is 0, its entire row and column are set to 0. 

    Two methods: 
        using additional datastructure 
            1 or 2 
        
        without using addtional datastucture 
*/

#include <iostream> 
#include <string> 
#include <vector>
#include <map>
#include <stdlib.h> 

using namespace std; 

const int row = 5; 
const int col = 4; 

void nullify1(int **matrix, int row, int col); 
void nullify2(int **matrix, int row, int col); 
void print(int **matrix, int row, int col); 

int main() {
    
    int **matrix = new int*[row]; 
    for (int i = 0; i < row; i++) {
        matrix[i] = new int[col]; 
    }

    /* initialize random seed: */
    srand (time(NULL));

    /* generate secret number between 1 and 10: */
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            int random = rand() % 10;
            matrix[i][j] = random; 
        }
    }

    print(matrix, row, col);
    /*cout << endl;

    nullify1(matrix, row, col); 
    
    print(matrix, row, col);*/ 
    cout << endl;  

    nullify2(matrix, row, col); 
    
    print(matrix, row, col);
    cout << endl;

    return 0; 
}

void print(int **matrix, int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cout << matrix[i][j] << " "; 
        }
        cout << endl;
    }
}

// second method 
void nullify2(int **matrix, int row, int col) {
    // check if first row and column has zero 
    bool firstRowZeros = false; 
    bool firstColZeros = false;

    // first row  
    for (int i = 0; i < col; i++) {
        if (matrix[0][i] == 0) {
            firstRowZeros = true; 
        }
    }

    // first col 
    for (int i = 0; i < row; i++) {
        if (matrix[i][0] == 0) {
            firstColZeros = true;
        } 
    }

    // check rest of the matrix and record 0 in the 
    // first row and col 

    for (int i = 1; i < row; i++) {
        for (int j = 1; j < col; j++) {
            if (matrix[i][j] == 0) {
                matrix[i][0] = 0; 
                matrix[0][j] = 0; 
            }
        }
    }

    // check fist row and column to convert all zeros 
    for (int i = 0; i < col; i++) {
        if (matrix[0][i] == 0) {
            for (int j = 0; j < row; j++) {
                matrix[j][i] = 0; 
            }
        }
    }
 
    for (int i = 0; i < row; i++) {
        if (matrix[i][0] == 0) {
            for (int j = 0; j < col; j++) {
                matrix[i][j] = 0; 
            }
        }
    }

    if (firstRowZeros) {
        for (int i = 0; i < col; i++) {
            matrix[0][i] = 0; 
        }
    }

    if (firstColZeros) {
        for (int i = 0; i < col; i++) {
            matrix[i][0] = 0; 
        }
    }
}

// first method 
void nullify1(int **matrix, int row, int col) {
    map<int, bool> zeroRow; 
    map<int, bool> zeroCol; 

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (matrix[i][j] == 0) {
                zeroRow[i] = true;
                zeroCol[j] = true; 
            }
        }
    }

    for (map<int, bool>::iterator it = zeroRow.begin(); it != zeroRow.end(); ++it) {
        int row = it->first; 
        for (int i = 0; i < col; i++) {
            matrix[row][i] = 0; 
        }
    }

    for (map<int, bool>::iterator it = zeroCol.begin(); it != zeroCol.end(); ++it) {
        int col = it->first; 
        for (int i = 0; i < row; i++) {
            matrix[i][col] = 0; 
        }
    }
}