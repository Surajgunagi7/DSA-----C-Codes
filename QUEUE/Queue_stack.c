#include<stdlib.h>
#include<stdio.h>
#define N 5

int stack[N],tempStack[N],top1 = -1,top2 = -1,count = 0;

void push1(int x)
{
    stack[++top1] = x;
}
void push2(int x)
{
    tempStack[++top2] = x;
}
int pop1()
{
    return stack[top1--];
}
int pop2()
{
    return tempStack[top2--];
}
void enqueue(int data)
{
    if(top1 == N - 1)
        printf("Queue Full.\n");
    else
        {
            push1(data);
            count++;
        }
}
void dequeue()
{
    int i;
    if(top1 == -1 && top2 == -1)
        printf("Queue empty..\n");
    else       {
            for(i = 0;i < count;i++)
                push2(pop1());
            printf("Dequeued element : %d\n",pop2());
            count--;

            for(i = 0;i < count;i++)
                push1(pop2());
    }

}
void display()
{
    int i;
    if(top1 == - 1)
        printf("Queue Empyt..\n");
    else    {
        printf("Queue : ");
        for(i = 0;i <= top1;i++)
            printf("%d\t",stack[i]);
        printf("\n");
    }
}
void main()
{
    int response,ip;
    for(;;)
    {
        printf("1 - Enqueue\n2 - Dequeue\n3 - Display\n4 - exit\n");
        scanf("%d",&response);
        switch(response)
        {
            case 1 : printf("Enter Element : ");
                     scanf("%d",&ip);
                     enqueue(ip); break;
            case 2 : dequeue(); break;

            case 3 : display(); break;

            case 4 : exit(0);

            default : printf("Invalid Input..\n");
        }
    }
}
