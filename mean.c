#include<stdio.h>
#include<math.h>
void main()
{
    float lb[20],ub[20],x[20],fx[20],sfx=0,mean;
    int f[20],sf=0,n,i;
    printf("Enter the number of data inputs:");
    scanf("%d",&n);
    printf("\nEnter lower boundary, upper boundary and frequency:");
    for(i=0;i<n;i++)
    {
        scanf("%f %f %d",&lb[i],&ub[i],&f[i]);
        x[i]=(ub[i]+lb[i])/2;
        fx[i]=x[i]*f[i];
    }
    for(i=0;i<n;i++)
    {
        sf+=f[i];
        sfx+=fx[i];
    }
    mean=sfx/sf;
    for(i=0;i<n;i++)
    {
        printf(" %d ",f[i]);
    }
    printf(" %f %d ",sfx,sf);
    printf("mean=%f",mean);
}
