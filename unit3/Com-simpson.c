// 3/8 composite simpson rule
#include<stdio.h>
#include<math.h>

float f(float x){
    return x*x;
}

int main(){
    float a,b,h,sum=0;
    int n,i;

    printf("Enter a and b: ");
    scanf("%f %f",&a,&b);

    printf("Enter number of intervals (multiple of 3): ");
    scanf("%d",&n);

    if(n%3!=0){
        printf("n must be multiple of 3.\n");
        return 0;
    }

    h = (b-a)/n;
    sum = f(a) + f(b);

    for(i=1;i<n;i++){
        if(i%3==0)
            sum += 2*f(a+i*h);
        else
            sum += 3*f(a+i*h);
    }

    printf("Result = %.4f\n",(3*h/8)*sum);
    return 0;
}
