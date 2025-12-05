#include <stdio.h>

int main() {
    float nivel;
    printf("Ingrese nivel del depósito (%%): ");
    scanf("%f", &nivel);

    if (nivel < 10) {
        printf("Depósito VACÍO\n");
    } else if (nivel <= 90) {
        printf("Niveles NORMALES\n");
    } else {
        printf("Posible DESBORDAMIENTO\n");
    }

    return 0;
}
