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

Node *reverse(Node *head)
{
    if (!head || !head->next)
        return head;

    Node *curr = head, *prev = NULL, *next = NULL;
    while (curr)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    return prev;
}

Node *rotateLL(Node *head, int n, int k)
{
    if (!head || !head->next)
        return head;

    head = reverse(head);
    k = k % n;

    Node *curr = head, *prev = NULL, *next = NULL;
    for (int i = 0; i < n - k; i++)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    head->next = reverse(curr);

    return prev;
}

int main()
{

    int n;
    printf("Enter the number of Nodes: ");
    scanf("%d", &n);
    if (n == 0)
        return 0;
    int k;
    printf("Enter the value of K: ");
    scanf("%d", &k);

    Node *head = NULL;
    head = getLinkedList(head, n);

    head = rotateLL(head, n, k);

    printf("After rotating:\n");
    display(head);

    return 0;
}