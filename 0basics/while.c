#include <stdio.h>
#include <stdbool.h>

int main(void) {
    printf("## While Loops");
    
    int limit;
    
    printf("\nHow many times? ");
    scanf("%d", &limit);
    
    int num, counter = 0;
    while (counter < limit) {
        num = counter + 1;
        printf("\n - Hello, world! (%d)", num);
        counter += 1;
    }
    
    return 0;
}