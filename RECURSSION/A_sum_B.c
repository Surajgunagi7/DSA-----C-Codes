#include<stdio.h>
int scc(int x)
{
    return ++x;
}
int add(int a,int b)
{
    if(b == 0)
        return a;
    else
        return add(scc(a),b-1);
}
void main()
{
    int a,b,res;
    printf("Enter the two number :");
    scanf("%d%d",&a,&b);
    res = add(a,b);
    printf("Sum of %d and %d is %d\n",a,b,res);
}