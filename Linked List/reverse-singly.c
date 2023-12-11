#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};

void insert_front(struct node** head,int element)
{
    struct node* new = (struct node *)malloc(sizeof(struct node));
    new->data = element; new->next = NULL;

    if(*head == NULL)
    {
        *head = new;
    }
    else{
       struct node * temp = *head;
       while(temp->next != NULL)
       {
            temp = temp->next;
       }
        temp->next = new;
    }
}
void reverse(struct node** head)
{
    struct node* previous_node = NULL;
    struct node* current_node = *head;
    struct node* next_node;

    while (current_node != NULL)
    {
        next_node = current_node->next;
        current_node->next = previous_node;

        previous_node = current_node;
        current_node = next_node;
    }

    *head = previous_node;
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

    int n,i,element;
    printf("Enter the number to elements in the list:");
    scanf("%d",&n);

    for(i = 0;i < n;i++)
    {
        printf("Enter %d element:",i+1);
        scanf("%d",&element);
        insert_front(&head,element);
    }
    printf("\n");
    
    printf("Original List: ");
    Display(head);

    printf("Reversed List: ");
    reverse(&head);
    Display(head);  
}