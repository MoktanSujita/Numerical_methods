#include<stdio.h>
#include<math.h>

float f(float x){
    return (1/(1+x*x));   // example function
}

float trapezoidal(float a, float b, int n){
    float h, sum = 0.0;
    int i;
    
    h = (b - a) / n;
    sum = f(a) + f(b);
    
    for(i = 1; i < n; i++){
        sum += 2 * f(a + i*h);
    }
    
    return (h/2) * sum;
}

int main(){
    float a, b, R[10][10];
    int i, j;

    printf("Enter lower and upper limits: ");
    scanf("%f %f", &a, &b);

    // First column (Trapezoidal approximations)
    for(i = 0; i < 4; i++){
        int n = pow(2, i);
        R[i][0] = trapezoidal(a, b, n);
    }

    // Romberg calculation
    for(i = 1; i < 4; i++){
        for(j = 1; j <= i; j++){
            R[i][j] = (pow(4,j)*R[i][j-1]-R[i-1][j-1])/(pow(4,j)-1);
        }
    }

    printf("\nRomberg Integration Table:\n");
    for(i = 0; i < 4; i++){
        for(j = 0; j <= i; j++){
            printf("%f\t", R[i][j]);
        }
        printf("\n");
    }

    printf("\nFinal Answer = %f\n", R[3][3]);
    return 0;
}
