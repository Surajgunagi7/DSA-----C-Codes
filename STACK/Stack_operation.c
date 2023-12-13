#include<stdio.h>
#include<stdlib.h>
#define MAX 5  /* Defining the size of the Stcak */

int stack[MAX],top = -1;

void push(int x)   /* Push Operation function */
{
        if(top == MAX -1)   /* stackoverflow condition */
                printf("StcakOverflow..Push Operation Failed\n");
        else
                stack[++top] = x; /* incrementing the index and assinging the elements */
}

int pop() /* Pop operation function */
{
        if(top == -1)  /* Stack Empty Condition */
                return 0;
        else
                return stack[top--]; /* Returning the element and decrementing the index of the stack */
}

void display()   /* Display function - Display the contents of the Stcak */
{
        int i;
        if(top == -1)
                printf("Stack Empty\n");
        else
                printf("\nContents of the Stack\n"); 
                for(i = 0;i <= top; i++)
                        printf("%d\t",*(stack+i));
                printf("\n");
}

int Stacktop()   /* Stack Top element condition */
{
        if(top == -1)
                return 0;
        else
                return stack[top];   /* Only return the stcakTop element */
}
void main()
{
        int choice,y;

        for(;;)
        {
                start :
                printf("\n1 - Push Operation\n2 - Pop Operation\n3 - Display Contents of the Stack\n4 - StcakTop Elemet\n5 - exit\n");
                scanf("%d",&choice);

                switch(choice)
                {
                        case 1 : printf("Input the number to push to the Stack : ");
                                 scanf("%d",&y);
                                 push(y); break;
                        case 2 :if(!(y = pop()))
                                        printf("Stack Empty\n");
                                else
                                        printf("The Pop Element : %d\n",y);
                                break;
                        case 3 : display();
                                 break;
                        case 4 : if(!(y = Stacktop()))
                                        printf("Stcak Empty..\n");
                                 else
                                        printf("The Stack_Top Element ; %d\n",y);
                                 break;
                        case 5 : exit(0);

                        default : printf("Invalid Input\n");
                                         goto start; /* Using goto statement for invalid input */
                }
        }
}
                                        