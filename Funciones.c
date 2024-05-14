//
// Created by danie on 4/05/2024.
//

#include <stdio.h>
#include <string.h>

void changeChar(char text[], char oldChar, char newChar) {
    for (int i = 0; i < strlen(text); i++) {
        if (text[i] == oldChar) {
            text[i] = newChar;
        }
    }
}

void insertText(char baseText[], char insertText[], int position) {
    int i, j;

    for (i = strlen(baseText) + strlen(insertText) - 1; i >= position + strlen(insertText); i--) {
        baseText[i] = baseText[i - strlen(insertText)];
    }

    for (j = 0; j < strlen(insertText); j++) {
        baseText[position + j] = insertText[j];
    }
}
