#include<stdio.h>
#include<math.h>
void main()
{
    double lb[10], ub[10],  x[10], fx[10], fx2[10];
    double sf=0, sfx=0, sfx2=0, mean, median, mode, sd, variance;
    int i, n, f[10], cf[10], sum=0;
    printf("\nEnter the number of data entry:");
    scanf("%d",&n);
    printf("\nEnter lb, ub, freq:\n");
    for(i=0; i<n; i++)
    {
        scanf("%lf %lf %d", &lb[i], &ub[i], &f[i]);
        x[i]=(ub[i]+lb[i])/2;
        fx[i]=f[i]*x[i];
        fx2[i]=f[i]*pow(x[i], 2);
        sum+=f[i];
        cf[i]=sum;
    }
    for(i=0; i<n; i++)
    {
        sf+=f[i];
        sfx+=fx[i];
        sfx2+=fx2[i];
    }
    mean=sfx/sf;
    variance=sfx2/sf-pow(mean, 2);
    sd=sqrt(variance);
    //Mode = 3Median - 2Mean
    //find mode
    int higest=f[0];
    int modeindex, medianindex, L; //L->lower bound of the median class 
    double h=ub[0]-lb[0];
    for(i=0; i<n; i++)
    {
        if(f[i]>higest)
        {
            higest=f[i];
            modeindex=i;
        }
    }
    int halfn=sf/2, mi;
    for(i=0; i<n; i++)
    {
        if(cf[i]>=halfn)
        {
            mi=i; // to store the index before median class
            break;
        }
    }
    medianindex=mi;
    L=lb[medianindex];
    mode=L+(f[medianindex]-f[medianindex-1])/(2*f[medianindex]-f[medianindex-1]-f[medianindex+1])*h;
    median = (mode + 2*mean)/3;
    printf("\nmean=%lf",mean);
    printf("\nmedian=%lf",median);
    printf("\nmode=%lf",mode);
    printf("\nvariance=%lf",variance);
    printf("\nstandard deviation=%lf",sd);
}