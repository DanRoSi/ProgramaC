//
// Created by danie on 1/05/2024.
//

#include "subcadena.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* obtenerSubcadena(const char *cadena, int posicionInicial, int posicionFinal){
    int longitud = strlen(cadena);
    char* subcadena;

    if(posicionFinal == 0) {
        subcadena = (char *) malloc(longitud - posicionInicial + 1);
        strncpy(subcadena, cadena + posicionInicial, longitud - posicionInicial);
    } else if(posicionInicial > posicionFinal) {
        subcadena = (char *) malloc(posicionInicial - posicionFinal + 2);
        for (int i = posicionInicial; i >= posicionFinal; --i) {
            strncat(subcadena, &cadena[i], 1);
        }
    } else {
        subcadena = (char*) malloc(posicionFinal - posicionInicial + 2);
        strncpy(subcadena, cadena + posicionInicial, posicionFinal - posicionInicial +1 );
    }
subcadena[posicionFinal - posicionInicial + 1] = '\0';
    return subcadena;
}