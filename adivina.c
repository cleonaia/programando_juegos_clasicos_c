# include <stdio.h>

int main()
{
    int numJ1, numJ2, i, numintentos = 0;
    
    printf("J1 introduce numero: ");
    scanf("%d", &numJ1);

    for (i=1; i <= 100; i++) """ bucle for para borrar la pantalla imprimiendo enter """
    printf("\n");

    do
    {
        numintentos = numintentos + 1;
        printf("\n J2 introduce numero: ");
        scanf("%d", &numJ2);
      
        if(numJ2>numJ1)
        prinft("\n Te has pasado. ");

        if(numJ2<numJ1)
        printf("\n Te has quedado corto.");
      
    } while (numJ2<numJ1);

    printf("\n Acertaste tras %d intentos. \n", numintentos);    
}
