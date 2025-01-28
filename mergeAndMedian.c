/*
Problem Statement:

Given two sorted linked list of size m and n, the task is to merge them into a single sorted linked list and then find the median of the merged linked list.

If the length of the merged linked list is odd, then the median is the middle element. If the length of the merged linked list is even, then the median is the average of the two middle elements.

time complexity: O(m+n)
space complexity: O(1)

constraints:
0 <= m, n <= 10^3
-10^5 <= Node data <= 10^5

*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
}Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

Node* insertNode(Node* head, int data) {
    Node* newNode = createNode(data);
    if(head == NULL) {
        return newNode;
    }
    Node* temp = head;
    while(temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}

Node* takeInput(Node* head, int n) {
    for(int i = 0; i < n; i++) {
        int data;
        scanf("%d", &data);
        head = insertNode(head, data);
    }
    return head;
}

Node* mergeTwoLists(Node* head1, Node* head2){
    if(!head1) return head2;
    if(!head2) return head1;

    Node* head = createNode(-1); // creating dummy node

    Node* temp = head;

    while(head1 && head2) {
        if(head1->data < head2->data) {
            temp->next = head1;
            head1 = head1->next;
        } else {
            temp->next = head2;
            head2 = head2->next;
        }
        temp = temp->next;
    }
    
    if(head1) {
        temp->next = head1;
    } else {
        temp->next = head2;
    }

    temp = head;
    head = head->next;
    free(temp); // free the dummy node
    return head;
}

int findMedian(Node* head, int n) {
    if(head == NULL) return 0;


    Node* slow = head;
    Node* fast = head->next;

    while(fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    if(n % 2 == 0) {
        return (slow->data + slow->next->data) / 2;
    } else {
        return slow->data;
    }
}

void display(Node* head) {
    Node* temp = head;
    while(temp) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}



int main() {
    int m , n;
    printf("Enter the size of the first linked list: ");
    scanf("%d", &m);
    printf("Enter the size of the second linked list: ");
    scanf("%d", &n);

    Node* head1 = NULL, *head2 = NULL;

    printf("Enter the elements of the first linked list: ");

    head1 = takeInput(head1, m);

    printf("Enter the elements of the second linked list: ");
    
    head2 = takeInput(head2, n);

    Node *head = mergeTwoLists(head1, head2);

    int median = findMedian(head, m + n);

    printf("The resultant linked list is: ");
    display(head);

    printf("The median of the merged linked list is: %d\n", median);


    return 0;
}