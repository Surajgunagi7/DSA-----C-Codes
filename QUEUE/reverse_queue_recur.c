#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

int queue[MAX_SIZE];
int front = -1, rear = -1;

int isEmpty() {
    return front == -1;
}
void enqueue(int value) {
    if (rear == MAX_SIZE - 1) {
        printf("Queue is full.\n");
    } 
    else {
        if (front == -1) {
            front = 0;
        }
        rear++;
        queue[rear] = value;
    }
}
int dequeue() {
    int item;
    if (isEmpty()) {
        printf("Queue is empty.\n");
        return -1;
    } 
    else if(front == rear)
    {   
        item = queue[front];
        front = rear = -1;
    }
    else {
        item = queue[front];
        front++;
    }
        return item;
}
void reverseQueue() {
    if (isEmpty()) {
        return;
    }
    int item = dequeue();
    reverseQueue();

    enqueue(item);

}
void displayQueue() {
    if (isEmpty()) {
        printf("Queue is empty.\n");
    } else {
        printf("Queue elements: ");
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}
int main() {

    int response,ip;
    for(;;)
    {
        printf("1 - Enqueue\n2 - dequeue\n3 - display\n4 - reverse\n5 - exit\n");
        scanf("%d",&response);
        switch(response)
        {
            case 1 : printf("Enter : ");
                     scanf("%d",&ip);
                     enqueue(ip); break;
            case 2 : if((ip = dequeue()) != -1)
                        printf("Dequeued element : %d\n",ip);
                     break;
            case 3 : displayQueue(); break;
            
            case 4 : printf("Original ");
                     displayQueue();

                     reverseQueue();
                     printf("Reversed ");
                     displayQueue(); break;
            case 5 : exit(0);
            default : printf("Invalid input\n");
        }
    }
    return 0;
}
