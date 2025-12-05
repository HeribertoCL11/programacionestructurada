// voltaje medio
#include <stdio.h>

int main() {
    float a;
    float b;
    float total;
    printf("ingresa un voltaje");
    scanf("%f",&a);
    printf("ingresa otro voltaje");
    scanf("%f",&b);
    total=(a+b)/2;
    printf("el voltaje medio es =  %.2f\n",total);

    return 0;
}