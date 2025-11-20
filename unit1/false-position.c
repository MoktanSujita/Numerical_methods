#include<stdio.h>
#include<math.h>

float f(float x){
    return (pow(x,3) - 3*x + 1);
}

float false_position(float a, float b){
    return ((a*f(b) - b*f(a)) / (f(b) - f(a)));
}

int main(){
    int i;
    float a, b, xr, f_xr, xr_old;

    // INPUT SECTION
    do {
        printf("Enter the initial two guesses: ");
        scanf("%f %f", &a, &b);

        if (f(a) * f(b) >= 0) {
            printf("Invalid guesses! The signs must be opposite.\n");
        }
    } while(f(a) * f(b) >= 0);

    // Print table header
    printf("\nIter\t   a\t\t   b\t\t  xr\t\t f(xr)\n");

    xr_old = a;   // Initial dummy old value

    for (i = 1; i <= 9; i++)
    {
        xr = false_position(a, b);
        f_xr = f(xr);

        // Print iteration row
        printf("%d\t%.6f\t%.6f\t%.6f\t%.6f\n",
                i, a, b, xr, f_xr);

        // Convergence check
        if (i > 1 && fabs(xr - xr_old) < 0.001)
            break;

        // Update interval
        if (f(a) * f_xr < 0)
            b = xr;
        else
            a = xr;

        xr_old = xr;   // Update old xr for next loop
    }

    printf("\nRoot = %.6f\n", xr);
    return 0;
}
