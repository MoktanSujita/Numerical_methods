// 1/3 simpson rule for composite 
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

    printf("Enter even number of intervals: ");
    scanf("%d",&n);

    if(n%2!=0){
        printf("n must be even.\n");
        return 0;
    }

    h = (b-a)/n;

    sum = f(a) + f(b);

    for(i=1;i<n;i++){
        if(i%2==0)
            sum += 2*f(a+i*h);
        else
            sum += 4*f(a+i*h);
    }

    printf("Result = %.4f\n",(h/3)*sum);
    return 0;
}
