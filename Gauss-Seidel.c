#include<stdio.h>
#include<math.h>
#include<stdbool.h>
#define epsilon 0.001

/*
9 -2 1 50
1 5 -3 18
-2 2 7 19
*/
int n; 
float A[10][10];

void print(int iterations, float values[])
{
    int i;
    printf("\nIteration:%d", iterations);
    for(i=0; i<n; i++)
    {
        printf("\nvalues[%d]=%.2f", i+1, values[i]);
    }
}

bool isapplicable() //checking if it is applicable or not
{
    for (int i = 0; i < n; i++) //for rows
    {
        float sum = 0;
        for (int j = 0; j < n; j++) //for columns
        {
            if (i != j)
                sum += fabs(A[i][j]); //find the sum except the elements of primary diagonal
        }
        if (fabs(A[i][i]) <= sum) //if the condition is not true
            return false;
    }
    return true;
}

void findvalues(int maxiterations, float old_values[]) 
//this is to find the final values, old_values=> to store initial values, it will be updated after each iteration
{
    int iterations, i, j, k;
    float new_values[10]; 
    //this is to store the new values in each iteration, 
    //then the values of it will be used to update the initial values for next iteration,, to update the old_values[]
    for(i=0; i<n; i++)
        new_values[i]=0; //initialize with 0, upto the numbers of variables
    for(iterations=1; iterations<=maxiterations; iterations++) //this will count the iterations, go upto maxiteration (user given)
    {
        for(i=0; i<n; i++) //for rows
        {
            float sum=0;
            for(j=0; j<n; j++) //for colums
            {
                if(i!=j)
                {
                    sum+=A[i][j]*new_values[j]; 
                    //in each iteration for each row (row=>variables)
                    //coefficient of other variables (except primary diag.) will be multiplied with their initial values, and then added
                }
            }
            new_values[i]=(A[i][n]-sum)/A[i][i]; //the value of the variable will be found  
            //=(R.H.S. of ith equation - sum for other variables of ith eq.)/(coefficient of the variable of the primary diag.) 
        }
        bool flag = true;
        for(i=0; i<n; i++)
        {
            if(fabs(new_values[i]-old_values[i])>epsilon) 
            //check the difference b/w the new values got from this iteration and the values from the initial stage of the equation
            {
                flag=false;
                break;
            }
        }

        if(flag) // if all the difference is less than the epsilon value then it is the final value, that will be printed immediately 
        {
            print(iterations, new_values); // print final values of unknowns  and return
            return;
        }

        print(iterations,new_values); //To print intermediate roots, from the current iteration

        //copy new values of unknowns to old value array
        for(k=0; k<n; k++)
        {
            old_values[k]=new_values[k];
        }
    } //end of iterations loop
    print(iterations, new_values); //it reaches upto the maxiteration, if difference still is not less than epsilon
}


int main()
{
    int i, j, k, maxiterations;
    float values[10];
    printf("\nEnter the number of equations:");
    scanf("%d",&n);
    printf("\nEnter the number of maximum iterations:");
    scanf("%d",&maxiterations);
    printf("\nEnter the augmented matrix:");
    for(i=0; i<n; i++)
    {
        for(j=0; j<=n; j++)
        {
            scanf("%f",&A[i][j]);
        }
    }
    if(!isapplicable())
    {
        printf("\nThe method is not applicable");
        return 0;
    }
    printf("\nThe method is applicable");
    for(i=0; i<n; i++)
    {
        values[i]=0;
    }
    findvalues(maxiterations, values);
    return 0;
}