#include<stdio.h>
#include<stdlib.h>
#define N 5

struct Q {
    int data[N];
    int front, rear;
};

void Enqueue(struct Q *Queue, int x) {
    if (Queue->rear == N - 1)
        printf("Overflow....\n");
    else if (Queue->front == -1 && Queue->rear == -1)
        Queue->data[++Queue->rear] = x;
    else
        Queue->data[++Queue->rear] = x;
}

int Dequeue(struct Q *Queue) {
    int ret = -1; // Initialize to -1
    if (Queue->front == -1 && Queue->rear == -1)
        printf("Underflow...\n");
    else if (Queue->front == Queue->rear) /* Only one Element remaining*/
    {
        ret = Queue->data[Queue->front];
        Queue->front = -1;
        Queue->rear = -1;
    } else
        ret = Queue->data[Queue->front++];

    return ret;
}

void push(struct Q *queue1, struct Q *queue2, int element) {
    if (queue1->rear == N - 1) {
        printf("Stack full\n");
        return;
    }

    while (queue1->front != -1) {
        Enqueue(queue2, Dequeue(queue1));
    }

    Enqueue(queue1, element);

    while (queue2->front != -1) {
        Enqueue(queue1, Dequeue(queue2));
    }
}

void Display(struct Q queue) {
    int i;
    if (queue.rear == -1 && queue.front == -1) {
        printf("Stack empty..\n");
        return;
    } else {
        printf("Content:");
        for (i = queue.front; i <= queue.rear; i++) {
            printf("%d\t", queue.data[i]);
        }
        printf("\n");
    }
}

void pop(struct Q *queue1) {
    if (queue1->rear == -1 && queue1->front == -1) {
        printf("Stack empty..\n");
        return;
    } else
        printf("Popped element: %d\n", Dequeue(queue1));
}

int main() {
    struct Q queue1, queue2;
    queue1.front = -1;
    queue1.rear = -1;
    queue2.front = -1;
    queue2.rear = -1;
    int choice, element;

    push(&queue1, &queue2, 1);
    Display(queue1);
    push(&queue1, &queue2, 2);
    Display(queue1);
    push(&queue1, &queue2, 3);
    Display(queue1);
    push(&queue1, &queue2, 4);
    Display(queue1);

    pop(&queue1);
    Display(queue1);
    pop(&queue1);
    Display(queue1);
    pop(&queue1);
    Display(queue1);
    push(&queue1, &queue2, 10);
    Display(queue1);

    return 0;
}
