#include <stdio.h>

int main(void) {
    printf("## For Loops");
    int limit;
    
    printf("\nHow many times? ");
    scanf("%d", &limit);
    
    int index, number, counter = 0;
    for (index=1; index<limit; ++index) {
        number = index*limit;
        printf("\n %d*%d: %d", index, limit, number);
    }
    return 0;
}