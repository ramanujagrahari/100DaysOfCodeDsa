/* Day 70 - Question 1: Bellman-Ford Algorithm
   Find shortest paths from a source vertex to all other vertices.
   Works with negative edge weights and detects negative cycles. */
#include <stdio.h>

#define MAX 105
#define INF 1000000000

int u[MAX * MAX], v[MAX * MAX], wt[MAX * MAX];
int dist[MAX];
int n, m;

void bellmanFord(int source) {
    for (int i = 0; i < n; i++)
        dist[i] = INF;
    dist[source] = 0;

    /* Relax all edges V-1 times */
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < m; j++) {
            if (dist[u[j]] != INF && dist[u[j]] + wt[j] < dist[v[j]]) {
                dist[v[j]] = dist[u[j]] + wt[j];
            }
        }
    }

    /* Check for negative cycle */
    for (int j = 0; j < m; j++) {
        if (dist[u[j]] != INF && dist[u[j]] + wt[j] < dist[v[j]]) {
            printf("Negative cycle detected\n");
            return;
        }
    }

    for (int i = 0; i < n; i++) {
        if (dist[i] == INF)
            printf("INF ");
        else
            printf("%d ", dist[i]);
    }
    printf("\n");
}

int main() {
    int source;
    scanf("%d %d %d", &n, &m, &source);

    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &u[i], &v[i], &wt[i]);
    }

    bellmanFord(source);

    return 0;
}
