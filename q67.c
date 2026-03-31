/* Day 67 - Question 1: Topological Sort (DFS)
   Perform topological sort on a Directed Acyclic Graph (DAG) using DFS.
   Push each node to a stack after visiting all its children. */
#include <stdio.h>
#include <stdlib.h>

#define MAX 105

int adj[MAX][MAX];
int visited[MAX];
int stack[MAX];
int top = -1;
int n, m;

void dfs(int node) {
    visited[node] = 1;

    for (int i = 0; i < n; i++) {
        if (adj[node][i] && !visited[i]) {
            dfs(i);
        }
    }

    stack[++top] = node; /* Push after visiting all children */
}

int main() {
    scanf("%d %d", &n, &m);

    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][v] = 1; /* Directed edge */
    }

    for (int i = 0; i < n; i++)
        visited[i] = 0;

    for (int i = 0; i < n; i++) {
        if (!visited[i])
            dfs(i);
    }

    /* Print topological order */
    while (top >= 0) {
        printf("%d ", stack[top--]);
    }
    printf("\n");

    return 0;
}
