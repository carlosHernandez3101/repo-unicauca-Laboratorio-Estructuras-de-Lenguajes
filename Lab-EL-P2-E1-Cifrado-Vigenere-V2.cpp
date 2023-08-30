#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char vigenereMatrix[26][26];
char abecedario[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

void generarVigenereMatrix();
void generarClaveConCifradoCesar(char cadena[], char clave[]);
void generarClaveConCifradoVigerene(char cadena[], char claveEnCesar[], char claveEnVigerene[]);
int encontrarPosicionCaracter(char caracter);

int main() {
	generarVigenereMatrix();
	char *nombre;
    nombre = (char *)malloc(100 * sizeof(char)); 
    
    char claveEnCesar[strlen(nombre)];
    char claveEnVigerene[strlen(nombre)];
    
	printf("Introduzca su nombre: \n");
	gets(nombre);
	
	generarClaveConCifradoCesar(nombre, claveEnCesar);
	
	printf("\nClave cifrada CESAR: %s\n", claveEnCesar);
	
	generarClaveConCifradoVigerene(nombre, claveEnCesar, claveEnVigerene);
	
	printf("\nClave cifrada VIGERENE: %s\n", claveEnVigerene);
    return 0;
}

int encontrarPosicionCaracter(char caracter){	
	int posicion = -1;	
	for(int i = 0; i < strlen(abecedario); i++){
		if(abecedario[i] == caracter){
			return i;			
		}		
	}	
	return posicion;
}

void generarClaveConCifradoVigerene(char cadena[], char claveEnCesar[], char claveEnVigerene[]){
	int posicionCaracter = -1;
	int posicionClave = -1;
	for(int i = 0; i < strlen(cadena); i++){
		posicionCaracter = encontrarPosicionCaracter(cadena[i]);
		posicionClave = encontrarPosicionCaracter(claveEnCesar[i]);
		claveEnCesar[i] = vigenereMatrix[posicionCaracter][posicionClave];
	}
}

void generarClaveConCifradoCesar(char cadena[], char claveEnCesar[]){
	for(int i = 0; i < strlen(cadena); i++){
		claveEnCesar[i] = 'A' + (cadena[i] - 'A' + 3) % 26;
	}
}

void generarVigenereMatrix() {
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < 26; j++) {
            vigenereMatrix[i][j] = 'A' + (i + j) % 26;
        }
    }    
    //Mostrar Matriz
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < 26; j++) {
            printf("%c ", vigenereMatrix[i][j]);
        }
        printf("\n");
    }
    
    printf("\n");
}


