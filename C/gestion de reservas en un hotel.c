#include <stdio.h>
#include <string.h>

#define MAX_RESERVAS 50

typedef struct {
    char nombre[30];
    int dias;
    int habitacion;
    int activa;  // 1 = activa, 0 = cancelada
} Reserva;

void agregarReserva(Reserva reservas[], int *contador) {
    if (*contador >= MAX_RESERVAS) {
        printf("No se pueden agregar mas reservas.\n");
        return;
    }

    printf("\n--- Nueva Reserva ---\n");
    printf("Nombre del huesped: ");
    scanf("%s", reservas[*contador].nombre);

    printf("Dias de estancia: ");
    scanf("%d", &reservas[*contador].dias);

    printf("Numero de habitacion: ");
    scanf("%d", &reservas[*contador].habitacion);

    reservas[*contador].activa = 1;

    (*contador)++;
    printf("Reserva registrada con exito.\n");
}

void mostrarReservas(Reserva reservas[], int contador) {
    printf("\n=== LISTA DE RESERVAS ===\n");

    for (int i = 0; i < contador; i++) {
        if (reservas[i].activa) {
            printf("%d) %s - %d dias - Hab %d (Activa)\n",
                   i + 1, reservas[i].nombre, reservas[i].dias, reservas[i].habitacion);
        } else {
            printf("%d) %s - (CANCELADA)\n", i + 1, reservas[i].nombre);
        }
    }
}

void buscarReserva(Reserva reservas[], int contador) {
    char nombre[30];
    printf("Ingrese el nombre a buscar: ");
    scanf("%s", nombre);

    for (int i = 0; i < contador; i++) {
        if (strcmp(reservas[i].nombre, nombre) == 0) {
            printf("\nReserva encontrada:\n");
            if (reservas[i].activa) {
                printf("%s - %d dias - Habitacion %d\n",
                       reservas[i].nombre, reservas[i].dias, reservas[i].habitacion);
            } else {
                printf("%s - RESERVA CANCELADA\n", reservas[i].nombre);
            }
            return;
        }
    }

    printf("No se encontro una reserva con ese nombre.\n");
}

void cancelarReserva(Reserva reservas[], int contador) {
    char nombre[30];
    printf("Nombre de la reserva a cancelar: ");
    scanf("%s", nombre);

    for (int i = 0; i < contador; i++) {
        if (strcmp(reservas[i].nombre, nombre) == 0) {
            reservas[i].activa = 0;
            printf("Reserva cancelada con exito.\n");
            return;
        }
    }

    printf("No existe una reserva con ese nombre.\n");
}

int main() {
    Reserva reservas[MAX_RESERVAS];
    int contador = 0;
    int opcion;

    do {
        printf("\n===== MENU HOTEL =====\n");
        printf("1. Agregar reserva\n");
        printf("2. Mostrar reservas\n");
        printf("3. Buscar reserva\n");
        printf("4. Cancelar reserva\n");
        printf("5. Salir\n");
        printf("Elige una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                agregarReserva(reservas, &contador);
                break;
            case 2:
                mostrarReservas(reservas, contador);
                break;
            case 3:
                buscarReserva(reservas, contador);
                break;
            case 4:
                cancelarReserva(reservas, contador);
                break;
            case 5:
                printf("Saliendo del sistema...\n");
                break;
            default:
                printf("Opcion no valida.\n");
        }

    } while (opcion != 5);

    return 0;
}
