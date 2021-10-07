#include <stdio.h>

// pointers
int main(void) {
    printf("## Pointers");
    int num1 = 1;
    // copying the value only
    int num2 = num1;
    num2 += 1;
    printf("\n - Test values: num1 = %d, num2(+1) = %d", num1, num2);
    
    // syntax:
    // dtype* var2 <pointer of dtype variable #2> = <assign> &var1; <pointer to variable #1>
    
    // num3 takes the pointer of num1
    // meaning num1 and num3 variables takes a single memory location!
    int* num3 = &num1; // initialize pointer to variable
    printf("\n - Pointer to num1: %d", &num1);  // ampersand, get pointer of variable
    printf("\n - Pointer to num3: %d", num3);   // basically a pointer
    *num3 += 1;
    // changes to num3 will have the same results to num1, and vice versa
    printf("\n - Read values: num1 = %d, *num3(+1) = %d", num1, *num3); // percent, get value to pointer

    return 0;
}