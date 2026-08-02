// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 4
// =============================================================================
//
// TASK: Matrix Operations
//
// Write a C++ program that performs three operations on matrices (2D arrays),
// each implemented in its own function.
//
// NOTE: Use a fixed maximum size of 10 for array dimensions.
//       Declare arrays as int matrix[10][10].
//
// -----------------------------------------------------------------------------
// PART A — Transpose a Matrix
// -----------------------------------------------------------------------------
// - Read an M x N matrix from the user.
// - Compute and display its transpose (rows become columns, columns become rows).
//
// Example (2 x 3 input):
//
//   Original Matrix:      Transposed Matrix:
//   1  2  3               1  4
//   4  5  6               2  5
//                         3  6
//
// -----------------------------------------------------------------------------
// PART B — Add Two Matrices
// -----------------------------------------------------------------------------
// - Read two matrices of exactly the same size (M x N).
// - Compute their element-wise sum and display the result.
//
// -----------------------------------------------------------------------------
// PART C — Multiply Two Matrices
// -----------------------------------------------------------------------------
// - Read matrix A of size M x N and matrix B of size N x P.
//   (Number of COLUMNS in A must equal number of ROWS in B.)
// - Compute and display the matrix product A x B (result is M x P).
//
// -----------------------------------------------------------------------------
// EXPECTED INPUT FORMAT
// -----------------------------------------------------------------------------
// The user enters each row's values one at a time:
//
//   Enter number of rows: 2
//   Enter number of columns: 3
//   Enter element [0][0]: 1
//   Enter element [0][1]: 2
//   ...
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Use nested loops for all operations (no external libraries).
// - Each operation must be in its own function (see scaffold below).
// - Display each matrix in a neat, aligned grid using setw().
// - Tip: Complete Part A first, then Parts B and C.
//

// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#include <iostream>
#include <iomanip>
using namespace std;

// Maximum allowed dimension for matrices
const int MAX_SIZE = 10;

// Function prototypes
void readMatrix(int mat[MAX_SIZE][MAX_SIZE], int rows, int cols, string name);
void printMatrix(const int mat[MAX_SIZE][MAX_SIZE], int rows, int cols);
void transposeMatrix(const int src[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows, int cols);
void addMatrices(const int A[MAX_SIZE][MAX_SIZE], const int B[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows, int cols);
void multiplyMatrices(const int A[MAX_SIZE][MAX_SIZE], const int B[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int m, int n, int p);

int main() {
    int choice;

    cout << "=== Matrix Operations Menu ===" << endl;
    cout << "1. Transpose a Matrix" << endl;
    cout << "2. Add Two Matrices" << endl;
    cout << "3. Multiply Two Matrices" << endl;
    cout << "Enter choice (1-3): ";
    cin >> choice;

    cout << endl;

    if (choice == 1) {
        // --- PART A: TRANSPOSE ---
        int rows, cols;
        int mat[MAX_SIZE][MAX_SIZE];
        int result[MAX_SIZE][MAX_SIZE];

        cout << "Enter number of rows: ";
        cin >> rows;
        cout << "Enter number of columns: ";
        cin >> cols;

        readMatrix(mat, rows, cols, "Matrix");

        transposeMatrix(mat, result, rows, cols);

        cout << "\nOriginal Matrix:" << endl;
        printMatrix(mat, rows, cols);

        cout << "\nTransposed Matrix:" << endl;
        printMatrix(result, cols, rows); // Dimensions swap to cols x rows
    }
    else if (choice == 2) {
        // --- PART B: ADDITION ---
        int rows, cols;
        int A[MAX_SIZE][MAX_SIZE];
        int B[MAX_SIZE][MAX_SIZE];
        int result[MAX_SIZE][MAX_SIZE];

        cout << "Enter number of rows for both matrices: ";
        cin >> rows;
        cout << "Enter number of columns for both matrices: ";
        cin >> cols;

        readMatrix(A, rows, cols, "Matrix A");
        readMatrix(B, rows, cols, "Matrix B");

        addMatrices(A, B, result, rows, cols);

        cout << "\nMatrix A:" << endl;
        printMatrix(A, rows, cols);

        cout << "\nMatrix B:" << endl;
        printMatrix(B, rows, cols);

        cout << "\nSum (A + B):" << endl;
        printMatrix(result, rows, cols);
    }
    else if (choice == 3) {
        // --- PART C: MULTIPLICATION ---
        int m, n, p;
        int A[MAX_SIZE][MAX_SIZE];
        int B[MAX_SIZE][MAX_SIZE];
        int result[MAX_SIZE][MAX_SIZE];

        cout << "Enter rows for Matrix A (M): ";
        cin >> m;
        cout << "Enter cols for A / rows for B (N): ";
        cin >> n;
        cout << "Enter cols for Matrix B (P): ";
        cin >> p;

        readMatrix(A, m, n, "Matrix A");
        readMatrix(B, n, p, "Matrix B");

        multiplyMatrices(A, B, result, m, n, p);

        cout << "\nMatrix A:" << endl;
        printMatrix(A, m, n);

        cout << "\nMatrix B:" << endl;
        printMatrix(B, n, p);

        cout << "\nProduct (A x B):" << endl;
        printMatrix(result, m, p);
    }
    else {
        cout << "Invalid selection." << endl;
    }

    return 0;
}

// Reads elements into a 2D array from user input
void readMatrix(int mat[MAX_SIZE][MAX_SIZE], int rows, int cols, string name) {
    cout << "\n--- Input elements for " << name << " ---" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << "Enter element [" << i << "][" << j << "]: ";
            cin >> mat[i][j];
        }
    }
}

// Prints the matrix with neat column formatting using setw()
void printMatrix(const int mat[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << setw(6) << mat[i][j];
        }
        cout << endl;
    }
}

// Part A: Transposes a matrix by swapping row and column indices
void transposeMatrix(const int src[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[j][i] = src[i][j];
        }
    }
}

// Part B: Adds two M x N matrices element-by-element
void addMatrices(const int A[MAX_SIZE][MAX_SIZE], const int B[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = A[i][j] + B[i][j];
        }
    }
}

// Part C: Multiplies Matrix A (M x N) and Matrix B (N x P) to produce result (M x P)
void multiplyMatrices(const int A[MAX_SIZE][MAX_SIZE], const int B[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int m, int n, int p) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < p; j++) {
            // Initialize accumulator for dot product
            result[i][j] = 0;
            for (int k = 0; k < n; k++) {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}