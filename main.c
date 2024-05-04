#include<string.h>
#include <stdio.h>
int equals(char a[],char b[]);
int findingOcurrence(char str[],char sub[],int init);
int main(){
    char a[]="cola";
    char b[]="holassss";

    printf("%d",findingOcurrence(&a,&b,2));
    return 0;
}
int findingOcurrence(char str[],char sub[],int init) {
    if (init < 0) {
        return -1;
    }
    if (strlen(str) < strlen(sub)) {
        return -2;
    }
    char *resultado = strstr(str, sub);

    if (resultado != NULL) {
        int pos=resultado - str;
        return pos;
    } else {
        return 0;
    }
}

