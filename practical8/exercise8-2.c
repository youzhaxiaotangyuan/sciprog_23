#include <stdio.h>

// Recursive function to calculate the GCD
int recursive_gcd(int a, int b) {
    if (b == 0) {
        return a;
    } else {
        return recursive_gcd(b, a % b);
    }
}

int main() {
    int num1, num2;

    // Input two numbers
    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);

    // Calculate and print the GCD
    printf("GCD: %d\n", recursive_gcd(num1, num2));

    return 0;
}
