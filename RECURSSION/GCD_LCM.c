/* C program to find GCD and LCM of given numbers using recursion */
#include<stdio.h>
int gcd(int,int);
int count=0;
main()
{
    int g,n1,n2;
    printf("Enter two integers :");
    scanf("%d%d", &n1,&n2);
    g=gcd(n1,n2);
    printf("GCD = %d\n", g);
    printf("LCM = %d\n", (n1*n2)/g);
    printf("Count = %d\n", count);
}
int gcd(int n1,int n2)
{
    ++count;
    if(n2 == 0)
        return n1;
    else
        return gcd(n2, n1%n2 );
}