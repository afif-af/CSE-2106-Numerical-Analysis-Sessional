#include <stdio.h>

void luDecomposition(double A[10][10], double L[10][10], double U[10][10], int n) {
    int i,j,k;
    for (i=0;i<n;i++) {
        for (j=0;j<n;j++) {
            L[i][j]=0;
            U[i][j]=0;
        }
    }
    for (i=0; i<n;i++) {
        for (j = i;j<n;j++) {
           double sum = 0;
            for (k = 0; k < i; k++) {
                sum += L[i][k] * U[k][j];
            }
            U[i][j] = A[i][j] - sum;
        }
        for (j=i;j<n;j++) {
            if (i==j) {
                L[i][i]=1;
            } else {
                double sum = 0;
                for (k=0;k<i;k++){
                    sum+= L[j][k]*U[k][i];
                }
                L[j][i]=(A[j][i]-sum)/U[i][i];
            }
        }
    }
}

int main() {
    int n, i, j;
    double A[10][10], L[10][10], U[10][10];

    printf("Enter the size of the matrix: ");
    scanf("%d",&n);

    printf("Enter the elements of the matrix A:\n");
    for (i=0;i<n;i++) {
        for (j=0;j<n;j++) {
            scanf("%lf",&A[i][j]);
        }
    }

    luDecomposition(A, L, U, n);

    printf("\nMatrix L (Lower Triangular Matrix):\n");
    for (i=0;i< n; i++) {
        for (j = 0;j< n; j++) {
            printf("%8.2lf ", L[i][j]);
        }
        printf("\n");
    }

    printf("\nMatrix U (Upper Triangular Matrix):\n");
    for (i=0;i<n;i++) {
        for (j=0;j<n;j++) {
            printf("%8.2f ",U[i][j]);
        }
        printf("\n");
    }

    return 0;
}

