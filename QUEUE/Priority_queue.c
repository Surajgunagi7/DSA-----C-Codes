    #include<stdio.h>
    #include<stdlib.h>
    #define N 3     /* Marco Definition of Size of the Queue */

    struct Queues {     /* Struct Definition */
        int info[N];
        int front,rear;
    };
    struct Queues Queue1,Queue2,Queue3;  /* Decalartion of three Queues of type Struct Queues */

    void initialize(struct Queues *Q)   /* Function to initialize a Queue*/
    {
        Q->front = -1;
        Q->rear = -1;
    }
    void insert(struct Queues *Q,int x)     /* Function to insert an element */
    {
        if(Q->front == -1 && Q->rear == -1){    /* Queue empty condition */
            Q->front = 0;
        }
        Q->rear = (Q->rear + 1) % N;     /* Incrementing and inserting the element into the Queue */
        Q->info[Q->rear] = x;
    }
    void enqueue(int element)   /* Function to check Queue full Condition and if not call Enqueue() for insertion */
    {
        if(Queue1.front != ((Queue1.rear + 1) % N))
            insert(&Queue1,element);
        else if(Queue2.front != ((Queue2.rear + 1) % N))
            insert(&Queue2,element);
        else if(Queue3.front != ((Queue3.rear + 1) % N))
            insert(&Queue3,element);
        else
            printf("Queues are full..\n");
    }
    void delete(struct Queues *Q)  /* Function to Delete an element */
    {
        if(Q->front == Q->rear){    /* Check's if Only One element present in the Queue*/
            printf("Deleted Element : %d\n",Q->info[Q->front]);
            initialize(Q);          /* Reset the Queue After deletion */
        }
        else{
            printf("Deleted Element : %d\n",Q->info[Q->front]);
            Q->front = (Q->front + 1) % N;  /* Incrementing front to point to next element */
        }   
    }
    void dequeue()   /* Function to check for Queue empty condition ,if not calls the Dequeue() for Deletion */
    {
        if(Queue1.rear != -1 && Queue1.front != -1)
            delete(&Queue1);
        else if(Queue2.rear != -1 && Queue2.front != -1)
            delete(&Queue2);
        else if(Queue3.rear != -1 && Queue3.front != -1)
            delete(&Queue3);
        else
            printf("Queue Empyt..\n");
    }
    void Display() {
        /* Array of pointers to Queues structures, representing Queue1, Queue2, and Queue3 */
        struct Queues *ptr[] = {&Queue1,&Queue2,&Queue3};
        int i;
        if((Queue1.front == -1 && Queue1.rear == -1) &&
        (Queue2.front == -1 && Queue2.rear == -1) &&         /* Check if all queues are empty */
        (Queue3.front == -1 && Queue3.rear == -1))   {

                printf("Queue Empty..\n");
        }
        else{
            for(i = 0; i < 3; i++) 
            {
                if(ptr[i]->front != -1 && ptr[i]->rear != -1)       /*  Check if the current Queue is not empty */
                {
                    printf("Queue %d : ",i+1);
                    int index = ptr[i]->front;      /* Initialize index with the front of the current Queue */
                    do {                                          /* Traverse the Queue and print elements */
                        printf("%d ", ptr[i]->info[index]);
                        index = (index + 1) % N;
                    } while (index != (ptr[i]->rear + 1) % N);
                    printf("\n");
                }
            }
        }
        printf("\n");
    }
    void main()
    {
        int response,Element;
        /* Initialization of all the Queues */
        initialize(&Queue1);
        initialize(&Queue2);
        initialize(&Queue3);

        for(;;)
        {
            printf("1 - Enqueue\n2 - Dequeue\n3 - Display\n4 - exit\n");
            scanf("%d",&response);
            switch(response)
            {
                case 1 : printf("Enter Element :");
                        scanf("%d",&Element);
                        enqueue(Element); break;
                case 2 : dequeue(); break;
                case 3 : Display(); break;
                case 4 : exit(0);
                default : printf("Invalid input..\n");
            }
        }
    }