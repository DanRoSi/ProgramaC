#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Funciones.h"


int buscarPrimeraOcurrenciaCadena(char *cadena, char *subcadena, int posicionInicio) {
    int longitudCadena = strlen(cadena);
    int longitudSubcadena = strlen(subcadena);

    if (posicionInicio < 0 || posicionInicio > longitudCadena - longitudSubcadena) {
        return -1; // Posición de inicio inválida
    }

    for (int i = posicionInicio; i <= longitudCadena - longitudSubcadena; i++) {
        int j = 0;
        while (cadena[i + j] == subcadena[j] && j < longitudSubcadena) {
            j++;
        }

        if (j == longitudSubcadena) {
            return i; // Ocurrencia encontrada
        }
    }

    return 0; // No se encontró la subcadena
}

int iniciaConCadena(char *cadenaBase, char *cadenaVerificar) {
    int longitudCadenaBase = strlen(cadenaBase);
    int longitudCadenaVerificar = strlen(cadenaVerificar);

    if (longitudCadenaBase < longitudCadenaVerificar) {
        return 0; // La cadena base es más corta
    }

    for (int i = 0; i < longitudCadenaVerificar; i++) {
        if (cadenaBase[i] != cadenaVerificar[i]) {
            return 0; // No inicia con la subcadena
        }
    }

    return 1; // Inicia con la subcadena
}

void ordenarCadenaIgnorandoMayusculas(char *cadena) {
    int longitudCadena = strlen(cadena);

    for (int i = 0; i < longitudCadena - 1; i++) {
        for (int j = i + 1; j < longitudCadena; j++) {
            char caracter1 = tolower(cadena[i]);
            char caracter2 = tolower(cadena[j]);

            if (caracter1 > caracter2) {
                char aux = cadena[i];
                cadena[i] = cadena[j];
                cadena[j] = aux;
            }
        }
    }
}

//Daniel methods rellenarCadena (2)
char* rellenarCadenaConCaracter(char* cadena, char caracter, int direccion, int numCaracteres) {
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
char* eliminarCaracteresRepetidosCadena(const char* cadena) {
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
char* diferenciaEntreCadenas(char* primera, char* segunda) {
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
char *changeChar(char text[], char old, char new) {
    char *result = malloc(strlen(text) + 1); // Reservar memoria para la nueva cadena
    if (result == NULL) {
        // Manejo de error si malloc falla
        return NULL;
    }

    strcpy(result, text); // Copiar el contenido de la cadena original a la nueva cadena

    for (int i = 0; i < strlen(result); i++) {
        if (tolower(result[i]) == tolower(old)) {
            result[i] = new;
        }
    }

    return result;
}



//Jonathan methods changeChar (8)
char *insertText(char base_text[], char insert_text[], int pos) {
    int base_len = strlen(base_text);
    int insert_len = strlen(insert_text);
    int new_len = base_len + insert_len;
    char *new_text = (char *)malloc(new_len + 1);

    if (new_text == NULL) {
        return NULL;
    }

    int i, j = 0;

    // Copiar parte de la base_text hasta la posición pos
    for (i = 0; i < pos; i++) {
        new_text[j++] = base_text[i];
    }

    // Insertar el insert_text
    for (i = 0; i < insert_len; i++) {
        new_text[j++] = insert_text[i];
    }

    // Copiar el resto de base_text desde la posición pos en adelante
    for (i = pos; i < base_len; i++) {
        new_text[j++] = base_text[i];
    }

    new_text[j] = '\0';

    return new_text;
}
