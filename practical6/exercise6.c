#include <stdio.h>

#define n 5
#define p 3
#define q 4

// Function to multiply two matrices A and B and store the result in matrix C
void matmult(double A[n][p], double B[p][q], double C[n][q]) {
    // Initialize matrix C to zero
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < q; j++) {
            C[i][j] = 0.0;
        }
    }

    // Calculate matrix C elements using the given formulas
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < q; j++) {
            for (int k = 0; k < p; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

int main(void) {
    // Declare three arrays A, B, and C
    double A[n][p], B[p][q], C[n][q];

    // Initialize arrays A and B as per the given formulas
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < p; j++) {
            A[i][j] = i + j;
        }
    }

    for (int i = 0; i < p; i++) {
        for (int j = 0; j < q; j++) {
            B[i][j] = i - j;
        }
    }

    // Multiply matrices A and B and store the result in matrix C
    matmult(A, B, C);

    // Print arrays A, B, and C to the screen
    printf("Matrix A:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < p; j++) {
            printf("%f ", A[i][j]);
        }
        printf("\n");
    }

    printf("\nMatrix B:\n");
    for (int i = 0; i < p; i++) {
        for (int j = 0; j < q; j++) {
            printf("%f ", B[i][j]);
        }
        printf("\n");
    }

    printf("\nMatrix C (Result of A x B):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < q; j++) {
            printf("%f ", C[i][j]);
        }
        printf("\n");
    }

    return 0;
}
