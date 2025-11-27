#include<stdio.h>
#include<math.h>

float f(float x){
    return x*x;   // example function
}

int main(){
    float x,h,ans;

    printf("Enter x and step size h: ");
    scanf("%f %f",&x,&h);

    ans = (f(x+h)-f(x))/h;

    printf("Forward Difference = %.4f\n",ans);
    return 0;
}
