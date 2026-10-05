#include <stdio.h>

#define NF 8
#define NC 8
#define NB 3

void limpiapantalla()
{
    int i;
    for (i = 1; i <= 100; i++)
        printf("\n");
}

int transformaletra(char letra)
{
    int resultado = -1;
    if (letra >= 'A' && letra <= 'A' + NF - 1)
        resultado = letra - 'A';
    if (letra >= 'a' && letra <= 'a' + NF - 1)
        resultado = letra - 'a';
    return (resultado);
}

void inicializatablero(int m[NF][NC])
{
    int i, j;
    for (i = 0; i < NF; i++)
        for (j = 0; j < NC; j++)
            m[i][j] = 0;
}

int gameover(int m[NF][NC])
{
    int i, j, resultado = 1;
    for (i = 0; i < NF && resultado; i++)
        for (j = 0; j < NC && resultado; j++)
            if (m[i][j] > 0)
                resultado = 0;
    return (resultado);
}

void coloca(int m[NF][NC])
{
    char letra;
    int i, j, l;
    for (l = 1; l <= NB; l++)
    {
        printf("Iteracion %d\n", l);
        printf("Intro fila (A-%c): ", 'A' + NF - 1);
        scanf(" %c", &letra);
        i = transformaletra(letra);
        printf("Intro col (1-%d): ", NC);
        scanf(" %d", &j);
        j = j - 1;
        m[i][j] = 1;
    }
}

void imprimetablero(int m[NF][NC])
{
    int i, j;
    for (i = 0; i < NF; i++)
    {
        for (j = 0; j < NC; j++)
        {
            if (m[i][j] < 0)
                printf("*");
            else
                printf("?");
        }
        printf("\n");
    }
}

void turno(int m[NF][NC])
{
    char letra;
    int i, j;
    printf("Intro fila (A-%c): ", 'A' + NF - 1);
    scanf(" %c", &letra);
    i = transformaletra(letra);
    printf("Intro col (1-%d): ", NC);
    scanf(" %d", &j);
    j = j - 1;
    limpiapantalla();
    if (m[i][j] > 0)
        printf("Barco hundido!\n");
    else
        printf("Agua\n");
    m[i][j] = -1;
    imprimetablero(m);
    printf("\nPulsa enter para acabar el turno.");
    letra = getc(stdin);
    letra = getc(stdin);
}

int main()
{
    int findeljuego = 0;
    int J1[NF][NC];
    int J2[NF][NC];

    inicializatablero(J1);
    inicializatablero(J2);

    printf("J1 Coloca barcos:\n");
    coloca(J1);
    limpiapantalla();

    printf("J2 Coloca barcos:\n");
    coloca(J2);
    limpiapantalla();

    while (findeljuego == 0)
    {
        if (gameover(J1) == 0)
        {
            limpiapantalla();
            printf("Turno J1:\n");
            imprimetablero(J2);
            turno(J2);
            if (gameover(J2))
            {
                findeljuego = 1;
                printf("\nHa ganado J1!\n");
            }
        }

        if (gameover(J2) == 0 && findeljuego == 0)
        {
            limpiapantalla();
            printf("Turno J2:\n");
            imprimetablero(J1);
            turno(J1);
            if (gameover(J1))
            {
                findeljuego = 1;
                printf("\nHa ganado J2!\n");
            }
        }
    }
    return 0;
}
