#include<stdio.h>
#include<math.h>
 float f(float x)
 {
 	return (pow(x,3)-3*x-5);
 }
 void main()
 {
 	float a,b,c;
 	printf("Enter:");
 	scanf("%f %f",&a,&b);

 while((b-a)>=0.001)
 	{
 	c=(a+b)/2;
 	if(f(a)*f(c)<0)
 		b=c;
 	else
 		a=c;
	}
 printf("result=%.3f",c);
}
