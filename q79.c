/* Day 79 - Question 1: Single Source Shortest Path using Dijkstra's Algorithm
   Find shortest distances from a source to all vertices using Dijkstra's
   algorithm with adjacency matrix. */
#include <stdio.h>

#define MAX 105
#define INF 1000000000

int graph[MAX][MAX];
int dist[MAX];
int visited[MAX];
int n, m;

int minDist() {
    int u = -1, minD = INF;
    for (int i = 1; i <= n; i++) {
        if (!visited[i] && dist[i] < minD) {
            minD = dist[i];
            u = i;
        }
    }
    return u;
}

void dijkstra(int source) {
    for (int i = 1; i <= n; i++) {
        dist[i] = INF;
        visited[i] = 0;
    }
    dist[source] = 0;

    for (int count = 0; count < n; count++) {
        int u = minDist();
        if (u == -1) break;

        visited[u] = 1;

        for (int v = 1; v <= n; v++) {
            if (graph[u][v] != INF && !visited[v] &&
                dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }
}

int main() {
    int source;
    scanf("%d %d", &n, &m);

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            graph[i][j] = (i == j) ? 0 : INF;

    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        graph[u][v] = w;
        graph[v][u] = w;
    }

    scanf("%d", &source);
    dijkstra(source);

    for (int i = 1; i <= n; i++)
        printf("%d ", dist[i]);
    printf("\n");

    return 0;
}
