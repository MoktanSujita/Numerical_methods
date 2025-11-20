//C program to find root of an equation using bisection method
#include<stdio.h>
#include<math.h>
#include<conio.h>

//creating a function for equation
float fun(float x){
    return(pow(x,3)-2*x-5);
}

int main()
{
    float x1,x2,x0,a,b,c;
    int i;

    //Prompting for inputs until correct guesses
    do{
         printf("Enter any two guesses:");
         scanf("%f%f",&x1,&x2);
         a=fun(x1);
         b=fun(x2);
         if(a*b>0){
            printf("Invalid inputs! Enter other guesses");
         }
        } while(a*b >0);

         printf("iter\tx1\tx2\tx0\tf(x0)\n");
        //Upto 10th iteration
        for(i=1; i <=10; i++){
            x0 =(x1+x2)/2;
            c=fun(x0);
            printf("%d\t %.4f\t %.4f\t %.4f\t %.4f\n",i,x1,x2,x0,c);

            if(a*c<0){
                x2=x0;
                b=c;
            }
            else{
                x1=x0;
                a=c;
            }
            i++;
        }
        printf("\nThe root is %f",x1);
        return 0;
     }
