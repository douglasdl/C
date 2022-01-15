#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function that allocates a memory area in the heap
char *allocate_memory() {
    char *myString = malloc(13 * sizeof(char));

    memcpy(myString, "Hello World!", 12);
    myString[12] = '\0';

    return myString;
}

// Main Function. The first function to be put in the stack
int main(int argc, char *argv[]) {
    int answer = 51;
    char *newString = allocate_memory();

    printf("%s\n", newString);
    printf("%d\n", answer);

    return 0;
}

// gcc heap_vs_stack.c -o heap_vs_stack
