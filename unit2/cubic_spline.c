#include <stdio.h>

int main() {
    int i, j, n;
    float x[10], y[10], h[10];
    float a[10], b[10], c[10], d[10];
    float A[10], B[10], C[10], F[10];
    float X, S;

    printf("Enter number of data points: ");
    scanf("%d", &n);

    printf("Enter values of x and y:\n");
    for(i = 0; i < n; i++) {
        scanf("%f %f", &x[i], &y[i]);
    }

    // Step 1: Calculate h[i]
    for(i = 0; i < n-1; i++)
        h[i] = x[i+1] - x[i];

    // Step 2: Setup the system of equations
    for(i = 1; i < n-1; i++) {
        A[i] = h[i-1];
        B[i] = 2 * (h[i-1] + h[i]);
        C[i] = h[i];
        F[i] = 3 * ((y[i+1] - y[i]) / h[i] - (y[i] - y[i-1]) / h[i-1]);
    }

    // Natural spline boundary conditions
    B[0] = B[n-1] = 1;
    F[0] = F[n-1] = 0;
    C[0] = A[n-1] = 0;

    // Step 3: Thomas Algorithm (Tridiagonal solver)
    for(i = 1; i < n; i++) {
        float temp = A[i] / B[i-1];
        B[i] = B[i] - temp * C[i-1];
        F[i] = F[i] - temp * F[i-1];
    }

    c[n-1] = F[n-1] / B[n-1];

    for(i = n-2; i >= 0; i--)
        c[i] = (F[i] - C[i] * c[i+1]) / B[i];

    // Step 4: Calculate coefficients a, b, d
    for(i = 0; i < n-1; i++) {
        a[i] = y[i];
        b[i] = (y[i+1] - y[i]) / h[i] - h[i]*(2*c[i] + c[i+1])/3;
        d[i] = (c[i+1] - c[i]) / (3 * h[i]);
    }

    // Step 5: Interpolation
    printf("\nEnter value of X for interpolation: ");
    scanf("%f", &X);

    for(i = 0; i < n-1; i++) {
        if(X >= x[i] && X <= x[i+1]) {
            float dx = X - x[i];
            S = a[i] + b[i]*dx + c[i]*dx*dx + d[i]*dx*dx*dx;
            break;
        }
    }

    printf("\nInterpolated value at X = %.3f is Y = %.3f\n", X, S);

    return 0;
}
