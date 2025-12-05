// cuadrado y cubo de un numero
#include <stdio.h>

int main() {
    float a;
    
    float total1;
    float total2;
    printf("ingresa un numero");
    scanf("%f",&a);
    
    total1=a*a;
    total2=a*a*a;
    printf("el cuadrado es =  %.2f\n",total1);
    printf("el cubo es =  %.2f\n",total2);
    

    return 0;
}