#include<stdio.h>
#include<math.h>

int main()
    {
        int i,j,n,k;
        printf("\nEnter the value of n : ");
        scanf("%d",&n);

        float X[n],Y[n],d[n][n],x,t,y=0,s=1;
        for(i=0;i<n;i++){

            printf("\nEnter the value of X[i] and Y[i] : \n");
                scanf("%f%f",&X[i],&Y[i]);
        }

        printf("\nEnter the value of x  : ");
        scanf("%f",&x);
        for(j=0;j<n;j++)
        {
            for(i=0;i<n-j;i++){

                d[i][j]=0;
            }
        }
        for(i=0;i<n;i++){
            d[i][0]=Y[i];
        }
        for(j=0;j<n;j++)
        {
            for(i=0;i<n-j;i++)
            {
                if(j==0)    continue;                
                d[i][j]=(d[i+1][j-1]-d[i][j-1])/(X[i+j]-X[i]);
            }        
        }
        y=Y[0];
        for(k=1;k<n;k++)
        {
            s=s*(x-X[k-1]);
            t=s*d[0][k];
            y=y+t;
        }
        printf("\nAnswer = %f\n\n",y);
    }