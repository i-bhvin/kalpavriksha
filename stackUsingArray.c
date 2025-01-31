/*

Description: This is a program to implement Stack using Array. The program will take the number of operations as input and then it will take the choice of operation from the user. The operations are as follows:
1. Push - To push an element into the stack
2. Pop - To pop an element from the stack
3. Peek - To get the top element of the stack
4. Size - To get the size of the stack
5. isEmpty - To check if the stack is empty or not

The program will perform the operations as per the choice of the user and will print the output accordingly.

Time Complexity: O(1) for all operations
Space Complexity: O(n) where n is the size of the stack
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

int peek(Stack *s)
{
    if (s->top == -1)
    {
        printf("Stack is Empty\n");
        return -1;
    }
    return s->arr[s->top];
}

int getSize(Stack *s)
{
    return s->top + 1;
}

int isEmpty(Stack *s)
{
    return s->top == -1;
}

int main()
{

    Stack *s = NULL;
    s = initializeStack(s);
    int q;
    printf("Enter the number of Operations: ");
    scanf("%d", &q);

    while (q--)
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
            push(s, x);
            break;
        case 2:
            x = pop(s);
            if (x != -1)
            {
                printf("Popped Element: %d\n", x);
            }
            break;
        case 3:
            x = peek(s);
            if (x != -1)
            {
                printf("Top Element: %d\n", x);
            }
            break;
        case 4:
            x = getSize(s);
            printf("Size of Stack: %d\n", x);
            break;
        case 5:
            if (isEmpty(s))
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
        }
    }

    return 0;
}
