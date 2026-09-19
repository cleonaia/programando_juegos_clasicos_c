# Aprende programando C a través de juegos clásicos 

Este repositorio trata de un aprendizaje adquirido del lenguaje de programación C donde se obtiene conocimientos sobre
  - programación estructurada
  -  funciones
  -  escritura de ficheros
  -  estructura simple de datos
  -  estructura de datos dinámicas

a través de la lógica de juegos clásicos.

## Requisitos previos

Un compilador de C instalado:

macOS: Xcode Command Line Tools (clang viene incluido).

Linux: gcc o clang (paquete build-essential en Debian/Ubuntu).

Windows: MinGW (gcc) o WSL con gcc.


## Como compilar y ejecutar los juegos

1. Abre la terminal y sitÃºate en la carpeta del repositorio

bash
cd ruta/al/repositorio

2. Compila el juego que quieras probar

Por ejemplo, para compilar matemagia.c:

bash
gcc matemagia.c -o matemagia
Esto genera un ejecutable llamado matemagia (en Windows serÃ¡ matemagia.exe).

3. Ejecuta el programa

En macOS y Linux:

bash
./matemagia
En Windows (con MinGW o CMD/PowerShell):

bash
matemagia.exe
o:

bash
./matemagia.exe
Pruebas / ejemplos

Como prueba principal puedes usar:

matemagia.c

Para compilar y ejecutar esta prueba:

bash
gcc matemagia.c -o matemagia
./matemagia

Si en el futuro hay más archivos de prueba (por ejemplo, en una carpeta tests/ o con nombres tipo test_*.c), puedes:

Listar los archivos disponibles:

bash
ls

o, si hay subcarpetas:

bash
ls tests

Compilar y ejecutar cada prueba igual que antes:

bash
gcc tests/test_algo.c -o test_algo
./test_algo

Si hay un Makefile, puedes usar:

bash
make
make run

