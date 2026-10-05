# include <stdio.h>
# define FILAS 8
# define COLUMNAS 8

int main()
{
    char tablero [FILAS][COLUMNAS];
    char simbolo[2]={'*','*'};
    int i, j;
    int turno;
    int col;
    int numjugadas=0;
    int gameover=0;
    int ok;

    for(i=0; i<FILAS;i++)
    for(j=0; j<COLUMNAS;j++)
    tablero [i][j]='O';

    
}