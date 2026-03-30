/* Day 66 - Question 1: Cycle Detection in Directed Graph
   Detect if a directed graph contains a cycle using DFS with a recursion stack.
   If a node is visited and also in the current path, a cycle exists. */
#include <stdio.h>
#include <stdlib.h>

#define MAX 105

int adj[MAX][MAX];
int visited[MAX];
int pathVis[MAX];
int n, m;

int dfsCheck(int node) {
    visited[node] = 1;
    pathVis[node] = 1;

    for (int i = 0; i < n; i++) {
        if (adj[node][i]) {
            if (!visited[i]) {
                if (dfsCheck(i))
                    return 1;
            } else if (pathVis[i]) {
                return 1; /* Cycle found */
            }
        }
    }

    pathVis[node] = 0;
    return 0;
}

int isCyclic() {
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
        pathVis[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (dfsCheck(i))
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
        adj[u][v] = 1; /* Directed edge */
    }

    if (isCyclic())
        printf("True\n");
    else
        printf("False\n");

    return 0;
}
