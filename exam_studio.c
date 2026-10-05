// estudio del primer parcial tenemos: estructuras que van de secuencial, bucle y secuencial

// secuencial ( while, switch)

// 3.1 Numeros primos

#include <stdio.h>

int main(){

    int numero, divisor=2;
    printf("Introduce un numero mayor de 2:");
    scanf("%d",&numero);

    while(numero%divisor != 0)
        divisor = divisor+1;


    if ( divisor == numero)
        printf("%d es primo\n", numero);
    else
        printf("%d no es primo\n", numero);

    int clave;
    do
    {
        printf("Introduce la clave:");
        scanf("%d", &clave);
    }
    while(clave!=1234);
    printf("Has desbloqueado la contrasena secreta\n");
    
    int i;
    for (i = 1; i <= 100; i = i + 1)
    {
        printf("%d- Tengo que estudiar mas de 100 veces\n", i);
    }

    // hacer el juego del arbol, bastante complicado

    int numJ1, numJ2, numintentos = 0;

    printf("\nIntroduce valor de J1 (numero objetivo):");
    scanf("%d", &numJ1);
    
    for (i = 1; i <= 100; i++)
        printf("\n");

    do
    {
        numintentos = numintentos + 1;
        printf("\n Introduce valor de J2:");
        scanf("%d", &numJ2);

        if(numJ2>numJ1)
        printf("Te has pasado\n");

        if(numJ2<numJ1)
        printf("No te has pasado\n");

    }

    while(numJ2!=numJ1);
    printf("Has acertado %d de intentos\n", numintentos);

    return 0;

}

