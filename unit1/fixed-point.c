#include<stdio.h>
#include<math.h>

float f(float x){
   return (pow(x,2)+x-2);   //f(x)
}

float g(float x){      //g(x)
    return (2/(x+1));
}

int main()
{
    int i= 1;
    float x1,a,b;
    printf("Enter the initial guess:");     //initial guess
    scanf("%f",&x1);

    do
    {
        a = f(x1);
        b = g(x1);
        if(fabs(a-b)<0.0001){    //difference checking
            break;
        }
        x1 = b;
        printf("\nIteration %d x :%.4f",i, x1);   //value of x (i+1)
        i++;
    } while (i<10);
    printf("\nRoot: %.4f",x1);             //final approximate root
    return 0; 
}