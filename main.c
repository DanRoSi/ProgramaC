#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main() {
    char cadena1[] = "Hola";
    char* resultado1 = rellenarCadena(cadena1, '*', 0, 3);
    printf("Cadena rellenada por la izquierda: %s\n", resultado1);
    free(resultado1);

    char cadena2[] = "Mundo";
    char* resultado2 = rellenarCadena(cadena2, '#', 1, 2);
    printf("Cadena rellenada por la derecha: %s\n", resultado2);
    free(resultado2);

    char cadena3[] = "Programacion en C";
    char cadena4[] = "Programacion";
    int resultado3 = cadenaIniciaCon(cadena3, cadena4);
    if (resultado3 == 1) {
        printf("La cadena inicia con la subcadena.\n");
    } else {
        printf("La cadena no inicia con la subcadena.\n");
    }

    return 0;
}
