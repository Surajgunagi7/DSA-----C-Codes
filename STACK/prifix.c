#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SiZE 100
float stack[SiZE];
int top = -1;

void Push(float value)
{
    if (top == SiZE - 1) 
    {
    printf("Stack Overflow\n");
    exit(1);
    }
    stack[++top] = value;
}
float pop()
{
    if (top == -1)
    {
    printf("Stack Underflow\n");
    exit(1);
    }
    return stack[top--];
}
float evaluatePrefixExpression(char expression[])
{
    int i;
    float operand1, operand2;
            for(i = strlen(expression) - 1; i >= 0; i--) {
                if(expression[i] >= '0' && expression[i] <= '9') 
                {
                    Push(expression[i] - '0');
                } 
                else
                {
                    operand1 = pop(); 
                    operand2 = pop();
                switch (expression[i]) 
                {
                    case '+':
                    Push(operand1 + operand2);
                    break;
                    case '-':
                    Push(operand1 - operand2);
                    break;
                    case '*':
                    Push(operand1 * operand2);
                    break;
                    case '/':
                    Push(operand1 / operand2);
                    break;
                    default:
                    printf("invalid operator in the expression\n");
                    exit(1);
                }
    }
}
    return pop();
}
int main()
{
 char expression[100];
 printf("Enter a prefix expression: ");
 scanf("%s", expression);
 float result= evaluatePrefixExpression(expression);
 printf("Result: %f\n", result);
 return 0;
}