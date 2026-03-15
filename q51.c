/* Day 51 - Question 1: Lowest Common Ancestor in BST
   Find the LCA of two nodes n1 and n2 in a BST.
   Uses BST ordering: if both nodes are smaller go left, if both larger go right,
   otherwise current node is the LCA. */
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

struct Node* insert(struct Node* root, int data) {
    if (root == NULL) return createNode(data);
    if (data < root->data) root->left = insert(root->left, data);
    else if (data > root->data) root->right = insert(root->right, data);
    return root;
}

struct Node* LCA(struct Node* root, int n1, int n2) {
    while (root != NULL) {
        if (n1 < root->data && n2 < root->data)
            root = root->left;
        else if (n1 > root->data && n2 > root->data)
            root = root->right;
        else
            return root;
    }
    return NULL;
}

int main() {
    int n, value, n1, n2;
    scanf("%d", &n);

    struct Node* root = NULL;
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        root = insert(root, value);
    }

    scanf("%d %d", &n1, &n2);

    struct Node* lca = LCA(root, n1, n2);
    if (lca)
        printf("LCA: %d\n", lca->data);
    else
        printf("LCA not found\n");

    return 0;
}
