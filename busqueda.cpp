//
// Created by danie on 1/05/2024.
//

#include <string.h>
#include "busqueda.h"

int buscarSubcadena(const char *cadena, const char *subcadena, int posicion){
    conts char *ocurrencia = strstr(cadena + posicion, subcadena);

    if(ocurrencia != NULL){
        return ocurrencia - cadena;
    }else{
        return 0;
    }
}