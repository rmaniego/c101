#include <stdio.h>

int counter(int max);

int main(void) {
    int max = 5;
    int total = counter(max);
    printf("Total = %d", total);
    
    return 0;
}

// T(n) = 2 + (n+1) + 2n
// T(n) = 3n + 3
//
// big-oh:
// n0 = 1, c = ?
// (3n + 3) / n <= (c*n) / n
// 3 + 3/n <= c
// 3 + 3/1 <= c
// 6 <= c
// n0 = 1, c = 6
//
// T(n) = 6*n
// Therefore T(n) is O(n)
//
// big-omega:
// n0 = 1, c = ?; as n0 approaches infinity
// (3n + 3) / n <= (c*n) / n
// 3 + 3/n >= c
// 3 + 3/3 >= c
// 3 + 0 >= c
// 3 >= c
// n0 = 1, c = 3
//
// T(n) = 3*n
// Therefore T(n) is Ω(n)
//
// big-theta:
// Therefore T(n) is θ(n)

int counter(int max) {
    //           1
    int i, total = 0;
    //    1    n+1     n
    for (i=1; i<=max; ++i) {
        //    n
        total += i;
    }
    return total;
}