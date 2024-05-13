#include <stdio.h>
#include <stdlib.h>
#include "Funciones.h"
#include <string.h>

int main() {
    int opcion;
    char primera[100], segunda[100], cadena[100];
    int posicionInicial, posicionFinal;
    char* resultado;

    do {
        printf("Seleccione una opcion:\n");
        printf("1. Diferencia entre dos cadenas de texto\n");
        printf("2. Obtener subcadena\n");
        printf("3. Salir\n");
        scanf("%d", &opcion);
        getchar(); // Limpiar el buffer de entrada

        switch (opcion) {
            case 1:
                printf("Ingrese la primera cadena de texto: ");
                fgets(primera, 100, stdin);
                primera[strcspn(primera, "\n")] = '\0'; // Eliminar el salto de línea

                printf("Ingrese la segunda cadena de texto: ");
                fgets(segunda, 100, stdin);
                segunda[strcspn(segunda, "\n")] = '\0'; // Eliminar el salto de línea

                resultado = diferenciaEntreTextos(primera, segunda);
                printf("Diferencia entre las cadenas: %s\n", resultado);
                free(resultado);
                break;
            case 2:
                printf("Ingrese la cadena de caracteres: ");
                fgets(cadena, 100, stdin);
                cadena[strcspn(cadena, "\n")] = '\0'; // Eliminar el salto de línea

                printf("Ingrese la posicion inicial: ");
                scanf("%d", &posicionInicial);

                printf("Ingrese la posicion final: ");
                scanf("%d", &posicionFinal);

                resultado = obtenerSubcadena(cadena, posicionInicial, posicionFinal);
                printf("Subcadena: %s\n", resultado);
                free(resultado);
                break;
            case 3:
                printf("Saliendo...\n");
                break;
            default:
                printf("Opcion inválida. Por favor, intente de nuevo.\n");
                break;
        }

        printf("\n");
    } while (opcion != 3);

    return 0;
}
