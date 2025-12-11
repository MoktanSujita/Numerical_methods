#include <stdio.h>
#include <math.h>

int main(){
    int n, i, j, k;
    float c, l;
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
    for(k =0; k < n; k++){
        for(i = 0;i <= n; i++){
            l = matrix[i][k];
            for(j = 0; j<=n; j++){
                if(i !=k){
                    matrix[i][j] = (matrix[k][k]*matrix[i][j])-(l*matrix[k][j]);
                }
            }
        }
    }

    printf("\nSolution:::");
    for(i = 0; i<=n-1; i++){
        printf("\n x%d = %f\t", (i+1), matrix[i][n]/ matrix[i][i]);
    }
    return 0;
}