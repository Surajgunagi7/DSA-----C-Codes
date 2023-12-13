#include<stdio.h>
#include<string.h>
#define MAX 50

char String[MAX];
int top = -1;

void push(char x)
{
    if(top == MAX - 1)
        printf("Stack Overflow..Push Operation failed\n");
    else    
        String[++top] = x;
}
char pop()
{
    if(top == -1)
        printf("Stack Empty..Pop Operation Failed\n");
    else
        return String[top--];
}
char* reverse(char str[])
{
    int i;
    for(i = 0;str[i] != '\0';i++)
        push(str[i]);

        for(i = 0; str[i] != '\0'; i++)
        {
            str[i] = pop();
        }
    return str;

}
void main()
{

    char inputString[MAX];
    printf("\nEnter the String to Reverse:\n");
    gets(inputString);
    
    printf("%s : The Given String is Palindrome\n",reverse(inputString));
}