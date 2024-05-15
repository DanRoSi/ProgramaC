#include <stdio.h>
#include <stdlib.h>
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

char* diferenciaEntreTextos(char* primera, char* segunda) {
    // array para almacenar la frecuencia de los caracteres
    int frecuencia[256] = {0};

    // Contar la frecuencia de los caracteres en ambas cadenas
    for (int i = 0; primera[i]; i++) {
        frecuencia[primera[i]]++;
    }
    for (int i = 0; segunda[i]; i++) {
        frecuencia[segunda[i]]++;
    }

    // Contar el número de caracteres con frecuencia 1
    int longitud = 0;
    for (int i = 0; i < 256; i++) {
        if (frecuencia[i] == 1) {
            longitud++;
        }
    }

    // Asignar memoria para la nueva cadena
    char* resultado = (char*)malloc((longitud + 1) * sizeof(char));
    int j = 0;
    for (int i = 0; i < 256; i++) {
        if (frecuencia[i] == 1) {
            resultado[j++] = (char)i;
        }
    }
    resultado[j] = '\0';

    return resultado;
}


char* obtenerSubcadena(char* cadena, int posicionInicial, int posicionFinal) {
    int longitud = strlen(cadena);

    // Si la posición final es cero, retornamos hasta el final de la cadena
    if (posicionFinal == 0) {
        posicionFinal = longitud;
    }

    // Asignar memoria para la subcadena
    int subcadenaLongitud = posicionFinal - posicionInicial;

    // Si la posición final es menor que la posición inicial, retornamos en forma invertida
    if (posicionFinal < posicionInicial) {
        subcadenaLongitud = posicionInicial - posicionFinal;
        char* subcadena = (char*)malloc((subcadenaLongitud + 1) * sizeof(char));
        int j = 0;
        for (int i = posicionInicial - 1; i >= posicionFinal; i--) {
            subcadena[j++] = cadena[i];
        }
        subcadena[j] = '\0';
        return subcadena;
    }
        // subcadena normal
    else {
        if (posicionInicial < 0) {
            posicionInicial = 0;
        }
        if (posicionFinal > longitud) {
            posicionFinal = longitud;
        }
        subcadenaLongitud = posicionFinal - posicionInicial;
        char* subcadena = (char*)malloc((subcadenaLongitud + 1) * sizeof(char));
        strncpy(subcadena, cadena + posicionInicial, subcadenaLongitud);
        subcadena[subcadenaLongitud] = '\0';
        return subcadena;
    }
}
