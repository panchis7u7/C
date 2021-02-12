#include <stdlib.h>
#include <stdio.h>
#include <curses.h>
#include <time.h>
#define COLS 10
#define FILAS 8

void imprimir(char laberinto [][COLS]);
void imprimirRec(char laberinto [][COLS], int, int);
void recorrer(char laberinto [][COLS], int, int);
void delay(int);

int main(){
	char laberinto [FILAS][COLS] = {{' ','#',' ','#',' ','#',' ',' ',' ',' ',},
									{' ','#',' ',' ',' ','#',' ','#','#',' ',},
									{' ','#',' ','#',' ',' ',' ','#',' ',' ',},
									{' ','#',' ',' ',' ','#',' ','#',' ',' ',},
									{' ',' ',' ','#',' ','#',' ','#',' ','#',},
									{' ','#',' ',' ',' ',' ',' ','#',' ','#',},
									{' ','#','#','#','#',' ',' ','#',' ',' ',},
									{' ',' ',' ',' ','#',' ',' ','#',' ','S',}};
	imprimirRec(laberinto,0,0);
	recorrer(laberinto,0,0);
	imprimirRec(laberinto,0,0);
}

//funcion imprimir con iteracion
void imprimir(char laberinto [][COLS]){
	system("clear");
	int i = 0, j = 0;
	for (i = 0; i < FILAS; i++)
	{
		for (j = 0; j < COLS; j++)
		{
			printf("  %c  ", laberinto[i][j]);
		}
		printf("\n");
	}
}

//funcion imprimir con recursividad
void imprimirRec(char laberinto[][COLS], int filas, int columnas){
	if(filas >= FILAS){
		return;
	}else{
		if(columnas >= COLS){
			printf("\n\n");
			imprimirRec(laberinto, filas+1, columnas = 0);
		} else {
			printf("  %c  ", laberinto[filas][columnas]);
			imprimirRec(laberinto, filas, columnas+1);
		}
	}	
}

void recorrer(char laberinto[][COLS], int x, int y){
	if(laberinto[x][y] == 'S'){
		system("clear");
		laberinto[x][y] = 'P';
		imprimirRec(laberinto,0,0);
		exit(0);
	}
		if(laberinto[x][y] == ' ' && x >= 0 && x < FILAS && y >= 0 && y < COLS){
			system("clear");
			imprimirRec(laberinto,0,0);
			delay(100);
			laberinto[x][y] = 'P';
			recorrer(laberinto, x, y-1);
			system("clear");
			imprimirRec(laberinto,0,0);
			delay(100);
			recorrer(laberinto, x-1, y);
			system("clear");
			imprimirRec(laberinto,0,0);
			delay(100);
			recorrer(laberinto, x, y+1);
			system("clear");
			imprimirRec(laberinto,0,0);
			delay(100);
			recorrer(laberinto, x+1, y);
			system("clear");
			imprimirRec(laberinto,0,0);
			delay(100);
			} else {
			delay(100);
			return;
	}
}


void delay(int segundos) 
{ 
    int milli_segundos = 1000 * segundos; 
    clock_t inicio = clock(); 
    while (clock() < inicio + milli_segundos); 
} 
