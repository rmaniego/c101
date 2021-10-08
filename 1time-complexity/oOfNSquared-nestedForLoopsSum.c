#include <stdio.h>

int counter(int max);

int main(void) {
    int max = 5;
    int total = counter(max);
    printf("Total = %d", total);
    
    return 0;
}

// inner loop:
// T(n) = 1 + (n+1) + 2n
// T(n) = 2n + 3
//
// outer loop:
// Σ = summation!!
// T(n) = Σ(2n + 3) + 2 + (n+1) + n
// T(n) = Σ(2n + 3) + 3 + 2n
// T(n) = Σ(3n) + Σ(3) + 2n + 3
// T(n) = 3Σn + Σ3 + 2n + 3
// T(n) = 3n² + 3n + 2n + 3
// T(n) = 3n² + 5n + 3
//
// big-oh:
// n0 = 1, c = ?
// (3n² + 5n + 3) / n² <= (c*n²) / n²
// 3 + 5/n + 3/n² <= c
// 3 + 5/1 + 3/1 <= c
// 11 <= c
// n0 = 1, c = 11
//
// T(n) = 11*n²
// Therefore T(n) is O(n²)
//
// big-omega:
// n0 = 1, c = ?; as n0 approaches infinity
// (3n² + 5n + 3) / n² >= (c*n²) / n²
// 3 + 5/n + 3/n² >= c
// 3 + 5/5 + 3/5 >= c
// 3 >= c
// n0 = 1, c = 3
//
// T(n) = 3*n²
// Therefore T(n) is Ω(n²)
//
// big-theta:
// Therefore T(n) is θ(n²)

int counter(int max) {
    //           1
    int i, j, total = 0;
    //    1    n+1     n
    for (i=1; i<=max; ++i) {
        //    1    n+1     n
        for (j=1; j<=max; ++j) {
            //    n
            total += j;
        }
    }
    return total;
}