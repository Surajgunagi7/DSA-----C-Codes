#include<stdio.h>
#include<stdlib.h>
#define N 10

int queue[N] = {2 ,1};

int isEmpty()
{
    
    if(queue[0] == 2 && queue[1] == 1)
        return 1;
    else
        return 0;
}
void enqueue(int x)
{
    if(queue[1] == N - 1)
        printf("Queue Fulll..\n");
    else 
        queue[++queue[1]] = x;

}
void dequeue()
{
    if(isEmpty())
        printf("Queue Empty..\n");
    else if(queue[0] == queue[1])
    {
        printf("Dequeued Element : %d\n",queue[queue[0]]);
        queue[0] = 2; queue[1] = 1;
    }
    else
    {
        printf("Dequeued Element : %d\n",queue[queue[0]]);
        queue[0]++;
    }
}
void Display()
{
    if(queue[0] == 2 && queue[1] == 1)
        printf("Queue empty\n");
    else{
        int i;
            for(i = queue[0];i <= queue[1]; i++)
            {
                printf("%d\t",queue[i]);
            }printf("\n");
    }
}
void main()
{
   int choice,element;
   for(;;)
   {
        printf("1 - Enqueue\n2 - Dequeue\n3 - Display\n4 -Exit\n");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1: printf("Enter element:");
                    scanf("%d",&element);
                    enqueue(element); break;
            case 2: dequeue(); break;

            case 3: Display(); break;

            case 4: exit(0);
        }
   }
}