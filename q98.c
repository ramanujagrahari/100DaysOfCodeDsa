/* Day 98 - Question 1: Merge Overlapping Intervals
   Given a list of intervals, merge all overlapping intervals and return
   the resulting list of non-overlapping intervals. */
#include <stdio.h>
#include <stdlib.h>

int compareIntervals(const void* a, const void* b) {
    int* i1 = *(int**)a;
    int* i2 = *(int**)b;
    return i1[0] - i2[0];
}

int main() {
    int n;
    scanf("%d", &n);

    int** intervals = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        intervals[i] = (int*)malloc(2 * sizeof(int));
        scanf("%d %d", &intervals[i][0], &intervals[i][1]);
    }

    /* Sort by start time */
    qsort(intervals, n, sizeof(int*), compareIntervals);

    int** result = (int**)malloc(n * sizeof(int*));
    int idx = 0;

    result[idx] = (int*)malloc(2 * sizeof(int));
    result[idx][0] = intervals[0][0];
    result[idx][1] = intervals[0][1];

    for (int i = 1; i < n; i++) {
        if (intervals[i][0] <= result[idx][1]) {
            /* Overlapping: extend the current interval */
            if (intervals[i][1] > result[idx][1])
                result[idx][1] = intervals[i][1];
        } else {
            /* Non-overlapping: start a new interval */
            idx++;
            result[idx] = (int*)malloc(2 * sizeof(int));
            result[idx][0] = intervals[i][0];
            result[idx][1] = intervals[i][1];
        }
    }

    int returnSize = idx + 1;

    for (int i = 0; i < returnSize; i++) {
        printf("[%d, %d] ", result[i][0], result[i][1]);
        free(result[i]);
    }
    printf("\n");

    for (int i = 0; i < n; i++) free(intervals[i]);
    free(intervals);
    free(result);

    return 0;
}
