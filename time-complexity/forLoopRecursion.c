#include <stdio.h>

int factorial(int num);

int main(void) {
    int num, total;
    
    printf("Enter a number: ");
    scanf("%d", &num);
    total = factorial(num);
    
    printf("Total %d!: %d", num, total);
    
    return 0;
}

//
// T(1) = O(1) = 1
// T(n) = O(1) + O(n) + T(n-1)
// T(n) = 1 + n + [1 + T(n-2)]
//
// in general:
// T(n) = 1 + T(n-1)
// T(n) = i + T(n-i)
//
// as i approaches n
//
// T(n) = n + T(n-n)
// T(n) = n + T(0)
// T(n) = n + 1
// T(n) = O(n)
//
// Therefore T(n) is O(n)


int factorial(int num) {
    int i, x = 1;
    //     1
    if (num == 1)
        // O(1)
        return 1;
    //   1     n+1    n
    for (i=1; i<=num; ++i) {
        // O(n)
        // n       
        x += i;
    }
    //       1     1          T(n-1)
    return x + num + factorial(num-1);
}
