/* Day 76 - Question 1: Count Connected Components (Undirected Graph)
   Count the number of connected components in an undirected graph using DFS. */
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int vertex;
    struct Node* next;
};

struct Node* adj[105];
int visited[105];

struct Node* addNode(struct Node* head, int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;

    if (head == NULL)
        return newNode;

    struct Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
    return head;
}

void dfs(int node) {
    visited[node] = 1;
    struct Node* temp = adj[node];

    while (temp != NULL) {
        if (!visited[temp->vertex])
            dfs(temp->vertex);
        temp = temp->next;
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    for (int i = 1; i <= n; i++)
        adj[i] = NULL;

    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u] = addNode(adj[u], v);
        adj[v] = addNode(adj[v], u);
    }

    for (int i = 1; i <= n; i++)
        visited[i] = 0;

    int count = 0;

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            dfs(i);
            count++;
        }
    }

    printf("%d\n", count);
    return 0;
}
