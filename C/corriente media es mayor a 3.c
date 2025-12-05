#include <stdio.h>

int main() {
    float corriente, voltaje;
    printf("Ingrese corriente (A): ");
    scanf("%f", &corriente);
    printf("Ingrese voltaje (V): ");
    scanf("%f", &voltaje);

    if (corriente > 3 && voltaje < 1) {
        printf("Alarma de CORTOCIRCUITO\n");
    } else {
        printf("Sistema en monitoreo...\n");
    }

    return 0;
}
