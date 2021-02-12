#include <stdlib.h>
#include <stdio.h>
#include <curses.h>
#include <time.h>
#define FILAS 6
#define COLS 8

void imprimir(char mapa[][COLS], int, int);
void recorrer(char mapa[][COLS], int, int);
void isla(char mapa[][COLS], int, int);
void delay(int);

int islas = 0, numCasillasRec = 0, casillas = (FILAS)*(COLS);

int main(){
	char mapa[FILAS][COLS] = {{' ',' ',' ',' ',' ',' ',' ',' '},
							  {' ','#','#',' ','#','#',' ',' '},
							  {' ','#','#',' ',' ','#','#',' '},
							  {' ',' ',' ',' ',' ',' ',' ',' '},
							  {' ','#',' ','#','#','#',' ',' '},
							  {' ','#',' ',' ',' ',' ',' ',' '}};
	imprimir(mapa,0,0);
	recorrer(mapa,0,0);
	printf("No de islas = %d", islas);
}

void imprimir(char mapa[][COLS], int filas, int columnas){
	if(filas >= FILAS){
		return;
	} else {
		if(columnas >= COLS){
			printf("\n\n");
			imprimir(mapa, filas+1, columnas = 0);
		} else {
			printf("  %c  ", mapa[filas][columnas]);
			imprimir(mapa, filas, columnas+1);
		}
	}
}

void recorrer(char mapa[][COLS], int x, int y){
	if(numCasillasRec == casillas){
		system("clear");
		imprimir(mapa,0,0);
		return;
	}
	
	if(mapa[x][y] == '#'){
		isla(mapa, x, y);
		islas++;
	}
	
	if(mapa[x][y] == ' ' && x >= 0 && x < FILAS && y >= 0 && y < COLS){
		numCasillasRec++;
		system("clear");
		imprimir(mapa,0,0);
		delay(100);
		mapa[x][y] = '*';
		recorrer(mapa, x, y-1);
		system("clear");
		imprimir(mapa,0,0);
		delay(100);
		recorrer(mapa, x-1, y);
		system("clear");
		imprimir(mapa,0,0);
		delay(100);
		recorrer(mapa, x, y+1);
		system("clear");
		imprimir(mapa,0,0);
		delay(100);
		recorrer(mapa, x+1, y);
		system("clear");
		imprimir(mapa,0,0);
		delay(100);
	} else return;
}

void isla(char mapa [][COLS], int x, int y){
	if(mapa[x][y] == '#' && x >= 0 && x < FILAS && y >= 0 && y < COLS){
		numCasillasRec++;
		system("clear");
		imprimir(mapa,0,0);
		delay(100);
		mapa[x][y] = '%';
		isla(mapa, x, y-1);
		system("clear");
		imprimir(mapa,0,0);
		delay(100);
		isla(mapa, x-1, y);
		system("clear");
		imprimir(mapa,0,0);
		delay(100);
		isla(mapa, x, y+1);
		system("clear");
		imprimir(mapa,0,0);
		delay(100);
		isla(mapa, x+1, y);
		system("clear");
		imprimir(mapa,0,0);
		delay(100);
	} else return;
}

void delay(int segundos) 
{ 
    int milli_segundos = 1000 * segundos; 
    clock_t inicio = clock(); 
    while (clock() < inicio + milli_segundos); 
} 
