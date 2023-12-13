#include <stdio.h>
#include <stdlib.h>
#define QUEUE_SIZE 5

int priorityQueue[QUEUE_SIZE];
int front = 0;
int rear = -1;

void pqueue_insert(int element)
{
    if (rear == QUEUE_SIZE - 1)
    {
        printf("Priority queue is full. Cannot insert %d.\n", element);
        // Check if the priority queue is full, and if so, print an error message.
    }
    else
    {
        int i;
        for (i = rear; i >= 0; i--)
        {
            if (element < priorityQueue[i])
            {
                // If the new element has higher priority, shift the current element one position to the right.
                priorityQueue[i + 1] = priorityQueue[i];
            }
            else
            {
                // If the new element has lower or equal priority, break out of the loop.
                break;
            }
        }
        // Insert the new element into its correct position in the priority queue.
        priorityQueue[i + 1] = element;

        rear++;
        // Increment the 'rear' index to indicate that a new element has been added to the queue.
    }
}
int pqempty()
{
    return front > rear;
}
int pqMindelete()
{
    if(pqempty())
    {
        printf("Priority queue is empty.\n");
        return -1;
    }
    int minElement = priorityQueue[front];

    for (int i = front; i < rear; i++)
    {
        priorityQueue[i] = priorityQueue[i + 1];
        // physically shift all elements in the array one place backward when an element is deleted
    }
    rear--;
    return minElement;
}

void display()
{
    if (pqempty())
    {
        printf("Priority queue is empty.\n");
    }
    else
    {
        printf("Priority queue elements: ");
        for (int i = front; i <= rear; i++)
        {
            printf("%d ", priorityQueue[i]);
        }
    }
}
int main()
{
    int choice, element;
    while (1)
    {
        printf("\nAscending Priority Queue Operations\n");
        printf("1. Insert\n2. Min Delete\n3. Is Empty\n4. Display\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\nEnter element to insert: ");
            scanf("%d", &element);
            pqueue_insert(element);
            break;
        case 2:
            element = pqMindelete();
            if(element != -1)
            {
                printf("\nDeleted element with the highest priority: %d\n", element);
            }
            break;
        case 3:
            if (pqempty())
            {
                printf("Priority queue is empty.\n");
            }
            else
            {
                printf("Priority queue is not empty.\n");
            }
            break;
        case 4:
            display();
            break;
        case 5:
            exit(0);
        default:
            printf("Invalid choice. Please enter a valid option.\n");
        }
    }
}