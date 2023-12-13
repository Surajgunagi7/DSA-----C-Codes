#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 30  /* Size of the Stack*/

char stack[MAX_SIZE];
int top = -1;

void push(char item) {         /* Function to push an item onto the stack */
    if(top == MAX_SIZE - 1) 
        printf("Stack Overflow\n");
     else 
        stack[++top] = item;      /*Incrementing the index and then assigning the incoming value*/
}
char pop() {           /* Function to pop an item from the stack */
    if (top == -1) 
        printf("Stack Underflow\n");
    else 
        return stack[top--];    /*The value is Used First and then index is Decremented*/
}
void reverse(char *str,int len)
{
    int i,temp;
    for(i = 0; i < len/2; i++)
    {
        temp = str[i];
        str[i] = str[len -i-1];
        str[len-i-1] = temp;
    }
}
/* To check whether the a character is number/Alphabet */
int isAlphaNum(char x) { 
     return ((x >= 'A' && x <= 'Z') || (x >= 'a' && x <= 'z') || (x >= '0' && x <= '9'));
}
/* To check wether character is operator or not */
int isOperator(char symbol) { 
    return (symbol == '+' || symbol == '-' || symbol == '*' || symbol == '/' || symbol == '^');
}
/* Function to determine the precedence of an operator */
int precedence(char symbol) { 
    switch(symbol)
    {
        case '+' :
        case '-' : return 1;
        case '*' :
        case '/' : return 2;
        case '^' : return 3;
        default : return 0;
    }
}
/* Function to convert infix expression to prefix expression */
void infixToPrefix(char infix[], char prefix[]) 
{
    int i, j = 0;
    reverse(infix,strlen(infix));        /* Reverse the infix expression */
        for(i = 0; i < strlen(infix); i++) 
        {
            if(infix[i] == ' ')
                continue;
            else if(isAlphaNum(infix[i]))  /* If alphanumeric, add to the prefix expression */
                prefix[j++] = infix[i];
            else if(infix[i] == ')')    /* If closing parenthesis, push onto the stack */
                    push(infix[i]);
                else if(infix[i] == '(') 
                    {   /* If opening parenthesis, pop operators from the stack and add to prefix until a closing parenthesis is encountered */
                        while(stack[top] != ')') 
                        {
                            prefix[j++] = pop();
                        }
                        pop(); /* Pop the closing parenthesis */
                    } 
                    else if(isOperator(infix[i])) 
                        {
                            if(precedence(stack[top]) > precedence(infix[i]))
                            {
                                     /* If operator, handle operator precedence and stack operations */
                                while(precedence(stack[top]) > precedence(infix[i])) {
                                    prefix[j++] = pop();
                                }
                                push(infix[i]);
                            }
                            else if(precedence(stack[top]) == precedence(infix[i]))
                                    {
                                        if(stack[top] == '^')   {
                                            prefix[j++] = pop();
                                            push(infix[i]);
                                        }
                                        else
                                            push(infix[i]);
                                    }
                            else
                                    push(infix[i]);
                        }
        }
    while (top != -1)  /* Pop remaining operators from the stack and add to prefix */
    {
        prefix[j++] = pop();
    }
  /* Reverse the prefix expression to get the correct order */
    reverse(prefix,strlen(prefix));
}
void main()     
{
    char infix[MAX_SIZE], prefix[MAX_SIZE] = {0};

    
    printf("\nEnter infix expression: ");
    gets(infix);

    /* Convert infix to prefix */
    infixToPrefix(infix, prefix);

    printf("Prefix expression: %s\n", prefix);
}