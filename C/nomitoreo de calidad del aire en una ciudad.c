#include <stdio.h>

int main() {
    float calidad[5][3][168]; // [zona][contaminante][hora]
    float promedio[5][3] = {0};
    float maximo[5][3] = {0};
    float umbral = 100.0;
    int alertas = 0;

    for (int z = 0; z < 5; z++) {
        for (int c = 0; c < 3; c++) {
            for (int h = 0; h < 168; h++) {
                printf("Zona %d, Contaminante %d, Hora %d: ", z+1, c+1, h+1);
                scanf("%f", &calidad[z][c][h]);
                promedio[z][c] += calidad[z][c][h];
                if (calidad[z][c][h] > maximo[z][c])
                    maximo[z][c] = calidad[z][c][h];
            }
        }
    }

    // Calcular promedios
    for (int z = 0; z < 5; z++) {
        for (int c = 0; c < 3; c++) {
            promedio[z][c] /= 168.0;
            printf("\nZona %d, Contaminante %d -> Promedio: %.2f, Máximo: %.2f",
                   z+1, c+1, promedio[z][c], maximo[z][c]);
        }
    }

    printf("\n\nTotal de alertas activadas: %d\n", alertas);
    return 0;
}
#include <stdio.h>

int main() {
    float calidad[5][3][168]; // [zona][contaminante][hora]
    float promedio[5][3] = {0};
    float maximo[5][3] = {0};
    float umbral = 100.0;
    int alertas = 0;

    for (int z = 0; z < 5; z++) {
        for (int c = 0; c < 3; c++) {
            for (int h = 0; h < 168; h++) {
                printf("Zona %d, Contaminante %d, Hora %d: ", z+1, c+1, h+1);
                scanf("%f", &calidad[z][c][h]);
                promedio[z][c] += calidad[z][c][h];
                if (calidad[z][c][h] > maximo[z][c])
                    maximo[z][c] = calidad[z][c][h];
            }
        }
    }

    // Calcular promedios
    for (int z = 0; z < 5; z++) {
        for (int c = 0; c < 3; c++) {
            promedio[z][c] /= 168.0;
            printf("\nZona %d, Contaminante %d -> Promedio: %.2f, Máximo: %.2f",
                   z+1, c+1, promedio[z][c], maximo[z][c]);
        }
    }

    printf("\n\nTotal de alertas activadas: %d\n", alertas);
    return 0;
}