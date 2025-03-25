#include<stdio.h>
#include<math.h>
void main()
{
    int n,i;
    float x[20],y[20],sumx=0,sumy=0,sumxy=0,sumx2=0,a,b;
    printf("\nEnter the no. of observation:");
    scanf("%d",&n);
    printf("\nEnter the values of x:");
    for(i=0;i<n;i++)
    {
        scanf("%f",&x[i]);
    }
    printf("\nEnter the values of y:");
    for(i=0;i<n;i++)
    {
        scanf("%f",&y[i]);
    }
    for(i=0;i<n;i++)
    {
        sumx=sumx+x[i];
        sumy=sumy+y[i];
        sumxy=sumxy+x[i]*y[i];
        sumx2=sumx2+pow(x[i],2);
    }
    //printf("%f %f %f %f",sumx,sumy,sumxy,sumx2);
    a=(sumx2*sumy-sumx*sumxy)/(n*sumx2-pow(sumx,2));
    b=(n*sumxy-sumx*sumy)/(n*sumx2-pow(sumx,2));
    printf("y=%.1f+%.1fx",a,b);
}
