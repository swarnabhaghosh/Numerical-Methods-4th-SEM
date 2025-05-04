#include<stdio.h>
#include<math.h>
void main()
{
    float lb[20],ub[20],x[20],x2[20],fx[20],fx2[20],sfx=0,sfx2=0,mean,variance,sd;
    int f[20],sf=0,n,i;
    printf("Enter the number of data inputs:");
    scanf("%d",&n);
    printf("\nEnter lower boundary, upper boundary and frequency:");
    for(i=0;i<n;i++)
    {
        scanf("%f %f %d",&lb[i],&ub[i],&f[i]);
        x[i]=(ub[i]+lb[i])/2;
        x2[i]=pow(x[i],2);
        fx[i]=x[i]*f[i];
        fx2[i]=x2[i]*f[i];
        sf+=f[i];
        sfx+=fx[i];
        sfx2+=fx2[i];
    }
    mean=sfx/sf;
    variance=(sfx2/sf)-pow(mean,2); //variance=[s(fx^2)/s(f)]-[s(fx)/s(f)]^2
    sd=sqrt(variance);
    /*printf("lower\tupper\tfrequency\n");
    for(i=0;i<n;i++)
    {
        printf("%.3f\t%.3f\t%d\n",lb[i],ub[i],f[i]);
    }*/
    //printf(" %f %d ",sfx2,sf);
    printf("\nmean=%f",mean);
    printf("\nvariance=%f",variance);
    printf("\nstandard deviation=%f",sd);
}
