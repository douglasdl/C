#include <stdio.h>
#include <stdlib.h>

int cubo(int x) {
    return x * x * x;
}

int main() {
    
    printf("\n\nC Test\n\n");
    
    int contador = 2;
    if (contador == 1) {
        printf("Contador 1\n");
    } else {
        printf("Contador Diferente de 1\n");
    }

    int num;

    printf("Informe um numero: \a");
    scanf("%d", &num);

    printf("O numero %d elevado ao cubo eh \n\n", &contador);

//system("pause");
    return 0;
}