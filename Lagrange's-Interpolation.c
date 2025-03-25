#include<stdio.h>
#include<math.h>
void main()
{
        int n, i, j;
        double x[10], y[10], a, p;
        printf("\nEnter the number of arguments:");
        scanf("%d",&n);
        printf("\nEnter x and y:");
        for(i=0; i<n; i++)
        {
                scanf("%lf",&x[i]);
                scanf("%lf",&y[i]);
        }
        printf("\nEnter the point of interpolation:");
        scanf("%lf",&a);
        double sum=0.0;
        for(i=0; i<n; i++)
        {
                p=1.0;
                for(j=0; j<n; j++)
                {
                        if(i!=j)
                        {
                                p*=(a-x[j])/(x[i]-x[j]);
                        }
                }
                sum+=p*y[i];
        }
        printf("\na=%lf",a);
        printf("\nSum=%lf",sum);
}