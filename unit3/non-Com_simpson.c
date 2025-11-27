// 1/3 simpson rule for non-composite 

#include<stdio.h>
#include<math.h>

float f(float x){
    return (1/(1+x*x));   // Example function
}

int main(){
    float a,b,h,result;

    printf("Enter lower and upper limits: ");
    scanf("%f %f",&a,&b);

    h = (b-a)/2;

    result = (h/3)*( f(a) + 4*f(a+h) + f(b) );

    printf("Result = %.4f\n",result);
    return 0;
}
