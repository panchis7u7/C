#include "stdlib.h"
#include "stdio.h"

typedef struct Nodo {
	int info;
	struct Nodo *sig;
	struct Nodo *ant;
}Nodo;

void prioridad(Nodo**, int);
Nodo* prioridadRec(Nodo*, int);
void insInicio(Nodo**, int);
//void insFinal(Nodo**, int);
Nodo* insFinal(Nodo*, int);
void ins(Nodo**, int, int);
//void imprimirSig(Nodo**);
void imprimirSig(Nodo*);
void imprimirAnt(Nodo**);

int main(){
	Nodo* raiz = NULL;
	//insInicio(&raiz, 8);
	//insInicio(&raiz, 7);
	//insInicio(&raiz, 6);
	//printf("\n");
	//imprimirSig(&raiz);
	//imprimirAnt(&raiz);
	//insFinal(&raiz, 2);
	//insFinal(&raiz, 3);
	//insFinal(&raiz, 4);
	//printf("\n");
	//imprimirSig(&raiz);
	//imprimirAnt(&raiz);
	//ins(&raiz, 5, 3);
	//insInicio(&raiz,5);
	//ins(&raiz, 10, 5);
	//ins(&raiz, 3, 5);
	//printf("\n");
	//prioridad(&raiz, 3);
	//prioridad(&raiz, 8);
	//prioridad(&raiz, 5);
	//prioridad(&raiz, 2);
	//prioridad(&raiz, 5);
	//prioridad(&raiz, 1);
	//prioridad(&raiz, 6);
	//raiz = insFinal(raiz, 2);
	//raiz = insFinal(raiz, 6);
	//raiz = insFinal(raiz, 14);
	//raiz = insFinal(raiz, 3);
	raiz = prioridadRec(raiz, 11);
	raiz = prioridadRec(raiz, 10);
	raiz = prioridadRec(raiz, 8);
	raiz = prioridadRec(raiz, 12);
	raiz = prioridadRec(raiz, 9);
	raiz = prioridadRec(raiz, 1);
	raiz = prioridadRec(raiz, 20);
	raiz = prioridadRec(raiz, 8);
	raiz = prioridadRec(raiz, 13);
	raiz = prioridadRec(raiz, 6);
	imprimirSig(raiz);
	imprimirAnt(&raiz);
}

void insInicio(Nodo** raiz, int x){
	Nodo* nuevo = (Nodo*)malloc(sizeof(Nodo));
	if(nuevo != NULL){
		nuevo->info = x;
		if((*raiz) == NULL){
			*raiz = nuevo;
			nuevo->sig = NULL;
			nuevo->ant = NULL;
		} else {
			nuevo->sig = *raiz;
			(*raiz)->ant = nuevo;
			nuevo->ant = NULL;
			*raiz = nuevo;
		}
	}
}
/* Funcion insFinal sin recursividad
void insFinal(Nodo** raiz, int x){
	Nodo* nuevo = (Nodo*)malloc(sizeof(Nodo));
	if(nuevo != NULL){
		Nodo* le = *raiz;
		nuevo->info = x;
	if((*raiz) == NULL){
		*raiz = nuevo;
		nuevo->sig = NULL;
		nuevo->ant = NULL;
	}else{
	while(le->sig != NULL){
		le = le->sig;
	}
	le->sig = nuevo;
	nuevo->ant = le;
	nuevo->sig = NULL;
}
}
}*/

Nodo* insFinal(Nodo* raiz, int x){
	if(raiz == NULL){
		Nodo* nuevo = (Nodo*)malloc(sizeof(Nodo));
		nuevo->info = x;
		nuevo->sig = NULL;
		nuevo->ant = NULL;
		raiz = nuevo;
		return raiz;
	} else if(raiz->sig == NULL){
		Nodo* nuevo = (Nodo*)malloc(sizeof(Nodo));
		nuevo->info = x;
		raiz->sig = nuevo;
		nuevo->ant = raiz;
		return raiz;
	} else {
		raiz->sig = insFinal(raiz->sig, x);
		return raiz;
	}
}

//prioridad sin recursion
void prioridad(Nodo** raiz, int x){
	Nodo* nuevo = (Nodo*)malloc(sizeof(Nodo));
	if(nuevo != NULL){
		nuevo->info = x;
		Nodo* le = *raiz;
		Nodo* post = NULL;
		if(*raiz == NULL){
			*raiz = nuevo;
			nuevo->sig = NULL;
			nuevo->ant = NULL;
		} else {
			while(le->sig != NULL && le->sig->info > x){
				le = le->sig;
			}
			if((*raiz)->info > nuevo->info){
			if(le->sig != NULL){
				post = le->sig;
				nuevo->sig = post;
				post->ant = nuevo;
				le->sig = nuevo;
				nuevo->ant = le;
			} else {
				le->sig = nuevo;
				nuevo->ant = le;
				nuevo->sig = NULL;
			}
		} else {
			nuevo->sig = *raiz;
			(*raiz)->ant = nuevo;
			*raiz = nuevo;
		}
	}
	}
}

//Prioridad con recursion
Nodo* prioridadRec(Nodo* raiz, int x){
	if(raiz == NULL){
		Nodo* nuevo = (Nodo*)malloc(sizeof(Nodo));
		if(nuevo != NULL){
			nuevo->info = x;
			raiz = nuevo;
			nuevo->sig = NULL;
			nuevo->ant = NULL;
			return raiz;
		}
	} else {
		if(raiz->sig == NULL){
			if(x <= raiz->info){
				Nodo* nuevo = (Nodo*)malloc(sizeof(Nodo)); 
				nuevo->info = x;
				raiz->sig = nuevo;
				nuevo->ant = raiz;
				nuevo->sig = NULL;
				return raiz;
			} else if(x > raiz->info){
				Nodo* nuevo = (Nodo*)malloc(sizeof(Nodo));
				nuevo->info = x;
				nuevo-> sig = raiz;
				nuevo->ant = raiz->ant;
				raiz->ant = nuevo;
				raiz = nuevo;
				return raiz;
			}
		} else {
			if(x <= raiz->info){
				raiz->sig = prioridadRec(raiz->sig, x);
				return raiz;
			} else if (x > raiz->info && raiz->ant == NULL){
				Nodo* nuevo = (Nodo*)malloc(sizeof(Nodo));
				nuevo->info = x;
				nuevo->sig = raiz;
				raiz->ant = nuevo;
				nuevo->ant = NULL;
				raiz = nuevo;
				return raiz;	
			} else {
				Nodo* nuevo = (Nodo*)malloc(sizeof(Nodo));
				raiz->ant->sig = nuevo;
				nuevo->ant = raiz->ant;
				nuevo->sig = raiz;
				raiz->ant = nuevo;
				//raiz = nuevo;
				return raiz;
			}
		}
	}
	return raiz;
}

void ins(Nodo** raiz, int dato, int x){
	Nodo* nuevo = (Nodo*)malloc(sizeof(Nodo));
	if(nuevo != NULL){
		Nodo* le = *raiz;
		nuevo->info = dato;
		if(*raiz == NULL ){
			*raiz = nuevo;
			nuevo->sig = NULL;
			nuevo->ant = NULL;
		} else {
			while(le->sig != NULL && le->info != x){
				le = le->sig;
			}		
				if(le->sig != NULL){
					nuevo->sig = le->sig;
					le->sig = nuevo;
					nuevo->sig->ant = nuevo;
					nuevo->ant = le;	
				}else{
					nuevo->sig = *raiz;
					(*raiz)->ant = nuevo;
					*raiz = nuevo;
			}
		}
	}
}

/*Funcion imprimir-Sig sin recursividad
void imprimirSig(Nodo** raiz){
	Nodo* le = *raiz;
	printf("<-");
	while(le != NULL){
		printf("|%d|-", le->info);
		le= le->sig;
	}
	printf("|\n");
}*/

//funcion imprimir-Sig recursiva
void imprimirSig(Nodo* raiz){
	if(raiz == NULL){
		printf(">\n");
	return;
} else {
	printf("|%d|-", raiz->info);
	imprimirSig(raiz->sig);
}
}

void imprimirAnt(Nodo** raiz){
	Nodo* le = *raiz;
	printf("<-");
	while(le->sig != NULL){
		le= le->sig;
	}
	while(le != NULL){
		printf("|%d|-", le->info);
		le = le->ant;
	}
	printf("|\n");
}
