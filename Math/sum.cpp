#include <stdio.h>
#include <math.h>

int main() {
    
    int num1, sucessor, antecessor, soma;
    printf("Digite um numero: \n");
    scanf("%d", &num1);
    sucessor = num1 * 3 + 1;
    antecessor = num1 * 2 - 1;
    soma = sucessor + antecessor;
    printf("\nSoma: %d\n", soma);
    return 0;
}