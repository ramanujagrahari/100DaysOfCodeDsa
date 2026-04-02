/* Day 69 - Question 1: Dijkstra's Algorithm (Shortest Path)
   Find the shortest path from a source vertex to all other vertices
   in a weighted undirected graph using Dijkstra's algorithm. */
#include <stdio.h>

#define MAX 105
#define INF 1000000000

int graph[MAX][MAX];
int dist[MAX];
int visited[MAX];
int n, m;

int minDistance() {
    int u = -1, minDist = INF;
    for (int i = 0; i < n; i++) {
        if (!visited[i] && dist[i] < minDist) {
            minDist = dist[i];
            u = i;
        }
    }
    return u;
}

void dijkstra(int source) {
    for (int i = 0; i < n; i++) {
        dist[i] = INF;
        visited[i] = 0;
    }
    dist[source] = 0;

    for (int count = 0; count < n; count++) {
        int u = minDistance();
        if (u == -1) break;

        visited[u] = 1;

        for (int v = 0; v < n; v++) {
            if (graph[u][v] != INF && !visited[v] &&
                dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }
}

int main() {
    int source;
    scanf("%d %d %d", &n, &m, &source);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            graph[i][j] = (i == j) ? 0 : INF;

    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        graph[u][v] = w;
        graph[v][u] = w;
    }

    dijkstra(source);

    for (int i = 0; i < n; i++)
        printf("%d ", dist[i]);
    printf("\n");

    return 0;
}
