/* Day 52 - Question 1: LCA in Binary Tree
   Find the Lowest Common Ancestor of two nodes in a general binary tree.
   Uses recursive approach: if both sides return non-NULL, current node is LCA. */
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
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

struct Node* LCA(struct Node* root, int n1, int n2) {
    if (root == NULL) return NULL;
    if (root->data == n1 || root->data == n2) return root;

    struct Node* left = LCA(root->left, n1, n2);
    struct Node* right = LCA(root->right, n1, n2);

    if (left != NULL && right != NULL) return root;
    if (left != NULL) return left;
    return right;
}

int main() {
    int n, n1, n2;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    scanf("%d %d", &n1, &n2);

    struct Node* root = buildTree(arr, n);
    struct Node* lca = LCA(root, n1, n2);

    if (lca)
        printf("LCA: %d\n", lca->data);
    else
        printf("LCA not found\n");

    return 0;
}
