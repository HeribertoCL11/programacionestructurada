#include <stdio.h>
#include <string.h>

int main() {
    char nombre[50];
    int codigo, codigoCorrecto = 1234; //codigo correcto
    int hora;
    
    printf("sistema de control de acceso\n");
    printf("Ingrese su nombre: ");//espacio pare ingresar el nombre
    scanf("%s", nombre);
    printf("Ingrese su codigo de acceso: ");
    scanf("%d", &codigo);//espacio para ingresar el codigo
    printf("Ingrese la hora de ingreso : ");
    scanf("%d", &hora);//espacio para ingresar la hora

    printf("\n REPORTE DE ACCESO \n");
    printf("Empleado: %s\n", nombre);
    printf("Hora: %d:00 hrs\n", hora);
//toma de decisiones y mostrado de resultados
    if (codigo == codigoCorrecto) {
        if (hora >= 7 && hora <= 18) {
            printf("Resultado: ACCESO PERMITIDO \n");
        } else {
            printf("Resultado: ACCESO DENEGADO\n");
        }
    } else {
        printf("Resultado: ACCESO DENEGADO (Codigo incorrecto)\n");
    }

    return 0;
}
