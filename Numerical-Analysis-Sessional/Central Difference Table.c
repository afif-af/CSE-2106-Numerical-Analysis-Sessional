#include <stdio.h>
#include <math.h>

void central_difference_table(int size) {
    double x[30], y[30][30];
    printf("Enter values of x and corresponding y:");
    for (int i = 0; i < size; i++) {
        printf("\nx[%d] = ", i);
        scanf("%lf", &x[i]);
        printf("y[%d] = ", i);
        scanf("%lf", &y[i][0]);
    }

    for (int j = 1; j < size; j++) {
        for (int i = j / 2; i < size - j / 2; i++) {
            y[i][j] = (y[i + 1][j - 1] - y[i - 1][j - 1]) / 2.0;
        }
    }

    printf("\nCentral Difference Table\n");
    for (int i = 0; i < size; i++) {
        printf("%0.2lf", x[i]);
        for (int j = 0; j < size - i; j++) {
            printf("\t%0.2lf", y[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int size;
    printf("Enter the size: ");
    scanf("%d", &size);
    central_difference_table(size);
    return 0;
}
