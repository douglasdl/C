// gcc pointer.c -o pointer

#include <stdio.h>
#include <stdlib.h>

// Function Swap
void swap(int *a, int *b);


int main() {
    // VARIABLE POINTER
    int *p;
    int i;
    p = &i;
    *p = 10;
    printf("i value: %d\n", i);
    printf("i address: %p\n", &i);


    // FUNCTION POINTER

    // Sum Function
    int addInt(int a, int b) {
        return a + b;
    }

    // Sum Function Pointer
    int (*addIntPtr)(int, int);

    // Assign Function Pointer
    addIntPtr = &addInt;

    // Call Function Pointer
    printf("%d\n", addIntPtr(1, 2));



   


    int m = 25;
    int n = 50;
    printf("Before swap: m = %d, n = %d\n", m, n);
    swap(&m, &n);
    printf("After swap: m = %d, n = %d\n", m, n);

    return 0;
}


void swap(int *a, int *b) {
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}