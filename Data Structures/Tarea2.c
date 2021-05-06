#include <stdio.h>
#include <stdlib.h>
#define PI 3.1416

void cuadrado (float, float*);
void rectangulo (float, float, float*);
void circulo (float, float*);
void triangulo (float, float, float*);
void trapecio(float, float, float, float*);

int main()
{
  float a = 5, b = 3, c = 2;
  float rest = 0; 
  cuadrado(a, &rest);
  printf("area del cuadrado: %f\n", rest);
  rectangulo(a,b, &rest);
  printf("area del rectangulo: %f\n", rest);
  circulo(a, &rest);
  printf("area del circulo: %f\n", rest);
  triangulo(a,b, &rest);
  printf("area del triangulo: %f\n", rest);
  trapecio(a,b,c,&rest);
  printf("area del trapecio: %f\n", rest);
  system("PAUSE");	
  return 0;
}

void cuadrado (float a, float* res){
     *res = a*a;
     }
void rectangulo (float a, float b, float* res){
     *res = a*b;
     }
void circulo (float a, float* res){
     *res = PI*(a*a);
     }
void triangulo (float a, float b, float* res){
     *res = (a*b)/2;
     }
void trapecio(float a, float b, float c, float* res){
     *res = (b+c)*a/2;
     }
