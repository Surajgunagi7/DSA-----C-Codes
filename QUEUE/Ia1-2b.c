#include <stdio.h>

#define MAX_CUSTOMERS 10

int customerQueue[MAX_CUSTOMERS];
int front = -1, rear = -1;

// Function to check if the queue is empty
int isEmpty() {
    return front == -1 && rear == -1;
}

// Function to enqueue a customer
void enqueue(int customer) {
    if((rear + 1) % MAX_CUSTOMERS == front) {
        printf("Queue is full. Cannot add more customers.\n");
    } else {
        if (isEmpty()) {
            front = 0;
        }
        rear = (rear + 1) % MAX_CUSTOMERS;
        customerQueue[rear] = customer;
    }
}

// Function to dequeue a customer
int dequeue() {
    int customer = -1; // Indicates an empty customer
    if (isEmpty()) {
        printf("Queue is empty. No customers to dequeue.\n");
    } else {
        customer = customerQueue[front];
        if (front == rear) {
            // Last customer is dequeued, reset the queue
            front = rear = -1;
        } else {
            front = (front + 1) % MAX_CUSTOMERS;
        }
    }
    return customer;
}

int main() {
    int numCustomers;
    printf("Enter the number of customers: ");
    scanf("%d", &numCustomers);

    // Enqueue customers with tokens
    for (int i = 1; i <= numCustomers; ++i) {
        enqueue(i);
    }

    // Process customers in order
    while (!isEmpty()) {
        int currentCustomer = dequeue();
        if(currentCustomer != -1) {
            printf("Processing customer with token %d\n", currentCustomer);
            
        }
    }

    return 0;
}
