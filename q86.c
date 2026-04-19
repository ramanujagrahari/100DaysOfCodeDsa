/* Day 86 - Question 1: Square Root using Binary Search
   Find the integer square root of n (largest integer m such that m*m <= n)
   using binary search. */
#include <stdio.h>

int mySqrt(int n) {
    if (n == 0) return 0;

    int low = 1, high = n;
    int ans = 0;

    while (low <= high) {
        long long mid = low + (high - low) / 2;

        if (mid * mid == (long long)n)
            return (int)mid;
        else if (mid * mid < (long long)n) {
            ans = (int)mid;
            low = (int)mid + 1;
        } else {
            high = (int)mid - 1;
        }
    }

    return ans;
}

int main() {
    int n;
    scanf("%d", &n);

    printf("%d\n", mySqrt(n));

    return 0;
}
