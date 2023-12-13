#include<stdio.h>

int fact(int n)
{
    static int count =  0;
    count++;
    printf("%d times function called\n",count);
    if (n==1)
        return n;
    else
        return n*fact(n-1);
}
int main()
{
    int n,s;
    enter :
    printf("Enter a number :");
    scanf("%d", &n);
    if (n<=0)
    {
        printf("Enter a valid number\n");
        goto enter;
        return 0;
    }
    
    printf("Fact = %d\n",fact(n));
}