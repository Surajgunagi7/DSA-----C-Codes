#include<stdio.h>
#include<stdlib.h>

/* Singly List */
struct node{
    int data;
    struct node* next;
};

struct node* head = NULL;

void insert_end(int element)
{
    struct node* new = (struct node *)malloc(sizeof(struct node));
        new->data = element; new->next = NULL;

    if(head == NULL)    {
            head = new;
    }
    else{
        struct node* temp = head;
        
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = new;
    }
}
void search_List(int search_element)
{
    struct node * temp = head;
        if(head == NULL)    {
            printf("List is empty\n");
            insert_end(search_element);
            printf("Element inserted successfully\n");
        }
        else{
            while(temp != NULL){
                if(temp->data == search_element)    {
                    printf("Element(%d) found at %x address\n",search_element,temp);
                    return;
                }
                temp = temp->next;
            }
            printf("Element not found\n");
            insert_end(search_element);
            printf("Element inserted successfully\n");
        }
}
void Display()
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
    int choice,element;

    for(;;)
    {
        printf("1 - Insertion\n2 - search element\n3 - Display\n4 - exit\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1 : printf("Enter the element:");
                     scanf("%d",&element);
                     insert_end(element); break;

            case 2 : printf("Enter the element to be searched:");
                     scanf("%d",&element);
                     search_List(element); break;

            case 3 : Display(); break;

            case 4 : exit(0);
        }
    }

}