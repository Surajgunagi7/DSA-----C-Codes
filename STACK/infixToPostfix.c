#include<stdio.h>
#include<string.h>

#define N 30        /* Size of the Stack*/

char stack[N];  /* Global Declaration of Stack and index Top*/
int top = -1;

void push(char x)       /* Function to push an item onto the stack*/
{
    if(top == N - 1)
        printf("Stack Overflow..\n");
    else
        stack[++top] = x;             /*Incrementing the index and then assigning the incoming value*/
}  
char pop()          /*Function to pop an item from the stack*/
{
    if(top == -1)
        printf("Stack empty..\n");
    else    
        return stack[top--];       /*The value is Used First and then index is Decremented*/
}
/* To check whether the a character is Alphanumeric Or Not */
int isAlphaNum(char x)
{
    return ((x >= '0' && x <= '9') || (x >= 'a' && x <= 'z') || (x >= 'A' && x <= 'Z'));
}
/* To check wether character is operator or not */
int isOperator(char x)
{
    return (x == '+' || x == '-' || x == '*' || x == '/' || x == '^');
}
int precedence(char x)      /* Function to determine the precedence of an operator */
{
    switch(x)
    {
        case '+' :
        case '-' : return 1;

        case '*' :
        case '/' : return 2;

        case '^' : return 3;

        default : return 0;     /* If Incoming character = '(' or ') */
    }
}
void infixToPostfix(char infix[],char Postfix[])    /* Function to convert infix expression to prefix expression */
{
    int i,j = 0;
    for(i = 0;i < strlen(infix);i++)
    {
        if(isAlphaNum(infix[i]))    /* If alphanumeric, add to the prefix expression */
           Postfix[j++] = infix[i];
        else if(infix[i] == '(')    /* If Opening parenthesis, push onto the stack */
            push(infix[i]);
        else if(infix[i] == ')')
        {       /* If Closing parenthesis, pop operators from the stack and add to Postfix until a Opening parenthesis is encountered */
            while(stack[top] != '(') 
                {
                    Postfix[j++] = pop();
                }
                pop();  /* Pop the Opening parenthesis*/
        }
        /* If operator, handle operator precedence and stack operations */
        else if(isOperator(infix[i]))
        {
            /* Precedence of stacktop > incoming Operator then pop and assign to Postfix expression and compare with new stacktop*/
            if(precedence(stack[top]) > precedence(infix[i]))
                {      
                    while(precedence(stack[top]) >= precedence(infix[i])) {
                          Postfix[j++] = pop();
                    }
                    push(infix[i]); /* Else Push the incoming Operator to the Stack */
                }
            else if(precedence(stack[top]) == precedence(infix[i])) {  /* Stacktop and incoming operator same Precedence , check Associativity*/
                    
                        if(stack[top] == '^')   /* Exponential associativity : R --> L, Push On to the Stack */
                           push(infix[i]);      
                        else  {                 /* '+','-','*','/' L --> R, pop and assign to Postfix exp and push incoming operator */
                            Postfix[j++] = pop();
                            push(infix[i]);
                          }
                }
            else    /* For Stack Empty Condition Push */
                push(infix[i]); 
        }                        
        else  
            continue;
    }
    while (top != -1)   /* Pop remaining operators from the stack and add to Postfix */
    {
        Postfix[j++] = pop();
    }
    Postfix[j] = '\0'; /* Assigning Null character indicating End of String */

}
void main()     /* Main function to read input and call infixToPrefix function */
{
    char infix[N],Postfix[N];
    printf("Enter the infix expression :");
    scanf("%s",infix);

    infixToPostfix(infix,Postfix);  /* Function Call to convert infix to Postfix*/
    printf("Postfix expression : %s\n",Postfix);
}