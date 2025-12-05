#include <stdio.h>

int main() {
    float temperatura;

    printf("Ingresa la temperatura: ");
    scanf("%f", &temperatura);

    if (temperatura < 18) {
        printf("La temperatura es FRIA.\n");
    }
    else if (temperatura <= 30) { 
        printf("La temperatura es NORMAL.\n");
    }
    else {
        printf("La temperatura es CALIENTE.\n");
    }

    return 0;
}
