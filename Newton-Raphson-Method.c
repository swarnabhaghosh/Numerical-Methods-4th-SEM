#include<stdio.h>
#include<math.h>
float f(float x)
{
    return (pow(x,3)-3*x-5);
}
float d(float x)
{
    return (3*pow(x, 2)-3);
}
void main()
{
    float a, b, x0, x;
    int i=1, mi;
    printf("\nEnter a and b:");
    scanf("%f %f", &a, &b);

    printf("\nenter the maximum iteration:");
    scanf("%d",&mi);

    if(fabs(f(a))<fabs(f(b)))
        x0=a;
    else
        x0=b;
    
    do
    {
        x=x0-f(x0)/d(x0);
        if(fabs(x-x0)<0.001)
            break;
        printf("\niteration=%d, root=%f", i, x);
        x0=x;
        i++;
    }while(i<=mi);
    printf("\nresult=%.4f, total iteration",x0);
}