#include<stdio.h>
#include<math.h>
#define f(x) (x*sin(x)+pow(x,3))
#define x0 0

void main()
{
        int i;
        float a, b, aux1=0.0, aux2=0.0, n, sum, h, y;
        printf("\nEnter a , b (upper limit) & n:"); //a=lower limit, b=upper limit, n= no. of subintervals
        scanf("%f %f %f",&a,&b,&n);
        h=(b-a)/n;
        sum=f(0)+f(1);
        for(i=0; i<n; i++)
        {
                y=x0+i*h;
                if(i%2==0)
                {
                        aux2+=f(y);
                }
                else
                {
                        aux1+=f(y);
                }
                printf("\n %d %.4f", i, y, f(y));
        }
        sum+=aux1*4+aux2*2;
        sum*=h/3;
        printf("\n Answer: %.3f",sum);
}
