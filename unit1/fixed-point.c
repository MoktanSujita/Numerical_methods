#include<stdio.h>
#include<math.h>

/* f(x) = x^2 + x - 2
   g(x) = 2 / (x + 1)
*/

float g(float x){
    return (2 / (x + 1));
}

int main()
{
    int i = 1;
    float x1, x2;

    printf("Enter the initial guess: ");
    scanf("%f", &x1);

    // Header
    printf("\nIter\t   x(i)\t\t   x(i+1)\n");

    do
    {
        x2 = g(x1);

        printf("%d\t%.6f\t%.6f\n", i, x1, x2);

        if (fabs(x2 - x1) < 0.0001)   // convergence check
            break;

        x1 = x2;
        i++;

    } while (i < 10);

    printf("\nRoot:\t%.6f\n", x2);

    return 0;
}
