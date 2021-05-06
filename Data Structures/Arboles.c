#include <stdlib.h>
#include <stdio.h>

typedef struct Nodo {
	int info;
	struct Nodo* der;
	struct Nodo* izq;
}Nodo;

Nodo* push(Nodo*, int);
void preOrden(Nodo*);
void inOrden(Nodo*);
void postOrden(Nodo*);
void busquedaManual(Nodo**);
int x;

int main(){
	Nodo* raiz = NULL;
	raiz = push(raiz, 4);
	raiz = push(raiz, 6);
	raiz = push(raiz, 3);
	raiz = push(raiz, 133);
	raiz = push(raiz, 5);
	raiz = push(raiz, 10);
	raiz = push(raiz, 9);
	raiz = push(raiz, 12);
	raiz = push(raiz, 160);
	raiz = push(raiz, 1);
	raiz = push(raiz, 34);
	raiz = push(raiz, 2);
	raiz = push(raiz, 13);
	raiz = push(raiz, 98);
	raiz = push(raiz, 56);
	raiz = push(raiz, 200);
	raiz = push(raiz, 43);
	raiz = push(raiz, 90);
	raiz = push(raiz, 189);
	raiz = push(raiz, 369);
	raiz = push(raiz, 250);
	raiz = push(raiz, 16);
	raiz = push(raiz, 123);
	raiz = push(raiz, 99);
	printf("PreOrden: ");
	preOrden(raiz);
	printf("\n");
	printf("InOrden: ");
	inOrden(raiz);
	printf("\n");
	printf("PostOrden: ");
	postOrden(raiz);
	printf("\n\n");
	busquedaManual(&raiz);
}

Nodo* push(Nodo* raiz, int x){
	if(raiz == NULL){
		Nodo* nuevo = (Nodo*)malloc(sizeof(Nodo));
		nuevo->info = x;
		raiz = nuevo;
		raiz->izq = NULL;
		raiz->der = NULL;
		return raiz;
	} else {
		if(x < raiz->info){
			raiz->izq = push(raiz->izq, x);
			return raiz;
		} else {
			if(x > raiz->info){
				raiz->der = push(raiz->der, x);
				return raiz;
			} else {
				printf("Valores duplicados");
				return raiz;
			}
		}
	}
	return raiz;
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
	if((*raiz)->der == NULL && ((*raiz)->izq == NULL)){
		printf("tu numero es: %d", (*raiz)->info);
		exit(0);
	}
	printf("\ntu posicion actual es: %d", (*raiz)->info);
	printf("\nDerecha o izquierda: ");
	printf("\n1 - Izquierda \n2 - Derecha\n");
	scanf("%d", &x);
	
	if(x != 1 && x != 2){
		busquedaManual(raiz);
	}
	if(x == 1){
		busquedaManual(&(*raiz)->izq);
	} else if (x == 2){
		busquedaManual(&(*raiz)->der);
	}
}

