/*Write a C program to insert an element x at a given 1-based position pos in an array of n integers. 
Shift existing elements to the right to make space.*/
#include <stdio.h>

int main() {
    int n, pos, x, i;

    // Read number of elements
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n + 1];   // extra space for insertion

    // Read array elements
    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Read element and position
    printf("Enter element to insert: ");
    scanf("%d", &x);

    printf("Enter position (1-based): ");
    scanf("%d", &pos);

    // Check valid position
    if (pos < 1 || pos > n + 1) {
        printf("Invalid position!\n");
        return 0;
    }

    // Shift elements to the right
    for (i = n; i >= pos; i--) {
        arr[i] = arr[i - 1];
    }

    // Insert element
    arr[pos - 1] = x;
    n++;

    // Print updated array
    printf("Array after insertion:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
