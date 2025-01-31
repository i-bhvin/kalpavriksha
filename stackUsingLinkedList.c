/*
Description: Stack Implementation using Linked List. The program will take the number of operations as input and then it will take the choice of operation from the user. The operations are as follows:
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

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node *createNode(int x)
{
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->data = x;
    temp->next = NULL;
    return temp;
}

Node *push(Node *top, int x)
{
    Node *temp = createNode(x);
    temp->next = top;
    top = temp;
    return top;
}

int pop(Node **top)
{
    if (isEmpty(*top))
    {
        printf("Stack Underflow\n");
        return -1;
    }
    Node *temp = *top;
    *top = (*top)->next;
    int x = temp->data;
    free(temp);
    return x;
}

int peek(Node *top)
{
    if (isEmpty(top))
    {
        printf("Stack is Empty\n");
        return -1;
    }
    return top->data;
}

int isEmpty(Node *top)
{
    return top == NULL;
}

int getSize(Node *top)
{
    int count = 0;
    while (top != NULL)
    {
        count++;
        top = top->next;
    }
    return count;
}

int main()
{

    Node *top = NULL;
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
            top = push(top, x);
            break;
        case 2:
            x = pop(&top);
            if (x != -1)
                printf("Popped Element: %d\n", x);
            break;
        case 3:
            x = peek(top);
            if (x != -1)
                printf("Top Element: %d\n", top->data);
            break;
        case 4:
            printf("Size of Stack: %d\n", getSize(top));
            break;
        case 5:
            if (isEmpty(top))
                printf("Stack is Empty\n");
            else
                printf("Stack is not Empty\n");
            break;
        default:
            printf("Invalid Choice\n");
        }
    }

    return 0;
}