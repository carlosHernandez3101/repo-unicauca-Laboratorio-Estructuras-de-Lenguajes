#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 100

typedef struct {
    char *texto;
} Linea;

typedef struct {
    Linea *lineas;
    int numLineas;
} Documento;

Documento* crearDocumento() {
    Documento *doc = (Documento*)malloc(sizeof(Documento));
    doc->lineas = NULL;
    doc->numLineas = 0;
    return doc;
}

void addLinea(Documento *doc, const char *texto) {
    if (doc == NULL) {
        return;
    }
    
    Linea nuevaLinea;
    nuevaLinea.texto = strdup(texto); // Duplicar la cadena para evitar problemas de memoria

    doc->lineas = (Linea*)realloc(doc->lineas, (doc->numLineas + 1) * sizeof(Linea));
    doc->lineas[doc->numLineas] = nuevaLinea;
    doc->numLineas++;
}

void eliminarLinea(Documento *doc, int index) {
    if (doc == NULL || index < 0 || index >= doc->numLineas) {
        return;
    }

    free(doc->lineas[index].texto);

    for (int i = index; i < doc->numLineas - 1; i++) {
        doc->lineas[i] = doc->lineas[i + 1];
    }

    doc->numLineas--;
    doc->lineas = (Linea*)realloc(doc->lineas, doc->numLineas * sizeof(Linea));
}

void modificarLinea(Documento *doc, int index, const char *nuevoTexto) {
    if (doc == NULL || index < 0 || index >= doc->numLineas) {
        return;
    }

    free(doc->lineas[index].texto);
    doc->lineas[index].texto = strdup(nuevoTexto);
}

void eliminarDocumento(Documento *doc) {
    if (doc == NULL) {
        return;
    }

    for (int i = 0; i < doc->numLineas; i++) {
        free(doc->lineas[i].texto);
    }

    free(doc->lineas);
    free(doc);
}

int main() {
    Documento *doc = crearDocumento();
    int opcion;
    int index;
    char buffer[MAX_LINE_LENGTH];
    
    printf("       EDITOR DE LINEAS DE TEXTO EN C\n");

    while (1) {
        printf("\nEditor de Lineas de Texto\n");
        printf("1. Agregar nueva linea\n");
        printf("2. Eliminar linea\n");
        printf("3. Modificar linea\n");
        printf("4. Mostrar documento\n");
        printf("5. Salir\n");
        printf("Ingrese su eleccion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                printf("\n    Ingrese la nueva linea de texto: ");
                getchar(); // Consumir el carácter de nueva línea en el búfer
                fgets(buffer, sizeof(buffer), stdin);
                addLinea(doc, buffer);
                break;
            case 2:
                printf("\n    Ingrese el indice de la linea que desea eliminar: ");
                scanf("%d", &index);
                eliminarLinea(doc, index);
                break;
            case 3:
                printf("\n    Ingrese el indice de la linea que desea modificar: ");
                scanf("%d", &index);
                printf("    Ingrese el nuevo texto: ");
                getchar();
                fgets(buffer, sizeof(buffer), stdin);
                modificarLinea(doc, index, buffer);
                break;
            case 4:
                printf("\n    Documento de lineas de texto:\n");
                for (int i = 0; i < doc->numLineas; i++) {
                    printf("    %d: %s", i, doc->lineas[i].texto);
                }
                break;
            case 5:
                eliminarDocumento(doc);
                return 0;
            default:
                printf("\n    Eleccion no valida. Por favor, ingrese un numero del 1 al 5.\n");
                break;
        }
    }

    return 0;
}
