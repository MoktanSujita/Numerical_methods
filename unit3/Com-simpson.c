// 3/8 simpson's composite
#include<stdio.h>
#include<math.h>

float f(float x){
    return 1/(1 + x*x);  // correct function
}

int main(){
    float a,b,h,sum=0;
    int n,i;

    printf("Enter a and b: ");
    scanf("%f %f",&a,&b);

    printf("Enter number of intervals (multiple of 3): ");
    scanf("%d",&n);

    if(n%3!=0){
        printf("n must be a multiple of 3.\n");
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

    printf("Result = %.6f\n",(3*h/8)*sum);
    return 0;
}
