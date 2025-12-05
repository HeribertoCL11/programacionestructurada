// cabio de temperatura
#include <stdio.h>

int main() {
    float celsius;
    float fahrenheit;
    printf("ingresa temperatura en celcius");
    scanf("%f",&celsius);
    fahrenheit=celsius*9/5+32;
    printf("tu total es %f\n",fahrenheit);

    return 0;
}