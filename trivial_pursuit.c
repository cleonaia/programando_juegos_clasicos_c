#include <stdio.h>

int main(void)
{
    int opcion;
    int marcador = 0;

    printf("Bienvenido a nuestro juego de preguntas y respuestas\n");
    printf("Demuestra tu cultura general y alcanza un gran marcador de puntos\n\n");

    printf("Atencion, pregunta: Un datagrama IP de 1000 bytes de datos cruza un enlace con MTU = 500 bytes. Cabecera IP = 20 bytes. Cuantos fragmentos se generan como minimo?\n");
    printf("1 - 1\n");
    printf("2 - 2\n");
    printf("3 - 3\n");
    printf("Elige una opcion introduciendo el numero (1, 2 o 3): ");
    scanf("%d", &opcion);

    switch (opcion)
    {
        case 3:
            printf("Enhorabuena. Respuesta correcta.\n");
            marcador++;
            break;
        case 1:
        case 2:
            printf("Respuesta incorrecta. Sigue intentandolo.\n");
            break;
        default:
            printf("No has seguido las reglas del juego. No ganas ningun punto.\n");
            break;
    }

    printf("\nAtencion, pregunta: Cual es la forma correcta de declarar una funcion en C que no devuelve ningun valor?\n");
    printf("1 - int funcion(void)\n");
    printf("2 - void funcion(void)\n");
    printf("3 - null funcion(void)\n");
    printf("Elige una opcion introduciendo el numero (1, 2 o 3): ");
    scanf("%d", &opcion);

    switch (opcion)
    {
        case 2:
            printf("Enhorabuena. Respuesta correcta.\n");
            marcador++;
            break;
        case 1:
        case 3:
            printf("Respuesta incorrecta. Sigue intentandolo.\n");
            break;
        default:
            printf("No has seguido las reglas del juego. No ganas ningun punto.\n");
            break;
    }

    printf("\nAtencion, pregunta: Con cual de estos comandos podemos controlar el flujo de un programa en C?\n");
    printf("1 - if / else\n");
    printf("2 - printf()\n");
    printf("3 - scanf()\n");
    printf("Elige una opcion introduciendo el numero (1, 2 o 3): ");
    scanf("%d", &opcion);

    switch (opcion)
    {
        case 1:
            printf("Enhorabuena. Respuesta correcta.\n");
            marcador++;
            break;
        case 2:
        case 3:
            printf("Respuesta incorrecta. Sigue intentandolo.\n");
            break;
        default:
            printf("No has seguido las reglas del juego. No ganas ningun punto.\n");
            break;
    }

    printf("\nFin de la partida. Tu puntuacion final ha sido de %d.\n", marcador);

    return 0;
}
