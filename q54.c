/* Day 54 - Question 1: Zigzag Traversal
   Print binary tree nodes in zigzag (alternating left-to-right and right-to-left)
   level order traversal. */
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

void zigzagTraversal(struct Node* root) {
    if (root == NULL) return;

    struct Node* q[1000];
    int front = 0, rear = 0;
    q[rear++] = root;

    int leftToRight = 1;

    while (front < rear) {
        int size = rear - front;
        int level[1000];

        for (int i = 0; i < size; i++) {
            struct Node* temp = q[front++];
            int index;

            if (leftToRight)
                index = i;
            else
                index = size - i - 1;

            level[index] = temp->data;

            if (temp->left != NULL)
                q[rear++] = temp->left;
            if (temp->right != NULL)
                q[rear++] = temp->right;
        }

        for (int i = 0; i < size; i++)
            printf("%d ", level[i]);
        printf("\n");

        leftToRight = !leftToRight;
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    struct Node* root = buildTree(arr, n);
    zigzagTraversal(root);

    return 0;
}
