/*
Description: Implementing Queue using two Stacks. The program will take the number of operations as input and then it will take the choice of operation from the user. The operations are as follows:
1. Enqueue - To enqueue an element into the queue
2. Dequeue - To dequeue an element from the queue
3. Peek - To get the front element of the queue
4. Size - To get the size of the queue
5. isEmpty - To check if the queue is empty or not

The program will perform the operations as per the choice of the user and will print the output accordingly.

Time Complexity: O(n) for dequeue and peek operations, O(1) for enqueue operation
Space Complexity: O(n) where n is the size of the queue
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 1001

typedef struct Stack
{
    int top;
    int arr[MAX];
} Stack;

Stack *initializeStack(Stack *s)
{
    s = (Stack *)malloc(sizeof(Stack));
    s->top = -1;
    return s;
}

int isEmpty(Stack *s)
{
    return s->top == -1;
}

void push(Stack *s, int x)
{
    if (s->top == MAX - 1)
    {
        printf("Stack Overflow\n");
        return;
    }
    s->arr[++s->top] = x;
}

int pop(Stack *s)
{
    if (s->top == -1)
    {
        printf("Stack Underflow\n");
        return -1;
    }
    return s->arr[s->top--];
}

void enqueue(Stack *s, int x)
{
    push(s, x);
}

int dequeue(Stack *s1, Stack *s2)
{
    if (isEmpty(s1))
    {
        printf("Queue is Empty\n");
        return -1;
    }
    while (!isEmpty(s1))
    {
        push(s2, pop(s1));
    }
    int x = pop(s2);
    while (!isEmpty(s2))
    {
        push(s1, pop(s2));
    }
    return x;
}

int peek(Stack *s1, Stack *s2)
{
    if (isEmpty(s1))
    {
        printf("Queue is Empty\n");
        return -1;
    }
    while (!isEmpty(s1))
    {
        push(s2, pop(s1));
    }

    int x = s2->arr[s2->top];
    while (!isEmpty(s2))
    {
        push(s1, pop(s2));
    }

    return x;
}

int getSize(Stack *s)
{
    return s->top + 1;
}

int main()
{

    Stack *s1 = NULL;
    s1 = initializeStack(s1);
    Stack *s2 = NULL;
    s2 = initializeStack(s2);

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
            printf("Enter the element to Enqueue: ");
            scanf("%d", &x);
            enqueue(s1, x);
            break;
        case 2:
            x = dequeue(s1, s2);
            if (x != -1)
            {
                printf("Dequeued Element: %d\n", x);
            }
            break;
        case 3:
            x = peek(s1, s2);
            if (x != -1)
            {
                printf("Front Element: %d\n", x);
            }
            break;
        case 4:
            printf("Size of Queue: %d\n", getSize(s1));
            break;

        case 5:
            if (isEmpty(s1))
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