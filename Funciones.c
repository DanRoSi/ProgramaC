//
// Created by danie on 4/05/2024.
//

#include <string.h>
#include "Funciones.h"

void changeChar(char text[], char oldChar, char newChar) {
    for (int i = 0; i < strlen(text); i++) {
        if (text[i] == oldChar) {
            text[i] = newChar;
        }
    }
}

void insertText(char baseText[], char insertText[], int position) {
    int i;

    for (i = strlen(baseText); i >= position; --i) {
        baseText[i + strlen(insertText)] = baseText[i];
    }

    for (i = 0; i < strlen(insertText); ++i) {
        baseText[position + i] = insertText[i];
    }
}

