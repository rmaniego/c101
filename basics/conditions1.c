#include <stdio.h>
#include <stdbool.h>

int main(void) {
    // conditional statements
    printf("\n\n## Conditional statements");
    // basic OR statement
    char *date = "2021-10-07";
    char *user = "admin";
    bool condition;
    condition = (date == "2021-10-07" | user == "admin");
    printf("\nif (\"%s\" == \"2021-10-07\" | \"%s\" == \"admin\")", date, user);
    if (condition) {
        printf("\n    Condition is True (1): %d", condition);
    } else {
        printf("\n    Condition is False (0): %d", condition);
    }
    
    // basic AND statement
    int temperature = 27;
    int humidity = 60;
    condition = (temperature <= 30 & humidity >= 66);
    printf("\nif (%d <= 30 & %d >= 66)", temperature, humidity);
    if (condition) {
        printf("\n - Condition is True (1): %d", condition);
    } else {
        printf("\n - Condition is False (0): %d", condition);
    }
    return 0;
}