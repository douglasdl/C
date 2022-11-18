#include <stdio.h>
#include <stdlib.h>

int main() {
    int *p = NULL;

    int x = 10;
    int *p1;
    p1 = &x;

    printf("x = %d\n", x);
    printf("p1 = %d\n", p1);
    printf("*p1 = %d\n", *p1);

    *p1 = 12;

    printf("x = %d\n", x);
    printf("p1 = %d\n", p1);
    printf("*p1 = %d\n", *p1);
    
    return 0;
}