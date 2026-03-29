/* Day 65 - Question 1: Cycle Detection in Undirected Graph (DFS)
   Detect if an undirected graph contains a cycle using DFS.
   If a visited neighbor is not the parent, a cycle exists. */
#include <stdio.h>
#include <stdlib.h>

#define MAX 105

int adj[MAX][MAX];
int visited[MAX];
int n, m;

int dfs(int node, int parent) {
    visited[node] = 1;

    for (int i = 0; i < n; i++) {
        if (adj[node][i]) {
            if (!visited[i]) {
                if (dfs(i, node))
                    return 1;
            } else if (i != parent) {
                return 1; /* Cycle found */
            }
        }
    }
    return 0;
}

int isCycle() {
    for (int i = 0; i < n; i++)
        visited[i] = 0;

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (dfs(i, -1))
                return 1;
        }
    }
    return 0;
}

int main() {
    scanf("%d %d", &n, &m);

    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    if (isCycle())
        printf("1\n");
    else
        printf("0\n");

    return 0;
}
