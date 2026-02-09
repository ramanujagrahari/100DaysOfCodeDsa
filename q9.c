/* A secret system stores code names in forward order. To display them in mirror format,
 you must transform the given code name so that its characters appear in the opposite order.*/
 #include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    int i, len;
    char temp;

    // Read string
    scanf("%s", str);

    len = strlen(str);

    // Two-pointer string reversal
    for (i = 0; i < len / 2; i++) {
        temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }

    // Print reversed string
    printf("%s\n", str);

    return 0;
}
