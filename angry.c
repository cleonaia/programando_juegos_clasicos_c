#include <stdio.h>

int main() {
    int fila = 0;
    int columna;
    int ancho = 31;

    while (fila < 19) {
        columna = 0;

        do {
            int distancia = columna - 15;
            int arriba = fila - 9;
            int abajo = fila - 9;

            if (arriba < 0) {
                arriba = -arriba;
            }

            if (abajo < 0) {
                abajo = -abajo;
            }

            if (distancia < 0) {
                distancia = -distancia;
            }

            if (fila == 0 || fila == 18) {
                if (distancia < 4) {
                    printf("*");
                } else {
                    printf(" ");
                }
            } else if (fila == 1 || fila == 17) {
                if (distancia < 6) {
                    printf("*");
                } else {
                    printf(" ");
                }
            } else if (fila == 2 || fila == 16) {
                if (distancia < 8) {
                    printf("*");
                } else {
                    printf(" ");
                }
            } else if (fila == 3 || fila == 15) {
                if (distancia < 9) {
                    printf("*");
                } else {
                    printf(" ");
                }
            } else if (fila == 4 || fila == 14) {
                if (distancia < 10) {
                    printf("*");
                } else {
                    printf(" ");
                }
            } else if (fila == 5 || fila == 13) {
                if (distancia < 11) {
                    printf("*");
                } else {
                    printf(" ");
                }
            } else if (fila == 6 || fila == 12) {
                if (distancia < 12) {
                    printf("*");
                } else {
                    printf(" ");
                }
            } else if (fila == 7 || fila == 11) {
                if (distancia < 13) {
                    printf("*");
                } else {
                    printf(" ");
                }
            } else {
                if (distancia < 14) {
                    if (fila == 8 && (columna == 7 || columna == 8 || columna == 9 || columna == 21 || columna == 22 || columna == 23)) {
                        printf(" ");
                    } else if (fila == 9 && (columna == 7 || columna == 8 || columna == 9 || columna == 21 || columna == 22 || columna == 23)) {
                        printf(" ");
                    } else if (fila == 10 && (columna == 7 || columna == 8 || columna == 9 || columna == 21 || columna == 22 || columna == 23)) {
                        printf(" ");
                    } else if (fila == 9 && columna >= 12 && columna <= 18) {
                        printf("*");
                    } else {
                        printf("*");
                    }
                } else {
                    printf(" ");
                }
            }

            columna++;
        } while (columna < ancho);

        printf("\n");
        fila++;
    }

    return 0;
}
