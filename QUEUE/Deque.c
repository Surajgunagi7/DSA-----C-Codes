#include<stdio.h>
#include<stdlib.h>
#define N 5

int deque[N],f = -1,r = -1;

void enqueue_front(int x)
{
    if((f == 0 && r == N - 1) || (f == (r + 1)))
        printf("Queue Full..\n");
    else if(f == -1 && r == -1) {
        f = r = 0;
        deque[f] = x;
    }
    else if(f == 0) {
        f = N - 1;
        deque[f] = x;
    }
    else {
        f--;
        deque[f] = x;
    }
}
void enqueue_rear(int x)
{
    if((f == 0 && r == N - 1) || (f == (r + 1)))
        printf("Queue Full..\n");
    else if(f == -1 && r == -1) {
        f = r = 0;
        deque[r] = x;
    }
    else if(r == N - 1) {
        r = 0;
        deque[r] = x;
    }
    else {
        r++;
        deque[r] = x;
    }
}
void dequeue_front()
{
    if(f == -1 && r == -1)
        printf("Queue Empty..\n");
    else if(f == r) {
        printf("Dequeued Element : %d\n",deque[f]);
        f = r = -1;
    }
    else if(f == N - 1) {
        printf("Dequeued Element : %d\n",deque[f]);
        f = 0;
    }
    else {
        printf("Dequeued Element : %d\n",deque[f]);
        f++;
    }
}
void dequeue_rear()
{
    if(f == -1 && r == -1)
        printf("Queue Empty..\n");
    else if(f == r) {
        printf("Dequeued Element : %d\n",deque[r]);
        f = r = -1;
    }
    else if(r == 0) {
        printf("Dequeued Element : %d\n",deque[r]);
        r = N - 1;
    }
    else {
        printf("Dequeued Element : %d\n",deque[r]);
        r--;
    }
}
void display(){
    int i;

    if(f == -1 && r == -1)
        printf("Queue Empty..\n");
    else {
        i = f;
        printf("Queue : ");
        while(i != r)
        {
            printf("%d\t",deque[i]);
            i = (i + 1) % N;
        }
        printf("%d\n",deque[r]);
    }   
}
void main()
{
    int response,ip;
    for(;;)
    {
        printf("1 - Enqueue_front\n2 - Enqueue_rear\n3 - Dequeue_front\n4 - Dequeue_rear\n5 - Display\n6 - exit\n");
        scanf("%d",&response);
        switch(response)
        {
            case 1 : printf("Enter element : ");
                     scanf("%d",&ip);
                     enqueue_front(ip); break;
            case 2 : printf("Enter element : ");
                     scanf("%d",&ip);
                     enqueue_rear(ip); break;
            case 3 : dequeue_front(); break;

            case 4 : dequeue_rear(); break;

            case 5 : display(); break;
            case 6 : exit(0);

            default : printf("Invalid Input..\n");
        }
    }
}