#include<stdio.h>
#include<stdlib.h>

/* Singly List */
struct node{
    int data;
    struct node* next;
};

void insert_sorted(struct node** head,int element)
{
    
    struct node* temp;
    struct node* new = (struct node *) malloc(sizeof(struct node));
    new->data = element; new->next = NULL;

    int key = element;
    if(*head == NULL || key < (*head)->data) {
        new->next = *head;
        *head = new;
    }
    else{
        temp = *head;

        while(temp->next != NULL && temp->next->data < key)
        {
            temp = temp->next;
        }
        new->next = temp->next;
        temp->next = new;
    }
}
void delete(struct node** head)
{
    struct node* temp;

    if(*head == NULL)
    {
        printf("List is empty..\n");
        return;
    }
    else{
        temp = *head;
        printf("Deleted element: %d\n",temp->data);
        *head = temp->next;
        free(temp);
    }
}
void Display(struct node* head)
{
   struct node* temp = head;

    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
    
}
void main()
{
    struct node* head = NULL;
    int choice,element;

    for(;;)
    {
        printf("1 - Insertion(sorted)\n2 - Deletion(front)\n3 - Display\n4 - exit\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1 : printf("Enter the element:");
                     scanf("%d",&element);
                     insert_sorted(&head,element); break;
            case 2 : delete(&head); break;

            case 3 : Display(head); break;

            case 4 : exit(0);
        }
    }
}