/*#include<stdio.h>
#include<math.h>
void main()
{
    int n,i;
    float sumx=0.0, sumxY=0.0, sumY=0.0, sumx2=0.0, a,b,A,p,q;
    printf("Enter the value of n:");
    scanf("%d",&n);
    printf("Enter the value of x and y:");
    for(i=0;i<n;i++)
    {
        scanf("%f %f",&p,&q);
        sumx+=p; sumY+=log(q);sumxY+=p*log(q);sumx2+=p*p;
    }
    A=(sumx2*sumY-sumx*sumxY)/(n*sumx2-sumx*sumx);
    b=(n*sumxY-sumx*sumY)/(n*sumx2-sumx*sumx);
    a=exp(A);
    printf("InThe curve is:y=%0.3f*e^(%0.3f*x)",a,b);
}*/

#include <stdio.h>
#include <math.h>

void main() {
    int n, i;
    float sumx = 0.0, sumY = 0.0, sumxY = 0.0, sumx2 = 0.0, a, b, A, p, q;

    // Input number of data points
    printf("Enter the value of n: ");
    scanf("%d", &n);

    // Input x and y values
    printf("Enter the value of x and y:\n");
    for (i = 0; i < n; i++) {
        scanf("%f %f", &p, &q);
        sumx += p;
        sumY += log(q);
        sumxY += p * log(q);
        sumx2 += p * p;
    }

    // Calculate A and b using least squares method
    A = (sumx2 * sumY - sumx * sumxY) / (n * sumx2 - sumx * sumx);
    b = (n * sumxY - sumx * sumY) / (n * sumx2 - sumx * sumx);
    a = exp(A);

    // Print the resulting exponential curve equation
    printf("\nThe curve is: y = %.3f * e^(%.3f * x)\n", a, b);
}

