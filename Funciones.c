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
int sub_str(const char *str, const char *sub, int init) {
    int len = strlen(str);
    int sublen = strlen(sub);
    //error code for negative index
    if (init < 0 ) {
        return -1;
    }
    //error code for an index bigger than the string's length
    if (init >= len){
        return -2;
    }
    //error code in case the sub string is bigger than the string's length
    if (sublen>len){
        return -3;
    }


    int i, j;
    for (i = init; i <= len - sublen; i++) {
        if (str[i] == sub[0]) {
            for (j = 1; j < sublen; j++) {
                if (str[i + j] != sub[j]) {
                    break;
                }
            }
            if (j == sublen) {
                return i;
            }
        }

    }
    return 0;
}
/**
 * punto 5 del taller
 * @param str string a evaluar si contiene el prefijo
 * @param prefix prefijo a evaluar
 * entero que define si es prefijo de la siguiente manera:
 * @return -1 si la longitud del prefijo es mayor a la del string
 * @return 0 si no es prefijo
 * @return 1 si es prefijo
 *
 */
int isPrefix(char* str,char* prefix){
    if (strlen(str)< strlen(prefix)){
        return -1;
    }

    for (int  i = 0; i < strlen(prefix); ++i) {
        if(str[i]!=prefix[i]){
            return 0;
        }
    }
    return 1;
}
/***
 * punto nueve del taller
 * @param str string a ordenar
 * @return copia del string ordenada
 */
char* orderedString(char str[]) {
    int len = strlen(str);
    char* result = (char*)malloc(len + 1);
    if (result == NULL) {
        return NULL;
    }
    strcpy(result, str);
    char aux;
    for (int i = 0; result[i]; ++i) {
        for (int j = 0; result[j]; ++j) {
            if (result[j] > result[i]) {
                aux = result[j];
                result[j] = result[i];
                result[i] = aux;
            }
        }
    }

    result[len] = '\0';

    return result;
}

