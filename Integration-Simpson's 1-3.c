#include<stdio.h>
#include<math.h>
#define f(x) (x*sin(x)+pow(x,3))

/*
h=(b-a)/n
xi=x0+i*h, for (i = 1 to (n-1))
yi=f(xi), for (i = 1 to (n-1))
integration result= h/2[y0+yn+2*(sum of even terms)+4*(sum of remaining odd terms)] 
*/

void main()
{
        int i;
        float a, b, aux1=0.0, aux2=0.0, n, sum, h, x, x0, xn; //aux1 = sum of even terms, aux2 = sum of remaining odd terms
        printf("\nEnter a , b  & n:"); //a=lower limit, b=upper limit, n= no. of subintervals
        scanf("%f %f %f",&a,&b,&n);
        h=(b-a)/n;
        x0=a; xn=b;
        sum=f(x0)+f(xn); //sum of first and last term
        for(i=1; i<n; i++) //sum of remaining terms
        {
                x=x0+i*h;
                if(i%2==0) //if even
                {
                        aux1+=f(x);
                        printf("\n x%d=%.4f,\ty%d=%.4f", i, x, i, f(x));
                }
                else //if odd
                {
                        aux2+=f(x);
                        printf("\n x%d=%.4f,\ty%d=%.4f", i, x, i, f(x));
                }
        }
        sum+=aux1*2+aux2*4;
        sum*=h/3;
        printf("\n Answer: %.3f",sum);
}
