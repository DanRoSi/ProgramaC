#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Función :diferencia entre dos cadenas de texto
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
