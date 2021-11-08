#include <stdio.h>

// since C don't have boolean data-types
// this will be a workaround
#include <stdbool.h>

int main(void) {
    printf("## Boolean");
    bool complete;
    complete = false;
    printf("\n - // bool complete;");
    printf("\n - // complete = false;");
    printf("\n - Value of boolean complete: %d", complete);
    complete = true;
    printf("\n\n - // complete = true;");
    printf("\n - Value of boolean complete: %d", complete);
    
    // conditional assignments
    printf("\n\n## Conditional Assignments");
    int y;
    bool condition;
    
    condition = true;
    // set variable = if condition is true ? to A : else B
    y = condition ? 1 : 0;
    printf("\n1. Value of y: %d", y);
    condition = false;
    y = condition ? 1 : 0;
    printf("\n2. Value of y: %d", y);
    
    return 0;
}