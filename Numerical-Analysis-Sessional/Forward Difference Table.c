#include<stdio.h>
#include<math.h>
void forward_table(int size)
{
    double x[30],y[30][30];
    printf("Enter value of x:\n");
    for(int i=0;i<size;i++)
    {
        printf("x[%d]=",i);
        scanf("%lf",&x[i]);
        printf("y[%d] = ",i);
        scanf("%lf",&y[i][0]);

    }
    for (int i=1;i<size;i++)
    {
        for (int j=0;j<size-i;j++)
        {
            y[j][i]= y[j+1][i-1]-y[j][i-1];
        }
    }


    printf("\nForward Difference Table\n");
    for(int i=0;i<size;i++)
    {
        printf("%0.2lf",x[i]);
        for(int j=0;j<size-i;j++)
        {
            printf("\t%0.2lf",y[i][j]);

        }
        printf("\n");
    }
}


int main()
{
    int size;
    printf("Enter the size : ");
    scanf("%d",&size);
    forward_table(size);

    return 0;

}
