// iva del 16%
#include <stdio.h>

int main() {
    float a;
    float b;
    float total;
    printf("ingresA el precio del producto");
    scanf("%f",&a);
    printf("ingresa el iva");
    scanf("%f",&b);
    total=a*1.16;
    printf("el total es =  %.2f\n",total);
    

    return 0;
}