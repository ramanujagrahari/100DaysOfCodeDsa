/* Implement linear search to find key k in an array.
 Count and display the number of comparisons performed.*/
 #include <stdio.h>

int main() {
    int n, k;
    int arr[100];
    int i, comparisons = 0;
    int found = -1;

    // Input size
    scanf("%d", &n);

    // Input array elements
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Input key to search
    scanf("%d", &k);

    // Linear search
    for (i = 0; i < n; i++) {
        comparisons++;
        if (arr[i] == k) {
            found = i;
            break;
        }
    }

    // Output result
    if (found != -1) {
        printf("Found at index %d\n", found);
    } else {
        printf("Not Found\n");
    }

    printf("Comparisons = %d\n", comparisons);

    return 0;
}


