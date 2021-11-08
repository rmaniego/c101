#include <stdio.h>

int num2bits(int num);

int main(void) {
    int num, bits;
    
    printf("Enter a number: ");
    scanf("%d", &num);
    bits = num2bits(num);
    
    printf("The number %d has %d bits.", num, bits);
    
    return 0;
}

//
// T(1) = O(1) = 1
// T(n) = O(1) + T(n/2)
// T(n) = 1 + [n/2 + T(n/2²)]
//
// assume: n=2k, k=log₂n
//
// in general:
// T(n) = 1 + T(n/2)
// T(n) = i + T(2k/2i)
//
// as i approaches k
//
// T(n) = k + T(1)
// T(n) = k + 1
// T(n) = log₂n + 1
// T(n) = O(log₂n)
//
// Therefore T(n) is O(log₂n)


int num2bits(int num) {
    //  1    1     1
    num = (num-(num%2));
    //        1
    if (num <=1)
        // O(1)
        return 1;
    //       1           T(n/2)
    return 1 + num2bits(num/2);
}
