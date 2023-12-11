#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
};

/* Function to push an element onto the stack */
void push(struct node **stack, int element) {    /* Insert front */
    /* Create a new node */
    struct node *new = (struct node *)malloc(sizeof(struct node));
    new->data = element;

    if (*stack == NULL) {
        /* If the stack is empty, point to itself */
        new->next = new;
        *stack = new;
    } else {
        /* Insert the new node at the top of the stack */
        new->next = (*stack)->next;     /* Newnode next points to previous first node */
        (*stack)->next = new;       /* Last node points to the new first node */
    }
}

/* Function to pop an element from the stack or dequeue an element from the queue */
int pop_dequeue(struct node **list) {
    struct node *temp;
    int ret_var;

    if (*list == NULL)
        return -1;
    else {
        /* Remove the first node from the list */
        temp = (*list)->next;       /* temp points to first node */
        ret_var = temp->data;      

        if (temp == *list) {    /* If there was only one node, free it and set the list to NULL */
            free(temp);
            *list = NULL;
        } else {
            /* Remove the first node and adjust the pointers */
            (*list)->next = temp->next; /* Last node points to new first node */
            free(temp);         
        }
        return ret_var;
    }
}

/* Function to enqueue an element into the queue */
void Enqueue(struct node **queue, int element) {
    struct node *new = (struct node *)malloc(sizeof(struct node));
    new->data = element;

    if (*queue == NULL) {
        /* If the queue is empty, points to itself */
        new->next = new;
        *queue = new;
    } else {    /* Insert the new node at the end(from rear) of the queue */ 
        new->next = (*queue)->next;  /* Last node(new created) points to first node */
        (*queue)->next = new;       /* Previous last points to new Last node */
        *queue = new;               /* External Pointer Queue points to last node */
    }
}

/* Function to display the elements in the list */
void Display(struct node *list) {
    struct node *temp;
    if (list == NULL)  
        printf("Underflow Condition..\n");
    else {
        temp = list->next;  /* Assigning First elemet address to temp */
        /* Traverse the list and print each element */
        do {
            printf("%d\t", temp->data);
            temp = temp->next;
        } while(temp != list->next);
        printf("\n");
    }
}

void main() {
    /* Initialize pointers to the stack and queue */
    struct node *stack = NULL, *queue = NULL;
    int choice, element;

    /* Display the main menu */
    menu:
    printf("------------------------------------------------------------------\n");
    printf("1 - Stack Operation\n2 - Queue operation\n3 - Exit\n");
    scanf("%d", &choice);
    printf("------------------------------------------------------------------\n");

    if (choice == 1) {
        /* Stack operations */
        for (;;) {
            printf("------------------------------------------------------------------\n");
            printf("1 - Push\n2 - Pop\n3 - Display\n4 - Menu\n");
            scanf("%d", &choice);
            printf("------------------------------------------------------------------\n");
            switch (choice) {
                case 1:
                    printf("Enter element :");
                    scanf("%d", &element);
                    push(&stack, element);
                    break;
                case 2:
                    element = pop_dequeue(&stack);
                    if (element == -1)
                        printf("Stack Underflow..\n");
                    else
                        printf("Popped element: %d\n", element);
                    break;
                case 3:
                    Display(stack);
                    break;
                case 4:
                    goto menu;
            }
        }
    } else if (choice == 2) {
        /* Queue operations */
        for (;;) {
            printf("------------------------------------------------------------------\n");
            printf("1 - Enqueue\n2 - Dequeue\n3 - Display\n4 - Menu\n");
            scanf("%d", &choice);
            printf("------------------------------------------------------------------\n");
            switch (choice) {
                case 1:
                    printf("Enter element :");
                    scanf("%d", &element);
                    Enqueue(&queue, element);
                    break;
                case 2:
                    element = pop_dequeue(&queue);
                    if (element == -1)
                        printf("Queue Underflow..\n");
                    else
                        printf("Dequeued element: %d\n", element);
                    break;
                case 3:
                    Display(queue);
                    break;
                case 4:
                    goto menu;
            }
        }
    } else
        exit(0);
}
