/* Day 68 - Question 1: Topological Sort (Kahn's BFS Algorithm)
   Perform topological sort using Kahn's algorithm (BFS with in-degree).
   Nodes with in-degree 0 are processed first. */
#include <stdio.h>
#include <stdlib.h>

#define MAX 105

int adj[MAX][MAX];
int indegree[MAX];
int n, m;

void topoSort() {
    int queue[MAX];
    int front = 0, rear = 0;

    /* Enqueue all nodes with in-degree 0 */
    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0)
            queue[rear++] = i;
    }

    while (front < rear) {
        int node = queue[front++];
        printf("%d ", node);

        for (int i = 0; i < n; i++) {
            if (adj[node][i]) {
                indegree[i]--;
                if (indegree[i] == 0)
                    queue[rear++] = i;
            }
        }
    }
    printf("\n");
}

int main() {
    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; i++)
        indegree[i] = 0;

    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        indegree[v]++;
    }

    topoSort();

    return 0;
}
