// gcc pointer2.c -o pointer2

#include <stdio.h>
#include <stdlib.h>

int main() {
    // POINTER EXAMPLE
    int *pc, c;
    c = 10;
    pc = &c;
    printf("c (value): %d\n", c);    // Output: 10
    printf("c (value): %d\n", *pc);  // Output: 10
    printf("c (address): %p\n", pc); // Output: 0x7ffc0a0a0c
    printf("c (address): %p\n", &c); // Output: 0x7ffc0a0a0c

    // Error: pc = c;
    // Error: *pc = &c;
    // Not an error: pc = &c;
    // Not an error: *pc = c;

    return 0;
}
