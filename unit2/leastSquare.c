#include<stdio.h>

int main(){
    int i, n;
    float x[10], y[10];
    float sumx=0, sumy=0, sumxy=0, sumx2=0;
    float a, b;

    printf("Enter number of data points: ");
    scanf("%d", &n);

    printf("Enter values of x and y:\n");
    for(i=0;i<n;i++){
        scanf("%f %f", &x[i], &y[i]);
    }

    for(i=0;i<n;i++){
        sumx += x[i];
        sumy += y[i];
        sumxy += x[i]*y[i];
        sumx2 += x[i]*x[i];
    }

    // Calculating constants
    b = (n*sumxy - sumx*sumy)/(n*sumx2 - sumx*sumx);
    a = (sumy - b*sumx)/n;

    printf("\nBest fitting line is:\n");
    printf("y = %.3f + %.3fx\n", a, b);

    return 0;
}
