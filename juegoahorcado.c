#include <stdio.h>

#define LONGMAX 20
#define MAXFALLOS 6
#define TRUE 1
#define FALSE 0

void dibujaahorcado(int fallos)
{
    int i;
    for (i = 0; i < 100; i++)
        printf("\n");

    switch (fallos)
    {
    case 1:
        printf("\n\n\n\n");
        printf("_____\n");
        break;
    case 2:
        printf("\n\n\n");
        printf("  |  \n");
        printf("__|__\n");
        break;
    case 3:
        printf("\n\n");
        printf("  |  \n");
        printf("  |  \n");
        printf("  |  \n");
        printf("  |  \n");
        printf("__|__\n");
        break;
    case 4:
        printf("\n");
        printf("  |--\n");
        printf("  | |\n");
        printf("  |  \n");
        printf("  |  \n");
        printf("__|__\n");
        break;
    case 5:
        printf("  |--\n");
        printf("  | |\n");
        printf("  | o\n");
        printf("  |  \n");
        printf("__|__\n");
        break;
    case 6:
        printf("  |--\n");
        printf("  | |\n");
        printf("  | o\n");
        printf("  | |\n");
        printf("__/ \\\n");
        break;
    default:
        break;
    }
}

int main()
{
    char palabra[LONGMAX], mascara[LONGMAX], cadena[LONGMAX], letra;
    int i, longitud, acierto, gameover = 0, numfallos = 0;

    printf("Juego del ahorcado\n");
    printf("Jugador 1 introduce palabra: ");
    gets(palabra);

    for (i = 0; palabra[i] != '\0'; i++)
        mascara[i] = '_';
    longitud = i - 1;

    do
    {
        dibujaahorcado(numfallos);
        printf("La palabra es: ");
        for (i = 0; i <= longitud; i++)
            printf("%c ", mascara[i]);

        printf("\n Jugador 2, elige letra: ");
        gets(cadena);
        letra = cadena[0];

        for (i = 0, acierto = FALSE; i <= longitud; i++)
        {
            if (letra == palabra[i])
            {
                acierto = TRUE;
                mascara[i] = letra;
            }
        }

        if (acierto == FALSE)
        {
            numfallos++;
            if (numfallos == MAXFALLOS)
                gameover = TRUE;
        }
        else
        {
            i = 0;
            while (palabra[i] == mascara[i])
                i++;
            if (i > longitud)
                gameover = TRUE;
        }
    } while (gameover == FALSE);

    dibujaahorcado(numfallos);
    if (acierto)
        printf("\n Enhorabuena!!");
    else
        printf("\n Has perdido");
    printf("\n La palabra era: %s\n", palabra);

    return 0;
}
