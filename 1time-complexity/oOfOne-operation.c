#include <stdio.h>

int operate(int num1, int num2, int num3, int num4);

int main(void) {
    int num1 = 1;
    int num2 = 2;
    int num3 = 3;
    int num4 = 4;
    int num5 = operate(num1, num2, num3, num4);
    printf("(((%d + %d) * %d) / %d) = %d", num1, num2, num3, num4, num5);
    
    return 0;
}

int operate(int num1, int num2, int num3, int num4) {
    //             1       1       1
    return (((num1 + num2) * num3) / num4);
}