#include <stdio.h>
#include <math.h>

// Global array to store tan(x) values
double tanValues[13];  // 13 elements to include 0, 60, and steps of 5 degrees

// Function to convert degrees to radians
double degreesToRadians(double degrees) {
    return degrees * (M_PI / 180.0);
}

// Function to calculate the area under the curve of tan(x) using the Trapezoidal Rule
double calculateAreaUnderCurve(int numPoints) {
    double a = 0.0;           // Lower limit of integration
    double b = degreesToRadians(60.0);  // Upper limit of integration
    double h = (b - a) / numPoints;    // Width of each interval
    double integralSum = tan(a) + tan(b);

    for (int i = 1; i < numPoints; i++) {
        double xi = a + i * h;
        integralSum += 2 * tan(xi);
    }

    integralSum *= (b - a) / (2.0 * numPoints);
    return integralSum;
}

int main(void) {
    // Step 1: Loop to calculate tan(x) values and store in the global array
    for (int i = 0; i <= 12; i++) {
        double degrees = i * 5.0;
        double radians = degreesToRadians(degrees);
        tanValues[i] = tan(radians);
    }

    // Step 2: Print the array
    printf("tan(x) values:\n");
    for (int i = 0; i <= 12; i++) {
        printf("tan(%d degrees) = %f\n", i * 5, tanValues[i]);
    }

    // Step 3: Calculate and print the area under the curve of tan(x)
    int numPoints = 13;  // Number of points, including endpoints
    double area = calculateAreaUnderCurve(numPoints);
    printf("Area under the curve of tan(x) from 0 to 60 degrees: %f\n", area);

    return 0;
}
