#include <stdio.h>

int power(int num1, int num2);

int main(void) {
    int num1 = 5;
    int num2 = 2;
    int num3 = power(num1, num2);
    printf("%d**%d = %d", num1, num2, num3);
    
    return 0;
}

// T(n) = 2 + (n+1) + 2n
// T(n) = 3n + 3
//
// n0 = 1, c = ?
// (3n + 3) / n <= (c*n) / n
// 3 + 3 <= c
// 6 <= c
// n0 = 1, c = ?
//
// T(n) = 6*n
// Therefore T(n) is O(n)

int power(int x, int n) {
    //           1
    int i, value = x;
    //    1   n+1   n
    for (i=1; i<=n; ++i) {
        //     n
        value *= x;
    }
    return value;
}