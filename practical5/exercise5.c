#include <stdio.h>

// Function to display Fibonacci series up to n
void displayFibonacci(int n) {
    int firstTerm = 0, secondTerm = 1, nextTerm;

    printf("Fibonacci Series up to %d terms: %d, %d, ", n, firstTerm, secondTerm);

    for (int i = 3; i <= n; ++i) {
        nextTerm = firstTerm + secondTerm;
        printf("%d, ", nextTerm);
        firstTerm = secondTerm;
        secondTerm = nextTerm;
    }
    printf("\n");
}

int main(void) {
    int n;

    // Step 1: Get the user input for the number of terms
    printf("Enter the number of terms: ");
    scanf("%d", &n);

    // Step 2: Call the function to display the Fibonacci series up to n terms
    displayFibonacci(n);

    return 0;
}
