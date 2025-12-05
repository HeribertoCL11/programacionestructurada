#include <stdio.h>

int main() {
    int sensor;  

    printf("lectura del sensor de luz: ");
    scanf("%d", &sensor);

    if (sensor < 300) {
        printf("la lampara se enciende\n");
    } else {
        printf("la lampara de apaga\n");
    }

    return 0;
}
