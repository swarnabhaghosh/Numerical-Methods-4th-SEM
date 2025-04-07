#include<stdio.h>
float f(float x, float y)
{
        return (3*x+y*y);
}
void main()
{
        float x0, y0, h, xn;
        printf("\nEnter the initial values of x, y, h, xn:");
        scanf("%f %f %f %f",&x0, &y0, &h, &xn );
        do
        {
                y0+=h*f(x0, y0);
                x0+=h;
        } while (x0<xn);
        printf("\n for x=%.1f y=%.3f\n\n",xn,y0);
}
