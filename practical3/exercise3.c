#include <stdio.h>
#include <math.h>

int main(void) {
    // Step 1: Define variables and constants
    double a = 0.0;           // Lower limit of integration
    double b = M_PI / 3.0;    // Upper limit of integration
    int N = 12;               // Number of intervals (equidistant points)
    double h = (b - a) / N;    // Width of each interval

    // Step 2: Initialize sum with the values at the endpoints
    double integral_sum = tan(a) + tan(b);

    // Step 3: Create a loop to generate equidistant points
    for (int i = 1; i < N; i++) {
        double xi = a + i * h;
        // Step 4: Add 2 * tan(xi) for each point
        integral_sum += 2 * tan(xi);
    }

    // Step 5: Multiply the sum by (b - a) / (2 * N)
    integral_sum *= (b - a) / (2.0 * N);

    // Step 6: Output the result and compare against log(2)
    printf("Approximated integral: %f\n", integral_sum);
    printf("Actual integral (log(2)): %f\n", log(2.0));

    return 0;
}
