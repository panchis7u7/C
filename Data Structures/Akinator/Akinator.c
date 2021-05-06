#include <stdlib.h>
#include <stdio.h>

typedef struct Nodo {
	int info;
	struct Nodo* der;
	struct Nodo* izq;
	char* pregunta [50];
}Nodo;

Nodo* push(Nodo*, int, char[]);
void preOrden(Nodo*);
void inOrden(Nodo*);
void postOrden(Nodo*);
void busquedaManual(Nodo**);
void exportar(Nodo*);
void exportar_Recursivo(FILE*, Nodo*);
int x;

int main(){
	Nodo* raiz = NULL;
	raiz = push(raiz, 66, "Es Humanoide?");
	////////////////////////////////////////////////////////////////////
	raiz = push(raiz, 36, "Es Objeto?");
	raiz = push(raiz, 50, "Es mayor a 2da generacion?");
	raiz = push(raiz, 20, "Es Legendario?");
	raiz = push(raiz, 10, "Es de tipo Normal?");
	raiz = push(raiz, 6, "Tiene 2 atributos elementales?");
	raiz = push(raiz, 14, "Es de primera generacion?");
	raiz = push(raiz, 4, "Es amarillo?");
	raiz = push(raiz, 8, "Es un dragon?");
	raiz = push(raiz, 12, "Puede Volar?");
	raiz = push(raiz, 18, "Puede hablar?");
	raiz = push(raiz, 16, "Es un oso?");
	raiz = push(raiz, 26, "Es un dragon?");
	raiz = push(raiz, 24, "Creo el universo?");
	raiz = push(raiz, 22, "Es un ave y controla el hielo?");
	raiz = push(raiz, 32, "Es de 5ta Generacion?");
	raiz = push(raiz, 30, "Esta basado en el quetzacoatl?");
	raiz = push(raiz, 34, "Es blanco?");
	raiz = push(raiz, 28, "Controla el espacio?");
	raiz = push(raiz, 44, "Tiene forma de bolas o es un conjunto de bolas?");
	raiz = push(raiz, 60, "Es tipo Roca?");
	raiz = push(raiz, 64, "Parece una estatua?");
	raiz = push(raiz, 62, "Se parece a un sol?");
	raiz = push(raiz, 56, "Se reensambla a un objeto del hogar?");
	raiz = push(raiz, 58, "Es un candelabro?");
	raiz = push(raiz, 52, "Es tipo acero psiquico?");
	raiz = push(raiz, 54, "Tiene forma de campana?");
	raiz = push(raiz, 5, "Pikachu!");
	raiz = push(raiz, 1, "Wobuffet!");
	raiz = push(raiz, 3, "Magikarp!");
	raiz = push(raiz, 11, "Zigzagon!");
	raiz = push(raiz, 13, "Swellow!");
	raiz = push(raiz, 19, "Meowth!");
	raiz = push(raiz, 15, "Rattata!");
	raiz = push(raiz, 17, "Zigzagon!");
	raiz = push(raiz, 7, "Psyduck!");
	raiz = push(raiz, 9, "Charizard!");
	raiz = push(raiz, 25, "Arceus!");
	raiz = push(raiz, 21, "Moltres!");
	raiz = push(raiz, 23, "Articuno!");
	raiz = push(raiz, 27, "Dialga!");
	raiz = push(raiz, 29, "Palkia!");
	raiz = push(raiz, 31, "Rayquaza!");
	raiz = push(raiz, 33, "Zekrom!");
	raiz = push(raiz, 35, "Reshiram!");
	raiz = push(raiz, 37, "Muk!");
	raiz = push(raiz, 39, "Unown!");
	raiz = push(raiz, 41, "Onix!");
	raiz = push(raiz, 43, "Staryu!");
	raiz = push(raiz, 45, "Magnamite!");
	raiz = push(raiz, 47, "Voltorb!");
	raiz = push(raiz, 49, "Weezing!");
	raiz = push(raiz, 51, "Klinklang!");
	raiz = push(raiz, 53, "Metagross!");
	raiz = push(raiz, 55, "Bronzong!");
	raiz = push(raiz, 57, "Klefkey!");
	raiz = push(raiz, 59, "Chandeleir!");
	raiz = push(raiz, 61, "Lunatone!");
	raiz = push(raiz, 63, "Solrock!");
	raiz = push(raiz, 65, "Nosepass!");
	////////////////////////////////////////////////////////////////////
	raiz = push(raiz, 104, "Es un luchador?");
	raiz = push(raiz, 88, "Es psiquico?");
	raiz = push(raiz, 80, "Es arriba de 3ra Generacion?");
	raiz = push(raiz, 100, "Es legendario?");
	raiz = push(raiz, 84, "Tiene mas de un elemento?");
	raiz = push(raiz, 108, "Usa las manos para pelear?");
	raiz = push(raiz, 120, "Tiene mas de un elemento?");
	raiz = push(raiz, 106, "Tiene forma de trompo?");
	raiz = push(raiz, 124, "Son pokemones iniciales?");
	raiz = push(raiz, 122, "Su personaje parece luchador mexicano?");
	raiz = push(raiz, 128, "Es de 3ra Generacion?");
	raiz = push(raiz, 126, "Es de 4ta Generacion?");
	raiz = push(raiz, 118, "Utiliza objetos?");
	raiz = push(raiz, 114, "Es arriba de 3ra Generacion?");
	raiz = push(raiz, 112, "Es de 3ra Generacion?");
	raiz = push(raiz, 116, "Es de color azul?");
	raiz = push(raiz, 110, "Es de 2da Generacion?");
	
	
	exportar(raiz);
	busquedaManual(&raiz);
	printf("\n\n");
	printf("PreOrden: ");
	preOrden(raiz);
	printf("\n");
	printf("InOrden: ");
	inOrden(raiz);
	printf("\n");
	printf("PostOrden: ");
	postOrden(raiz);
	
}

Nodo* push(Nodo* raiz, int x, char preg[50]){
	if(raiz == NULL){
		Nodo* nuevo = (Nodo*)malloc(sizeof(Nodo));
		nuevo->pregunta[0] = preg;
		nuevo->info = x;
		raiz = nuevo;
		raiz->izq = NULL;
		raiz->der = NULL;
		return raiz;
	} else {
		if(x < raiz->info){
			raiz->izq = push(raiz->izq, x, preg);
			return raiz;
		} else {
			if(x > raiz->info){
				raiz->der = push(raiz->der, x,preg);
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
		printf("tu pokemon es: %s", *(*raiz)->pregunta);
		exit(0);
	}
	printf("%s", *(*raiz)->pregunta);
	printf("\nDerecha o izquierda: ");
	printf("\n1 - Si \n2 - No\n");
	scanf("%d", &x);
	
	if(x != 1 && x != 2){
		busquedaManual(raiz);
	}
	if(x == 1){
		busquedaManual(&(*raiz)->der);
	} else if (x == 2){
		busquedaManual(&(*raiz)->izq);
	}
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
		fprintf(fp, "%d\n%s\n", raiz->info, *(raiz->pregunta));
        exportar_Recursivo(fp, raiz->izq);
        exportar_Recursivo(fp, raiz->der);
    }
}
