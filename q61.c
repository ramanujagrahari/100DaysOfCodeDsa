/* Day 61 - Question 1: Graph Representation Using Adjacency Matrix
   Read a graph with n vertices and m edges, store it as an adjacency matrix,
   and print the matrix. */
#include <stdio.h>

#define MAX 105

int adj[MAX][MAX];

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    /* Initialize matrix to 0 */
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            adj[i][j] = 0;

    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        adj[v][u] = 1; /* Undirected graph */
    }

    /* Print adjacency matrix */
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            printf("%d", adj[i][j]);
            if (j < n) printf(" ");
        }
        printf("\n");
    }

    return 0;
}
