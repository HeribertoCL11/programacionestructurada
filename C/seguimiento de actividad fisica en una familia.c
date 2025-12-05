include <stdio.h>

int main() {
    int ejercicio[4][4][7]; // [persona][semana][día]
    int total_persona[4] = {0};
    int total_familia = 0;
    int meta = 150;

    // Captura de datos
    for (int p = 0; p < 4; p++) {
        for (int s = 0; s < 4; s++) {
            for (int d = 0; d < 7; d++) {
                printf("Persona %d, Semana %d, Día %d (minutos): ", p+1, s+1, d+1);
                scanf("%d", &ejercicio[p][s][d]);
                total_persona[p] += ejercicio[p][s][d];
                total_familia += ejercicio[p][s][d];
            }
        }
    }

    for (int p = 0; p < 4; p++) {
        printf("\nPersona %d - Total: %d min, Promedio semanal: %.2f\n",
               p+1, total_persona[p], total_persona[p] / 4.0);
    }

    printf("\nTotal familiar mensual: %d minutos\n", total_familia);
    return 0;
}