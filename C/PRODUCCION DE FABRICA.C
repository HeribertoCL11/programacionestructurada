#include <stdio.h>

int main() {
    int produccion[3][12]; 
    int i, n;
    int totalProducto[3] = {0}; 
    int totalMes[12] = {0};
    int totalGeneral = 0;
    int mayorMes = 0, mesMayor = 0;
    int menorProducto = 0; 
    
    printf("Ingrese la produccion de cada producto por mes:\n\n");
    for (i = 0; i < 3; i++) {
        printf("Producto %d:\n", i + 1);
        for (n = 0; n < 12; n++) {
            printf("  Mes %d: ", n + 1);
            scanf("%d", &produccion[i][n]);
        }
        printf("\n");
    }

    for (i = 0; i < 3; i++) {
        for (n = 0; n < 12; n++) {
            totalProducto[i] += produccion[i][n];
            
        }
    }
    printf("\nProduccion total por mes  \n");
    for (n = 0; n < 12; n++) {
        printf("Mes %2d: %d unidades\n", n + 1, totalMes[n]);
        if (totalMes[n] > mayorMes) {
            mayorMes = totalMes[n];
            mesMayor = n + 1;
        }
    }

    printf("\n=== Total anual por producto ===\n");
    for (i = 0; i < 3; i++) {
        printf("Producto %d: %d unidades\n", i + 1, totalProducto[i]);
    }

    for (n = 0; n < 12; n++) {
        int sumaMes = 0;
        for (i = 0; i < 3; i++) {
            sumaMes += produccion[i][n];
        }
        if (sumaMes > mayorMes) {
            mayorMes = sumaMes;
            mesMayor = n + 1;
        }
    }
    printf("\nmes con mayor produccion general: Mes %d (%d unidades)\n", mesMayor, mayorMes);

    menorProducto = 0;
    for (i = 1; i < 3; i++) {
        if (totalProducto[i] < totalProducto[menorProducto]) {
            menorProducto = i;
        }
    }
    printf("Producto con menor produccion total: Producto %d (%d unidades)\n", menorProducto + 1, totalProducto[menorProducto]);

    return 0;
}
