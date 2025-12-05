#include <stdio.h>

int main() {
    int p;
    printf("Ingrese el número de pedidos del dia: ");
    scanf("%d", &p);

    int dist[p];
    printf("Ingrese la distancia de los pedidos en km:\n");
    for (int i = 0; i < p; i++) {
        printf("Pedido %d: ", i + 1);
        scanf("%d", &dist[i]);
    }

    //método burbuja
    for (int i = 0; i < p - 1; i++) {
        for (int j = 0; j < p - i - 1; j++) {
            if (dist[j] > dist[j + 1]) {
                int temp = dist[j];
                dist[j] = dist[j + 1];
                dist[j + 1] = temp;
            }
        }
    }

    
    printf("\nDistancias ordenadas: ");
    for (int i = 0; i < p; i++) {
        printf("%d ", dist[i]);
    }

    
    int total = 0;
    for (int i = 0; i < p; i++) {
        total += dist[i];
    }
    printf("\nDistancia recorrida: %d km\n", total);

    printf("\nDistancias repetidas:\n");
    int repetido = 0;
    for (int i = 0; i < p; i++) {
        int conteo = 1;
        while (i + 1 < p && dist[i] == dist[i + 1]) {
            conteo++;
            i++;
        }
        if (conteo > 1) {
            printf("Distancia %d km aparece %d veces.\n", dist[i], conteo);
            repetido = 1;
        }
    }
    if (!repetido)
        printf("No hay distancias repetidas.\n");

    
    return 0;
}