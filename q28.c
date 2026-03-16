/*Circular Linked List Creation and Traversal - Implement using linked list with dynamic memory allocation.*/
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct Node* insert(struct Node* head, int data) {

    struct Node* newNode = createNode(data);

    if (head == NULL) {
        head = newNode;
        newNode->next = head;
        return head;
    }

    struct Node* temp = head;

    while (temp->next != head)
        temp = temp->next;

    temp->next = newNode;
    newNode->next = head;

    return head;
}

void traverse(struct Node* head) {

    if (head == NULL)
        return;

    struct Node* temp = head;

    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
}

int main() {

    int n, x;
    struct Node* head = NULL;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        head = insert(head, x);
    }

    traverse(head);

    return 0;
}