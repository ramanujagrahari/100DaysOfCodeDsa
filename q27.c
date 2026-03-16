/*Find Intersection Point of Two Linked Lists - Implement using linked list with dynamic memory allocation.
*/
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Create new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Insert at end
struct Node* insert(struct Node* head, int data) {
    struct Node* newNode = createNode(data);

    if (head == NULL)
        return newNode;

    struct Node* temp = head;

    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;

    return head;
}

// Find length of list
int length(struct Node* head) {
    int count = 0;

    while (head != NULL) {
        count++;
        head = head->next;
    }

    return count;
}

// Find intersection
int findIntersection(struct Node* head1, struct Node* head2) {

    int len1 = length(head1);
    int len2 = length(head2);

    int diff = abs(len1 - len2);

    struct Node *p1 = head1;
    struct Node *p2 = head2;

    // Move pointer of longer list
    if (len1 > len2) {
        for (int i = 0; i < diff; i++)
            p1 = p1->next;
    }
    else {
        for (int i = 0; i < diff; i++)
            p2 = p2->next;
    }

    // Traverse together
    while (p1 != NULL && p2 != NULL) {

        if (p1->data == p2->data)
            return p1->data;

        p1 = p1->next;
        p2 = p2->next;
    }

    return -1;
}

int main() {

    int n, m, x;

    struct Node *head1 = NULL;
    struct Node *head2 = NULL;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        head1 = insert(head1, x);
    }

    scanf("%d", &m);

    for (int i = 0; i < m; i++) {
        scanf("%d", &x);
        head2 = insert(head2, x);
    }

    int result = findIntersection(head1, head2);

    if (result == -1)
        printf("No Intersection");
    else
        printf("%d", result);

    return 0;
}