//C program to find root of an equation using bisection method
#include<stdio.h>
#include<math.h>
#include<conio.h>

//creating a function for equation
float fun(float a){
    return(pow(a,3)-2*a-5);
}

int main()
{
    float x1,x2,x3,a,b,c;
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

        //Upto 10th iteration
        for(i=1; i <=10; i++){
            x3 =(x1+x2)/2;
            printf("Iteration %d = %f\n",i,x3);
            c=fun(x3);

            if(a*c<0){
                x2=x3;
                b=c;
            }
            else{
                x1=x3;
                a=c;
            }
            i++;
        }
        printf("the root is %f",x1);
        return 0;
    }
