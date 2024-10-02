#include<stdio.h>

int main(){
    char operator;
    float number1, number2;

    scanf("%f", &number1);                      //input the first number 

    while(1){
        operator = getchar();                   //input the operator
        if (operator=='\n')
            break;

        scanf("%f", &number2);  
        switch(operator){                       //determine the kind of operators
            case '+':
                number1 += number2;
                break;
            case '-':
                number1 -= number2;
                break;
            case '*':
                number1 *= number2;
                break;
            case '/':
                number1 /= number2;
                break;
        }
    }
    printf("%.2f", number1);                    //print the answer
}
