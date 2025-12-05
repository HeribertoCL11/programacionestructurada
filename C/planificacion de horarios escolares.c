#include <stdio.h>

int main() {
    int salones = 5, horas = 6;
    int horario[5][6];

    printf("Disponibilidad de salones (1=ocupado, 0=libre)\n");
    for (int i = 0; i < salones; i++) {
        printf("\nSalon %d:\n", i + 1);
        for (int j = 0; j < horas; j++) {
            printf("  Hora %d: ", j + 1);
            scanf("%d", &horario[i][j]);
        }
    }

    int demanda[6] = {0};
    for (int j = 0; j < horas; j++)
        for (int i = 0; i < salones; i++)
            demanda[j] += horario[i][j];

    int maxHora = 0;
    for (int j = 1; j < horas; j++)
        if (demanda[j] > demanda[maxHora]) maxHora = j;

    printf("\nHora con mayor demanda de salones: %d (Ocupados: %d)\n", maxHora + 1, demanda[maxHora]);


    printf("\nRevisión de uso por salón:\n");
    for (int i = 0; i < salones; i++) {
        int libres = 0, ocupados = 0;
        for (int j = 0; j < horas; j++) {
            if (horario[i][j] == 0) libres++;
            else ocupados++;
        }
        if (ocupados == 0)
            printf("Salon %d: nunca se usa.\n", i + 1);
        else if (libres == 0)
            printf("Salon %d: siempre ocupado.\n", i + 1);
    }

  
    int horasLibres = 0;
    printf("\nIngrese cuántas horas consecutivas necesita: ");
    scanf("%d", &horasLibres);

    for (int i = 0; i < salones; i++) {
        int consecutivas = 0;
        for (int j = 0; j < horas; j++) {
            if (horario[i][j] == 0) consecutivas++;
            else consecutivas = 0;

            if (consecutivas == horasLibres) {
                printf("El salón %d tiene %d horas libres consecutivas (desde la hora %d).\n",
                       i + 1, horasLibres, j - horasLibres + 2);
                break;
            }
        }
    }

    return 0;
}
