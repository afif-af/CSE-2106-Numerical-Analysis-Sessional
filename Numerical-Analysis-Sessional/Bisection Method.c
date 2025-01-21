#include <stdio.h>
#include <math.h>

double f(double x);

int main() {
    double a, b;
    double tolerance = 0.00001;
    double mid;
    int maxIterations = 1000;
    int iterations = 0;

    printf("Enter the lower bound of the interval: ");
    scanf("%lf", &a);
    printf("Enter the upper bound of the interval: ");
    scanf("%lf", &b);

    if (f(a) * f(b) >= 0) {
        printf("The bisection method cannot be applied because f(a) and f(b) do not have opposite signs.\n");
        return -1;
    }

    // Print table header
    printf("--------------------------------------------------\n");
    printf("| Iteration |    a    |    b    |   mid   |  f(mid)  |\n");
    printf("--------------------------------------------------\n");

    // Bisection method loop
    while ((b - a) / 2.0 > tolerance && iterations < maxIterations) {
        mid = (a + b) / 2.0;
        printf("|    %2d     | %7.4f | %7.4f | %7.4f | %8.4f |\n", iterations + 1, a, b, mid, f(mid));

        if (f(mid) == 0.0) {

            break;
        } else if (f(a) * f(mid) < 0) {
            b = mid;
        } else {
            a = mid;
        }
        iterations++;
    }

    printf("--------------------------------------------------\n");
    printf("The root is approximately: %f\n", mid);
    printf("Number of iterations: %d\n", iterations);

    return 0;
}

double f(double x) {
    return x * x - 7;
}
