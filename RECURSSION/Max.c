#include<stdio.h>
int max(int a[],int n)
{   
    int m;
   if(n == 0)
        return a[0];
    else
         m = max(a,n-1);
    return (m > a[n - 1]) ? m : a[n - 1]; /* min element : <*/
}
void main()
{
    int arr[10],n;
    printf("Enter the number of elements :");
    scanf("%d",&n);
    printf("Enter the %d element :",n);
    for(int i = 0;i < n;i++)
        scanf("%d",&arr[i]);

    printf("Max of element of the array = %d\n",max(arr,n));
}