#include <stdio.h>

int main() {
    float f;
    printf("Ingrese la frecuencia (Hz): ");
    scanf("%f", &f);

    if (f < 20) {
        printf("Sub-sonido\n");
    } else if (f <= 20000) {
        printf("Sonido\n");
    } else {
        printf("Ultrasonido\n");
    }

    return 0;
}
