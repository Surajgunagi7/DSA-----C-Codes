#include <stdio.h>
#include <stdlib.h>
#define N 5

int queue[N], front = -1, rear = -1;

/*  Function to enqueue an element into the queue */
void Enqueue(int x) {
    /* Check if the queue is full */
    if (front == ((rear + 1) % N))
        printf("Queue Overflow..\n");
    /*  Check if the queue is empty */
    else if (front == -1 && rear == -1) {
        queue[++rear] = x;
        front = 0;
    }
    else {
        rear = (rear + 1) % N;
        queue[rear] = x;
    }
}

/*  Function to dequeue an element from the queue */
void Dequeue() {
    /*  Check if the queue is empty */
    if (front == -1 && rear == -1)
        printf("Queue Empty..\n");
    /* Check if there is only one element in the queue */
    else if (front == rear) {
        printf("Dequeued element = %d\n", queue[front]);
        front = rear = -1;
    }
    /* Remove element from the queue */
    else {
        printf("Dequeued element = %d\n", queue[front]);
        front = (front + 1) % N;
    }
}

/*  Function to display the elements in the queue */
void Display() {
    int i = front;
    /* Check if the queue is empty */
    if (front == -1 && rear == -1)
        printf("Queue Empty..\n");
    else {
        printf("\nContents: ");
       do{
           printf("%d\t",queue[i]);
           i = (i + 1) % N; 
       }while(i != ((rear + 1)%N));
       printf("\n");
    }
}

/* Function to peek at the front element of the queue */ 
void peek() {
    /* Check if the queue is empty */
    if (front == -1 && rear == -1)
        printf("Queue empty...\n");
    /* Print the front element of the queue */
    else {
        printf("Peeked Element : %d\n", queue[front]);
    }
}

void main() {
    int ip, response;

    /* Infinite loop for user interaction */
    for (;;) {
        /* Menu for user choices */ 
        printf("1 - Enqueue\n2 - Dequeue\n3 - Display\n4 - Peek/Front Check\n5 - Exit\n");
        scanf("%d", &response);
        switch (response) {
            case 1:
                printf("Enter the element to Enqueue: ");
                scanf("%d", &ip);
                Enqueue(ip);  /* Call Enqueue function */
                break;
            case 2:
                Dequeue();  /* Call Dequeue function */
                break;
            case 3:
                Display();  /* Call Display function */
                break;
            case 4:
                peek();  /* Call peek function */
                break;
            case 5:
                exit(0);  /* Exit the program */
            default:
                printf("Invalid Input\n");  /* Invalid input, show menu again */
        }
    }
}
