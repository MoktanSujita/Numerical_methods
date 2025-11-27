//3 point gauss_integration
#include<stdio.h>
#include<math.h>

float f(float x){
    return (1/(1+x*x));   // example function
}

int main(){
    float a,b;
    float x1,x2,w1=1,w2=1,ans;
    float t1,t2;

    printf("Enter lower and upper limits: ");
    scanf("%f %f",&a,&b);

    x1 = -1/sqrt(3);
    x2 = 1/sqrt(3);

    t1 = ((b+a)/2) + ((b-a)/2)*x1;
    t2 = ((b+a)/2) + ((b-a)/2)*x2;

    ans = ((b-a)/2) * (w1*f(t1) + w2*f(t2));

    printf("Result = %.6f\n",ans);
    return 0;
}
