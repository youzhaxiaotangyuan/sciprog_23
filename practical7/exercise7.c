#include <stdio.h>
#include <stdlib.h>

// Function to allocate an array of size n
double* allocatearray(int n) {
    return (double*)malloc(n * sizeof(double));
}

// Function to fill the array with ones
void fillwithones(double* array, int n) {
    for (int i = 0; i < n; i++) {
        array[i] = 1.0;
    }
}

// Function to print the array elements
void printarray(double* array, int n) {
    for (int i = 0; i < n; i++) {
        printf("%.4f ", array[i]);
    }
    printf("\n");
}

// Function to free the allocated memory
void freearray(double* array) {
    free(array);
}

// Function to estimate e using the Taylor series expansion
double estimate_e(int order) {
    double* terms = allocatearray(order + 1);
    fillwithones(terms, order + 1);

    // Perform the Taylor series expansion
    for (int i = 1; i <= order; i++) {
        terms[i] /= i;
    }

    // Sum up the terms
    double result = 0.0;
    for (int i = 0; i <= order; i++) {
        result += terms[i];
    }

    // Free the allocated memory
    freearray(terms);

    return result;
}

int main(void) {
    int n;

    printf("Enter the order of the polynomial: ");
    scanf("%d", &n);

    for (int order = 1; order <= n; order++) {
        double estimation = estimate_e(order);
        printf("Order %d: %.10f\n", order, estimation);
    }

    return 0;
}
