/* Day 95 - Question 1: Bucket Sort (Float Values 0-1)
   Sort an array of floating-point numbers in [0, 1) using Bucket Sort.
   Distributes elements into buckets, sorts each bucket, then concatenates. */
#include <stdio.h>
#include <stdlib.h>

void insertionSortFloat(float arr[], int n) {
    for (int i = 1; i < n; i++) {
        float key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void bucketSort(float arr[], int n) {
    float** buckets = (float**)malloc(n * sizeof(float*));
    int* bucketSizes = (int*)calloc(n, sizeof(int));

    for (int i = 0; i < n; i++) {
        buckets[i] = (float*)malloc(n * sizeof(float));
    }

    /* Distribute elements into buckets */
    for (int i = 0; i < n; i++) {
        int idx = (int)(n * arr[i]);
        if (idx >= n) idx = n - 1;
        buckets[idx][bucketSizes[idx]++] = arr[i];
    }

    /* Sort individual buckets */
    for (int i = 0; i < n; i++) {
        insertionSortFloat(buckets[i], bucketSizes[i]);
    }

    /* Concatenate buckets */
    int index = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < bucketSizes[i]; j++) {
            arr[index++] = buckets[i][j];
        }
        free(buckets[i]);
    }

    free(buckets);
    free(bucketSizes);
}

int main() {
    int n;
    scanf("%d", &n);

    float arr[n];
    for (int i = 0; i < n; i++)
        scanf("%f", &arr[i]);

    bucketSort(arr, n);

    for (int i = 0; i < n; i++)
        printf("%.2f ", arr[i]);
    printf("\n");

    return 0;
}
