#include <stdio.h>
#include <stdlib.h>

// prototypes
int varValue(int num);
int varPointer(int *num);

// pointers
void main(void) {
    printf("## Pointers");
    int* a; // a is an integer pointer
    int *b; // b is an integer pointer (same)
    int* c, d; // both c and d are integer pointers
    int *c, d; // only c is an integer pointer, d is a normal variable
    
    
    printf("## Operations");
    int num1 = 1;
    // copying the value only
    int num2 = num1;
    num2 += 1;
    printf("\n - Test values: num1 = %d, num2(+1) = %d", num1, num2);
    
    // syntax:
    // dtype* var = value; var is a dtype pointer
    int* xyz = NULL;
    
    // syntax:
    // dtype* var2 <pointer of dtype variable #2> = <assign> &var1; <pointer of variable #1>
    
    // pointer num3 takes the pointer of num1
    // meaning num1 and num3 variables takes a single memory location!
    // or num3 is a pointer to an integer location
    int* num3 = &num1; // initialize pointer to variable
    printf("\n - Pointer to num1: %d", &num1);  // ampersand, get pointer of variable
    printf("\n - Pointer to num3: %d", num3);   // basically a pointer
    
    // operations with *pointer means, accessing its value
    // increments the value of pointer num3
    *num3 += 1; // or num3++;
    // changes to num3 will have the same results to num1, and vice versa
    printf("\n - Read values: num1 = %d, *num3(+1) = %d", num1, *num3); // percent, get value to pointer
    
    // functions
    varValue(num1);
    varPointer(&num1);
    
    // changes to varPointer will affect num1
    num1++;
    printf("\nValue of num1: %d", num1);
    
}

// varValue accepts the value of the variable supplied as an argument
// this create a new variable, separate from the argument
int varValue(int num) {
    // display pointer of num
    printf("\nPointer of num: %d", &num);
    // access the value of num
    printf("\nValue of num: %d", num);
    num += 1;
    printf("\nValue of num: %d", num);
}

// varPointer accepts an integer pointer supplied as an argument
// the variable now points to the same memory lcoation of the variable of supplied argument
int varPointer(int *num) {
    // display pointer of num
    printf("\nPointer of num: %d", num);
    // access the value of num
    printf("\nValue of num: %d", *num);
    *num += 1;
    printf("\nValue of num: %d", *num);
}