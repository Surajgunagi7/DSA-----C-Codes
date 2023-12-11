#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};
void insert_front(struct node** tail,int element)
{
    struct node* new = (struct node *)malloc(sizeof(struct node));
    new->data = element;

    if(*tail == NULL)   {
        new->next = new;
        *tail = new;
    }
    else    {
        new->next = (*tail)->next; 
        (*tail)->next = new;
    }
}
void Display(struct node* tail)
{
    struct node* temp;

    if(tail == NULL)
        printf("Underflow Condition..\n");
    else    {
        temp = tail->next;
        do
        {
            printf("%d\t",temp->data);
            temp = temp->next;
        }while(temp != tail->next); printf("\n");
    }
}
void Concatenate(struct node* tail1,struct node* tail2)
{
    struct node* temp;
    if(tail2 == NULL)   {
        Display(tail1); return;
    }
    else if(tail1 == NULL)   {
        tail1 = tail2;
        Display(tail1); return;
    }
    else{
        temp = tail1->next;
        tail1->next = tail2->next;
        tail2->next = temp;
        tail1 = tail2; 
        Display(tail1);
        exit(0);
    }
}
void main()
{
    struct node *tail1 = NULL,*tail2 = NULL;
    int choice,element;

    for(;;)
    {
        printf("------------------------------------------------------------------\n");
        printf("1 - Insert in List-1\n2 - Insert in Lisy-2\n3 - Concatenate\n4 - Exit\n");
        scanf("%d",&choice);
        printf("------------------------------------------------------------------\n");

        switch(choice)
        {
            case 1 : printf("Enter element:");
                     scanf("%d",&element);
                     insert_front(&tail1,element); break;

            case 2 : printf("Enter element:");
                     scanf("%d",&element);
                     insert_front(&tail2,element);break;

            case 3 : Concatenate(tail1,tail2); break;

            case 4 : exit(0);

            default : printf("Invalid Input\n"); break;
        }

    }

}