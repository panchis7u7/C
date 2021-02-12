#include <stdlib.h>
#include <stdio.h>

int fibonacciRec(int);
void fibonacciIt(int);
unsigned long long factorialRec(int);
unsigned long long factorialIt(int);
unsigned long long resultado;

int main()
{	
	int desicion, n, fibo;
	unsigned long long fact = 0;
	printf("---------------------------------------\n");
	printf("Que opcion quiere seleccionar: \n");
	printf("1.-Fibonacci Recursivo.\n");
	printf("2.-Fibonacci Iterativo.\n");
	printf("3.-Factorial Recursivo.\n");
	printf("4.-Factorial Iterativo.\n");
	printf("---------------------------------------\n");
	scanf("%d", &desicion);
	switch(desicion){
		case 1:
		printf("Ingrese el numero de valores a imprimir de la serie: ");
		scanf("%d", &n);
		fibo = fibonacciRec(n);
		printf("%d", fibo);
		break;
		case 2:	
		printf("Ingrese el numero de valores a imprimir de la serie: ");
		scanf("%d", &n);
		fibonacciIt(n);
		break;
		case 3:
		printf("Ingrese un entero para sacar su fatorial: ");
		scanf("%d", &n);
		printf("\nEl factorial de %d es: ", n);
		fact = factorialRec(n);
		printf("%llu", fact);
		break;
		case 4:
		printf("Ingrese un entero para sacar su fatorial: ");
		scanf("%d", &n);
		printf("\nEl factorial de %d es: ", n);
		fact = factorialIt(n);
		printf("%llu", fact);
		break;
		default:
		printf("No selecciono nada!");
		break;
}
   return 0;
}

int fibonacciRec(int n){
	if(n == 1 || n == 0)
	return n;
	
	return fibonacciRec(n-2) + fibonacciRec(n-1);
}

void fibonacciIt(int n){
	int primero = 0, segundo= 1;
	unsigned long long siguiente, c;
	
	for (c = 0; c < n; c++)
	{
    if (c <= 1)
      siguiente = c;
    else
    {
      siguiente = primero + segundo;
      primero = segundo;
      segundo = siguiente;
    }
    printf("%lld, ", siguiente);
  }
}

unsigned long long factorialRec(int n){
	if(n == 1 || n == 0)
	return 1;	
	
	resultado = n * factorialRec(n-1);
	return resultado;
}

unsigned long long factorialIt(int n){
	int i;
    unsigned long long factorial = 1;
    if (n < 0)
        printf("Error! Factorial no existe! ");
    else
    {
        for(i=1; i<=n; ++i)
        {
            factorial *= i;              // factorial = factorial*i;
        }
    }
    return factorial;
}
