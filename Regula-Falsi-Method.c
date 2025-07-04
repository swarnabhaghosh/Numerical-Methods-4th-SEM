//C Program to Implement Regula Falsi Method
#include<stdio.h>
#include<math.h>
#define error 0.0001 //3 decimal places
float findValueAt(float x)
{
   return 3*x - cos(x) -1;
}

float findX(float x1,float x2)
{
    //c=[af(b)-bf(a)]/[f(b)-f(a)]
      return (x1*findValueAt(x2) - x2 * findValueAt(x1)) / (findValueAt(x2) - findValueAt(x1));
}
int main()
{
    int maxIteration,i=1;
    float x1,x2,x3,x;
    printf("Enter Maximum no of Iterations\n");
    scanf("%d",&maxIteration);

   //Finding x1 and x2
   do
   {
        printf("Enter x1 and x2:");
        scanf("%f%f",&x1,&x2);
        if(findValueAt(x1)*findValueAt(x2)>0)
        {
           printf("Roots are Invalid\n");
           continue;
        }
        else
        {
            printf("Roots Lie between %f and %f\n",x1,x2);
            break;
        }
    } while(1);

    //find the Intermediate point
    x = findX(x1,x2);

    do
    {
      if(findValueAt(x)*findValueAt(x1)<0)
         x2=x;
      else
         x1=x;
      printf("Iterations=%d  Root=%f\n",i,x);
      x3 = findX(x1,x2);
      if(fabs(x3-x)<error)
          break;
      x=x3;  //Important
      i++;
    }while(i<=maxIteration);
    printf("Root=%f  Total Iterations=%d",x,--i);

    return 0;
}
