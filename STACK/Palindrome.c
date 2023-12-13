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
int isPalindrome(char str[])
{
    void push(char);
    char pop();

    int strlength = strlen(str),i;
    for(i = 0; i < strlength;i++)
        push(str[i]);

        for(i = 0; i < strlength; i++)
        {
            if(str[i] != pop())
                return 0;
        }
    return 1;

}
void main()
{
    int isPalindrome(char inputString[]);

    char inputString[MAX];
    printf("\nEnter the String to check to palindrome or not\n");
    gets(inputString);
    
    if(isPalindrome(inputString))
        printf("%s : The Given String is Palindrome\n",inputString);
    else
        printf("%s : The Given String is not Palindrome\n",inputString);
}