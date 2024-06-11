// Calculator

#include<stdio.h>

float calculate(float, char, float);

int main(){
    float a,b;
    char o;

    label1 :
    printf("Enter 1st number : ");
    scanf("%f",&a);
    printf("Enter operator : ");
    scanf(" %c",&o);
    printf("Enter 2nd number : ");
    scanf("%f",&b);
    
    if(o=='+'||o=='-'||o=='*'||o=='/'){
        float result = calculate(a,o,b);
        printf("\nThe result is %.2f .\n",result);
    }else{
        printf("\nEnter only +, -, * or / operators.\n");
        goto label1;
    }

    return 0;
}

float calculate(float a, char o, float b){
    switch(o){
        case '+' : {
            return a+b;
        }
        break;
        case '-' : {
            return a-b;
        }
        break;
        case '*' : {
            return a*b;
        }
        break;
        case '/' : {
            return a/b;
        }
        break;
        default : {
            printf("\n No operator matched ! \n");
            return 0;
        }
    }
}

