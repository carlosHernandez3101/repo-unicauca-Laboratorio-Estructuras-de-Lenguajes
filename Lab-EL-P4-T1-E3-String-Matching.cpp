#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encontrarCoincidencias(char *texto, char *patron) {
	int M = strlen(patron);
	int N = strlen(texto);
	int numeroDeCoincidencias = 0;
	
	for (int i = 0; i <= N - M; i++) {
		int j;
		for (j = 0; j < M; j++) {
			if (texto[i + j] != patron[j])
				break;
		}
		if (j == M) {
			numeroDeCoincidencias++;
			//printf("Coincidencia encontrada en la posición: %d\n", i);
		}
	}
	printf("   Se encontraron %d coincidencias del patron dentro del texto", numeroDeCoincidencias);
}

int main() {
	char *texto;
    texto = (char *)malloc(100 * sizeof(char));
    
    char *patron;
    patron = (char *)malloc(100 * sizeof(char));
    
	//char texto[] = "Este es un ejemplo de texto en el que buscamos un ejemplo";
	//char patron[] = "em";
	
	printf("            BUSCADOR DE COINCIDENCIAS - STRING MATCHING\n\n");
	
	printf("Ingrese el TEXTO al que se buscaran coincidencias: ");
	gets(texto);
	
	printf("Ingrese el PATRON al que se buscaran coincidencias dentro del texto: ");
	gets(patron);	

	printf("\n   Texto: %s\n", texto);
	printf("   Patron: %s\n\n", patron);

	encontrarCoincidencias(texto, patron);

	return 0;
}
