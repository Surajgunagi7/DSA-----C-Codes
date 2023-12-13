#include<stdio.h>

#define TRUE 1      /* Define constants for TRUE and FALSE */
#define FALSE 0
#define N 50

 /* Declare a character stack and initialize top to -1 */
char stack[N];
int top = -1;

void push(char input)           /* Function to push a character onto the stack */
{
    if(top == N - 1)            /* Check if the stack is full */
        printf("Stack Full..Push Operation failed\n");
    else
        stack[++top] = input;    
}
char pop()                       /* Function to pop a character from the stack */
{
    return stack[top--];
}
int check_symbols(char c1,char c2)  /* Function to check if two symbols form a valid pair */
{
    if((c1 == '(' && c2 == ')') || (c1 == '[' && c2 == ']') || (c1 == '{' && c2 == '}'))
        return TRUE;    
    return FALSE;   
}
int isBalanced(char inputString[])              /* Function to check if an expression has balanced parentheses */
{
    char symb;
    int i = 0;

    for(i = 0;inputString[i] != '\0';i++)     /* Loop through each character in the input string */
    {
        symb = inputString[i];

        if(symb == '(' || symb == '{' || symb == '[')
            push(symb);                         /* Push opening symbols onto the stack */
        if(symb == ')' || symb == '}' || symb == ']')
        {
            if(top == -1 )
                return FALSE;
            else { 
                if(!check_symbols(pop(),symb))    /* Stack empty OR Symbols dont form valid pair*/ 
                    return FALSE; 
            }     
        }
    }
    if(top != -1)               /* Stack is not empty, not balanced */
        return FALSE;
    else
        return TRUE;
}
void main()
{ 
    char inputString[N];

    /* Input an expression to check for balanced condition */
    printf("\n\nInput an Expression to check for Balanced Condition\n");
    scanf("%s",inputString);
    
    if(isBalanced(inputString))
        printf("%s is a Balanced Expression\n",inputString);
    else    
        printf("%s is not a Balanced Expression\n",inputString);
}