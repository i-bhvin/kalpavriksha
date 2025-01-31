/*
Description: This is a program to implement Queue using Array. The program will take the number of operations as input and then it will take the choice of operation from the user. The operations are as follows:
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
#define MAX 1001

typedef struct Queue
{
    int front, rear;
    int arr[MAX];
} Queue;

Queue *initilizeQueue(Queue *q)
{
    q = (Queue *)malloc(sizeof(Queue));
    q->front = q->rear = -1;
    return q;
}

int isFull(Queue *q)
{
    return (q->rear + 1) % MAX == q->front;
}

int isEmpty(Queue *q)
{
    return (q->front == -1 && q->rear == -1);
}

void enqueue(Queue *q, int x)
{
    if (isFull(q))
    {
        printf("Queue Overflow\n");
        return;
    }
    else if (isEmpty(q))
    {
        q->front = q->rear = 0;
        q->arr[q->rear] = x;
    }
    else
    {
        q->rear = (q->rear + 1) % MAX;
        q->arr[q->rear] = x;
    }
}

int dequeue(Queue *q)
{
    if (isEmpty(q))
    {
        printf("Queue Underflow\n");
        return -1;
    }
    int x = -1;
    if (q->front == q->rear)
    {
        x = q->arr[q->front];
        q->front = q->rear = -1;
    }
    else
    {
        x = q->arr[q->front];
        q->front = (q->front + 1) % MAX;
    }
    return x;
}

int peek(Queue *q)
{
    if (isEmpty(q))
    {
        printf("Queue is Empty\n");
        return -1;
    }
    return q->arr[q->front];
}

int getSize(Queue *q)
{
    if (isEmpty(q))
    {
        return 0;
    }
    if (q->front <= q->rear)
    {
        return q->rear - q->front + 1;
    }
    else
    {
        return MAX - q->front + q->rear + 1;
    }
}

int main()
{
    Queue *q = NULL;
    q = initilizeQueue(q);

    int iterations;
    printf("Enter the number of Operations: ");
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
            printf("Enter the element to Enqueue: ");
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
                printf("Front Element: %d\n", x);
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
            break;
        }
    }
    return 0;
}