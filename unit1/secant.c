#include <stdio.h>
#include<math.h>

float f(float x){
    return (pow(x,2) - 4*x -10);
}
float secant(float x1, float x2){
    return (x1*f(x2)-x2*f(x1))/(f(x2)-f(x1));
}

int main(){ 
    float x1,x2,x3,eps;
    int i=1;

    printf("Enter initial first guesses:");
    scanf("%f%f",&x1,&x2);
    printf("Enter the accuracy desired:\n");
    scanf("%f",&eps);

    printf("iter\t x1\t x2\t x3\t f(x3)\n");
    do{
        x3=secant(x1,x2);
        printf("%d\t%.4f\t%.4f\t%.4f\t%.4f\n",i,x1,x2,x3,f(x3));
         x1=x2;
         x2=x3;
        i++;
    }while(fabs(f(x3))>eps && i<9);
    printf("\n Root:%.4f",x3);

}