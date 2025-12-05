#include <stdio.h>

int main() {
    // caso a;7+5-6
    int a1,a2,a3;
    printf("caso a)7+5-6\n");
    printf("ingrese el primer numero: ");
    scanf("%d",&a1);
    printf("ingrese el segundo  numero: ");
    scanf("%d",&a2);
     printf("ingrese el tercer numero: ");
      scanf("%d",&a3);
      int resultado_a = a1 + a2 -a3;
    printf("resultado caso a:%d\n",resultado_a);

    return 0;
}