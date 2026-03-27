/* Day 63 - Question 1: Depth First Search (DFS)
   Perform DFS traversal of an undirected graph starting from vertex 0.
   Print all visited vertices in DFS order. */
#include <stdio.h>
#include <stdlib.h>

#define MAX 105

int adj[MAX][MAX];
int visited[MAX];
int n, m;

void dfs(int node) {
    visited[node] = 1;
    printf("%d ", node);

    for (int i = 0; i < n; i++) {
        if (adj[node][i] && !visited[i]) {
            dfs(i);
        }
    }
}

int main() {
    scanf("%d %d", &n, &m);

    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    for (int i = 0; i < n; i++)
        visited[i] = 0;

    /* DFS from all unvisited nodes (handles disconnected graphs) */
    for (int i = 0; i < n; i++) {
        if (!visited[i])
            dfs(i);
    }
    printf("\n");

    return 0;
}
