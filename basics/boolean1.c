#include <stdio.h>

// since C don't have boolean data-types
// try these alternative
const int true = 1;  // or #define true 1
const int false = 0; // or #define false 0

int main(void) {
    printf("## Boolean (workaround #1)");
    printf("\n - True: %d", true);
    printf("\n - False: %d", false);
    
    // conditional assignments
    int completed = true ? 1 : 0;
    printf("\n - Completed: %d", completed);
    
    int negated = !true ? 1 : 0;
    printf("\n - Negated: %d", negated);
    
    return 0;
}