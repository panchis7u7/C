#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAMANO 4

typedef struct registro{
	int id;
	char nombre [40];
	struct registro *ptr;			
} nv;

int main(int argc, char *argv[]) {
	nv aux2[TAMANO], aux1;
	int i, j;
	printf("Ingresa %d datos: \n\n", TAMANO);
	for (i=0; i < TAMANO; i++){
		printf("Ingresa el entero %d: ", i+1);
		scanf("%d", &aux2[i].id);
		printf("Ingresa el nombre %d: ", i+1);
		while (getchar()!='\n');
		fgets(aux2[i].nombre, 30, stdin);
		printf("\n");
	}	
	printf("Registro: \n");
	for(i=0; i < TAMANO; i++){
		printf("Id = %d | Nombre = %s", aux2[i].id, aux2[i].nombre);
	}
	
	for (j=0; j< TAMANO-1; j++){
		if(aux2[j].id < aux2[j+1].id){
			aux1 = aux2[j];
			aux2[j] = aux2[j+1];
			aux2[j+1] = aux1;
			j =-1;
		}
	}
	
	printf("\n\nID acomodados de mayor a menor: \n");	
	for(i=0; i<TAMANO; i++){
		printf("id = %d | nombre = %s", aux2[i].id, aux2[i].nombre);
	}
	
	printf("\n\nID acomodados de menor a mayor: \n");		
	for(i=0; i<TAMANO; i++){
		printf("id = %d | nombre = %s", aux2[TAMANO-i-1].id, aux2[TAMANO-i-1].nombre);
	}
	
	return 0;
}

