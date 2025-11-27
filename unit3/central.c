#include<stdio.h>
#include<math.h>

float f(float x){
    return x*x;   // example function
}

int main(){
    float x,h,ans;

    printf("Enter x and step size h: ");
    scanf("%f %f",&x,&h);

    ans = (f(x+h)-f(x-h))/(2*h);

    printf("Central Difference = %.4f\n",ans);
    return 0;
}
