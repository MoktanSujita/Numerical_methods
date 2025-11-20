#include<stdio.h>
#include<math.h>

float f(float x){      // f(x)
   return (pow(x,2) + 2*x - 2);
}

float df(float x){     // f'(x)
    return (2*x + 2);
}

float newton(float x1, float b, float c){
    return (x1 - (b/c));
}

int main(){
    int i = 0;
    float b, c, x1, x2;

    printf("Enter the initial guess: ");
    scanf("%f", &x1);

    // Table header
    printf("\nIter\t   x1\t\t   x2\t\t  f(x1)\n");

    do {
        b = f(x1);
        c = df(x1);
        x2 = newton(x1, b, c);

        i++;

        printf("%d\t%.6f\t%.6f\t%.6f\n", i, x1, x2, b);

        if (fabs(x2 - x1) < 0.00001)
            break;

        x1 = x2;

    } while (i < 9);

    printf("\nRoot:\t%.6f\n", x2);

    return 0;
}
