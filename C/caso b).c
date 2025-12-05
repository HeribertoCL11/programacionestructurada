int main() {
    // Write C code here
    int b1, b2, b3, b5;
    float b4;
    printf("\ncaso b) 9+7*8-36/5\n");
    printf("ingrese el primer numero:");
    scanf("%d",&b1);
     printf("ingrse el segundo numero:");
     scanf("%d",&b2);
     printf("ingrese el tercer numero:");
      scanf("%d",&b3);
      printf("ingresa el cuarto numero:");
      scanf("%f",&b4);
     printf("ingresa el quinto numero:");
      scanf("%d",&b5);
      
float resultado_b = b1+(b2*b3)-(b4/b5);
    printf("resultado del caso b:%.2f\n",resultado_b);

    return 0;
}