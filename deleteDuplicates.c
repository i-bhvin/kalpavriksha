// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node *createNode(int val)
{
    Node *newNode = (Node *)malloc(sizeof(Node));

    newNode->data = val;
    newNode->next = NULL;

    return newNode;
}

Node *insertAtEnd(Node *head, int val)
{
    if (head == NULL)
    {
        return createNode(val);
    }

    Node *newNode = createNode(val);

    Node *curr = head;
    while (curr->next)
        curr = curr->next;

    curr->next = newNode;

    return head;
}

Node *getLinkedList(Node *head, int n)
{
    int v;
    printf("Enter the Elements: ");
    while (n--)
    {
        scanf("%d", &v);
        head = insertAtEnd(head, v);
    }

    return head;
}

void display(Node *head)
{
    while (head)
    {
        printf("%d ", head->data);
        head = head->next;
    }
}

Node *deleteDuplicates(Node *head)
{
    if (!head || !head->next)
        return head;

    Node *prev = head, *curr = head->next;

    while (curr)
    {
        while (curr && curr->data == prev->data)
            curr = curr->next;

        prev->next = curr;
        prev = curr;
    }

    return head;
}

int main()
{

    int n;
    printf("Enter the number of Nodes: ");
    scanf("%d", &n);
    if (n == 0)
        return 0;

    Node *head = NULL;
    head = getLinkedList(head, n);

    head = deleteDuplicates(head);

    printf("LinkedList after deleting the duplicates:\n");
    display(head);

    return 0;
}