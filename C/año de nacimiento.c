// año de nacimiento
#include <stdio.h>

int main() {
    float a;
    float b;
    float año;
    printf("ingresa tu edad");
    scanf("%f",&a);
    printf("ingresa el año actual");
    scanf("%f",&b);
    año=b-a;
    printf("el cociente es =  %.2f\n",año);
    

    return 0;
}