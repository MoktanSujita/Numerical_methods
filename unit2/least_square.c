//linear
#include <stdio.h>

int main() {
    int n, i;
    printf("Enter number of points: ");
    scanf("%d", &n);

    float x[n], y[n];
    for(i = 0; i < n; i++) {
        printf("Enter x[%d] and y[%d]: ", i, i);
        scanf("%f%f", &x[i], &y[i]);
    }

    float sumX=0, sumY=0, sumXY=0, sumX2=0;
    for(i = 0; i < n; i++) {
        sumX += x[i];
        sumY += y[i];
        sumXY += x[i]*y[i];
        sumX2 += x[i]*x[i];
    }

    // Solve for a and b
    float b = (n*sumXY - sumX*sumY) / (n*sumX2 - sumX*sumX);
    float a = (sumY - b*sumX) / n;

    printf("The best fit line is: y = %.4f + %.4fx\n", a, b);

    // Predict y for a given x
    float xi;
    printf("Enter x to predict y: ");
    scanf("%f", &xi);
    float yi = a + b*xi;
    printf("Predicted y = %.4f\n", yi);

    return 0;
}
