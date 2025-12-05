#include <stdio.h>

#define NUM_PRODUCTOS 8

typedef struct {
    char nombre[30];
    float precio;
    int vida_util;  // tiempo de vida
} Producto;

void selectionSort(Producto productos[], int n) {
    int i, j, minIndex;
    Producto temp;

    for (i = 0; i < n - 1; i++) {
        minIndex = i;
        for (j = i + 1; j < n; j++) {
            if (productos[j].precio < productos[minIndex].precio) {
                minIndex = j;
            }
        }

        temp = productos[i];
        productos[i] = productos[minIndex];
        productos[minIndex] = temp;
    }
}

int main() {
   
    Producto productos[NUM_PRODUCTOS] = {
        {"cable", 22.5, 12},
        {"pinza", 15.0, 24},
        {"desarmador", 15.5, 36},
        {"gia", 100.0, 60},
        {"multimetro", 25.5, 48},
        {"cinta", 20.0, 6},
        {"guantes", 50.70, 18},
        {"casco de seguridad", 70.00, 30}
    };

    printf("Lista de productos:\n");
    for (int i = 0; i < NUM_PRODUCTOS; i++) {
        printf("%s - $%.2f - Vida útil: %d meses\n", productos[i].nombre, productos[i].precio, productos[i].vida_util);
    }

    selectionSort(productos, NUM_PRODUCTOS);

    printf("\nLista de productos ordenados :\n");
    for (int i = 0; i < NUM_PRODUCTOS; i++) {
        printf("%s - $%.2f - Vida útil: %d meses\n", productos[i].nombre, productos[i].precio, productos[i].vida_util);
    }

    return 0;
}