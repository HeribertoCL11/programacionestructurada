#include <stdio.h>

int main() {
    int ventas[7][7];
    int totalProd[7] = {0};
    int totalDia[7] = {0};

    printf(" Registro semanal de ventas (7 productos x 7 días)\n");
    
    
    for (int i = 0; i < 7; i++) {
        printf("\nProducto %d:\n", i + 1);
        for (int j = 0; j < 7; j++) {
            printf("  Día %d: ", j + 1);
            scanf("%d", &ventas[i][j]);
            totalProd[i] += ventas[i][j];
            totalDia[j] += ventas[i][j];
        }
    }

    
    printf("\nTotal vendido por producto:\n");
    for (int i = 0; i < 7; i++)
        printf("Producto %d: %d\n", i + 1, totalProd[i]);

    printf("\nTotal vendido por día:\n");
    for (int j = 0; j < 7; j++)
        printf("Día %d: %d\n", j + 1, totalDia[j]);

    
    int maxProd = 0, maxDia = 0;
    for (int i = 1; i < 7; i++)
        if (totalProd[i] > totalProd[maxProd]) maxProd = i;
    for (int j = 1; j < 7; j++)
        if (totalDia[j] > totalDia[maxDia]) maxDia = j;

    printf("\nProducto más vendido: Producto %d con %d ventas\n", maxProd + 1, totalProd[maxProd]);
    printf("Día con mayor venta total: Día %d con %d ventas\n", maxDia + 1, totalDia[maxDia]);

    printf("\nProductos con al menos un día sin ventas:\n");
    for (int i = 0; i < 7; i++) {
        int sinVenta = 0;
        for (int j = 0; j < 7; j++)
            if (ventas[i][j] == 0) sinVenta = 1;
        if (sinVenta) printf("Producto %d\n", i + 1);
    }


    int inventario[7];
    printf("\nIngrese el inventario inicial de cada producto:\n");
    for (int i = 0; i < 7; i++) {
        printf("Producto %d: ", i + 1);
        scanf("%d", &inventario[i]);
    }

    for (int j = 0; j < 7; j++) {
        for (int i = 0; i < 7; i++) {
            inventario[i] -= ventas[i][j];
            if (inventario[i] <= 0) {
                printf("Producto %d se agotó el día %d\n", i + 1, j + 1);
                inventario[i] = 0;
            }
        }
    }

    return 0;
}