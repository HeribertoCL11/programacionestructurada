#include <studio.h>

entero main() {
    flotante radio;
    flotante area;
    constante flotante PI = 3.1416;
    printf("ingresa el valor del radio");
    scanf("%f",&radio);
    area=PI*radio*radio;
    prinf("el area del circulo es  %.2f\n",area);

    retornar 0;
}