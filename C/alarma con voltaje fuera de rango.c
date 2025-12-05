#include <stdio.h>

int main() {
    float voltaje;
    printf("Ingrese el voltaje: ");
    scanf("%f", &voltaje);

    if (voltaje < 220 || voltaje > 240) {
        printf("Alarma ACTIVADA\n");
    } else {
        printf("Voltaje dentro del rango\n");
    }

    return 0;
}
