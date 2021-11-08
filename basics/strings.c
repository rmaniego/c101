#include <stdio.h>

int main(void) {
    // single-character
    char a = 'a';
    
    // multi-character strign arrays
    // percent, pointer to memory??
    char *x = "a";
    char *hello = "hello, world";
    char *lorem = "lorem ipsum";
    
    // change character array value
    lorem = "dolor amet";
    
    // character length + end (\0)
    char abc[13] = "hello, world";
    
    return 0;
}