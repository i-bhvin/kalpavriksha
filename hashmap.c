#include <stdio.h>
#include <stdlib.h>
#define TABLE_SIZE 10

typedef struct Node
{
    int key;
    int value;
    struct Node *next;
} Node;

Node *hashTable[TABLE_SIZE];

int hashFunction(int value)
{
    return value % TABLE_SIZE;
}

void insert(int key, int value)
{
    int index = hashFunction(key);
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->key = key;
    newNode->value = value;
    newNode->next = NULL;
    if (hashTable[index] == NULL)
    {
        hashTable[index] = newNode;
    }
    else
    {
        Node *temp = hashTable[index];
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void search(int key)
{
    int index = hashFunction(key);
    Node *temp = hashTable[index];
    while (temp != NULL)
    {
        if (temp->key == key)
        {
            printf("Value: %d\n", temp->value);
            return;
        }
        temp = temp->next;
    }
    printf("Key Not found\n");
}

void delete(int key)
{
    int index = hashFunction(key);
    Node *temp = hashTable[index];
    Node *prev = NULL;
    while (temp)
    {
        if (temp->key == key)
        {
            if (prev == NULL)
            {
                hashTable[index] = temp->next;
            }
            else
            {
                prev->next = temp->next;
            }
            free(temp);
            printf("Key %d deleted\n", key);
            return;
        }
        prev = temp;
        temp = temp->next;
    }
    printf("Key Not found\n");
}

void display()
{
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        if (hashTable[i] != NULL)
        {
            printf("Index %d: ", i);
            Node *curr = hashTable[i];
            while (curr)
            {
                printf("(%d, %d)", curr->key, curr->value);
                curr = curr->next;
                if (curr)
                {
                    printf("->");
                }
            }
            printf("\n");
        }
    }
}

int main()
{

    while (1)
    {
        printf("\n1. Insert\n2. Search\n3. Delete\n4. Display\n5. Exit\n");
        int choice;
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter key: ");
            int key;
            scanf("%d", &key);
            printf("Enter value: ");
            int value;
            scanf("%d", &value);
            insert(key, value);
            break;
        case 2:
            printf("Enter key: ");
            int searchKey;
            scanf("%d", &searchKey);
            search(searchKey);
            break;
        case 3:
            printf("Enter key: ");
            int deleteKey;
            scanf("%d", &deleteKey);
            delete (deleteKey);
            break;
        case 4:
            display();
            break;
        case 5:
            printf("Exiting Program");
            exit(0);
            break;
        default:
            printf("Invalid choice\n");
        }
    }
    return 0;
}
