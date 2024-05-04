//
// Created by danie on 4/05/2024.
//

#include "funciones.h"
#include <string.h>
#include <stdlib.h>

char* rellenarCadena(char* cadena, char caracter, int direccion, int numCaracteres) {
    int longitud = strlen(cadena);
    char* resultado = malloc(longitud + numCaracteres + 1);

    if (direccion == 0) { // Rellenar por la izquierda
        for (int i = 0; i < numCaracteres; i++) {
            resultado[i] = caracter;
        }
        strcpy(resultado + numCaracteres, cadena);
    } else if (direccion == 1) { // Rellenar por la derecha
        strcpy(resultado, cadena);
        for (int i = longitud; i < longitud + numCaracteres; i++) {
            resultado[i] = caracter;
        }
        resultado[longitud + numCaracteres] = '\0';
    }

    return resultado;
}


int cadenaIniciaCon(char* cadenaBase, char* cadenaVerificar) {
    int longitudBase = strlen(cadenaBase);
    int longitudVerificar = strlen(cadenaVerificar);

    if (longitudVerificar > longitudBase) {
        return 0; // La cadena a verificar es más larga que la base, por lo tanto no puede iniciar con ella
    }

    if (strncmp(cadenaBase, cadenaVerificar, longitudVerificar) == 0) {
        return 1; // La cadena inicia con la subcadena
    } else {
        return 0; // La cadena no inicia con la subcadena
    }
}

