#include<stdio.h>
#include<stdlib.h>

typedef struct Node 
{
    int data;
    struct Node * next;
}node;

node * head = NULL;

void insert(int x)
{
    node * new = (node *) malloc(sizeof(node));
    new->data = x; new->next = NULL;

    if(head == NULL)    {
        head = new;
    }
    else{
        node * temp = head;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = new;
    }
}
void mid_element()
{
    node* slow = head,* fast = head;
    while(fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }

    printf("Middle element of the list: %d\n",slow->data);
}
void Display()
{
    if(head == NULL)
        printf("List is empty..\n");
    else{
        node * temp = head;
        while(temp != NULL)
        {
            printf("%d->",temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}
void main()
{
    int i;
    for(i = 1;i<= 6;i++)
    {
        insert(i);
    }
    Display();
    mid_element();
    Display();
}