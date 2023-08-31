#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int es_primo(int n) {
    if (n <= 1) {
        return 0;
    }
    if (n <= 3) {
        return 1;
    }
    if (n % 2 == 0 || n % 3 == 0) {
        return 0;
    }
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) {
            return 0;
        }
    }
    return 1;
}

int count_prime_sum_representations(int num) {
    int count = 0;
    if(num == 2 || num == 3){
    	return 1;
	}
    for (int i = 2; i <= num / 2; i++) {
        if (es_primo(i)) {
            int current_sum = i;
            int j = i + 1;
            while (current_sum < num) {
                if (es_primo(j)) {
                    current_sum += j;
                    if (current_sum == num) {
                        count++;
                    }
                }
                j++;
            }
        }
    }
    if(count != 0 ){
    	return count + 1;
	}
    return count;  // Add 1 to account for the number itself as a representation
}

int main() {
	char *numerosEntrada;
    numerosEntrada = (char *)malloc(100 * sizeof(char));
	
	printf("Ingrese los numeros deseados, separados por un espacio e indique al final con 0 para finalizar y presione enter:\n");
	
	gets(numerosEntrada);
	
	int cantidadNumeros = (strlen(numerosEntrada) / 2) - 1;
	int numeros[cantidadNumeros];
	int consecutivos[cantidadNumeros];
	
	int j = 0;
	
	//Pasamos los numeros definidos en una cadena a un vector de enteros
	for(int i = 0; i < strlen(numerosEntrada) - 1; i+=2){
		numeros[j] = atoi(&numerosEntrada[i]);
		j++;
	}
	
	printf("\n");
	
    for(int i = 0; i < cantidadNumeros ; i++){
		int count = count_prime_sum_representations(numeros[i]);
        if (!es_primo(numeros[i])  && count > 0){
        	count--;
		}
        printf("%d %d %d\n", i, numeros[i], count);
	}
//    while (1) {
//        scanf("%d", &n);
//        if (n == 0) {
//            break;
//        }
//        int count = count_prime_sum_representations(n);
//        if (!es_primo(n)  && count > 0){
//        	count--;
//		}
//        printf("\nN = %d\n", count);
//    }
    return 0;
}
