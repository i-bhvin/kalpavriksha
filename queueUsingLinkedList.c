/*
Description: This is a program to implement Queue using Linked List. The program will take the number of operations as input and then it will take the choice of operation from the user. The operations are as follows:
1. Enqueue - To enqueue an element into the queue
2. Dequeue - To dequeue an element from the queue
3. Peek - To get the front element of the queue
4. Size - To get the size of the queue
5. isEmpty - To check if the queue is empty or not

The program will perform the operations as per the choice of the user and will print the output accordingly.

Time Complexity: O(1) for all operations
Space Complexity: O(n) where n is the size of the queue
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

typedef struct Queue
{
    Node *front, *rear;
} Queue;

Queue *initializeQueue(Queue *q)
{
    q = (Queue *)malloc(sizeof(Queue));
    q->front = q->rear = NULL;
    return q;
}

Node *createNode(int value)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

void enqueue(Queue *q, int x)
{
    Node *newNode = createNode(x);
    if (q->front == NULL && q->rear == NULL)
    {
        q->front = q->rear = newNode;
        return;
    }
    q->rear->next = newNode;
    q->rear = newNode;
}

int dequeue(Queue *q)
{
    if (q->front == NULL)
    {
        printf("Queue is Empty\n");
        return -1;
    }
    Node *temp = q->front;
    q->front = q->front->next;
    int x = temp->data;
    free(temp);
    return x;
}

int peek(Queue *q)
{
    if (q->front == NULL)
    {
        printf("Queue is Empty\n");
        return -1;
    }
    return q->front->data;
}

int getSize(Queue *q)
{
    int count = 0;
    Node *temp = q->front;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

int isEmpty(Queue *q)
{
    return q->front == NULL;
}
int main()
{

    Queue *q = NULL;
    q = initializeQueue(q);

    printf("Enter the number of Operations: ");
    int iterations;
    scanf("%d", &iterations);

    while (iterations--)
    {
        printf("1. Enqueue\n2. Dequeue\n3. Peek\n4. Size\n5. isEmpty\n");
        int choice;
        printf("Enter the choice: ");
        scanf("%d", &choice);
        int x;

        switch (choice)
        {
        case 1:
            printf("Enter the value to Enqueue: ");
            scanf("%d", &x);
            enqueue(q, x);
            break;
        case 2:
            x = dequeue(q);
            if (x != -1)
            {
                printf("Dequeued Element: %d\n", x);
            }
            break;
        case 3:
            x = peek(q);
            if (x != -1)
            {
                printf("Peeked Element: %d\n", x);
            }
            break;
        case 4:
            printf("Size of Queue: %d\n", getSize(q));
            break;
        case 5:
            if (isEmpty(q))
            {
                printf("Queue is Empty\n");
            }
            else
            {
                printf("Queue is not Empty\n");
            }
            break;
        default:
            printf("Invalid Choice\n");
            break;
        }
    }

    return 0;
}