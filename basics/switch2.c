#include <stdio.h>

int main(void) {
    char letter;
    
    printf("Enter a letter: ");
    scanf("%c", &letter);
    
    switch(letter) {
        case 'a':
            printf("One.");
            break;
        case 'b':
            printf("Two.");
            break;
        case 'c':
            printf("Three.");
            break;
        case 'd':
            printf("Four.");
            break;
        case 'e':
            printf("Five.");
            break;
        default:
            printf("Oops!");
    }
    
    return 0;
}