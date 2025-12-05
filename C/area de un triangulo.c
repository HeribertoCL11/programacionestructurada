// area de un triangulo
#include <stdio.h>

int main() {
    float a;
    float b;
    float area;
    printf("ingresa el valor de la base");
    scanf("%f",&a);
    printf("ingresa el valor de la altura");
    scanf("%f",&b);
    area=(a*b)/2;
    printf("el area del triandulo es  %.2f\n",area);

    return 0;
}