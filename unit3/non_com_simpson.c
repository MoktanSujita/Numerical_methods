//3/8 simpson's non-composite 
#include<stdio.h>
#include<math.h>

float f(float x){
    return x*x;
}

int main(){
    float a,b,h,result;

    printf("Enter a and b: ");
    scanf("%f %f",&a,&b);

    h = (b-a)/3;

    result = (3*h/8)*( f(a) + 3*f(a+h) + 3*f(a+2*h) + f(b) );

    printf("Result = %.4f\n",result);
    return 0;
}
