/* Day 71 - Question 1: Hash Table Using Quadratic Probing
   Implement a hash table with quadratic probing for collision resolution.
   Supports insert and search operations. */
#include <stdio.h>
#include <string.h>

#define SIZE 7

int table[SIZE];

void init() {
    for (int i = 0; i < SIZE; i++) {
        table[i] = -1;
    }
}

void insert(int key) {
    int h = key % SIZE;
    int i = 0;

    while (i < SIZE) {
        int index = (h + i * i) % SIZE;
        if (table[index] == -1) {
            table[index] = key;
            return;
        }
        i++;
    }
    printf("Hash table is full\n");
}

int search(int key) {
    int h = key % SIZE;

    for (int i = 0; i < SIZE; i++) {
        int index = (h + i * i) % SIZE;

        if (table[index] == key)
            return 1;

        if (table[index] == -1)
            return 0;
    }
    return 0;
}

void display() {
    for (int i = 0; i < SIZE; i++) {
        printf("table[%d] = %d\n", i, table[i]);
    }
}

int main() {
    init();

    int n, key;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &key);
        insert(key);
    }

    display();

    int q;
    scanf("%d", &q);
    scanf("%d", &key);

    if (search(key))
        printf("Found\n");
    else
        printf("Not Found\n");

    return 0;
}
