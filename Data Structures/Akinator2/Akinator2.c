#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

typedef struct Nodo {
	int info;
	struct Nodo* ant;
	struct Nodo* der;
	struct Nodo* izq;
	char pregunta [50];
}Nodo;

Nodo* push(Nodo*, Nodo*, int, char*);
Nodo* pushManual(Nodo*);
void modificar(Nodo*);
Nodo* editar(Nodo*);
void delay(int);
void preOrden(Nodo*);
void inOrden(Nodo*);
void postOrden(Nodo*);
void busquedaManual(Nodo**);
Nodo* importar(Nodo*);
void exportar(Nodo*);
void exportar_Recursivo(FILE*, Nodo*);
int x;
char guardarSlot = '0';

int main(){
	Nodo* raiz = NULL;
	//Nodo* raizAnt = raiz;
	char desicion;
	MAIN:
	printf("Arbol Pokemon! - Carlos Sebastian Madrigal Rodriguez\n");
	printf("------------------------------------------------------------\n");
	printf("1.- Nuevo adivinador.\n");
	printf("2.- Jugar.\n");
	printf("3.- Editar Arbol.\n");
	printf("4.- Abrir desde archivo.\n");
	printf("5.- Guardar Arbol.\n");
	printf("6.- Salir.\n");
	printf("------------------------------------------------------------\n");
	//scanf("%d", &desicion);
	desicion = getc(stdin);
	switch(desicion){
		case '1':
			OPCION1:
			if(raiz != NULL && guardarSlot != '0'){
				char desicion2;
				NOP:
				printf("Hay contenido almacenado en el arbol, desea guardar su contenido antes de crear un nuevo arbol? \n");
				printf("1.- Guardar y crear nuevo arbol.\n");
				printf("2.- No guardar y crear arbol nuevo.\n");
				printf("3.- Cancelar.\n");
				while (getchar()!='\n');
				desicion2 = getc(stdin);                 
				switch(desicion2){
					case '1':
						guardarSlot = '0';
						exportar(raiz);
						raiz = NULL;
						goto OPCION1;
						break;
					case '2':
						guardarSlot = '0';
						goto OPCION1;
						break;
					case '3':
						goto MAIN;
						break;
					default:
						system("clear");
						goto NOP;
						break;
				}
			} else {
			raiz = NULL;
			guardarSlot = '1';
			raiz = pushManual(raiz);
			system("clear");
			goto MAIN;
			}
			break;		
		case '2':
			if(raiz == NULL){
				printf("Error, No existe arbol!\n");
				delay(1000);
				goto MAIN;
			} else {
			busquedaManual(&raiz);
			system("clear");
			goto MAIN;
			}
			break;	
		case '3':
			guardarSlot = '1';
			if(raiz == NULL){
				raiz = pushManual(raiz);
			} 
			editar(raiz);
			goto MAIN;
			break;
		case '4':
			raiz = importar(raiz);
			goto MAIN;
			break;
		case '5':
			exportar(raiz);
			goto MAIN;
			break;
		case '6':
			exit(0);
			break;
		default:
			system("clear");
			goto MAIN;
			break;
		}
	printf("\n");
	printf("InOrden: ");
	inOrden(raiz);
	printf("\n");
	printf("PostOrden: ");
	postOrden(raiz);
}

Nodo* editar(Nodo* raiz){
	char desicion;
	system("clear");
	NOP5:
	system("clear");
	printf("\n\n%s\n\n", raiz->pregunta);
	printf("w -> Avanzar hacia atras.\n");
	printf("a -> Avanzar hacia la izquierda.\n");
	printf("d -> Avanzar hacia la derecha.\n");
	printf("h -> Crear subnodos.\n");
	printf("s -> Salir.\n");
	while ( getchar() != '\n' );
	desicion = getc(stdin);
	switch(desicion){
		case 'w': 
			if(raiz->ant != NULL){
			editar(raiz->ant);
		} else goto NOP5;
			break;
		case 'a':
			if(raiz->der != NULL && raiz->izq != NULL){
			editar(raiz->izq);
		} else goto NOP5;
			break;
		case 'd':
			if(raiz->der != NULL && raiz->izq != NULL){
			editar(raiz->der);
			} else goto NOP5;
			break;
		case 'h':
			raiz = pushManual(raiz);
			goto NOP5;
			break;
		case 's':
			return raiz;
			break;
		default:
			goto NOP5;
			break;
	}
	return raiz;
}

Nodo* push(Nodo* raiz, Nodo* ant, int x, char* preg){
	Nodo* antRaiz = ant;
	if(raiz == NULL){
		Nodo* nuevo = (Nodo*)malloc(sizeof(Nodo));
		//nuevo->pregunta[0] = *(preg);
		strncpy(nuevo->pregunta, preg, 50);
		nuevo->info = x;
		raiz = nuevo;
		raiz->ant = antRaiz;
		raiz->izq = NULL;
		raiz->der = NULL;
		return raiz;
	} else {
		if(x < raiz->info){
			raiz->izq = push(raiz->izq, raiz, x, preg);
			return raiz;
		} else {
			if(x > raiz->info){
				raiz->der = push(raiz->der, raiz, x,preg);
				return raiz;
			} else {
				printf("Valores duplicados");
				return raiz;
			}
		}
	}
	return raiz;
}

Nodo* pushManual(Nodo* raiz){
		Nodo* nuevo1 = (Nodo*)malloc(sizeof(Nodo));
		Nodo* nuevo2 = (Nodo*)malloc(sizeof(Nodo));
		nuevo1->izq = NULL;
		nuevo1->der = NULL;
		nuevo2->izq = NULL;
		nuevo2->der = NULL;
	if(raiz == NULL){
		//Creo mi nodo padre, hijo izquierdo e hijo derecho.
		Nodo* nuevo = (Nodo*)malloc(sizeof(Nodo));
		raiz = nuevo;
		raiz->ant = raiz;
		raiz->der = nuevo1;
		raiz->izq = nuevo2;
		nuevo1->ant = nuevo;
		nuevo2->ant = nuevo;
		////////////////////////////////////////////////////////////////
		printf("Elemento a la Derecha: ");
		while (getchar()!='\n');
		fgets(nuevo1->pregunta, 50, stdin);
		strtok(nuevo1->pregunta, "\n");
		////////////////////////////////////////////////////////////////
		printf("Elemento a la izquierda: ");
		fgets(nuevo2->pregunta, 50, stdin);
		strtok(nuevo2->pregunta, "\n");
		////////////////////////////////////////////////////////////////
		printf("Que diferencia a un %s de un %s? ", raiz->der->pregunta, raiz->izq->pregunta);
		fgets(raiz->pregunta, 50, stdin);
		strtok(nuevo1->pregunta, "\n");
		return raiz;
	} else {
		////////////////////////////////////////////////////////////////
		raiz->der = nuevo1;
		raiz->izq = nuevo2;
		nuevo1->ant = raiz;
		nuevo2->ant = raiz;
		printf("Elemento a la Derecha: ");
		while (getchar()!='\n');
		fgets(nuevo1->pregunta, 50, stdin);
		strtok(nuevo1->pregunta, "\n");
		////////////////////////////////////////////////////////////////
		printf("Elemento a la izquierda: ");
		fgets(nuevo2->pregunta, 50, stdin);
		strtok(nuevo2->pregunta, "\n");
		return raiz;
	} 
	return raiz;
}

void modificar(Nodo* raiz){
	Nodo* nuevo1 = (Nodo*)malloc(sizeof(Nodo));
	Nodo* nuevo2 = (Nodo*)malloc(sizeof(Nodo));
	nuevo1->izq = NULL;
	nuevo1->der = NULL;
	nuevo2->izq = NULL;
	nuevo2->der = NULL;
	////////////////////////////////////////////////////////////////
	raiz->der = nuevo1;
	raiz->izq = nuevo2;
	nuevo1->ant = raiz;
	nuevo2->ant = raiz;
	printf("Elemento a la Derecha: ");
	while (getchar()!='\n');
	fgets(nuevo1->pregunta, 50, stdin);
	strtok(nuevo1->pregunta, "\n");
	////////////////////////////////////////////////////////////////
	printf("Elemento a la izquierda: ");
	fgets(nuevo2->pregunta, 50, stdin);
	strtok(nuevo2->pregunta, "\n");
	////////////////////////////////////////////////////////////////
	printf("Que diferencia a un %s de un %s? ", raiz->der->pregunta, raiz->izq->pregunta);
	fgets(raiz->pregunta, 50, stdin);
	strtok(nuevo1->pregunta, "\n");
	while (getchar()!='\n');
}

void preOrden(Nodo* raiz){
	if(raiz == NULL)
	return;

	printf("%d ", raiz->info);
	preOrden(raiz->izq);
	preOrden(raiz->der);
	return;
}

void inOrden(Nodo* raiz){
	if(raiz == NULL)
	return;
	
	inOrden(raiz->izq);
	printf("%d ", raiz->info);
	inOrden(raiz->der);
	return;
}

void postOrden(Nodo* raiz){
	if(raiz == NULL)
	return;
	
	postOrden(raiz->izq);
	postOrden(raiz->der);
	printf("%d ", raiz->info);
	return;
}

void busquedaManual(Nodo** aux){
	Nodo** raiz = aux;
	char desicion, desicion2;
	if((*raiz)->der == NULL && ((*raiz)->izq == NULL)){
		printf("tu pokemon es: %s\n", (*raiz)->pregunta);
		printf("Este es el pokemon en el que pensaste?\n");
		printf("1.- Si.\n");
		printf("2.- No.\n");
		NOP2:
		desicion = getc(stdin);
		switch(desicion){
			case '1': 
				break;
			case '2':
				modificar(*raiz);
				return;
				break;
			default: 
				goto NOP2;
				break;
		}
		delay(1000);
		return;
	}
	printf("%s", (*raiz)->pregunta);
	printf("\n1 - Si \n2 - No\n");
	NOP7:
	while (getchar()!='\n');
	desicion2 = getc(stdin);
	switch(desicion2){
		case '1': 
			busquedaManual(&(*raiz)->der);
			break;
		case '2': 
			busquedaManual(&(*raiz)->izq);
			break;
		default:
			while (getchar()!='\n');
			goto NOP7;
			break;
	}
	/*
	if(x != 1 && x != 2){
		busquedaManual(raiz);
	}
	if(x == 1){
		busquedaManual(&(*raiz)->der);
	} else if (x == 2){
		busquedaManual(&(*raiz)->izq);
	}
	*/
}

Nodo* importar(Nodo* raiz){		
	char nombres[50];
	char archivo[50];
	int id;
	FILE* fp;
	NOP8:
	printf("Inserte el archivo que quiera abrir: \n");
	system("ls\n");
	while (getchar()!='\n');
	fgets(archivo, 50, stdin);
	strtok(archivo, "\n");
	if(fopen(archivo,"r+") == 0) {
			printf("Archivo Incorrecto!\n");
			delay(400);
			system("clear");
			goto NOP8;
		} else {
			fp=fopen(archivo,"r+");
		}
	//fp=fopen("Arbol_Pokemon.txt","r+");
	while(!feof(fp)){
		fscanf(fp,"%d\n", &id);
		fgets(nombres, 50, fp);
		raiz = push(raiz, raiz, id, nombres);
	}
	fclose(fp);
	system("clear");
    return raiz;
}

void exportar(Nodo* raiz)
{
    FILE *fp;
    fp=fopen("Arbol_Pokemon.txt","w+");
    exportar_Recursivo(fp, raiz);
    fclose(fp);
}

void exportar_Recursivo(FILE* fp, Nodo* raiz)
{
    if(raiz!=NULL)
    {
		fprintf(fp, "%d\n%s", raiz->info, raiz->pregunta);
        exportar_Recursivo(fp, raiz->izq);
        exportar_Recursivo(fp, raiz->der);
    }
}

void delay(int segundos) 
{ 
    int milli_segundos = 1000 * segundos; 
    clock_t inicio = clock(); 
    while (clock() < inicio + milli_segundos); 
} 
