#include<stdio.h>
#include<math.h>
#define f(x) (x*sin(x)+pow(x,3))
#define x0 0

void main()
{
        int i;
        float a, b, aux=0.0, n, sum, h, y;
        printf("\nEnter a (lower limit), b (upper limit) & n:"); //a=lower limit, b=upper limit, n= no. of subintervals
        scanf("%f %f %f", &a, &b, &n);
        h=(b-a)/n; 
        sum=f(a)+f(b); //sum of first and the last term
        for(i=0; i<n; i++)
        {
                y=x0+i*h;
                aux+=f(y);
                printf("\n %d %.4f",i,y,f(y));
        }
        sum+=aux*2;
        sum*=h/2;
        printf("\n Answer: %.3f",sum);
}
