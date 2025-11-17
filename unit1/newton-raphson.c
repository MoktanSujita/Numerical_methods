#include<stdio.h>
#include<math.h>

float f(float x){      //f(x)
   return(pow(x,2)+2*x-2);
}

float df(float x){        //f'(x)
    return (2*x +2);
}

float newton(float x1,float b, float c ){   //newton raphson (x1-(f(x)/f'(x))
    return (x1-(b/c));

}

int main(){
    int i=0;
    float b, c, x1, x2;
    printf("Enter the initial guess:");
    scanf("%f",&x1);
    do
    {
        //function call
        b = f(x1);
        c = df(x1);
        x2= newton(x1,b,c);

        i++;
        if (fabs(x2 - x1)<0.00001)      //if the difference is less than 0.0001 break the loop
        {
            break;
        }
        
        printf("\nIteration %d x2:%.4f",i,x2);
        x1= x2;
    } while (i < 9);      //loop around for 9 times 

    printf("\nThe root is : %.4f",x1);
     return 0;
}