#include<stdio.h>
#include<math.h>
/*
1 -1 2 3
1 2 3 5
3 -4 -5 -13
*/

int n;
float c[10][10], x[10];
void uppertriangle()
{
    int i, j, k;
    float ratio;
    for(i=0; i<n; i++) //for each row, if n=3, i=0, 1, 2...... i is a row index as well as the
    //for n=3, for conversion to upper triangular=>
    //when i=0, it is the step 1 of matrix conversion, when i=1, it is the step 2 of matrix conversion, 
    {
        for(j=i+1; j<n; j++) //for each column of a row as
        {
            if(i<j) //for upper triangular
            {
                ratio=c[j][i]/c[i][i]; //deduces ratio, like m21, m31, m32 ..., the ratio will be column wise
                for(k=0; k<n+1; k++) //for each elements in a row, (coefficients+constants)
                {
                    c[j][k]-=ratio*c[i][k]; //here j is used as a row index (the row(s) below ith row), ie, j=>R2, R3 and i=>R1 
                    //formula=> R2=R2-ratio*R1 & R3=R3-ratio*R1
                    //and k is column(k is the index of each elements in the ith and jth row)
                }
            }
        }
    }
    for(i=0; i<n; i++)
    {
        for(j=0; j<n+1; j++)
        {
            printf("%.2f\t",c[i][j]);
        }
        printf("\n");
    }
}

void backsubstitution()
{
    int i, j;
    x[n-1]=c[n-1][n]/c[n-1][n-1];
    for(i=n-2; i>=0; i--)
    {
        float sum=0;
        for(j=i+1; j<n; j++)
        {
            sum+=c[i][j]*x[j];
        }
        x[i]=(c[i][n]-sum)/c[i][i];
    }
}

void main()
{
    int i, j, k;
    float ratio;
    printf("\nenter the number of equations:");
    scanf("%d", &n);
    printf("\nEnter the augmented matrix:");
    for(i=0; i<n; i++)
    {
        for(j=0; j<=n; j++)
        {
            scanf("%f", &c[i][j]);
        }
    }
    uppertriangle();
    backsubstitution();
    printf("\nFinal values of the variables:");
    for(i=0; i<n; i++)
    {
        printf("\nvalue[%d]=%.2f", i, x[i]);
    }
}
