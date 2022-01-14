#include <stdio.h>

int main() {
    printf("Characters: %c %c \n", 'a', 65);                                        // a A
    printf("%s \n", "A string");
    printf("Decimals: %d %ld\n", 1977, 650000L);                                    // 1977 650000
    printf("Preceding with blanks: %10d \n", 1977);                                 //       1977
    printf("Preceding with zeros: %010d \n", 1977);                                 // 0000001977
    printf("Some different radices: %d %x %o %#x %#o \n", 100, 100, 100, 100, 100); // 100 64 144 0x64 0144
    printf("floats: %4.2f %+.0e %E \n", 3.1416, 3.1416, 3.1416);                    // 3.14 3.14e+00 3.1416E+00
    printf("Width trick: %*d \n", 5, 10);                                           //  10
    printf("%02x", 16);                                                              // 10

    return 0;
}

// gcc -o formats formats.c
// ./formats
