#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Funciones.h"
#include <malloc.h>
int sub_str(const char *str, const char *sub, int init) ;
int isPrefix(char* str,char* prefix);
char* orderedString(char str[]);
void mostrarMenu() {
    printf("\n--- Menu ---\n");
    printf("1. Rellenar cadena\n");
    printf("2. Eliminar caracteres repetidos\n");
    printf("3. Salir\n");
    printf("Ingrese la opcion deseada: ");
}



int main() {
    int opcion;
    char cadena[100];
    char caracter;
    int inicio, fin, direccion;

    do {
        mostrarMenu();
        scanf("%d", &opcion);
        fflush(stdin);

        switch (opcion) {
            case 1: {
                char* resultado;
                printf("\nIngrese una cadena de texto: ");
                fgets(cadena, sizeof(cadena), stdin);

                if (strlen(cadena) <= 1) {
                    printf("Error: La cadena ingresada esta vacia.\n");
                    break;
                }

                printf("Ingrese el caracter con el que desea rellenar: ");
                scanf(" %c", &caracter);
                fflush(stdin);

                printf("Ingrese la direccion para rellenar (0 para izquierda, 1 para derecha): ");
                scanf("%d", &direccion);
                fflush(stdin);

                printf("Ingrese el inicio y fin para rellenar (ejemplo: 0 3): ");
                scanf("%d %d", &inicio, &fin);
                fflush(stdin);

                if (inicio < 0 || fin >= strlen(cadena)) {
                    printf("Error: Indices de inicio y fin fuera de rango.\n");
                    break;
                }

                resultado = rellenarCadena(cadena, caracter, direccion, fin - inicio);
                printf("Cadena rellenada: %s\n", resultado);
                free(resultado);
                break;
            }

            case 2: {
                char* resultado;
                printf("\nIngrese una cadena de texto para eliminar caracteres repetidos: ");
                fgets(cadena, sizeof(cadena), stdin);

                if (strlen(cadena) <= 1) {
                    printf("Error: La cadena ingresada esta vacia.\n");
                    break;
                }
//    printf("la cadena %s, %s prefijo de la cadena %s",sub,isPrefix(str,sub)==0?"no es":"es",str);
    printf("%s", orderedString(str));
    return 0;
}
int sub_str(const char *str, const char *sub, int init) {
    int len = strlen(str);
    int sublen = strlen(sub);
    //error code for negative index
    if (init < 0 ) {
        return -1;
    }
    //error code for an index bigger than the string's length
    if (init >= strlen){
        return -2;
    }
    //error code in case the sub string is bigger than the string's length
    if (sublen>len){
        return -3;
    }

                resultado = eliminarCaracteresRepetidos(cadena);
                printf("Cadena original: %s", cadena);
                printf("Cadena sin caracteres repetidos: %s\n", resultado);
                free(resultado);
                break;
            }

            case 3:
                printf("Saliendo del programa...\n");
                break;

            default:
                printf("Opcion no valida. Por favor, seleccione una opcion valida.\n");
                break;
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

    } while (opcion != 3);

    }
    return 0;
}
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