#include<stdio.h>
#include<math.h>
#define Error 0.001

float f(float x) //implenting the equation
{
	return pow(x,3)-(3*x)-5 ;
}
float d(float x) //differentiate the equation
{
	return (3*x*x)-3;
}
int main()
{
	int mi,i;
	float x1,x2,x,x0;
	printf("Enter maximum number of iteration:");
	scanf("%f",&mi);

	do
	{
		printf("Enter the value of x1 and x2:"); //starting boundary
		scanf("%f %f",&x1,&x2);
		if(f(x1)*f(x2)>0)
		{
			printf("Boundary values are invalid");
			continue;
		}
		else
		{
			printf("Roots are lie between %f and %f",x1,x2);
			break;
		}
	}while(1);

	//finding x0
	if(fabs(f(x1))<fabs(f(x2)))
	{
		x0=x1;
	}
	else
	{
		x1=x2;
	}
	//finding root
	for(i=1;i<=mi;i++)
	{
		x=x0-(f(x0)/d(x0));
		if(fabs(x-x0)<Error)
		{
			printf("\nIteration:%d Final root:%f",i,x);
			return 0;
		}
		printf("\nIteration:%d Roots:%f",i,x);
		x0=x;
	}
	printf("\nRoot=%f Total Iteration=%d",x,--i);
	return 0;
}
