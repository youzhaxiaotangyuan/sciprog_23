#include <stdio.h>

// Iterative function to calculate the GCD
int iterative_gcd(int a, int b) {
    int temp;

    while (b != 0) {
        temp = b;
        b = a % b;
        a = temp;
    }

    return a;
}

int main() {
    int num1, num2;

    // Input two numbers
    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);

    // Calculate and print the GCD
    printf("GCD: %d\n", iterative_gcd(num1, num2));

    return 0;
}
