#include <stdio.h>
#include <stdlib.h>

void ordenarInv(int*);

int main() {
	int aux[10];
	int i=0;
	for(i=0; i<10; i++){
		aux[i] = i;
		printf("| %d |", aux[i]);
	}
	printf("\n");
	ordenarInv(&aux[9]);
	return 0;
}

void ordenarInv(int* aux){
	int i=0;
	for(i=0; i<10; i++){
		printf("| %d |", *aux);
		aux--;
	}
}
