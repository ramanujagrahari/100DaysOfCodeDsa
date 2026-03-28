/* Day 64 - Question 1: Breadth First Search (BFS)
   Perform BFS traversal of an undirected graph starting from vertex 0.
   Print all visited vertices in BFS order. */
#include <stdio.h>
#include <stdlib.h>

#define MAX 105

int adj[MAX][MAX];
int visited[MAX];
int n, m;

void bfs(int start) {
    int queue[MAX];
    int front = 0, rear = 0;

    visited[start] = 1;
    queue[rear++] = start;

    while (front < rear) {
        int node = queue[front++];
        printf("%d ", node);

        for (int i = 0; i < n; i++) {
            if (adj[node][i] && !visited[i]) {
                visited[i] = 1;
                queue[rear++] = i;
            }
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

    /* BFS from all unvisited nodes (handles disconnected graphs) */
    for (int i = 0; i < n; i++) {
        if (!visited[i])
            bfs(i);
    }
    printf("\n");

    return 0;
}
