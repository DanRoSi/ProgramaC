#include <stdio.h>
#include <string.h>
#include <malloc.h>

int sub_str(const char *str, const char *sub, int init) ;
int isPrefix(char* str,char* prefix);
char* orderedString(char str[]);
int main() {
    const char *str = "puto";
    const char *sub = "Hola";
//    int init = 1;
//
//    int index = sub_str(str, sub, init);
//    if (index != 0) {
//        printf("La cadena '%s' fue encontrada en el índice %d.\n", sub, index);
//    } else {
//        printf("La cadena'%s' no fue encontrada.\n", sub);
//    }

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