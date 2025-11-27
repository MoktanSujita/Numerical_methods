#include<stdio.h>
#include<math.h>

float f(float x){
    return x*x;   // example function
}

int main(){
    float a,b,h,result;
    
    printf("Enter lower and upper limits: ");
    scanf("%f %f",&a,&b);
    
    h = b - a;
    result = (h/2) * (f(a) + f(b));
    
    printf("Result = %.4f\n",result);
    return 0;
}
