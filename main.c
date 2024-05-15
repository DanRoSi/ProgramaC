#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "Funciones.h"

int main() {
    char cadena[1000];
    char originalString[1000];

    printf("Ingrese una cadena de texto: ");
    fgets(cadena, sizeof(cadena), stdin);
    cadena[strcspn(cadena, "\n")] = '\0';

    int opcion;
    do {
        printf("\n\nMenu de funciones:\n");
        printf("1. Buscar primera ocurrencia de subcadena\n");
        printf("2. Verificar si una cadena inicia con otra\n");
        printf("3. Ordenar cadena ignorando mayúsculas y minusculas\n");
        printf("4. Rellenar cadena con caracteres\n");
        printf("5. Eliminar caracteres repetidos\n");
        printf("6. Diferencia entre dos textos\n");
        printf("7. Obtener subcadena\n");
        printf("8. Cambiar caracter en una cadena\n");
        printf("9. Insertar texto en una cadena\n");
        printf("0. Salir\n");
        printf("Ingrese una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1: {
                char subcadena[100];
                int posicionInicio;

                printf("Ingrese la subcadena a buscar: ");
                scanf("%c", &opcion);
                fgets(subcadena, sizeof(subcadena), stdin);
                subcadena[strcspn(subcadena, "\n")] = '\0';
                printf("Ingrese la posición de inicio: ");
                scanf("%d", &posicionInicio);

                fflush(stdin);
                int resultado = buscarPrimeraOcurrenciaCadena(cadena, subcadena, posicionInicio);
                if (resultado == -1) {
                    printf("No se encontró la subcadena en la posición indicada.\n");
                } else {
                    printf("La subcadena se encontró en la posición %d.\n", resultado);
                }
                break;
            }
            case 2: {
                char subcadenaVerificar[100];

                do {
                    printf("Ingrese la cadena a verificar: ");
                    scanf("%c", &opcion); // Consume newline
                    fgets(subcadenaVerificar, sizeof(subcadenaVerificar), stdin);
                    subcadenaVerificar[strcspn(subcadenaVerificar, "\n")] = '\0';
                } while (strlen(subcadenaVerificar) > 99);

                int resultado = iniciaConCadena(cadena, subcadenaVerificar);
                if (resultado) {
                    printf("La cadena inicia con la subcadena.\n");
                } else {
                    printf("La cadena no inicia con la subcadena.\n");
                }
                break;
            }
            case 3: {
                // Guardar una copia de la cadena original
                char originalString[100];
                strcpy(originalString, cadena);

                // Ordenar la cadena ignorando mayúsculas
                ordenarCadenaIgnorandoMayusculas(cadena);
                printf("Cadena ordenada: %s\n", cadena);

                // Confirmar si se desea conservar la cadena ordenada
                char confirmation;
                printf("¿Desea conservar la cadena ordenada? (s/n): ");
                while (getchar() != '\n');  // Limpiar el buffer de entrada antes de leer la confirmación
                scanf("%c", &confirmation);

                if (confirmation != 's') {
                    // Si el usuario elige no mantener la cadena ordenada, revertir a la original
                    strcpy(cadena, originalString);
                    printf("Cadena revertida a la original: %s\n", cadena);
                }
                break;
            }

            case 4: {
                char caracter;
                int direccion;
                int numCaracteres;

                printf("Ingrese el caracter de relleno: ");
                scanf(" %c", &caracter);
                printf("Ingrese la dirección (0 para izquierda, 1 para derecha): ");
                scanf("%d", &direccion);
                printf("Ingrese la cantidad de caracteres: ");
                scanf("%d", &numCaracteres);

                char *resultado = rellenarCadenaConCaracter(cadena, caracter, direccion, numCaracteres);
                printf("Cadena rellena: %s\n", resultado);
                free(resultado);
                break;
            }
            case 5: {
                char *resultado = eliminarCaracteresRepetidosCadena(cadena);
                printf("Cadena sin caracteres repetidos: %s\n", resultado);
                free(resultado);
                break;
            }
            case 6: {
                char texto1[1000]; // Primer texto: ingresado por el usuario
                char texto2[1000]; // Segundo texto: ingresado por el usuario

                // Leer el primer texto
                printf("Ingrese el primer texto: ");
                fgets(texto1, sizeof(texto1), stdin);
                strtok(texto1, "\n"); // Eliminar el salto de línea

                // Limpiar el búfer del teclado
                int c;
                while ((c = getchar()) != '\n' && c != EOF);

                // Leer el segundo texto
                printf("Ingrese el segundo texto: ");
                fgets(texto2, sizeof(texto2), stdin);
                strtok(texto2, "\n"); // Eliminar el salto de línea

                // Calcular y mostrar los caracteres únicos en el primer texto
                printf("Caracteres únicos en el primer texto:\n");
                for (int i = 0; texto1[i] != '\0'; i++) {
                    int j;
                    for (j = 0; texto1[j] != '\0'; j++) {
                        if (i != j && texto1[i] == texto1[j]) {
                            break;
                        }
                    }
                    if (texto1[j] == '\0') {
                        printf("%c ", texto1[i]);
                    }
                }
                printf("\n");

                // Calcular y mostrar los caracteres únicos en el segundo texto
                printf("Caracteres únicos en el segundo texto:\n");
                for (int i = 0; texto2[i] != '\0'; i++) {
                    int j;
                    for (j = 0; texto2[j] != '\0'; j++) {
                        if (i != j && texto2[i] == texto2[j]) {
                            break;
                        }
                    }
                    if (texto2[j] == '\0') {
                        printf("%c ", texto2[i]);
                    }
                }
                printf("\n");

                return 0;
            }



            case 7: {
                int posicionInicial;
                int posicionFinal;

                printf("Ingrese la posición inicial: ");
                scanf("%d", &posicionInicial);
                printf("Ingrese la posición final: ");
                scanf("%d", &posicionFinal);

                char *resultado = obtenerSubcadena(cadena, posicionInicial, posicionFinal);
                printf("Subcadena: %s\n", resultado);
                free(resultado);
                break;
            }
            case 8: {
                char oldChar, newChar;

                printf("Ingrese el caracter a cambiar: ");
                scanf(" %c", &oldChar);

                printf("Ingrese el caracter de reemplazo: ");
                scanf(" %c", &newChar);

                // Validar que el carácter de reemplazo sea una letra o un número
                if (!isalpha(newChar) && !isdigit(newChar)) {
                    printf("Caracter de reemplazo no valido. Debe ser una letra o un numero.\n");
                    break;
                }

                getchar(); // Limpiar el buffer de entrada

                char *resultado = changeChar(cadena, oldChar, newChar);
                printf("Cadena con caracter cambiado: %s\n", resultado);
                free(resultado);
                break;
            }
            case 9: {
                char base_text[100];
                char insert_text[100];
                int pos = 0;

                while (getchar() != '\n');

                printf("Ingrese la cadena base: ");
                fgets(base_text, sizeof(base_text), stdin);
                base_text[strcspn(base_text, "\n")] = '\0';

                printf("Ingrese la cadena para insertar: ");
                fgets(insert_text, sizeof(insert_text), stdin);
                insert_text[strcspn(insert_text, "\n")] = '\0';

                printf("Ingrese la ubicacion donde insertara la cadena: ");
                if (scanf("%i", &pos) != 1) {
                    printf("Entrada no valida para la posicion.\n");
                    while (getchar() != '\n'); // Limpiar el buffer del teclado
                    break;
                }
                while (getchar() != '\n'); // Limpiar el buffer del teclado

                // Validar posición de inserción
                int base_len = strlen(base_text);
                if (pos < 0 || pos > base_len) {
                    printf("Posicion de insercion no valida.\n");
                    break;
                }

                char *cadena_final = insertText(base_text, insert_text, pos);
                if (cadena_final == NULL) {
                    printf("Error al asignar memoria.\n");
                    break;
                }
                printf("La cadena final es: %s\n", cadena_final);
                free(cadena_final);

                break;
            }


            case 0:
                printf("Saliendo del programa...\n");
                break;
            default:
                printf("Opción invalida.\n");
        }
        fflush(stdin);
    } while (opcion != 0);

    return 0;
}

