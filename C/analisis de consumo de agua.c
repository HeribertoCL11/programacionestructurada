#include <stdio.h>

int main() {
    int deptos = 4, dias = 7;
    float consumo[4][7];
    float totalDepto[4] = {0}, totalDia[7] = {0};
    float totalGeneral = 0;

    printf("Consumo diario de agua \n");
    for (int i = 0; i < deptos; i++) {
        printf("\nDepartamento %d:\n", i + 1);
        for (int j = 0; j < dias; j++) {
            printf("  Día %d: ", j + 1);
            scanf("%f", &consumo[i][j]);
            totalDepto[i] += consumo[i][j];
            totalDia[j] += consumo[i][j];
            totalGeneral += consumo[i][j];
        }
    }

    printf("\nConsumo total por departamento:\n");
    for (int i = 0; i < deptos; i++)
        printf("Depto %d: %.2f L\n", i + 1, totalDepto[i]);

    printf("\nConsumo total por día:\n");
    for (int j = 0; j < dias; j++)
        printf("Día %d: %.2f L\n", j + 1, totalDia[j]);

    float promedioGeneral = totalGeneral / (deptos * dias);
    printf("\nPromedio general diario: %.2f L\n", promedioGeneral);

 
    printf("\nDepartamentos con consumo > 2x promedio:\n");
    for (int i = 0; i < deptos; i++)
        if ((totalDepto[i] / dias) > 2 * promedioGeneral)
            printf("Depto %d: %.2f L diarios\n", i + 1, totalDepto[i] / dias);

   
    float maxDia = totalDia[0];
    int diaMax = 0;
    for (int j = 1; j < dias; j++)
        if (totalDia[j] > maxDia) {
            maxDia = totalDia[j];
            diaMax = j;
        }

    printf("\nDía con pico de consumo: Día %d (%.2f L)\n", diaMax + 1, maxDia);

    
    printf("\n Tarifa escalonada \n");
    printf("  - Hasta 100 L/día: $1.0 por L\n");
    printf("  - 101-200 L/día: $1.5 por L\n");
    printf("  - Más de 200 L/día: $2.0 por L\n");

    for (int i = 0; i < deptos; i++) {
        float promedio = totalDepto[i] / dias;
        float tarifa;
        if (promedio <= 100) tarifa = 1.0;
        else if (promedio <= 200) tarifa = 1.5;
        else tarifa = 2.0;

        float pago = totalDepto[i] * tarifa;
        printf("Depto %d paga: $%.2f\n", i + 1, pago);
    }

    return 0;
}
