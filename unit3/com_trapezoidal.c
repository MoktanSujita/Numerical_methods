#include<stdio.h>
#include<math.h>

float f(float x){
    return x*x;   // example function
}

int main(){
    float a,b,h,sum=0;
    int n,i;
    
    printf("Enter lower and upper limits: ");
    scanf("%f %f",&a,&b);
    
    printf("Enter number of subintervals: ");
    scanf("%d",&n);
    
    h = (b-a)/n;
    sum = f(a) + f(b);
    
    for(i=1;i<n;i++){
        sum += 2*f(a + i*h);
    }
    
    printf("Result = %.4f\n",(h/2)*sum);
    return 0;
}
