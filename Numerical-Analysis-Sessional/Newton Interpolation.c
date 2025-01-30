#include<stdio.h>
#include<math.h>

void newton_interpolation(int size,double v)
{
    double x[30],y[30][30];
    printf("Enter value of x & y:\n");
    for(int i=0;i<size;i++)
    {
        printf("x[%d]=",i);
        scanf("%lf",&x[i]);
        printf("y[%d]=",i);
        scanf("%lf",&y[i][0]);
    }

    for(int i=1;i<size;i++)
    {
        for(int j=0;j<size-i;j++)
        {
            y[j][i]=y[j+1][i-1]-y[j][i-1];
        }
    }
    printf("\nForward Difference Table \n\n");
    for(int i=0;i<size;i++)
    {
        printf("%0.2lf",x[i]);
        for(int j=0;j<size-i;j++)
        {
            printf("\t%0.2lf",y[i][j]);

        }
        printf("\n");
    }

    double h=x[1]-x[0];
    double p=(v-x[0])/h;

    double result=y[0][0];
    double term=1.0;

    for(int i=1;i<size;i++)
    {
        term *=(-(i-1))/i;
        result+=term*y[0][i];
    }
    printf("\n");
    printf("\nvalue is: %f ",result);



}


int main()
{
    int size;
    double v;
    printf("Enter size of table : ");
    scanf("%d",&size);
    printf("Enter position you find: ");
    scanf("%lf",&v);
    newton_interpolation(size,v);

    return 0;
}
