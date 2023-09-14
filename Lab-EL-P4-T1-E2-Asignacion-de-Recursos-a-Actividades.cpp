#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	int inicio;
	int fin;
	int id;
}Actividad;

int comparar(const void *a, const void *b) {
    return ((Actividad*)a)->fin - ((Actividad*)b)->fin;
}

void seleccionarActividades(Actividad actividades[], int n){
	
	qsort(actividades, n, sizeof(Actividad), comparar);
	
	Actividad actividadFin = actividades[0];
	
	printf("Actividad %d seleccionada: [%d |----| %d]\n",actividades[0].id, actividades[0].inicio, actividades[0].fin);
	
	for(int i = 1; i < n; i++){
		if(actividades[i].inicio >= actividadFin.fin){
			printf("Actividad %d seleccionada: [%d |----| %d]\n",actividades[i].id, actividades[i].inicio, actividades[i].fin);
			actividadFin = actividades[i];
		}
	}
	
}

int main(){
	
	int numeroActividades;
	printf("Ingrese el numero de actividades: ");
	scanf("%d", &numeroActividades);
	
	Actividad actividades[numeroActividades];
	
	printf("\nIngrese los tiempos de inicio separado por espacio del tiempo final:\n");
	
	for(int i = 0; i < numeroActividades; i++){
		printf("Tiempo de la actividad No %d: ", i + 1);
		scanf("%d %d", &actividades[i].inicio, &actividades[i].fin);
		actividades[i].id = i + 1;
	}
	
	printf("\n");

    seleccionarActividades(actividades, numeroActividades);

	return 0;
}