//
// Created by danie on 4/05/2024.
//

#include <string.h>
#include <stdlib.h>

char* rellenarCadena(char* cadena, char caracter, int direccion, int numCaracteres) {
    int longitud = strlen(cadena);
    char* resultado = malloc(longitud + numCaracteres + 1);

    if (direccion == 0) {
        for (int i = 0; i < numCaracteres; i++) {
            resultado[i] = caracter;
        }
        strcpy(resultado + numCaracteres, cadena);
    } else if (direccion == 1) {
        strcpy(resultado, cadena);
        for (int i = longitud; i < longitud + numCaracteres; i++) {
            resultado[i] = caracter;
        }
        resultado[longitud + numCaracteres] = '\0';
    }

    return resultado;
}
char* eliminarCaracteresRepetidos(const char* cadena) {
    int caracteres[256] = {0};
    int len = strlen(cadena);
    char* nuevaCadena = malloc(len + 1);
    int j = 0;

    for (int i = 0; i < len; i++) {
        char c = cadena[i];
        if (!caracteres[(unsigned char)c]) {
            caracteres[(unsigned char)c] = 1;
            nuevaCadena[j++] = c;
        }
    }
    nuevaCadena[j] = '\0';

    return nuevaCadena;
}