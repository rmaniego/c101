#include <stdio.h>

int main(void) {
    int age = 23;
    float weight = 72.1;
    char name[100] = "Juan dela Cruz";
    
    printf("Name: %s", name);
    printf("\n\tAge: %d years old", age);
    printf("\n\tWeight: %f kg", weight);
    
    printf("\n\nWhat is your name? ");
    scanf("%s", name);
    
    printf("\nWhat is your age? ");
    scanf("%d", &age);
    
    printf("\nWhat is your weight (kg)? ");
    scanf("%f", &weight);
    
    printf("\n\nName: %s", name);
    printf("\n\tAge: %d years old", age);
    printf("\n\tWeight: %f kg", weight);
    
    return 0;
}