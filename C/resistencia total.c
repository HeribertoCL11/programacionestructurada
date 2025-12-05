// resistencia total en serie
#include <stdio.h>

int main() {
    float a;
    float b;
    float c;
    float total;
     printf("valor de primera resistencia:");
    scanf("%f",&a);
    printf("segundo valor de resistencia:");
    scanf("%f",&b);
     printf("tercer valor de resistencia:");
     scanf("%f",&c);
    total=a+b+c;
    printf("resistencia total en serie =  %.2f\n",total);

    return 0;
}