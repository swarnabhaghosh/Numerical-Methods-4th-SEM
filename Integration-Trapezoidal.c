#include<stdio.h>
#include<math.h>
#define f(x) (x*sin(x)+pow(x,3)) //given expression
#define x0 0 //by default it will be 0

/*
h=(b-a)/n
xi=x0+i*h, for (i = 1 to (n-1))
yi=f(xi), for (i = 1 to (n-1))
integration result= h/2[y0+yn+2*(y1+y2+...+y(n-1))] 
*/

void main()
{
        int i;
        float a, b, x=0.0, n, sum, h, y;
        printf("\nEnter a, b & n:"); //a=lower limit, b=upper limit, n= no. of subintervals
        scanf("%f %f %f", &a, &b, &n);
        h=(b-a)/n; 
        sum=f(a)+f(b); //sum of first and the last term
        for(i=1; i<n; i++) //for the remaining terms
        {
                x=x0+i*h;
                y+=f(x);
                printf("\n x%d=%.4f,\ty%d=%.4f", i, x, i, f(x));
        }
        sum+=y*2;
        sum*=h/2;
        printf("\n Answer: %.3f",sum);
}
