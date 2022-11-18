#include <stdio.h>
#include <math.h>

int main() {
    
    int num1, area;
    printf("Digite o valor de um lado do quadrado: \n");
    scanf("%d", &num1);
    area = num1 * num1;
    printf("\nArea do Quadrado: %d\n", area);
    return 0;
}