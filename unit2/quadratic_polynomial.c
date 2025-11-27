#include <stdio.h>

int main() {
    int n, i;
    printf("Enter number of data points: ");
    scanf("%d", &n);

    double x[n], y[n];

    printf("Enter x values:\n");
    for (i = 0; i < n; i++)
        scanf("%lf", &x[i]);

    printf("Enter y values:\n");
    for (i = 0; i < n; i++)
        scanf("%lf", &y[i]);

    double Sx = 0, Sx2 = 0, Sx3 = 0, Sx4 = 0;
    double Sy = 0, Sxy = 0, Sx2y = 0;

    for (i = 0; i < n; i++) {
        Sx   += x[i];
        Sx2  += x[i] * x[i];
        Sx3  += x[i] * x[i] * x[i];
        Sx4  += x[i] * x[i] * x[i] * x[i];
        Sy   += y[i];
        Sxy  += x[i] * y[i];
        Sx2y += x[i] * x[i] * y[i];
    }

    // Solving normal equations using Cramer's rule
    double D = n*(Sx2*Sx4 - Sx3*Sx3) - Sx*(Sx*Sx4 - Sx2*Sx3) + Sx2*(Sx*Sx3 - Sx2*Sx2);
    double D1 = Sy*(Sx2*Sx4 - Sx3*Sx3) - Sx*(Sxy*Sx4 - Sx3*Sx2y) + Sx2*(Sxy*Sx3 - Sx2*Sx2y);
    double D2 = n*(Sxy*Sx4 - Sx3*Sx2y) - Sy*(Sx*Sx4 - Sx2*Sx3) + Sx2*(Sx*Sx2y - Sx2*Sxy);
    double D3 = n*(Sx2*Sx2y - Sxy*Sx3) - Sx*(Sx*Sx2y - Sx2*Sxy) + Sy*(Sx*Sx3 - Sx2*Sx2);

    double a = D1 / D;
    double b = D2 / D;
    double c = D3 / D;

    printf("\nQuadratic Best-Fit Polynomial:\n");
    printf("y = %.4lf + %.4lf x + %.4lf x^2\n", a, b, c);

    return 0;
}
