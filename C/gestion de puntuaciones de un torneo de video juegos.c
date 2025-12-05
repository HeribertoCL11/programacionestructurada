#include <stdio.h>
#include <string.h>

#define MAX_JUGADORES 50

typedef struct {
    char nombre[30];
    int puntuacion;
} Jugador;

void ordenar(Jugador jugadores[], int n) {
    int i, j;
    Jugador temp;

    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (jugadores[j].puntuacion > jugadores[i].puntuacion) {
                temp = jugadores[i];
                jugadores[i] = jugadores[j];
                jugadores[j] = temp;
            }
        }
    }
}

int main() {
    int n, i;
    Jugador jugadores[MAX_JUGADORES];

    printf("Cuantos jugadores participaron? ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("\nJugador %d\n", i + 1);
        printf("Nombre: ");
        scanf("%s", jugadores[i].nombre);

        printf("Puntuacion: ");
        scanf("%d", &jugadores[i].puntuacion);
    }

    ordenar(jugadores, n);

    printf("\n===== TABLA DE POSICIONES =====\n");
    for (i = 0; i < n; i++) {
        printf("%d) %s - %d puntos\n", i + 1, jugadores[i].nombre, jugadores[i].puntuacion);
    }

    return 0;
}
