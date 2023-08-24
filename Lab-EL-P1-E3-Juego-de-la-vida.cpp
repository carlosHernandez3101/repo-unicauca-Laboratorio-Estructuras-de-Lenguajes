#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// Dimensiones del tablero
#define FILAS 20
#define COLUMNAS 40

// Función para imprimir el tablero
void imprimirTablero(int tablero[FILAS][COLUMNAS]) {
    system("clear"); // Cambiar a "cls" en Windows
    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            if (tablero[i][j] == 1) {
                printf("#");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

// Función para calcular el siguiente estado del tablero
void siguienteGeneracion(int tablero[FILAS][COLUMNAS]) {
    int nuevoTablero[FILAS][COLUMNAS];
    
    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            int vecinosVivos = 0;
            
            // Contar vecinos vivos
            for (int x = -1; x <= 1; x++) {
                for (int y = -1; y <= 1; y++) {
                    if (x == 0 && y == 0) continue;
                    if (i + x >= 0 && i + x < FILAS && j + y >= 0 && j + y < COLUMNAS) {
                        vecinosVivos += tablero[i + x][j + y];
                    }
                }
            }
            
            // Aplicar reglas del juego
            nuevoTablero[i][j] = tablero[i][j];
            if (tablero[i][j] == 1) {
                if (vecinosVivos < 2 || vecinosVivos > 3) {
                    nuevoTablero[i][j] = 0;
                }
            } else {
                if (vecinosVivos == 3) {
                    nuevoTablero[i][j] = 1;
                }
            }
        }
    }
    
    // Copiar el nuevo tablero al original
    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            tablero[i][j] = nuevoTablero[i][j];
        }
    }
}

int main() {
    int tablero[FILAS][COLUMNAS] = {0};
    
    // Inicializar el tablero con células vivas aleatorias
    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            tablero[i][j] = rand() % 2;
        }
    }
    
    while (1) {
        imprimirTablero(tablero);
        siguienteGeneracion(tablero);
        usleep(10000); //Esperar 0.1 segundos
    }
    
    return 0;
}
