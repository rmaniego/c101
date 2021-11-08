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
// T(n) = O(1) + T(n-1)
// T(n) = 1 + [1 + T(n-2)]
// T(n) = 2 + [1 + T(n-3)]
// T(n) = 3 + [1 + T(n-4)]
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
    //     1
    if (num == 1)
        // O(1)
        return 1;
    //         1           T(n-1)
    return num + factorial(num-1);
}
