#include<stdio.h>

int main(void) {
	int m, *p, **q; //q es un puntero a puntero
	m = 7;
	p = &m;
	q = &p; //P recibe la DIRECCION de un PUNTERO
	**q = 17;
	printf ("%d, %d", m, **q); //¿Que imprime aquí?
	return 0;
}