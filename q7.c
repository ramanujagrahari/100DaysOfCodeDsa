/* Write a recursive function fib(n) to compute the n-th
 Fibonacci number where fib(0)=0 and fib(1)=1*/
 #include <stdio.h>

// Recursive function to find nth Fibonacci number
int fib(int n) {
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;
    else
        return fib(n - 1) + fib(n - 2);
}

int main() {
    int n;

    // Read input
    scanf("%d", &n);

    // Print nth Fibonacci number
    printf("%d\n", fib(n));

    return 0;
}
