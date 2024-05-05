#include <stdio.h>
#include <string.h>

int sub_str(const char *str, const char *sub, int init) {
    int len = strlen(str);
    int sublen = strlen(sub);
    if (init < 0 || init >= strlen) {
        return -1;
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

int main() {
    const char *str = "Hola, esto es un ejemplo.";
    const char *sub = "ejemplo";
    int init = 1;

    int indice = sub_str(str, sub, init);
    if (indice != 0) {
        printf("La cadena '%s' fue encontrada en el índice %d.\n", sub, indice);
    } else {
        printf("La cadena'%s' no fue encontrada.\n", sub);
    }

    return 0;
}
