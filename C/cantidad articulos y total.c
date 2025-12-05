// precio total
#include <stdio.h>

int main() {
    float a;
    float b;
    float total;
     printf("cantidad de articulos:");
    scanf("%f",&a);
    printf("precio de articulos:");
    scanf("%f",&b);
   total=a*b;
    printf("precio total =  %.2f\n",total);
    return 0;
}