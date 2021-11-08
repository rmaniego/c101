#include <stdio.h>

int main(void) {
    int number;
    
    printf("Enter a number: ");
    scanf("%d", &number);
    
    if (number >= 0 & number <= 10) {
        printf("Small number...");
    } else if (number >= 11 & number <= 100) {
        printf("Between 11 and 100...");
    } else {
        printf("Ok, not in my conditions...");
    }
    
    return 0;
}