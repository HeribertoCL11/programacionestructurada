#include <stdio.h>

int main() {
    int sensor; 
    printf("LECTURA DEL SENSOR DE LUZ: ");
    scanf("%d", &sensor);

    if (sensor < 300) {
        printf("La lámpara se ENCIENDE\n");
    } else {
        printf("La lámpara se APAGA\n");
    }

    return 0;
}

