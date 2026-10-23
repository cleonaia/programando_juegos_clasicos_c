#include <stdio.h>
#include <string.h>

/** Array de estructuras con 6 elementos **/
struct pagina
{
    char texto[300];
    char pregunta[100];
    char opcion1[100];
    char opcion2[100];
    int numero;
    int pagina_destino1;
    int pagina_destino2;
    int es_final; /** Valor 0 = NO, valor 1 = Sí **/
} libro[6];

int main(void)
{
    int pagina_actual = 0;
    int opcion_escogida = 0;

    /** Declaración de las 6 páginas **/

    libro[0].numero = 1;
    strcpy(libro[0].texto,
        "Estas explorando una oscura caverna a la luz de tu antorcha. "
        "De repente, te sientas a descansar en un humedo risco que "
        "sobresale del suelo. Bajas la vista y ante tus ojos se "
        "materializa un brillante anillo");
    strcpy(libro[0].pregunta, "Que decides hacer con dicho objeto?");
    strcpy(libro[0].opcion1, "Lo coges y te lo colocas en el dedo anular");
    strcpy(libro[0].opcion2, "Ignoras el anillo y prosigues tu camino");
    libro[0].pagina_destino1 = 1;
    libro[0].pagina_destino2 = 3;
    libro[0].es_final = 0;

    libro[1].numero = 2;
    strcpy(libro[1].texto,
        "Sientes un extrano cosquilleo. Cuando empiezas a pensar que no "
        "ha sido buena idea colocarte el anillo, percibes que una "
        "criatura de piel viscosa y ojos brillantes se planta ante ti. "
        "Grita desesperada que ha perdido el anillo");
    strcpy(libro[1].pregunta, "Que decides hacer?");
    strcpy(libro[1].opcion1, "La ayudas y se lo devuelves");
    strcpy(libro[1].opcion2, "La ignoras y continuas tu camino");
    libro[1].pagina_destino1 = 2;
    libro[1].pagina_destino2 = 3;
    libro[1].es_final = 0;

    libro[2].numero = 3;
    strcpy(libro[2].texto,
        "Al quitarte el anillo, la criatura se asusta y reacciona "
        "abalanzandose contra ti. No te esperabas tal movimiento, asi "
        "que tropiezas y caes, golpeandote en la cabeza con el risco. "
        "Tu ultima vision en vida es la criatura dando saltos de alegria");
    libro[2].es_final = 1;

    libro[3].numero = 4;
    strcpy(libro[3].texto,
        "Dos puertas se abren ante tus ojos. La de la izquierda refulge "
        "en la oscuridad con un destello dorado. La de la derecha es una "
        "verja oxidada y protege las tinieblas.");
    strcpy(libro[3].pregunta, "Que puerta abres?");
    strcpy(libro[3].opcion1, "La puerta dorada de la izquierda");
    strcpy(libro[3].opcion2, "La verja oxidada de la derecha");
    libro[3].pagina_destino1 = 4;
    libro[3].pagina_destino2 = 5;
    libro[3].es_final = 0;

    libro[4].numero = 5;
    strcpy(libro[4].texto,
        "Nada mas abrir la refulgente puerta dorada, descubres un "
        "brillante agujero en el fondo. Te atrae tanto que caes sin "
        "remision por el agujero, quedando atrapado para siempre en la "
        "camara del tesoro");
    libro[4].es_final = 1;

    libro[5].numero = 6;
    strcpy(libro[5].texto,
        "Abres la verja oxidada y atraviesas las tinieblas. Tras mucho "
        "caminar, encuentras una salida y consigues escapar con vida");
    libro[5].es_final = 1;

    /** Estructura de flujo del programa **/
    while (libro[pagina_actual].es_final != 1)
    {
        puts(libro[pagina_actual].texto);
        puts(libro[pagina_actual].pregunta);
        puts("Opcion 1:");
        puts(libro[pagina_actual].opcion1);
        puts("Opcion 2:");
        puts(libro[pagina_actual].opcion2);

        scanf("%d", &opcion_escogida);

        if (opcion_escogida == 1)
        {
            pagina_actual = libro[pagina_actual].pagina_destino1;
        }
        else if (opcion_escogida == 2)
        {
            pagina_actual = libro[pagina_actual].pagina_destino2;
        }
    }

    /** Fin: mostrar texto de pagina final **/
    puts(libro[pagina_actual].texto);
    puts("FIN");

    return 0;
}
