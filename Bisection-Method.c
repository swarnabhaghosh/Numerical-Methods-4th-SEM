#include<stdio.h>
#include<math.h>
 float f(float x)
 {
 	return (pow(x,3)-9*x+1);
 }
 void main()
 {
 	float a,b,c;
	int i=1, mi;
 	printf("Enter:");
 	scanf("%f %f",&a,&b);

	printf("\nEnter the maximum iteration:");
	scanf("%d",&mi);

 	do
 	{
		c=(a+b)/2;
		if(f(a)*f(c)<0)
			b=c;
		else
			a=c;
		if(fabs(b-a)<0.001 || fabs(c)<0.001)
			break;
		printf("\niteration=%d, root=%f", i, c);
		i++;
	}while(i<=mi);
 printf("\nresult=%f",c);
}
