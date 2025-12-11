#include <stdio.h>
#include <math.h>

int main(){
    int n, i, j, k;
    float c, sum;
    printf("Enter the order of matrix:");
    scanf("%d", &n);

    float matrix[n][n+1], x[n];

    printf("Enter the agumented matrix::\n");
    for (i = 0; i < n; i++){
        for (j = 0; j < (n+1); j++)
        {
            printf("matrix[%d][%d]::", i, j);
            scanf("%f", &matrix[i][j]);
        }
        
    }

    //Elimination Loop (0-based)
    for (i = 0; i < n-1; i++) { // Pivot row (0 to n-1)
      for (j = 0; j < n-1; j++) { // Rows below pivot
          if(j>i){
            c = matrix[j][i] / matrix[i][i]; // Now float division
            for (k = 0; k < n + 1; k++) {
                matrix[j][k] = matrix[j][k] - c * matrix[i][k];
            }
        }
        }
    }
    x[n] = matrix[n][n+1]/matrix [n][n];

    for(i = n-1; i>=1; i--){
        sum = 0;
        for(j=i+1; j<=n; j++){
            sum = sum + matrix[i][j] * x[j];
        }
        x[i] = (matrix[i][n+1] - sum)/ matrix[i][i];
    }
    printf("\nSolution:::");
    for(i = 1; i<=n; i++){
        printf("\n x%d = %f\t", i, x[i]);
    }
    return 0;
}