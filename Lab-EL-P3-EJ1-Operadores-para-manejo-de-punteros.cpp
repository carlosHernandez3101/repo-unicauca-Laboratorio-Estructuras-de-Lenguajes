#include<stdio.h>

int main() {
	int *p;//p es un Apuntador a una variable entera
	int x;
	char *p1; //p2 es un Apuntador a una variable carácter
	char c;
	x = 3;
	c = 'd';
	p = &x;//Al apuntador p se le asignó la dirección de la variable x
	p1 = &c; //Al apuntador p1 se le asignó la dirección de la variable c
	printf(" Imprimiendo el contenido de la variable X= %d usando el puntero",*p);
	printf(" \nImprimiendo la direccion de memoria de la variable X= %d usando el puntero",p);
	printf(" \nImprimiendo la direccion de memoria de la variable X= %d usando el operador &",&x);
	return 0;
}