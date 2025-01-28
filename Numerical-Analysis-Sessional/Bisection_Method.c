#include<stdio.h>
#include<math.h>

double f(double x)
{
    return x*x-7;
}


void bisection_method(double a,double b)
{
    int i=0;
    double c=0.0,c_old=0.0,tol=0.05;
    double error=0;

    if(f(a)*f(b)>=0)
    {
        printf("Invalid interval f(a) and f(b) must have opposite signs ");
        return;
    }
     printf("\nIteration\t a\t\t b\t\t c\t\t F(a)\t\t F(b)\t\tF(c)\t\t  error \n");
     printf("------------------------------------------------------------------------------------------------------------------------");

     do
     {
         c_old=c;
         c=(a+b)/2.0;
         double fc=f(c);
         double fa=f(a);
         double fb=f(b);

         if (c != 0)
         {
             error = fabs((c - c_old) / c);
         }
         else
         {
             error = fabs(c - c_old);
         }

         printf("%d\t%lf\t%lf\t%lf\t%lf\t%lf\t%lf\t%lf\n",i,a,b,c,fa,fb,fc,error);

         if(fc==0.0)
         {
             break;
         }
         else if(fa*fc<0)
         {
             b=c;
         }
         else
         {
             a=c;

         }


         i++;
     }
     while(error>=tol);
     printf("\n ROOT is =%.4lf\n",c);
}



int main()
{
    double a,b;
    printf("Enter interval [a, b]: ");
    scanf("%lf %lf",&a,&b);
    bisection_method(a,b);

    return 0;
}
