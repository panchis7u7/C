#include <stdlib.h>
#include <stdio.h>
#define FILAS 5
#define COLS 5
#define DIMENSION 25

void imprimir(int matriz[][COLS], int, int);
void ordenarMayor(int matriz[][COLS]);
void ordenarMenor(int matriz[][COLS]);

int main(){
	int matriz[FILAS][COLS] = {{3, 6, 5, 4, 11},
							  {12, 1, 2, 15, 10},
							  {91, 31, 211, 14, 65},
							  {21, 13, 61, 8, 9},
							  {16, 17, 18, 271, 7}};
	//imprimir(matriz, 0, 0);
	ordenarMayor(matriz);
	imprimir(matriz, 0, 0);
	printf("\n\n");
	ordenarMenor(matriz);
	imprimir(matriz, 0, 0);
}

void imprimir(int matriz[][COLS], int filas, int columnas){
	if(filas >= FILAS){
		return;
	} else {
		if(columnas >= COLS){
			printf("\n\n");
			imprimir(matriz, filas+1, columnas = 0);
		} else {
			printf("  %d  ", matriz[filas][columnas]);
			imprimir(matriz, filas, columnas+1);
		}
	}
}

/*	idea de ordenar matriz con un solo ciclo for
void ordenar(int matriz[][COLS]){
	int i, filas = 0, aux, j;
	for(i = 0; i < COLS-1; i++){
		if((i+1) == COLS && matriz[filas][i] < matriz[filas+1][0]){
		j = i;
		i = 0;
		filas += 1;
		aux = matriz[filas-1][j];
		matriz[filas-1][j] = matriz[filas][i];
		matriz[filas-1][i] = aux;
		i = -1;
	} else {
		if(matriz[filas][i] < matriz[filas][i+1]){
				aux = matriz[filas][i];
				matriz[filas][i] = matriz[filas][i+1];
				matriz[filas][i+1] = aux;
				i = -1;
			}
		}
	}
}*/

void ordenarMayor(int matriz[][COLS]){
	int i, j, k, l, aux;
	for (i = 0; i < FILAS; i++) {
		for (j = 0; j < COLS; j++) {
			aux = matriz[i][j];
			l = j + 1;
		for (k = i; k < FILAS; k++) {
			while (l < COLS) {
			if (aux < matriz[k][l]){
				aux = matriz[k][l];
				matriz[k][l] = matriz[i][j];
				matriz[i][j] = aux;
					}
				l++;
				}	
			l = 0;
			}
		}
	}
}

void ordenarMenor(int matriz[][COLS]){
	int i, j, k, l, aux;
	for (i = 0; i < FILAS; i++) {
		for (j = 0; j < COLS; j++) {
			aux = matriz[i][j];
			l = j + 1;
		for (k = i; k < FILAS; k++) {
			while (l < COLS) {
			if (aux > matriz[k][l]){
				aux = matriz[k][l];
				matriz[k][l] = matriz[i][j];
				matriz[i][j] = aux;
					}
				l++;
				}	
			l = 0;
			}
		}
	}
}
