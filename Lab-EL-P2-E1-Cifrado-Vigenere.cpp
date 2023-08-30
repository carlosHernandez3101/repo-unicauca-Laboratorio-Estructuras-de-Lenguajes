#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

struct persona {
	char nombre[50];
} p;
struct cifrado {
	char matrizA[27][27];
} c;
void generarDato(char abc[]);
void llenarMatriz(char abc[]);
void generarContrasenia(char clave[],char abc[],char nombre[]);

int main() {
	system("title Cifrado Vigenére - Carlos Hernández");
	char abecedario[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	generarDato(abecedario);
	printf("\n");
	system("pause");
	return 0;
}
void generarDato(char abc[]) {
	printf("Introduzca su nombre: \n");
	printf("\n");
	gets(p.nombre);
	//Generar clave de acuerdo al nombre
	int n, a, t;
	t = strlen(p.nombre);
	char clave[t];
	int m = 0;
	for(a = 0; a < strlen(p.nombre); a++) {
		for(n = 0; n < strlen(abc); n++) {
			if(p.nombre[a] == abc[n]) {
				if(n == 25) {
					clave[m] = abc[0+2];
				} else if(n == 24) {
					clave[m] = abc[0+1];
				} else if(n == 23) {
					clave[m] = abc[0];
				} else {
					clave[m] = abc[n+3];
				}
				m++;
			}
		}
	}
	//
	printf("\nClave cifrada: %s\n", clave);
	printf("\n");
	generarContrasenia(clave, abc, p.nombre);
}
void generarContrasenia(char clave[], char abc[], char nombre[]) {
	llenarMatriz(abc);
	char abecedario[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	int t = strlen(nombre);
	char contrasenia[t];
	int i, j, m, n, o, p, q;
	i = -1;
	j = -1;
	p = 0;
	q = 0;
	for(m = 0; m < t; m++) {
		for(n = 0; n < 26; n++) {
			if(nombre[p] == abecedario[n]) {
				i = n+1;
			}
		}
		for(o = 0; o < 26; o++) {
			if(clave[p] == abecedario[o]) {
				j = o + 1;
			}
		}
		contrasenia[m] = c.matrizA[i][j];
		p++;
		q++;
	}
	printf("\nEstimado usuario se le ha asignado la siguiente clave de acceso: %s\n",contrasenia);
}
void llenarMatriz(char vectorA[]) {
	int i, j, m, n, z;
	z = 0;
	for(i = 0; i < 27; i++) {
		for(j = 0; j < 27; j++) {
			if(i == 0 && j == 0) {
				c.matrizA[i][j] = '*';
			} else {
				if(z == 26) {
					z = 0;
					c.matrizA[i][j] = vectorA[z];
				} else {
					c.matrizA[i][j] = vectorA[z];
				}
				z++;
			}
		}
	}

	for(m = 0; m < 27; m++) {
		for(n = 0; n < 27; n++) {
			printf("%c ", c.matrizA[m][n]);
		}
		printf("\n");
	}
}