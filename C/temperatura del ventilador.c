#include <stdio.h>

int main() {
    float temp;
    printf("Ingrese la temperatura (°C): ");
    scanf("%f", &temp);

    if (temp < 20) {
        printf("Ventilador APAGADO\n");
    } else if (temp <= 30) {
        printf("Ventilador en BAJA velocidad\n");
    } else {
        printf("Ventilador en ALTA velocidad\n");
    }

    return 0;
}
