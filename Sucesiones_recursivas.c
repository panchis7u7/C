#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>

//a) 8, 3, -2, -7, -12 ...	
//8-(n-1)n
void a(int, int);

//b) 3, 6, 12, 24, 36 ...
//3*2^(n-1)
void b(int, int);

//c) 4, 9, 16, 25, 36 ...
//(n+1)^2
void c(int, int);

//d) 5, 10, 17, 26, 37, 50 ...
//n^2 + 2n +2 
void d(int, int);

//e) 6, 11, 18, 27, 38, 51 ...
//n^2 + 2n +3
void e(int, int);

//f) 3, 8, 15, 24, 35 ...
//n^2+2n
void f(int, int);

//g) -4, 9, -16, 25, -36, 49 ...
//(-1)^n*(n+1)^2
void g(int, int);

//h) 2/4, 5/9, 8/16, 11/25, 14/36 ...
//(2+(n-1)*3) / ((n+1) ^ 2)
void h(double, double);

//i) -5/1, 7/2, -9/3, 11/4, -13/5 ...
//(-1)^n*[(5+(n-1)*2)/n]
void i(double, double);
void delay(int);

int main(){
	int desicion =  0, limiteSup = 0, inicio = 0;
	printf("--------------------------------------------------------\n");
	printf("1. 8-(n-1)n\n");
	printf("2. 3*2^(n-1)\n");
	printf("3. (n+1)^2\n");
	printf("4. n^2 + 2n +2\n");
	printf("5. n^2 + 2n +3\n");
	printf("6. n^2+2n\n");
	printf("7. (-1)^n*(n+1)^2\n");
	printf("8. (2+(n-1)*3) / ((n+1) ^ 2)\n");
	printf("9. (-1)^n*[(5+(n-1)*2)/n]\n");
	printf("10. Salir\n");
	printf("--------------------------------------------------------\n\n");
	printf("Que serie quieres imprimir? ");
	scanf("%d", &desicion);
	switch(desicion){
		case 1:
			printf("Hasta que posicion quieres imprimir? ");
			scanf("%d", &limiteSup);
			printf("Desde que posicion quieres partir? ");
			scanf("%d", &inicio);
			printf("Sucesion: \n\n");
			a(limiteSup, inicio);
			printf("\n\n");
			main();
			break;
		case 2:
			printf("Hasta que posicion quieres imprimir? ");
			scanf("%d", &limiteSup);
			printf("Desde que posicion quieres partir? ");
			scanf("%d", &inicio);
			printf("Sucesion: \n\n");
			b(limiteSup, inicio);
			printf("\n\n");
			main();
			break;
		case 3:
			printf("Hasta que posicion quieres imprimir? ");
			scanf("%d", &limiteSup);
			printf("Desde que posicion quieres partir? ");
			scanf("%d", &inicio);
			printf("Sucesion: \n\n");
			c(limiteSup, inicio);
			printf("\n\n");
			main();
			break;
		case 4:
			printf("Hasta que posicion quieres imprimir? ");
			scanf("%d", &limiteSup);
			printf("Desde que posicion quieres partir? ");
			scanf("%d", &inicio);
			printf("Sucesion: \n\n");
			d(limiteSup, inicio);
			printf("\n\n");
			main();
			break;
		case 5:
			printf("Hasta que posicion quieres imprimir? ");
			scanf("%d", &limiteSup);
			printf("Desde que posicion quieres partir? ");
			scanf("%d", &inicio);
			printf("Sucesion: \n\n");
			e(limiteSup, inicio);
			printf("\n\n");
			main();
			break;
		case 6:
			printf("Hasta que posicion quieres imprimir? ");
			scanf("%d", &limiteSup);
			printf("Desde que posicion quieres partir? ");
			scanf("%d", &inicio);
			printf("Sucesion: \n\n");
			f(limiteSup, inicio);
			printf("\n\n");
			main();
		case 7:
			printf("Hasta que posicion quieres imprimir? ");
			scanf("%d", &limiteSup);
			printf("Desde que posicion quieres partir? ");
			scanf("%d", &inicio);
			printf("Sucesion: \n\n");
			g(limiteSup, inicio);
			printf("\n\n");
			main();
			break;
		case 8:
			printf("Hasta que posicion quieres imprimir? ");
			scanf("%d", &limiteSup);
			printf("Desde que posicion quieres partir? ");
			scanf("%d", &inicio);
			printf("Sucesion: \n\n");
			h(limiteSup, inicio);
			printf("\n\n");
			main();
			break;
		case 9:
			printf("Hasta que posicion quieres imprimir? ");
			scanf("%d", &limiteSup);
			printf("Desde que posicion quieres partir? ");
			scanf("%d", &inicio);
			printf("Sucesion: \n\n");
			i(limiteSup, inicio);
			printf("\n\n");
			main();
			break;
		case 10:
			exit(0);
			break;
		default:
			printf("\nOpcion incorrecta!, intente de nuevo\n");
			delay(800);
			system("clear");
			main();
			break;
	}
}

void a(int x, int y){
	if(y == x)
	return;
	
	if(y == 0){
		printf("0, ");
		a(x, y+1);
	} else {
	int res = 8-(y-1)*5;
	printf("%d, ", res);
	a(x, y+1);
	}
}

void b(int x, int y){
	if(y == x)
	return;
	
	if(y == 0){
		printf("0, ");
		b(x, y+1);
	} else {
	int res = 3*(pow(2,(y-1)));
	printf("%d, ", res);
	b(x, y+1);
	}
}

void c(int x, int y){
	if(y == x)
	return;
	
	if(y == 0){
		printf("0, ");
		c(x, y+1);
	} else {
	int res = pow((y+1), 2);
	printf("%d, ", res);
	c(x, y+1);
	}
}

void d(int x, int y){
	if(y == x)
	return;
	
	if(y == 0){
		printf("0, ");
		d(x, y+1);
	} else {
	int res = pow(y, 2) + (2*y) + 2;
	printf("%d, ", res);
	d(x, y+1);
	}
}

void e(int x, int y){
	if(y == x)
	return;
	
	if(y == 0){
		printf("0, ");
		e(x, y+1);
	} else {
	int res = pow(y, 2) + (2*y) + 3;
	printf("%d, ", res);
	e(x, y+1);
	}
}

void f(int x, int y){
	if(y == x)
	return;
	
	if(y == 0){
		printf("0, ");
		f(x, y+1);
	} else {
	int res = pow(y, 2) + (2*y);
	printf("%d, ", res);
	f(x, y+1);	
	}
}

void g(int x, int y){
	if(y == x)
	return;
	
	if(y == 0){
		printf("0, ");
		g(x, y+1);
	} else {
	int res = pow(-1, y) * pow(y+1, 2);
	printf("%d, ", res);
	g(x, y+1);	
	}
}

void h(double x, double y){
	//(3+(n-1)*3) / ((n+1) ^ 2)
	if(y == x)
	return;
	
	if(y == 0){
		printf("0, ");
		h(x, y+1);
	} else {
	//double res = (2 + (y-1) * 3) / pow((y+1), 2);
	int numerador = (2 + (y-1) * 3);
	int denominador = pow((y+1), 2);
	printf("%d/%d, ", numerador, denominador);
	h(x, y+1);	
	}
}

void i(double x, double y){
	//(-1)^n*[(5+(n-1)*2)/n]
	if(y == x)
	return;
	
	if(y == 0){
		printf("0, ");
		i(x, y+1);
	} else {
	//double res = pow(-1, y) * ((5 + (y-1) * 2) / y);
	int numerador = pow(-1, y) * (5 + (y-1) * 2);
	int denominador = y;
	printf("%d/%d, ", numerador, denominador);
	i(x, y+1);
	}	
}

void delay(int segundos) 
{ 
    int milli_segundos = 1000 * segundos; 
    clock_t inicio = clock(); 
    while (clock() < inicio + milli_segundos); 
} 
