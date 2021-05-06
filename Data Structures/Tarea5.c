#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <curses.h>

typedef struct Cliente {
	int kilos;
	struct Cliente* sig;
}Cliente;

void ins(Cliente**, int);
void prioridad(Cliente**, int);
void borrarInicio(Cliente**);
void imprimir(Cliente**);
void delay(int); 

int main(){
	Cliente* raiz = NULL;
	time_t t;
	int n, desicion, kilosP, i = 0;
	srand((unsigned) time(&t));
	printf("----------------Tortilleria Chencho----------------\n");
	printf("Escoga una opcion de la simulacion de la tortilleria: \n");
	printf("1.- Cola convencional.\n");
	printf("2.- Cola de prioridad.\n");
	printf("3.- Salir.\n");
	scanf("%d", &desicion);
	switch(desicion){
		case 1:
		printf("Inserte el numero de iteraciones: ");
		scanf("%d", &n);
			for (i = 0; i < n; i++)
			{
			int desicion2 = (rand() % 2) + 1;
			switch(desicion2){
				case 1:
					kilosP = (rand() % 6) + 1;
					ins(&raiz, kilosP);
					delay(600);
					system("clear");
					printf("----------------Tortilleria Chencho----------------\n\n");
					imprimir(&raiz);
					break;
				case 2: 
					delay(600);
					system("clear");
					borrarInicio(&raiz);
					printf("----------------Tortilleria Chencho----------------\n\n");
					imprimir(&raiz);
					break;
				default:
					printf("Error!");
					break;
			}
		}
			break;
		case 2:
		printf("Inserte el numero de iteraciones: ");
		scanf("%d", &n);
			for (i = 0; i < n; i++)
			{
			int desicion2 = (rand() % 2) + 1;
			switch(desicion2){
				case 1:
					kilosP = (rand() % 6) + 1;
					prioridad(&raiz, kilosP);
					delay(600);
					system("clear");
					printf("----------------Tortilleria Chencho----------------\n\n");
					imprimir(&raiz);
					break;
				case 2: 
					delay(600);
					system("clear");
					borrarInicio(&raiz);
					printf("----------------Tortilleria Chencho----------------\n\n");
					imprimir(&raiz);
					break;
				default:
					printf("Error!");
					break;
			}
		}
			break;
		case 3:
			exit(0);
			break;
		default:
			printf("Error!");
			break;
	}
	}

void ins(Cliente** raiz, int x){
	Cliente* le = *raiz;
	Cliente* nuevo = (Cliente*)malloc(sizeof(Cliente));
	if(nuevo != NULL){
		nuevo->kilos = x;
	if((*raiz) == NULL){
		*raiz = nuevo;
		nuevo->sig = NULL;
	}else{
	while(le->sig != NULL){
		le = le->sig;
	}
	le->sig = nuevo;
	nuevo->sig = NULL;
}
}
}

void prioridad(Cliente** raiz, int x){
	Cliente* nuevo = (Cliente*)malloc(sizeof(Cliente));
	if(nuevo != NULL){
		nuevo->kilos = x;
		Cliente* le = *raiz;
		Cliente* post = NULL;
		if(*raiz == NULL){
			*raiz = nuevo;
			nuevo->sig = NULL;
		} else {
			while(le->sig != NULL && le->sig->kilos > x){
				le = le->sig;
			}
			if((*raiz)->kilos > nuevo->kilos){
			if(le->sig != NULL){
				post = le->sig;
				le->sig = nuevo;
				nuevo->sig = post;
			} else {
				le->sig = nuevo;
				nuevo->sig = NULL;
			}
		} else {
			nuevo->sig = *raiz;
			*raiz = nuevo;
		}
	}
	}
}

void borrarInicio(Cliente** raiz){
	if(*raiz != NULL){
	Cliente* le = *raiz;
	*raiz = (*raiz)->sig;
	le->sig = NULL;
	free(le);
} else return;
}

void imprimir(Cliente** raiz){
	Cliente* le = *raiz;
	printf("|-");
	while(le != NULL){
		printf("|%d|-", le->kilos);
		le= le->sig;
	}
	printf(">\n");
	if(raiz == NULL)
	printf("Todos los clientes se han despachado!\n\n");
}

void delay(int segundos) 
{ 
    int milli_segundos = 1000 * segundos; 
    clock_t inicio = clock(); 
    while (clock() < inicio + milli_segundos); 
} 
