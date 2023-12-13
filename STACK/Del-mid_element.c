#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

int stack[MAX_SIZE];
int top = -1;


void push(int data) {
    if (top == MAX_SIZE - 1) {
        printf("Stack Overflow\n");
        exit(EXIT_FAILURE);
    }
    stack[++top] = data;
}

int pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        exit(EXIT_FAILURE);
    }
    return stack[top--];
}

void deleteMiddleRecursive(int n, int middle) {
    // Base case: reached the middle element
    if (n == middle) {
        pop(); // Skip the middle element
        return;
    }

    int temp = pop();
    deleteMiddleRecursive(n + 1, middle);

    // Push back the element after reaching the middle
    push(temp);
}

// Function to delete the middle element of the stack (wrapper function)
void deleteMiddle() {
    int middle = (top + 1) / 2;
    
    if (top == -1) {
        printf("Stack is empty, cannot delete middle element.\n");
        exit(EXIT_FAILURE);
    }

    deleteMiddleRecursive(0, middle);
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
        printf("1 - push\n2 - pop\n3 - Del_middle\n4 - Exit\n");
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

                    deleteMiddle(); 

                    printf("Reversed ");
                    printStack(); 
                    exit(0);
            case 4: exit(0); 
        }
    }

}
