/* Day 62 - Question 1: Graph Representation Using Adjacency List
   Read a graph with n vertices and m edges, store it as an adjacency list,
   and print the list for each vertex. */
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int vertex;
    struct Node* next;
};

struct Node* adj[105];

struct Node* createNode(int v) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->vertex = v;
    node->next = NULL;
    return node;
}

void addEdge(int u, int v) {
    /* Add v to u's list */
    struct Node* node = createNode(v);
    node->next = adj[u];
    adj[u] = node;

    /* Add u to v's list (undirected) */
    node = createNode(u);
    node->next = adj[v];
    adj[v] = node;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    for (int i = 1; i <= n; i++)
        adj[i] = NULL;

    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(u, v);
    }

    /* Print adjacency list */
    for (int i = 1; i <= n; i++) {
        printf("%d: ", i);
        struct Node* temp = adj[i];
        while (temp != NULL) {
            printf("%d ", temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }

    return 0;
}
