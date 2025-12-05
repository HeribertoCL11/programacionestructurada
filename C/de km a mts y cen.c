// de km a mts y cen
#include <stdio.h>

int main() {
    float a;
    float mts=1000;
    float cen=100000;
    float total1;
    float total2;
     printf("ingresa los kilometros:");
    scanf("%f",&a);
   total1=a*mts;
   total2=a*cen;
    printf("total en metros =  %.2f\n",total1);
     printf("total en centimetros =  %.2f\n",total2);

    return 0;
}