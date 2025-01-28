#include <stdio.h>
#include <math.h>

double function(double x)
{
    return pow(x, 3) - 2 * x - 5;
}
double functionDerivative(double x)
{
    return 3 * pow(x, 2) - 2;
}
void newton_Raphson_methods(double x0, double tol)
{
    double x = x0;
    double fx, dfx, er;
    int i = 0;
    printf("Iteration\t x\t\t f(x)\t\t f'(x)\t\t Error\n");
    printf("--------------------------------------------------------------------\n");

    do
    {
        fx = function(x);
        dfx = functionDerivative(x);
        if (dfx == 0.0)
        {
            printf("Derivative is zero. Cannot continue.\n");
            return;
        }

        double x_new = x - fx / dfx;
        er = fabs(x_new - x);
        printf("%d\t\t%lf\t%lf\t%lf\t%lf\n", i, x, fx, dfx, er);
        x = x_new;
        i++;


    } while (er > tol);

    printf("\nRoot is = %lf\n", x);
}

int main()
{
    double x0, tol;
    printf("Enter initial guess (x0): ");
    scanf("%lf", &x0);
    printf("Enter tolerance: ");
    scanf("%lf", &tol);
    newton_Raphson_methods(x0,tol);

    return 0;
}
