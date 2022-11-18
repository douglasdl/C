#include <stdio.h>
#include <math.h>

int main() {
    
    int num1, num2, media;
    printf("Digite 2 numeros: \n");
    scanf("%d %d", &num1, &num2);
    media = (num1 + num2) / 2;
    printf("\nMedia: %d\n", media);
    return 0;
}