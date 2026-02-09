/* Given a sorted array of n integers,
 remove duplicates in-place. Print only unique elements in order.*/
 #include <stdio.h>

int main() {
    int n;
    int arr[100];

    // Read size
    scanf("%d", &n);

    // Read sorted array
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Edge case: empty array
    if (n == 0) {
        return 0;
    }

    // Two-pointer approach
    int j = 0;   // index for unique elements

    for (int i = 1; i < n; i++) {
        if (arr[i] != arr[j]) {
            j++;
            arr[j] = arr[i];
        }
    }

    // Print unique elements
    for (int i = 0; i <= j; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
