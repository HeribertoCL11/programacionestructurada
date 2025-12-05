#include <stdio.h>

int main() {
    int selector;
    printf("Ingrese la posición del selector  ");
    scanf("%d", &selector);

    switch (selector) {
        case 1: printf("Entrada 1 seleccionada\n"); break;
        case 2: printf("Entrada 2 seleccionada\n"); break;
        case 3: printf("Entrada 3 seleccionada\n"); break;
        case 4: printf("Entrada 4 seleccionada\n"); break;
        default: printf("Valor inválido\n"); break;
    }

    return 0;
}
