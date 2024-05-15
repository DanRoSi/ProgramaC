#ifndef TALLERCOLABORATIVO_FUNCIONES_H
#define TALLERCOLABORATIVO_FUNCIONES_H

char* diferenciaEntreTextos(char* primera, char* segunda);
char* obtenerSubcadena(char* cadena, int posicionInicial, int posicionFinal);
char* rellenarCadena(char* cadena, char caracter, int direccion, int numCaracteres);
char* eliminarCaracteresRepetidos(const char* cadena);
char* changeChar(char text[], char old, char new);
char* insertText(char base_text[], char insert_text[],int pos);

#endif //TALLERCOLABORATIVO_FUNCIONES_H