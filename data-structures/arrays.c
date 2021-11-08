#include <stdio.h>
#include <stdlib.h>

// (c) 2021 Rodney Maniego Jr.
//  MIT License

struct xArray {
    int size;
    int *blocks;
    int lastIndex;
};

// type definition
typedef struct xArray *NewArray;

// prototypes
int arraySize(NewArray *nArray, int size);
int arrayInsert(NewArray *nArray, int value);
int arrayRemove(NewArray *nArray, int value);
int arrayIndexOf(NewArray *nArray, int value);
int arrayRemoveAt(NewArray *nArray, int index);
int arrayItemAt(NewArray *nArray, int index);
int arrayLength(NewArray *nArray);



void main(void) {
    int counter;
    NewArray nArray = NULL;
    
    // note: we are passing the pointer of the array to our functions
    // operations done to the array inside the function will have an effect
    // on the array on the main function
    
    arraySize(&nArray, 5);
    for (counter = 0; counter <= 5; counter++) {
        printf("\n");
        arrayInsert(&nArray, counter);
        printf("\nItem at index (%d): %d", counter, arrayItemAt(&nArray, counter));
        printf("\nArray length: %d", arrayLength(&nArray));
    }
    
    printf("\n");
    arrayRemoveAt(&nArray, 2);
    arrayRemoveAt(&nArray, 3);
    printf("\nArray length: %d", arrayLength(&nArray));
    printf("\nRemove (%d): %d", 1, arrayRemove(&nArray, 1));
    printf("\nRemove (%d): %d", 1, arrayRemove(&nArray, 1));
    printf("\nIndex Of (%d): %d", 0, arrayIndexOf(&nArray, 0));
    printf("\nIndex Of (%d): %d", 1, arrayIndexOf(&nArray, 1));
    free((nArray)->blocks);
    free(nArray);
}

int arraySize(NewArray *nArray, int size) {
    if (*nArray == NULL) {
        // allocate a memory size and point to first location
        *nArray = malloc(sizeof(NewArray));
        // if still null, return an error
        if (*nArray == NULL) {
            printf("\n - No memory is available.");
            printf("\n - Unable to initialize array.");
            return -1;
        }
        // https://stackoverflow.com/a/25344310/4943299
        // http://www.cplusplus.com/forum/general/69810
        // get the required memory allocation of integer x number of values
        // then cast malloc to integer
        int blockSize = sizeof(int);
        int totalBlockSize = blockSize * size;
        int *blocks = (int *) malloc(totalBlockSize);
        if (blocks == NULL) {
            printf("\nError: No memory is available.");
            printf("\nError: Unable to initialize array to size '%d'.", size);
            return -1;
        }
        // initialize memory lcoation to blocks pointer
        // blocks would be the memory at 0th location
        // initialize size and lastIndex to defaults
        (*nArray)->blocks = blocks;
        (*nArray)->size = size;
        (*nArray)->lastIndex = -1;
    }
    return 0;
}


int arrayInsert(NewArray *nArray, int value) {
    if (*nArray == NULL) {
        printf("\n - Array not yet initialized, cannot insert '%d'.", value);
        return -1;
    }
    
    // read and use the blocks pointer
    int *blocks = (*nArray)->blocks;
    if (blocks == NULL) {
        printf("\n - No memory is available.");
        printf("\n - Array not yet initialized, memory was not allocated.");
        return -1;
    }
    
    int size = (*nArray)->size;
    int lastIndex = (*nArray)->lastIndex;
    // printf("\n# blocks: %d, lastIndex: %d, size: %d", blocks, lastIndex, size);
    if (lastIndex >= size-1) {
        // this should imitate fixed-size arrays
        printf("\nError: Max size limit reached, cannot insert '%d'.", value);
        return -1;
    }
    // since we're dealing with defaults,
    // if lastIndex = -1, then set current block index at 0
    // else set to lastIndex + 1 to start at 1 to n
    int index = 0;
    if (lastIndex > -1) {
        index = lastIndex+1;
    }
    
    // pointer arithmmetic
    // https://www.geekforgeeks.org/pointer-arithmetics-in-c-with-examples
    // pointer additions adds the size of the data type, not the actual value
    int *nextBlock = (int *) blocks + index;
    // this means we're assigning a value to the variable (not changing the pointer)
    *nextBlock = value;
    (*nArray)->lastIndex = lastIndex + 1;
    // just for verification, get the value inside the pointer
    // value = *nextBlock;
    // printf("\nInserted: %d (block: %d)", value, nextBlock);
    return 1;
}

int arrayRemove(NewArray *nArray, int value) {
    if (*nArray == NULL) {
        return -1;
    }
    int size = (*nArray)->size;
    int *blocks = (*nArray)->blocks;
    int lastIndex = (*nArray)->lastIndex;
    
    int start;
    int index = -1;
    int found = 0;
    for (start=0; start<size-1; start++) {
        int *getBlockCurrent = (int *) blocks + start;
        if (*getBlockCurrent == value && found == 0) {
            found = 1;
            index = start;
        }
        if (found == 1) {
            // if the searched value is found
            // replace the current block with the next block (pointer)
            // this removes the search value along the process
            int *getBlockNext = (int *) blocks + start + 1;
            *getBlockCurrent = *getBlockNext;
        }
    }
    (*nArray)->lastIndex = lastIndex - 1;
    return index;
}

int arrayIndexOf(NewArray *nArray, int value) {
    if (*nArray == NULL) {
        return -1;
    }
    int size = (*nArray)->size;
    int *blocks = (*nArray)->blocks;
    
    int start;
    for (start=0; start<size; start++) {
        int *getBlockCurrent = (int *) blocks + start;
        if (*getBlockCurrent == value) {
            return start;
        }
    }
    return -1;
}

int arrayRemoveAt(NewArray *nArray, int index) {
    if (*nArray == NULL) {
        return -1;
    }
    int size = (*nArray)->size;
    int lastIndex = (*nArray)->lastIndex;
    if (lastIndex < 0 || index > lastIndex || index >= size) {
        printf("\nError: Index out of bounds. %d, %d", index, lastIndex);
        return -1;
    }

    int blockSize = sizeof(int);
    int *blocks = (*nArray)->blocks;
    int start;
    for (start=index; start<size-1; start++) {
        // starting from the specified index
        int *getBlockCurrent = (int *) blocks + start;
        int *getBlockNext = (int *) blocks + start + 1;
        // replace the current block with the next block (pointer)
        *getBlockCurrent = *getBlockNext;
    }
    (*nArray)->lastIndex = lastIndex - 1;
    // just for verification
    // int *getBlock = (int *) blocks + index;
    // int value = *getBlock;
    // printf("\nRemoved at index (%d): %d", index, value);
    return 1;
}

int arrayItemAt(NewArray *nArray, int index) {
    if (*nArray == NULL) {
        return -1;
    }
    int size = (*nArray)->size;
    int lastIndex = (*nArray)->lastIndex;
    if (lastIndex < 0 || index > lastIndex || index >= size) {
        printf("\nError: Index out of bounds. %d, %d", index, lastIndex);
        return -1;
    }

    int blockSize = sizeof(int);
    int *blocks = (*nArray)->blocks;
    int *getBlock = (int *) (blocks + index);
    int value = *getBlock;
    return value;
}
int arrayLength(NewArray *nArray) {
    if (*nArray == NULL) {
        return -1;
    }
    return (*nArray)->lastIndex + 1;
}