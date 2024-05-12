#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"

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
        }

    } while (opcion != 3);

    return 0;
}
