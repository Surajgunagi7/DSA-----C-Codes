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
void reverse(char str[])
{
    int i;
    for(i = 0;str[i] != '\0';i++)
        {
            if(str[i] != ' ')
                push(str[i]);
            else{
                while(top >= 0)
                {
                    printf("%c",pop());
                }printf(" ");
            }
        }
        while (top >= 0) {
        printf("%c", pop());
    }
    printf("\n");

}
void main()
{

    char inputString[MAX];
    printf("\nEnter the String to Reverse:\n");
    gets(inputString);
    reverse(inputString);
}