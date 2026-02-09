/* A system receives two separate logs of user arrival times from two different servers. 
Each log is already sorted in ascending order. 
Your task is to create a single chronological log that preserves the correct order of arrivals.*/
#include <stdio.h>

int main() {
    int p, q;
    int a[100], b[100], merged[200];
    int i = 0, j = 0, k = 0;

    // Input for server log 1
    scanf("%d", &p);
    for (int i = 0; i < p; i++) {
        scanf("%d", &a[i]);
    }

    // Input for server log 2
    scanf("%d", &q);
    for (int i = 0; i < q; i++) {
        scanf("%d", &b[i]);
    }

    // Merge using two pointers
    while (i < p && j < q) {
        if (a[i] <= b[j]) {
            merged[k++] = a[i++];
        } else {
            merged[k++] = b[j++];
        }
    }

    // Copy remaining elements from log 1
    while (i < p) {
        merged[k++] = a[i++];
    }

    // Copy remaining elements from log 2
    while (j < q) {
        merged[k++] = b[j++];
    }

    // Print merged log
    for (int i = 0; i < k; i++) {
        printf("%d ", merged[i]);
    }

    return 0;
}
