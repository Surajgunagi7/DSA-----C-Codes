#include<stdio.h>
#include<math.h>
#define N 50
int stack[N];
int top = - 1;
    void push(int input)
    {
        if(top == N - 1)
            printf("Stack Overflow..\n");
        else    
            stack[++top] = input;
    }
 int pop()
    {
        if(top == -1)
            printf("Stack Empty\n");
        else    
            return stack[top--];
    }
 int operation(int op1,int op2,char operator)
    {
        switch(operator)
        {
            case '+' : return op1 + op2;

            case '-' : return op1 - op2;

            case '*' : return op1 * op2;

            case '/' : return op1 / op2;

            case '$' : return pow(op1,op2);

            default  : printf("Invalid Operator..\n");
                    break;
        }
    }
int evaluate(char inputString[])
    {
     int op1,op2;
     int i;
        for(i = 0;inputString[i] != '\0';i++)
        {
            if(inputString[i] >= '0' && inputString[i] <= '9')
                push(inputString[i] - '0');
            else if(inputString[i] == ' ')
                continue;
            else
                {
                    op2 = pop();
                    op1 = pop();
                    push(operation(op1,op2,inputString[i]));
                }
        }
        return pop();
        
    }
void main()
    {
        char ipExp[N];
        int result;
        printf("Input the Postfix exp :");
        gets(ipExp);

        result = evaluate(ipExp);

        printf("The value of Expression : %s = %d\n",ipExp,result);
    }