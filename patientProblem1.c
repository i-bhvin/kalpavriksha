#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {
    CRITICAL = 1,
    SERIOUS,
    STABLE,
    INVALID
} Severity;

typedef struct Node {
    int id;
    Severity status;
    struct Node *next;
} Node;

const char* severityToString(Severity status) {
    switch (status) {
        case CRITICAL: return "Critical";
        case SERIOUS: return "Serious";
        case STABLE: return "Stable";
        default: return "Invalid";
    }
}

Severity getSeverity(const char *status) {
    if (strcmp(status, "Critical") == 0)
        return CRITICAL;
    else if (strcmp(status, "Serious") == 0)
        return SERIOUS;
    else if (strcmp(status, "Stable") == 0)
        return STABLE;
    else
        return INVALID;
}

Node *createNode(int val, Severity status) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->id = val;
    newNode->status = status;
    newNode->next = NULL;
    return newNode;
}

Node *insertAtEnd(Node *head, int id, Severity status) {
    if (head == NULL)
        return createNode(id, status);

    Node *newNode = createNode(id, status);
    Node *curr = head;
    while (curr->next)
        curr = curr->next;

    curr->next = newNode;
    return head;
}

Node *getLinkedList(Node *head, int n) {
    for (int i = 0; i < n; i++) {
        int id;
        char statusStr[101];
        printf("Enter the id and status of the patient: ");
        scanf("%d %s", &id, statusStr);

        Severity status = getSeverity(statusStr);
        if (status == INVALID) {
            printf("Enter a valid severity status\n");
            i--;
            continue;
        }

        int isExist = 0;
        Node *curr = head;
        while (curr) {
            if (curr->id == id) {
                isExist = 1;
                break;
            }
            curr = curr->next;
        }

        if (isExist) {
            printf("Duplicate ID detected!! Enter a Unique patient ID\n");
            i--;
        } else {
            head = insertAtEnd(head, id, status);
        }
    }
    return head;
}

void display(Node *head) {
    while (head) {
        printf("%d %s\n", head->id, severityToString(head->status));
        head = head->next;
    }
}

Node *merge(Node *first, Node *second) {
    if (first == NULL)
        return second;
    if (second == NULL)
        return first;

    Node *result = NULL;
    if (first->status <= second->status) {
        result = first;
        result->next = merge(first->next, second);
    } else {
        result = second;
        result->next = merge(first, second->next);
    }
    return result;
}

Node *mergeSort(Node *head) {
    if (head == NULL || head->next == NULL)
        return head;

    Node *slow = head, *fast = head->next;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    fast = slow->next;
    slow->next = NULL;

    Node *first = mergeSort(head);
    Node *second = mergeSort(fast);

    return merge(first, second);
}

int main() {
    Node *head = NULL;
    int n;
    printf("Enter the number of patients: ");
    scanf("%d", &n);
    if (n == 0)
        return 0;

    head = getLinkedList(head, n);
    head = mergeSort(head);

    printf("\nPatients will be treated in order:\n");
    display(head);

    return 0;
}
