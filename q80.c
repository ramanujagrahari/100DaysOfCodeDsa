/* Day 80 - Question 1: Floyd-Warshall Algorithm
   Compute shortest paths between all pairs of vertices.
   Input: n x n distance matrix (-1 means no direct edge). */
#include <stdio.h>

#define MAX 105
#define INF 1000000000

int dist[MAX][MAX];
int n;

int main() {
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &dist[i][j]);
            if (dist[i][j] == -1 && i != j)
                dist[i][j] = INF;
        }
    }

    /* Floyd-Warshall: try each vertex as intermediate */
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[i][k] != INF && dist[k][j] != INF &&
                    dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (dist[i][j] == INF)
                printf("-1 ");
            else
                printf("%d ", dist[i][j]);
        }
        printf("\n");
    }

    return 0;
}
