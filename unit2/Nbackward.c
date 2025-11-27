#include<stdio.h>

int fact(int n){
    int i, f=1;
    for(i=1;i<=n;i++)
        f=f*i;
    return f;
}

int main(){
    int i, j, n;
    float x[10], y[10][10], value, p, sum;

    printf("Enter number of data points: ");
    scanf("%d",&n);

    printf("Enter values of x:\n");
    for(i=0;i<n;i++)
        scanf("%f",&x[i]);

    printf("Enter values of y:\n");
    for(i=0;i<n;i++)
        scanf("%f",&y[i][0]);

    // Difference table
    for(j=1;j<n;j++){
        for(i=n-1;i>=j;i--){
            y[i][j]=y[i][j-1]-y[i-1][j-1];
        }
    }

    printf("Enter the value to interpolate: ");
    scanf("%f",&value);

    p = (value - x[n-1])/(x[1]-x[0]);
    sum = y[n-1][0];

    for(i=1;i<n;i++){
        float term=1;
        for(j=0;j<i;j++)
            term = term*(p+j);

        sum = sum + (term*y[n-1][i])/fact(i);
    }

    printf("Interpolated value = %.4f\n",sum);

    return 0;
}
