#include <stdlib.h>
#include <string.h>

//Daniel methods rellenarCadena (2)
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
//Daniel methods EliminarCaracteresRepetidos (6)
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
//Sergio methods diferenciaEntreTextos (7)
char* diferenciaEntreTextos(char* primera, char* segunda) {
    int frecuencia[256] = {0};

    for (int i = 0; primera[i]; i++) {
        frecuencia[primera[i]]++;
    }
    for (int i = 0; segunda[i]; i++) {
        frecuencia[segunda[i]]++;
    }

    int longitud = 0;
    for (int i = 0; i < 256; i++) {
        if (frecuencia[i] == 1) {
            longitud++;
        }
    }

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

//Sergio methods obtenerSubcadena (3)
char* obtenerSubcadena(char* cadena, int posicionInicial, int posicionFinal) {
    int longitud = strlen(cadena);

    if (posicionFinal == 0) {
        posicionFinal = longitud;
    }

    int subcadenaLongitud = posicionFinal - posicionInicial;

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


//Jonathan methods changeChar (4)
char * changeChar(char text[], char old, char new) {

    for (int i =0;i<strlen(text);i++) {
        if (text[i]==old) {
            text[i]=new;
        }
    }
    char *dir_text= text;
    return dir_text;

}

//Jonathan methods changeChar (8)
char * insertText(char base_text[], char insert_text[], int pos) {
    int i;

    for (i = strlen(base_text); i >= pos; --i) {
        base_text[i+strlen(insert_text)]=base_text[i];

    }

    for ( i = 0; i < strlen(insert_text); ++i) {
        base_text[pos+i]=insert_text[i];
    }
    char *dir_base_text=base_text;
    return dir_base_text;
}

