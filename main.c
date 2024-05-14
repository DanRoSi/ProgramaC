#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void mostrarMenu() {
    printf("\n--- Menu ---\n");
    printf("1. Modificar caracter\n");
    printf("2. Insertar texto\n");
    printf("3. Salir\n");
    printf("Ingrese la opcion deseada: ");
}

int main() {
    int opcion;
    char text[100], oldChar, newChar;
    char baseText[100], insertText[100];
    int position;

    do {
        mostrarMenu();
        scanf("%d", &opcion);
        fflush(stdin);

        switch (opcion) {
            case 1:
                printf("Ingrese la cadena que desea modificar: ");
                fgets(text, sizeof(text), stdin);
                text[strcspn(text, "\n")] = '\0';
                printf("Ingrese el caracter a reemplazar: ");
                scanf(" %c", &oldChar);
                fflush(stdin);
                printf("Ingrese el caracter de reemplazo: ");
                scanf(" %c", &newChar);
                fflush(stdin);

                changeChar(text, oldChar, newChar);
                printf("Cadena modificada: %s\n", text);
                break;

            case 2:
                printf("Ingrese la cadena base: ");
                fgets(baseText, sizeof(baseText), stdin);
                baseText[strcspn(baseText, "\n")] = '\0';
                printf("Ingrese la cadena a insertar: ");
                fgets(insertText, sizeof(insertText), stdin);
                insertText[strcspn(insertText, "\n")] = '\0';
                printf("Ingrese la posicion para insertar: ");
                scanf("%d", &position);

                insertText(baseText, insertText, position);
                printf("Cadena con texto insertado: %s\n", baseText);
                break;

            case 3:
                printf("Saliendo del programa...\n");
                break;

            default:
                printf("Opcion no valida. Por favor, seleccione una opcion valida.\n");
        }

    } while (opcion != 3);

    return 0;
}
