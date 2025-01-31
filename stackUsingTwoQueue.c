/*
Description: Implement Stack using two Queues. The program will take the number of operations as input and then it will take the choice of operation from the user. The operations are as follows:
1. Push - To push an element into the stack
2. Pop - To pop an element from the stack
3. Peek - To get the top element of the stack
4. Size - To get the size of the stack
5. isEmpty - To check if the stack is empty or not

The program will perform the operations as per the choice of the user and will print the output accordingly.

Time Complexity: O(n) for pop and peek operations, O(1) for push operation
Space Complexity: O(n) where n is the size of the stack
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

int isEmpty(Queue *q)
{
    return q->front == -1 && q->rear == -1;
}

int isFull(Queue *q)
{
    return (q->rear + 1) % MAX == q->front;
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

void push(Queue *q, int x)
{
    if (isFull(q))
    {
        printf("Stack Overflow\n");
        return;
    }
    enqueue(q, x);
}

int pop(Queue *q1, Queue *q2)
{
    if (isEmpty(q1))
    {
        printf("Stack is Empty\n");
        return -1;
    }

    int itr = getSize(q1) - 1;
    while (itr--)
    {
        int x = dequeue(q1);
        enqueue(q2, x);
    }

    int x = dequeue(q1);

    while (!isEmpty(q2))
    {
        int x = dequeue(q2);
        enqueue(q1, x);
    }

    return x;
}

int peek(Queue *q1, Queue *q2)
{
    if (isEmpty(q1))
    {
        printf("Stack is Empty\n");
        return -1;
    }

    int itr = getSize(q1) - 1;
    while (itr--)
    {
        int x = dequeue(q1);
        enqueue(q2, x);
    }

    int x = dequeue(q1);
    enqueue(q2, x);

    while (!isEmpty(q2))
    {
        int x = dequeue(q2);
        enqueue(q1, x);
    }

    return x;
}

int main()
{

    Queue *q1 = NULL;
    q1 = initilizeQueue(q1);
    Queue *q2 = NULL;
    q2 = initilizeQueue(q2);

    printf("Enter the number of Operations: ");
    int iterations;
    scanf("%d", &iterations);

    while (iterations--)
    {
        printf("1. Push\n2. Pop\n3. Peek\n4. Size\n5. isEmpty\n");
        int choice;
        printf("Enter the choice: ");
        scanf("%d", &choice);
        int x;

        switch (choice)
        {
        case 1:
            printf("Enter the element to push: ");
            scanf("%d", &x);
            push(q1, x);
            break;
        case 2:
            x = pop(q1, q2);
            if (x != -1)
            {
                printf("Popped Element: %d\n", x);
            }
            break;
        case 3:
            x = peek(q1, q2);
            if (x != -1)
            {
                printf("Top Element: %d\n", x);
            }
            break;
        case 4:
            printf("Size of Stack: %d\n", getSize(q1));
            break;
        case 5:
            if (isEmpty(q1))
            {
                printf("Stack is Empty\n");
            }
            else
            {
                printf("Stack is not Empty\n");
            }
            break;
        default:
            printf("Invalid Choice\n");
            break;
        }
    }
    return 0;
}