#include<stdio.h>
#include<math.h>
void main()
{
    double x[30], y[30][30], a;
    int i, j, n;
    printf("Enter the number of arguments:");
    scanf("%d",&n);
    printf("\nEnter the elements in x and y:");
    for(i=0; i<n; i++)
    {
        scanf("%lf %lf",&x[i],&y[i][0]);
    }
    //constructing forward difference table
    //column wise table formation, 
    //as first column is filled with the input values,
    //loop wll start from the 2nd column
    for(j=1; j<n; j++) //for column
    {
        for(i=0; i<n-j; i++) //for rows
        {
            y[i][j]=y[i+1][j-1]-y[i][j-1];
            //to create jth column have to look into
            //the previous column, (j-1)th column
            //and subtract the value of the ith row from its
            //next row, (i+1)th row 
        }
    }
    //print the forward difference table
    for(i=0; i<n; i++)
    {
        printf("%lf\t",x[i]);
        for(j=0; j<n-i; j++)
        {
            printf("%lf\t",y[i][j]);
        }
        printf("\n");
    }
    printf("\nEnter the point of interpolation:");
    scanf("%lf",&a);
    double h=x[1]-x[0]; //step length
    double u=(a-x[0])/h;
    double sum=y[0][0];
    double p=1.0;
    for(j=1; j<n; j++)
    {
        p=p*(u-j+1)/j;
        sum+=p*y[0][j];
    }
    printf("\na=%lf",a);
    printf("\nsum=%lf",sum);
}