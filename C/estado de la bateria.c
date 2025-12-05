#include <stdio.h>

int main() {
    float voltaje;
    printf("Ingrese voltaje de la batería (V): ");
    scanf("%f", &voltaje);

    if (voltaje < 11) {
        printf("Batería BAJA\n");
    } else if (voltaje <= 12.6) {
        printf("Batería NORMAL\n");
    } else {
        printf("Batería en SOBRECARGA\n");
    }

    return 0;
}
