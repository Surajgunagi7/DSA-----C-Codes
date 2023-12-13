#include<stdio.h>
#include<stdlib.h>
#define N 5
int queue[N],front = 0,rear = -1;
void Enqueue(int x)
{
    if(rear == N - 1)
        printf("Overflow....\n");
    else if(front == 0 && rear == -1)
        queue[++rear] = x; /* if front = rear == - 1 then increment both Here !*/
    else    
        queue[++rear] = x;
}
int Dequeue()
{
    int ret;
    if(front == 0 && rear == -1)
        printf("Underflow...\n");
    else if(front == rear) /* Only one Element remaining*/
            {
                ret = queue[front];
                front = 0; rear = -1;
            }
    else
        return queue[front++];
    
    return ret;
}
void Display()
{
    int i;
    if(front == 0 && rear == -1)
        printf("Underflow...\n");
    else
        {
            printf("\n\tThe Contents of the Queue are as follows :\n");
            for(i = front;i <= rear;i++)
                printf("%d\t",queue[i]);
        }printf("\n");   
}
int peek()
{
    if(front == 0 && rear == -1)
        printf("Underflow...\n");
    else{
        return queue[front];
    }
}
void main()
{
    int ip,i,response;
    
    while(1)
    {
        printf("1 - Enqueue\n2 - Dequeue\n3 - Display\n4 - peek/front_check\n5 - exit\n");
        scanf("%d",&response);
        switch(response)
        {
            case 1 : printf("Enter the element to Enqueue : ");
                     scanf("%d",&ip);
                     Enqueue(ip); break;
            case 2 : printf("Dequeued Element  =  %d\n",Dequeue());
                     break;
            case 3 : Display(); break;

            case 4 : printf("The front element  = %d\n",peek()); break;

            case 5 : exit(0);
        }
    }

}