#include <stdio.h>
#define FILAS 8
#define COLUMNAS 8

int main()
{
    char tablero[FILAS][COLUMNAS];
    char simbolo[2] = {'+', '*'};
    int i, j;
    int turno;
    int col;
    int numjugadas = 0;
    int gameover = 0;
    int ok;

    for (i = 0; i < FILAS; i++)
        for (j = 0; j < COLUMNAS; j++)
            tablero[i][j] = 'O';

    while (gameover == 0)
    {
        turno = numjugadas % 2 + 1;
        numjugadas++;
        printf("\n\n\nColumnas a elegir:\n");
        for (j = 0; j < COLUMNAS; j++)
            printf("%d ", j);
        printf("\n");
        for (i = 0; i < FILAS; i++)
        {
            for (j = 0; j < COLUMNAS; j++)
                printf("%c ", tablero[i][j]);
            printf("\n");
        }
        do
        {
            ok = 0;
            printf("\nLe toca a jugador %d. Elija columna: ", turno);
            scanf("%d", &col);
            if (col >= 0 && col < COLUMNAS)
            {
                for (i = FILAS - 1; tablero[i][col] != 'O' && i >= 0; i--);
                if (i > -1)
                {
                    ok = 1;
                    tablero[i][col] = simbolo[turno - 1];
                }
            }
        } while (!ok);

        for (i = 0; i < FILAS; i++)
            for (j = 0; j < COLUMNAS - 3; j++)
                if (tablero[i][j] != 'O' && tablero[i][j] == tablero[i][j + 1] && tablero[i][j] == tablero[i][j + 2] && tablero[i][j] == tablero[i][j + 3])
                    gameover = 1;

        for (i = 0; i < FILAS - 3; i++)
            for (j = 0; j < COLUMNAS; j++)
                if (tablero[i][j] != 'O' && tablero[i][j] == tablero[i + 1][j] && tablero[i][j] == tablero[i + 2][j] && tablero[i][j] == tablero[i + 3][j])
                    gameover = 1;

        for (i = 0; i < FILAS - 3; i++)
            for (j = 0; j < COLUMNAS - 3; j++)
                if (tablero[i][j] != 'O' && tablero[i][j] == tablero[i + 1][j + 1] && tablero[i][j] == tablero[i + 2][j + 2] && tablero[i][j] == tablero[i + 3][j + 3])
                    gameover = 1;

        for (i = 0; i < FILAS - 3; i++)
            for (j = 3; j < COLUMNAS; j++)
                if (tablero[i][j] != 'O' && tablero[i][j] == tablero[i + 1][j - 1] && tablero[i][j] == tablero[i + 2][j - 2] && tablero[i][j] == tablero[i + 3][j - 3])
                    gameover = 1;
    }

    printf("\n\n\nHa ganado el jugador %d tras %d jugadas!!!", turno, numjugadas);
    printf("\n\n\n");
    for (i = 0; i < FILAS; i++)
    {
        for (j = 0; j < COLUMNAS; j++)
            printf("%c ", tablero[i][j]);
        printf("\n");
    }
    return 0;
}
