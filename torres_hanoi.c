#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct nodo
{
    int numero;
    struct nodo *siguiente;
} tipoNodo;

typedef tipoNodo *Pila;

void push(Pila *pila, int valor);
int pop(Pila *pila);
void imprimeDiscos(int numero, Pila *pila);
int compruebaAlambreVacio(Pila *pila);
int compruebaMovimientoLegal(Pila *pilaOrigen, Pila *pilaDestino);
int compruebaExito(Pila *pila, int numDiscos);
void limpiaPantalla();

int main()
{
    /** Variables de control **/
    int movimiento;
    int valorExtraido;
    int intentos = 0;
    int movimientoIlegal = 0;

    /** Número de discos **/
    int numDiscos = 3;

    /** Inicializa alambres **/
    Pila alambre1 = NULL;
    Pila alambre2 = NULL;
    Pila alambre3 = NULL;

    push(&alambre1, 3);
    push(&alambre1, 2);
    push(&alambre1, 1);

    do
    {
        /** Borra pantalla **/
        limpiaPantalla();

        /** Imprime información del último movimiento realizado **/
        if (movimientoIlegal == 1)
        {
            printf("\n El movimiento que has seleccionado es ilegal \n");
            movimientoIlegal = 0;
        }

        /** Imprime alambres por pantalla **/
        imprimeDiscos(1, &alambre1);
        imprimeDiscos(2, &alambre2);
        imprimeDiscos(3, &alambre3);

        /** Presenta opciones **/
        puts("--------------------------------------------------");
        puts("1 - Mueve de alambre 1 a alambre 2");
        puts("2 - Mueve de alambre 1 a alambre 3");
        puts("3 - Mueve de alambre 2 a alambre 1");
        puts("4 - Mueve de alambre 2 a alambre 3");
        puts("5 - Mueve de alambre 3 a alambre 1");
        puts("6 - Mueve de alambre 3 a alambre 2");

        printf("Llevas %i movimientos hasta el momento \n", intentos);
        puts("Escoge tu siguiente movimiento introduciendo el numero:");
        scanf("%i", &movimiento);

        switch (movimiento)
        {
            case 1:
                if (compruebaMovimientoLegal(&alambre1, &alambre2))
                {
                    valorExtraido = pop(&alambre1);
                    push(&alambre2, valorExtraido);
                    intentos++;
                }
                else
                {
                    movimientoIlegal = 1;
                }
                break;

            case 2:
                if (compruebaMovimientoLegal(&alambre1, &alambre3))
                {
                    valorExtraido = pop(&alambre1);
                    push(&alambre3, valorExtraido);
                    intentos++;
                }
                else
                {
                    movimientoIlegal = 1;
                }
                break;

            case 3:
                if (compruebaMovimientoLegal(&alambre2, &alambre1))
                {
                    valorExtraido = pop(&alambre2);
                    push(&alambre1, valorExtraido);
                    intentos++;
                }
                else
                {
                    movimientoIlegal = 1;
                }
                break;

            case 4:
                if (compruebaMovimientoLegal(&alambre2, &alambre3))
                {
                    valorExtraido = pop(&alambre2);
                    push(&alambre3, valorExtraido);
                    intentos++;
                }
                else
                {
                    movimientoIlegal = 1;
                }
                break;

            case 5:
                if (compruebaMovimientoLegal(&alambre3, &alambre1))
                {
                    valorExtraido = pop(&alambre3);
                    push(&alambre1, valorExtraido);
                    intentos++;
                }
                else
                {
                    movimientoIlegal = 1;
                }
                break;

            case 6:
                if (compruebaMovimientoLegal(&alambre3, &alambre2))
                {
                    valorExtraido = pop(&alambre3);
                    push(&alambre2, valorExtraido);
                    intentos++;
                }
                else
                {
                    movimientoIlegal = 1;
                }
                break;

            default:
                break;
        }
    }
    while (!compruebaExito(&alambre3, numDiscos));

    limpiaPantalla();

    imprimeDiscos(1, &alambre1);
    imprimeDiscos(2, &alambre2);
    imprimeDiscos(3, &alambre3);

    printf("\n Has terminado el juego en %i movimientos \n", intentos);

    return 0;
}

void push(Pila *pila, int valor)
{
    tipoNodo *nuevo;

    /* Crear un nodo nuevo */
    nuevo = (tipoNodo *) malloc(sizeof(tipoNodo));

    nuevo->numero = valor;

    /* El siguiente nodo al nuevo es el que antes era la cima de la pila */
    nuevo->siguiente = *pila;

    /* Ahora, nuestra pila apuntará al nuevo nodo */
    *pila = nuevo;
}

int pop(Pila *pila)
{
    tipoNodo *nodo_aux;
    int int_aux;

    /* El nodo auxiliar apunta al nodo en la cima de la pila */
    nodo_aux = *pila;

    /* Si el nodo auxiliar de la cima es NULL, acabar función */
    if (!nodo_aux)
        return 0;

    /* Ahora, la pila apuntará al siguiente nodo al de la cima */
    *pila = nodo_aux->siguiente;

    /* Guardar valor del número del nodo a eliminar */
    int_aux = nodo_aux->numero;

    /* Libera la memoria del nodo a eliminar */
    free(nodo_aux);

    /* Retorna el valor del entero que había en el nodo eliminado */
    return int_aux;
}

void imprimeDiscos(int numero, Pila *pila)
{
    tipoNodo *nodo_aux;

    nodo_aux = *pila;

    printf("\n Alambre num. %i \n", numero);

    if (!nodo_aux)
    {
        printf("Sin discos \n");
    }
    else
    {
        /* Mientras el nodo actual no sea NULL, imprimir su valor y avanzar en la pila */
        while (nodo_aux)
        {
            printf("%i \n", nodo_aux->numero);
            nodo_aux = nodo_aux->siguiente;
        }
    }
}

int compruebaAlambreVacio(Pila *pila)
{
    if (!(*pila))
        return 1;

    return 0;
}

int compruebaMovimientoLegal(Pila *pilaOrigen, Pila *pilaDestino)
{
    int valor_origen;
    int valor_destino;

    tipoNodo *nodo_aux_origen;
    tipoNodo *nodo_aux_destino;

    /* Si la pila origen está vacía, movimiento ilegal */
    if (!(*pilaOrigen))
    {
        return 0;
    }

    nodo_aux_origen = *pilaOrigen;
    valor_origen = nodo_aux_origen->numero;

    /* Comprobar si la pila destino está vacía */
    if (*pilaDestino)
    {
        nodo_aux_destino = *pilaDestino;
        valor_destino = nodo_aux_destino->numero;

        /* Si el disco origen es más grande que el destino, ilegal */
        if (valor_origen > valor_destino)
        {
            return 0;
        }
    }

    /* Si llega hasta aquí, el movimiento es legal */
    return 1;
}

int compruebaExito(Pila *pila, int numDiscos)
{
    int contador = 0;
    int valor_actual;

    tipoNodo *nodo_aux;

    nodo_aux = *pila;

    if (!nodo_aux)
    {
        return 0;
    }

    while (contador < numDiscos)
    {
        if (nodo_aux)
        {
            contador++;
            valor_actual = nodo_aux->numero;
            nodo_aux = nodo_aux->siguiente;

            if (nodo_aux && (nodo_aux->numero < valor_actual))
            {
                return 0;
            }
        }
        else
        {
            return 0;
        }
    }

    return 1;
}

void limpiaPantalla()
{
    int i;

    for (i = 1; i <= 100; i++)
        printf("\n");
}
