// promedio total
#include <stdio.h>

int main() {
    float a;
    float b;
    float total;
     printf("primera nota:");
    scanf("%f",&a);
    printf("segunda nota:");
    scanf("%f",&b);
   total=(a+b)/2;
    printf("promedio total =  %.2f\n",total);
    return 0;
}