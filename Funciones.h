#ifndef TALLERCOLABORATIVO_FUNCIONES_H
#define TALLERCOLABORATIVO_FUNCIONES_H

int buscarPrimeraOcurrenciaCadena(char *cadena, char *subcadena, int posicionInicio);
int iniciaConCadena(char *cadenaBase, char *cadenaVerificar);
void ordenarCadenaIgnorandoMayusculas(char *cadena);
char* rellenarCadenaConCaracter(char* cadena, char caracter, int direccion, int numCaracteres);
char* eliminarCaracteresRepetidosCadena(const char* cadena);
char* diferenciaEntreCadenas(char* primera, char* segunda);
char* obtenerSubcadena(char* cadena, int posicionInicial, int posicionFinal);
char* changeChar(char text[], char old, char new);
char* insertText(char base_text[], char insert_text[], int pos);


#endif //TALLERCOLABORATIVO_FUNCIONES_H