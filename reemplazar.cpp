//
// Created by danie on 1/05/2024.
//

#include "reemplazar.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* reemplazarCaracter(const char *cadena, char caracterBusqueda, char caracterReemplazo){
    int longitud = strlen(cadena);
    char* nuevaCadena =(char*) malloc(longitud + 1);

    if(nuevaCadena == NULL){
        printf("Error: No se pudo asignar memoria\n");
        exit(1);
    }

    for(int i = 0; i < longitud; i++){
        if (cadena[i] == caracterBusqueda){
            nuevaCadena[i] = caracterReemplazo;
        } else {
            nuevaCadena[i] = cadena[i];
        }
    }
    nuevaCadena[longitud] = '\0';

    return nuevaCadena;
}