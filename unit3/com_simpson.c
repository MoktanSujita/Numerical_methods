// 1/3 simpson rule for composite 
#include<stdio.h>
#include<math.h>

float f(float x){
    return 1/(1+pow(x,2));
}

int main(){
    float a,b,h,sum=0;
    int n,i;

    printf("Enter a and b: ");
    scanf("%f %f",&a,&b);

    printf("Enter number of intervals: ");
    scanf("%d",&n);

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
