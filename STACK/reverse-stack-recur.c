#include <stdio.h>
#include <stdlib.h>

// Maximum size of the stack
#define MAX_SIZE 100

// Global variables
int stack[MAX_SIZE];
int top = -1;

// Function to check if the stack is full
void push(int data) {
    if (top == MAX_SIZE - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = data;
}
int pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        exit(0);
    }
    return stack[top--];
}

void insertAtBottom(int data) {
    if (top == -1) {    /* When stack is empty add the incoming element */
        push(data);
        return;
    }
    /* If not Pop till stack is empty using recurrsion & after the addition of the incoming element Push all the Poped element back into the stack */
    int temp = pop();
    insertAtBottom(data);

    push(temp);
}
void reverseStack() {
    if (top == -1) {
        return;
    }
    /* Pop and store it in the Function call stack , until the stack is empty */
    int temp = pop();
    reverseStack();

    /* When stack is empty Start inserting the last poped element in the Stack at bottom */
    insertAtBottom(temp); /* By using same Recurrsion principle */
}

void printStack() {
    printf("Stack: ");
    for (int i = 0; i <= top; i++) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

int main() {
    
    int choice,element;
    for(;;)
    {
        printf("1 - push\n2 - pop\n3 - reverse\n4 - Exit\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: printf("Enter element:");
                    scanf("%d",&element);
                    push(element); break;
            case 2: element = pop();
                    printf("Poped Element:%d\n",element); break;
            case 3: printf("Original ");
                    printStack();

                    reverseStack();

                    printf("Reversed ");
                    printStack(); 
                    exit(0);
            case 4: exit(0); 
        }
    }

    return 0;
}
