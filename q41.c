/* Day 41 - Question 1: Queue Using Linked List
   Implement a queue using a linked list with enqueue and dequeue operations.
   FIFO principle with dynamic memory allocation. */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* Node structure */
typedef struct Node {
    int data;
    struct Node* next;
} Node;

/* Queue structure */
typedef struct myQueue {
    int currSize;
    Node* front;
    Node* rear;
} myQueue;

Node* newNode(int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    if (node == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    node->data = data;
    node->next = NULL;
    return node;
}

myQueue* createQueue() {
    myQueue* q = (myQueue*)malloc(sizeof(myQueue));
    if (q == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    q->front = NULL;
    q->rear = NULL;
    q->currSize = 0;
    return q;
}

bool isEmpty(myQueue* q) {
    return q->front == NULL;
}

void enqueue(myQueue* q, int data) {
    Node* node = newNode(data);
    if (isEmpty(q)) {
        q->front = q->rear = node;
    } else {
        q->rear->next = node;
        q->rear = node;
    }
    q->currSize++;
}

int dequeue(myQueue* q) {
    if (isEmpty(q)) {
        return -1;
    }
    Node* temp = q->front;
    int removedData = temp->data;
    q->front = q->front->next;
    if (q->front == NULL)
        q->rear = NULL;
    free(temp);
    q->currSize--;
    return removedData;
}

int main() {
    myQueue* q = createQueue();
    int n, value;

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        enqueue(q, value);
    }

    /* Dequeue and print all elements */
    while (!isEmpty(q)) {
        printf("%d ", dequeue(q));
    }
    printf("\n");

    free(q);
    return 0;
}
