#include<stdio.h>
int mul(int a,int b)
{
    if(b==0)
        return 0;
    return a+mul(a,b-1);
}
void main()
{
    int a,b;
    printf("Enter two numbers :");
    scanf("%d%d",&a,&b);
    printf("The product of %d and %d is %d\n",a,b,mul(a,b));
}