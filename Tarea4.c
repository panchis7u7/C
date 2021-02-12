#include "stdlib.h"
#include "stdio.h"

typedef struct Nodo {
	int info;
	struct Nodo *sig;
}Nodo;

/*
typedef struct Lista {
	Nodo* raiz;
	Nodo* aux;
}Lista;
*/

void ins(Nodo**, int);
void borrarFinal(Nodo**);
void borrar(Nodo**, int x);
void borrarInicio(Nodo** raiz);
void despachar(Nodo**);
Nodo* anterior(Nodo**, int);
Nodo* buscar(Nodo**, int);
void imprimir(Nodo**);

int main(){
	Nodo* raiz = NULL;
	ins(&raiz, 2);
	ins(&raiz, 6);
	ins(&raiz, 3);
	imprimir(&raiz);
	despachar(&raiz);
	imprimir(&raiz);
	ins(&raiz, 7);
    ins(&raiz, 10);
	ins(&raiz, 55);
	imprimir(&raiz);
    despachar(&raiz);
	imprimir(&raiz);
	borrarInicio(&raiz);
	imprimir(&raiz);
	borrar(&raiz, 100);
	imprimir(&raiz);
	return 0;
}

void ins(Nodo** raiz, int x){
	Nodo* nuevo = (Nodo*)malloc(sizeof(Nodo));
	if(nuevo != NULL){
		if(raiz == NULL){
			*raiz = nuevo;
			nuevo->info = x;
			nuevo->sig = NULL;
		} else {
			nuevo->info = x;
			nuevo->sig = *raiz;
			*raiz = nuevo;
		}
	}
}

void borrarFinal(Nodo** raiz){
	Nodo* le = *raiz;
	if(raiz == NULL){
		
	} else {
		while(le->sig->sig != NULL)
		le = le->sig;
		Nodo* nuevo = le->sig;
		le->sig = NULL;
		free(nuevo);
	}
}

void borrar(Nodo** raiz, int x){
	if(raiz == NULL){
		printf("la lista esta vacia!\n");
		return;
	} 
	if (buscar(raiz, x) == NULL){
		printf("No hay elemento con tal dato!\n");
		return;
	}
	if((*raiz)->info == x){
		borrarInicio(raiz);
	} else {
	Nodo* le, *ele;
	le = anterior(raiz, x);
	ele = le->sig; 
	le->sig = ele->sig;
	free(ele);	
}
}

void borrarInicio(Nodo** raiz){
	if(*raiz != NULL && (*raiz)->sig != NULL){
	Nodo* le = *raiz;
	*raiz = le->sig;
	free(le);
} else return;
}

void despachar(Nodo** raiz){
	Nodo* le = *raiz;
	while(le->sig->sig != NULL){
		le=le->sig;
	}
	Nodo* nuevo = le->sig;
	le->sig = NULL;
	nuevo->sig = *raiz;
	*raiz = nuevo;
}

Nodo* anterior(Nodo** raiz, int x){
	if(raiz == NULL && (*raiz)->sig == NULL)
	return NULL;
	Nodo* le = *raiz;
	while(le->sig != NULL && le->sig->info != x){
		le = le->sig;
	}
	return le;
}

Nodo* buscar(Nodo** raiz, int x){
	if(raiz == NULL){
		return NULL;
	}
	Nodo* le = *raiz;
	while(le->sig != NULL){
		le = le->sig;
		if(le->info == x){
			return le;
		}
	}
	return NULL;
}

void imprimir(Nodo** raiz){
	Nodo* le = *raiz;
	printf("|-");
	while(le != NULL){
		printf("|%d|-", le->info);
		le= le->sig;
	}
	printf(">\n");
}
