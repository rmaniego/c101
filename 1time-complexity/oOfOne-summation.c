#include <stdio.h>

int sum(int num1, int num2);

int main(void) {
    int num1 = 1;
    int num2 = 2;
    int num3 = sum(num1, num2);
    printf("%d + %d = %d", num1, num2, num3);
    
    return 0;
}

int sum(int num1, int num2) {
    //          1
    return num1 + num2;
}