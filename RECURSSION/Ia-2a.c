#include<stdio.h>
static int count = 0;
int gcd(int x,int y)
{
    count++;
    if(y <= x && (x%y) == 0)
        return y;
    else if(x < y)
        gcd(y,x);
    else
        gcd(y,x%y);
}
void main(){
    int x,y,result;
    printf("Enter any two numbers:");
    scanf("%d%d",&x,&y);

    result = gcd(x,y);

    printf("Gcd : %d\n %d\n",result,count);

}