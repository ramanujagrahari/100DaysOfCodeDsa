/* Day 73 - Question 1: First Non-Repeating Character
   Find the first character in a string that appears exactly once.
   Uses a two-pass frequency array approach. */
#include <stdio.h>
#include <string.h>

int main() {
    char s[1000];
    int freq[26] = {0};
    int found = 0;

    scanf("%s", s);

    /* First pass: count frequencies */
    for (int i = 0; s[i] != '\0'; i++) {
        freq[s[i] - 'a']++;
    }

    /* Second pass: find first non-repeating */
    for (int i = 0; s[i] != '\0'; i++) {
        if (freq[s[i] - 'a'] == 1) {
            printf("%c", s[i]);
            found = 1;
            break;
        }
    }

    if (!found)
        printf("$");

    printf("\n");
    return 0;
}
