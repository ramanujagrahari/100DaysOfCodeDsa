/*Given an array of n integers, reverse the array in-place using two-pointer approach*/
#include <stdio.h>

int main() {
    int n;
    int arr[100];
    int left, right, temp;

    // Read size
    scanf("%d", &n);

    // Read array elements
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Two-pointer approach
    left = 0;
    right = n - 1;

    while (left < right) {
        temp = arr[left];
        arr[left] = arr[right];
        arr[right] = temp;

        left++;
        right--;
    }

    // Print reversed array
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
