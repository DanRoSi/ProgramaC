#include <stdio.h>
#include <string.h>
#include "Funciones.h"
#include <malloc.h>
int sub_str(const char *str, const char *sub, int init) ;
int isPrefix(char* str,char* prefix);
char* orderedString(char str[]);
void mostrarMenu() {
    printf("\n--- Menu ---\n"
           "1.Buscar ocurrencia\n");
    printf("2. Rellenar cadena\n");
    printf("5.Revisar si es prefijo\n"
            "6. Eliminar caracteres repetidos\n"
           "9.ordenar una cadena alfabeticamente\n");
    printf("0. Salir\n");
    printf("Ingrese la opcion deseada: ");
}



int main() {
    int opcion;
    char cadena[100];
    char caracter;
    int inicio, fin, direccion;
    char* str;
    char* substr;
    do {
        mostrarMenu();
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                str=(char *) malloc(inicio+1);
                substr=(char *) malloc(fin+1);
                int pos = 0;
                printf("ingrese la cadena de caracteres donde desea buscar: ");
                scanf("%s",str);
                printf("%s",str);
                printf("ingrese la subcadena de caracteres que desea buscar");
                scanf("%s",substr);
                printf("ingrese la posicion de la cadena donde desea empezar la busqueda");
                scanf("%d",&pos);
                pos= sub_str(str,substr,pos);
                if (pos==-1){
                    printf("negative index");
                }
                if(pos==-2){
                    printf("the index is bigger than the string length");
                }
                if(pos==-3)
                    printf("substring length is bigger than the string length");
                break;
            case 2: {
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
            case 5:
                str= (char *) malloc(inicio + 1);;
                substr= (char *) malloc(fin + 1);
                pos= 0;
                printf("ingrese la cadena de caracteres donde desea buscar si es prefijo: ");
                scanf("%s",str);
                printf("%s",str);
                printf("ingrese la subcadena de caracteres que desea evaluar");
                scanf("%s",substr);
                pos= isPrefix(str,substr);
                if (pos==-1){
                    printf("the prefix is bigger than the string");
                }
                if (pos==0){
                    printf("is not a prefix");
                }
                if (pos==1){
                    printf("is a prefix");
                }
                break;
            case 6: {
                char* resultado;
                printf("\nIngrese una cadena de texto para eliminar caracteres repetidos: ");
                fgets(cadena, sizeof(cadena), stdin);

                if (strlen(cadena) <= 1) {
                    printf("Error: La cadena ingresada esta vacia.\n");
                    break;
                }
                resultado = eliminarCaracteresRepetidos(cadena);
                printf("Cadena original: %s", cadena);
                printf("Cadena sin caracteres repetidos: %s\n", resultado);
                free(resultado);
                break;
            }
            case 9:
                break;
            case 0:
                printf("Saliendo del programa...\n");
                break;

            default:
                printf("Opcion no valida. Por favor, seleccione una opcion valida.\n");
                break;
        }
    } while (opcion != 0);


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