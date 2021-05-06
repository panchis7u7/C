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

//void ins(Nodo**, int);
void insInicio(Nodo**, int);
void insFinal(Nodo**, int);
void borrarFinal(Nodo**);
void borrar(Nodo**, int x);
void borrarInicio(Nodo** raiz);
void despachar(Nodo**);
Nodo* anterior(Nodo**, int);
Nodo* buscar(Nodo**, int);
void imprimir(Nodo**);

int main(){
	Nodo* raiz = NULL;
	int choice;
	int x = 0;
                printf("\n***Menu de operaciones de una lista enlazada simple:****\n");
                printf("\n                MENU                             \n");
                printf("---------------------------------------\n");
                printf("\n Bubble Sort");
                printf("\n 2.Insertion Sort  ");
                printf("\n 3.Selection Sort  ");
                printf("\n 4.Merge Sort      ");
                printf("\n 5.Quick Sort     ");
                printf("\n 6.Salir       ");
                printf("\n--------------------------------------\n");
                do{
				printf("Ingresa tu opcion: ");
                scanf("%d",&choice);
                switch(choice)
                {
                        case 1:
										imprimir(&raiz);
                                        break;
                        case 2:

                                        break;
                        case 3: 

                                        break;
                        case 4:			

                                        break;
                        case 5:

                                        break;
                        case 6:

                                        break;
                        case 7:
                                        exit(0);
                                        break;
                        default:
                                        printf("\n Opcion Incorrecta!\n");
                                        break;
									}
                } while(choice != 7);
	//ins(&raiz, 2);
	//ins(&raiz, 6);
	//ins(&raiz, 3);
	//imprimir(&raiz);
	//despachar(&raiz);
	//imprimir(&raiz);
	//ins(&raiz, 7);
    //ins(&raiz, 10);
	//ins(&raiz, 55);
	//imprimir(&raiz);
    //despachar(&raiz);
	//imprimir(&raiz);
	//borrarInicio(&raiz);
	//imprimir(&raiz);
	//borrar(&raiz, 7);
	//imprimir(&raiz);
	return 0;
}
//void ins(Nodo** raiz, int x){
	//Nodo* le = *raiz;
	//Nodo* nuevo = (Nodo*)malloc(sizeof(Nodo));
	//if(nuevo != NULL){
		//if(raiz == NULL)
		//insInicio(&raiz, x);
		//while(le->info != x){
			//le = le-> sig;
		//}
	//}
//}

void insInicio(Nodo** raiz, int x){
	Nodo* nuevo = (Nodo*)malloc(sizeof(Nodo));
	if(nuevo != NULL){
		if((*raiz) == NULL){
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

void insFinal(Nodo** raiz, int x){
	Nodo* le = *raiz;
	Nodo* nuevo = (Nodo*)malloc(sizeof(Nodo));
	if(nuevo != NULL){
		nuevo->info = x;
	if((*raiz) == NULL){
		insInicio(raiz, x);
	}else{
	while(le->sig != NULL){
		le = le->sig;
	}
	le->sig = nuevo;
	nuevo->sig = NULL;
}
}
}

void borrarFinal(Nodo** raiz){
	Nodo* le = *raiz;
	if(raiz == NULL){
		return;
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
	ele->sig = NULL;
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
