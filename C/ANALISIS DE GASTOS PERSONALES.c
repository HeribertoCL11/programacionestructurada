#include <stdio.h>

int main() {
    int gastos[30];
    int total = 0;
    float promedio;
    int i;

    
    printf("gastos diarios\n");
    for (i = 0; i < 30; i++) {
        printf("Gastos del día %d: ", i + 1);
        scanf("%d", &gastos[i]);
        total += gastos[i];
    }

    
    promedio = total / 30.0;

    printf("Gasto total del mes: %d\n", total);
    printf("Promedio diario: %.2f\n", promedio);

    int temp[30];
    for (i = 0; i < 30; i++)
        temp[i] = gastos[i];


    for (i = 0; i < 29; i++) {
        for (int j = 0; j < 29 - i; j++) {
            if (temp[j] > temp[j + 1]) {
                int aux = temp[j];
                temp[j] = temp[j + 1];
                temp[j + 1] = aux;
            }
        }
    }

    printf("\ndías con menor gasto: %d, %d, %d\n", temp[0], temp[1], temp[2]);
    printf("días con mayor gasto: %d, %d, %d\n", temp[27], temp[28], temp[29]);

    int gasto_semana = 0, gasto_finde = 0;
    int dias_semana = 0, dias_finde = 0;

    for (i = 0; i < 30; i++) {
        int dia_semana = (i + 1) % 7; // domingo = 0, sábado = 6
        if (dia_semana == 6 || dia_semana == 0) {
            gasto_finde += gastos[i];
            dias_finde++;
        } else {
            gasto_semana += gastos[i];
            dias_semana++;
        }
    }

    float prom_semana = gasto_semana / (float)dias_semana;
    float prom_finde = gasto_finde / (float)dias_finde;

    printf("\nPromedio entre semana: %.2f", prom_semana);
    printf("\nPromedio fines de semana: %.2f\n", prom_finde);

    if (prom_finde > prom_semana)
        printf(" Gasta más los fines de semana.\n");
    else if (prom_finde < prom_semana)
        printf(" Gasta más entre semana.\n");
    else
        printf(" Gasta igual entre semana y fines de semana.\n");

    

    return 0;
}