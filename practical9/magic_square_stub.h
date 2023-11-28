#include <stdio.h>
#include <stdlib.h>

// Checks if a matrix is a magic square.
// A magic square is an n-sided matrix whose sum of values for each
// row, column, main and secondary diagonals equals to n(n^2 + 1)/2.
// The function takes as input a matrix 'square' and its side length 'n'
// and outputs 0 if 'n' is negative or 'square' is NOT a magic square;
// otherwise, outputs a non-zero value
//
int isMagicSquare(int **square, const int n) {
    // Eliminate the case where 'n' is negative
    if (n < 0) {
        return 0;
    }

    // M is the sum of every row, column,
    // and the main and secondary diagonals
    int M = (n * (n*n + 1))/2;

    // Checking that every row and column add up to M
    for (int i = 0; i < n; i++) {
        int rowSum = 0, colSum = 0;
        for (int j = 0; j < n; j++) {
            rowSum += square[i][j];
            colSum += square[j][i];
        }
        if (rowSum != M || colSum != M) {
            return 0; // Not a magic square
        }
    }

    // Checking that the main and secondary diagonals each add up to M
    int mainDiagSum = 0, secDiagSum = 0;
    for (int i = 0; i < n; i++) {
        mainDiagSum += square[i][i];
        secDiagSum += square[i][n - 1 - i];
    }
    if (mainDiagSum != M || secDiagSum != M) {
        return 0; // Not a magic square
    }

    // If passed all checks, it is a magic square
    return 1;
}
