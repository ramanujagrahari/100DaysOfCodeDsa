/* Day 53 - Question 1: Print Binary Tree Vertical Order
   Print nodes of a binary tree grouped by their horizontal distance from root.
   Uses BFS with horizontal distance tracking. */
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

struct Node* buildTree(int arr[], int n) {
    if (n == 0) return NULL;

    struct Node* root = createNode(arr[0]);
    struct Node* queue[n];
    int front = 0, rear = 0;

    queue[rear++] = root;
    int i = 1;

    while (i < n) {
        struct Node* current = queue[front++];

        if (i < n) {
            current->left = createNode(arr[i++]);
            queue[rear++] = current->left;
        }
        if (i < n) {
            current->right = createNode(arr[i++]);
            queue[rear++] = current->right;
        }
    }
    return root;
}

struct Pair {
    struct Node* node;
    int hd;
};

void verticalOrder(struct Node* root) {
    if (root == NULL) return;

    struct Pair q[1000];
    int front = 0, rear = 0;

    int hdArr[1000];
    int valArr[1000];
    int count = 0;

    q[rear].node = root;
    q[rear].hd = 0;
    rear++;

    while (front < rear) {
        struct Pair cur = q[front++];
        struct Node* temp = cur.node;
        int hd = cur.hd;

        hdArr[count] = hd;
        valArr[count] = temp->data;
        count++;

        if (temp->left != NULL) {
            q[rear].node = temp->left;
            q[rear].hd = hd - 1;
            rear++;
        }

        if (temp->right != NULL) {
            q[rear].node = temp->right;
            q[rear].hd = hd + 1;
            rear++;
        }
    }

    for (int i = -100; i <= 100; i++) {
        int printed = 0;
        for (int j = 0; j < count; j++) {
            if (hdArr[j] == i) {
                printf("%d ", valArr[j]);
                printed = 1;
            }
        }
        if (printed)
            printf("\n");
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    struct Node* root = buildTree(arr, n);
    verticalOrder(root);

    return 0;
}
