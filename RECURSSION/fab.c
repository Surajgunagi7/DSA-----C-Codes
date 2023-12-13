#include<stdio.h>
int count = 0;
int fib_n(int);
main()
{
    int n;
    start :
    printf("Enter nth term to find fibonocci term : ");
    scanf("%d", &n);
    if(n <= 0)
        goto start;   
    printf("%d term = %d\n", n,fib_n(n));
        printf("%d times fucntion called\n",count);
}
int fib_n(int n)
{
    count++;
    
    if (n == 1 || n==2)
        return 1;
    return fib_n(n-1)+fib_n(n-2);
}