#include <stdio.h>
#include <stdlib.h>

void serie1(int);
void serie2(int);
void serie3(int);

int main(){
	printf("\nEscoja la serie a imprimir: \n");
	printf("1.- n \n");
	printf("2.- 2n \n");
	printf("3.- 3n \n");
	int desicion;
	scanf("%d", &desicion);
	switch(desicion){
		case 1:
			serie1(1);
			main();
			break;
		case 2:
			serie2(1);
			main();
			break;
		case 3:
			serie3(1);
			main();
			break;
		default:
			printf("Error1");
			system("clear");
			main();
			break;
	}
}

void serie1(int x){
	if(x > 10000)
	return;
	printf("%d ", x);
	serie1(x+1);
}

void serie2(int x){
	if(2*x > 16)
	return;
	printf("%d ", 2*x);
	serie2(x+1);
}

void serie3(int x){
	if(3*x > 18)
	return;
	printf("%d ", 3*x);
	serie3(x+1);
}
