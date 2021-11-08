#include <stdio.h>
#include <stdlib.h>

// (c) 2021 Rodney Maniego Jr.
//  MIT License
// guide: http://user.engineering.uiowa.edu/~cie/lecturenotes/tree.c

// self-referential structure
struct list {
    struct list *next;
    int data;
};

// type definition
typedef struct list List;
typedef List *NewList;

// prototypes
int listInsert(NewList *nList, int value);
int listRemove(NewList *nList, int value);
int listIndexOf(NewList *nList, int value);
int listRemoveAt(NewList *nList, int index);
int listLength(NewList *nList);

void main(void) {
    NewList myList = NULL;
    
    // note: we are passing the pointer of the list to our functions
    // operations done to the list inside the function will have an effect
    // on the list on the main function

    int counter;
    for (counter = 0; counter <= 5; counter++) {
        listInsert(&myList, counter);
    }
    
    printf("\nNumber of items: %d", listLength(&myList));
    printf("\nRemove (%d): %d", 2, listRemove(&myList, 2));
    printf("\nRemove (%d): %d", 2, listRemove(&myList, 2));
    printf("\nRemove at Index (%d): %d", 3, listRemove(&myList, 3));
    printf("\nRemove at Index (%d): %d", 3, listRemove(&myList, 3));
    printf("\nNumber of items: %d", listLength(&myList));
    
    printf("\nIndex Of (%d): %d", 0, listIndexOf(&myList, 0));
    printf("\nIndex Of (%d): %d", 1, listIndexOf(&myList, 1));
    printf("\nIndex Of (%d): %d", 2, listIndexOf(&myList, 2));
    printf("\nIndex Of (%d): %d", 3, listIndexOf(&myList, 3));
    printf("\nIndex Of (%d): %d", 4, listIndexOf(&myList, 4));
    printf("\nIndex Of (%d): %d", 5, listIndexOf(&myList, 5));
    printf("\nIndex Of (%d): %d", 6, listIndexOf(&myList, 6));
    
    // cleaner
    for (counter = 0; counter <= 5; counter++) {
        listRemove(&myList, counter);
    }
    free(myList);
}

int listInsert(NewList *nList, int value) {
    // if list is empty
    if (*nList == NULL) {
        // allocate a memory size
        *nList = malloc(sizeof(NewList));
        // printf("\n - Size Allocation: %lu", sizeof(NewList));
        
        // if still null, return an error
        if (*nList == NULL) {
            printf("\n - No memory is available.");
            printf("\n - Unable to insert %d to list", value);
            return -1;
        }
        
        // first insert
        (*nList)->next = NULL;
        (*nList)->data = value;
        printf("\nINSERTED: %d", value);
        
    } else {
        // list is not empty
        // get the pointer on the next list structure (NewList child)
        NewList* child = &((*nList)->next);
        // insert value to child
        listInsert(child, value);
    }
}

int listRemove(NewList *nList, int value) {
    // if list is empty
    if (*nList == NULL) {
        return -1;
    }
    
    NewList* parent = NULL;
    NewList* child = nList;
    while (1) {
        int data = (*child)->data;
        if (data == value) {
            // assign next of parent to the next of the child
            (*parent)->next = *(&((*child)->next));
            // free up allocated memory
            free(child);
            return 1;
        }
        // can be one-liner
        // code formatted to be easier to udnerstand by novices
        parent = child;
        child = &((*child)->next);
        // check if next child is null (or current is the last item)
        if (*child == NULL) {
            break;
        }
    }
    return -1;
}

int listIndexOf(NewList *nList, int value) {
    // if list is empty
    if (*nList == NULL) {
        return -1;
    }
    
    int index = -1;
    NewList* child = nList;
    while (1) {
        index += 1;
        int data = (*child)->data;
        if (data == value) {
            break;
        }
        // if the next child (last item) is empty,
        // and value is still not found, then return not found
        child = &((*child)->next);
        if (*child == NULL) {
            index = -1;
            break;
        }
    }
    return index;
}

int listRemoveAt(NewList *nList, int index) {
    // if list is empty
    if (*nList == NULL) {
        return -1;
    }
    
    int count = 0;
    NewList* parent = NULL;
    NewList* child = nList;
    while (1) {
        if (count == index) {
            // assign next of parent to the next of the child
            (*parent)->next = *(&((*child)->next));
            // free up allocated memory
            free(child);
            return 1;
        }
        parent = child;
        child = &((*child)->next);
        // check if the next child (last item) is null,
        // then end loop
        if (*child == NULL) {
            break;
        }
        count += 1;
    }
    return -1;
}

int listLength(NewList *nList) {
    // if list is empty
    if (*nList == NULL) {
        return 0;
    }
    
    int count = 1;
    // initialize pointer child to 
    NewList* child = nList;
    while (1) {
        // just loop until the end of the linked-list
        child = &((*child)->next);
        if (*child == NULL) {
            break;
        }
        count += 1;
    }
    return count;
}