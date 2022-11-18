#include <stdio.h>

enum projeto{simulacao, teste, real};

int main() {

    enum projeto evento;
    

    evento = real;
    printf("%d", evento);
    

    return 0;
}