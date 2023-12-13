#include<stdio.h>
#include<string.h>
#define N 20

char Stack[N];
int top = -1;
void push(char input)
{
    if(top == N - 1)
        printf("StackOverflow..\n");
    else
        Stack[++top] = input;
}
char pop()
{
    if(top == -1)
        printf("StackEmpty..\n");
    else
        return Stack[top--];
}
int check_exp(char inputString[])
{
    int i;

    for(i = 0;inputString[i] != '\0';i++)
    {
        if(inputString[i] == 'c' || inputString[i] == 'C')
            break;
        else
            push(inputString[i]);   
    }
    while(inputString[++i] != '\0')
    {
        if(inputString[i] != pop())
            return 0;
    }
    return 1;
}
void main()
{
    char ipExp[N];
    printf("Input the Expression toc= check to xCy form: ");
    scanf("%s",ipExp);

    if(check_exp(ipExp))
        printf("The Given Expression %s is of xCy form.\n",ipExp);
    else
        printf("The Given Expression %s is not of xCy form.\n",ipExp);
}