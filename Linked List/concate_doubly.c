#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
} node;

node *result_list = NULL;

/* Function to insert an element at the end of the list */
void insert_list(node **head, node **tail, int element) {

    node *newnode = (node *)malloc(sizeof(node));
    newnode->data = element;
    newnode->next = NULL;
    newnode->prev = NULL;

    /* Check if the list is empty */
    if (*head == NULL && *tail == NULL) {
        /* If empty, the new node becomes the head and the tail */
        *head = newnode;
        *tail = newnode;
    } else {
        /* If not empty, add the new node to the end of the list */
        (*tail)->next = newnode;
        newnode->prev = *tail;
        *tail = newnode;
    }
}

/* Function to concatenate two lists */
void concatenate(node *head1, node *head2, node *tail1, node *tail2) {
    void Display(); /* Forward declaration of the Display function */

    /* Check if both lists are empty */
    if ((head1 == NULL && tail1 == NULL) && (head2 == NULL && tail2 == NULL))
        printf("Lists are empty.\n");
    else if (head1 == NULL && tail1 == NULL) {
        /* If list 1 is empty, result_list is set to list 2 */
        result_list = head2;
        Display();
    } else if (head2 == NULL && tail2 == NULL) {
        /*  If list 2 is empty, result_list is set to list 1 */
        result_list = head1;
        Display();
    } else {
        result_list = head1; 
        tail1->next = head2;
        head2->prev = tail1;
        Display();
    }
}

/* Function to display the concatenated list */
void Display() {
    node *temp = result_list;
    /* Traverse the list and print each element */
    do {
        printf("%d\t", temp->data);
        temp = temp->next;
    } while (temp != NULL);
    printf("\n");
}

void main() {
    /* Declare pointers for the heads and tails of two lists */
    node *head1 = NULL, *head2 = NULL, *tail1 = NULL, *tail2 = NULL;

    int choice, element;

    for (;;) {
        printf("------------------------------------------------------------------\n");
        printf("1 - Insert in List-1\n2 - Insert in List-2\n3 - Concatenate\n4 - Exit\n");
        scanf("%d", &choice);
        printf("------------------------------------------------------------------\n");

        switch (choice) {
            case 1:
                printf("Enter element:");
                scanf("%d", &element);
                insert_list(&head1, &tail1, element);
                break;
            case 2:
                printf("Enter element:");
                scanf("%d", &element);
                insert_list(&head2, &tail2, element);
                break;
            case 3:
                concatenate(head1, head2, tail1, tail2);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid Input\n");
                break;
        }
    }
}
