#include "funcs.h"
#include "saludos.h"
#include <stdio.h>

// cómo ejecutar?
/*
gcc -c funcs.c
gcc -c saludos.c
gcc -o main.out main.c funcs.o saludos.o
./main.out
*/

int main(){
    saludar();

    printf("El doble de 14 es %d\n", doble(14));
}