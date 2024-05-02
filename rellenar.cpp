//
// Created by danie on 1/05/2024.
//

#include "rellenar.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* rellenarCadena(const char *cadena, char caracter, int direccion, int numCaracteres){
    int longitud = strlen(cadena);
    char* nuevaCadena = (char*) malloc(longitud + numCaracteres + 1);

    if(nuevaCadena == NULL){
        printf("Error: no se pudo asignar espacio de memoria\n");
    }

    if(direccion == 0){ //Rellena por la izquierda
        for (int i = 0; i < numCaracteres; ++i) {
            nuevaCadena[i] = caracter;
        }
        strcpy(nuevaCadena + numCaracteres, cadena);
    }else if(direccion == 1){ //Rellena por la derecha
        strcpy(nuevaCadena, cadena);
        for (int i = longitud; i < longitud + numCaracteres; i++ ){
            nuevaCadena[i] = caracter;
        }
    }

    nuevaCadena[longitud + numCaracteres] = '\0';
    return nuevaCadena;
}
