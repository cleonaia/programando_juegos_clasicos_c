#include <stdio.h>

int main(void)
{
    int resultado;
    int secreto;

    printf("Te demostraré un truco de magia que me permitirá adivinar cualquier número de 6 cifras que pienses.\n");
    printf("Por lo tanto, te pediré que memorices un número sin decírmelo:\n\n");

    printf("Genial, ahora dobla ese número secreto que tienes en mente y guarda el resultado,\n");
    printf("lo siguiente es multiplicar por 5 el resultado de la operación anterior.\n\n");
    printf("¿Ya lo tienes? Pues ahora escribe el resultado de dicha multiplicación:\n");
    scanf("%d", &resultado);

    secreto = resultado / 10;

    printf("El número secreto que pensaste es el... %d\n", secreto);
    printf("Gracias y recuerda que un buen mago jamás revela sus trucos ;)\n");

    return 0;
}