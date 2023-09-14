#include<stdio.h>

int a,b;

void intercambio ( int x, int y ) {
	int tmp;
	tmp = x;
	x = y;
	y = tmp;
}

int main() {
	a = 1;
	b = 2;
	printf("Valor original de las variables\n");
	printf("Variable a: %d\n",a);
	printf("Variable b: %d\n",b);
	intercambio( a, b );
	printf("Valor de las variables despues de invocar la funcion intercambio\n");
	printf(" a = %d b = %d\n", a, b );
}