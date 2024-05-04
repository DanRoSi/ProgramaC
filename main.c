#include <stdio.h>
#include <stdlib.h>
#include "busqueda.h"
#include "rellenar.h"
#include "subcadena.h"
#include "reemplazar.h"

int main() {
    char opcion;
    char cadena[100];
    char subcadena[100];
    char caracterBusqueda, caracterReemplazo;
    int posicionInicial, posicionFinal, direccionRelleno, numCaracteresRelleno;

    do {
        printf("\nMenu:\n");
        printf("1. Buscar subcadena\n");
        printf("2. Rellenar cadena\n");
        printf("3. Obtener subcadena\n");
        printf("4. Reemplazar caracter\n");
        printf("5. Salir\n");
        printf("Seleccione una opcion: ");
        scanf(" %c", &opcion);

        switch (opcion) {
            case '1':
                printf("Ingrese la cadena: ");
                scanf("%s", cadena);
                printf("Ingrese la subcadena: ");
                scanf("%s", subcadena);
                printf("Ingrese la posicion inicial: ");
                scanf("%d", &posicionInicial);
                int resultado1 = buscarSubcadena(cadena, subcadena, posicionInicial);
                printf("Resultado de buscarSubcadena: %d\n", resultado1);
                break;

            case '2':
                printf("Ingrese la cadena: ");
                scanf("%s", cadena);
                printf("Ingrese el caracter de relleno: ");
                scanf(" %c", &caracterBusqueda);
                printf("Ingrese el caracter de reemplazo: ");
                scanf(" %c", &caracterReemplazo);
                printf("Ingrese la direccion de relleno (0 - Izquierda, 1 - Derecha): ");
                scanf("%d", &direccionRelleno);
                printf("Ingrese el numero de caracteres a rellenar: ");
                scanf("%d", &numCaracteresRelleno);
                char* resultado2 = rellenarCadena(cadena, caracterBusqueda, direccionRelleno, numCaracteresRelleno);
                printf("Resultado de rellenarCadena: %s\n", resultado2);
                free(resultado2);
                break;

            case '3':
                printf("Ingrese la cadena: ");
                scanf("%s", cadena);
                printf("Ingrese la posicion inicial: ");
                scanf("%d", &posicionInicial);
                printf("Ingrese la posicion final (0 para final): ");
                scanf("%d", &posicionFinal);
                char* resultado3 = obtenerSubcadena(cadena, posicionInicial, posicionFinal);
                printf("Resultado de obtenerSubcadena: %s\n", resultado3);
                free(resultado3);
                break;

            case '4':
                printf("Ingrese la cadena: ");
                scanf("%s", cadena);
                printf("Ingrese el caracter a ser reemplazado: ");
                scanf(" %c", &caracterBusqueda);
                printf("Ingrese el caracter de reemplazo: ");
                scanf(" %c", &caracterReemplazo);
                char* resultado4 = reemplazarCaracter(cadena, caracterBusqueda, caracterReemplazo);
                printf("Resultado de reemplazarCaracter: %s\n", resultado4);
                free(resultado4);
                break;

            case '5':
                printf("Saliendo del programa...\n");
                break;

            default:
                printf("Opcion no valida. Por favor, seleccione una opcion valida.\n");
                break;
        }

    } while (opcion != '5');

    return 0;
}
