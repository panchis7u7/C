// EstructuraDeDatosC++.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include "Lista.h"
#include "Nodo.h"
using namespace std;

int main()
{
	Lista* lista1 = new Lista("Lista1");
	lista1->ins(4);
	lista1->ins(3);
	lista1->insInicio(10);
	lista1->ins(4);
	lista1->ver();
	Nodo* encontrado = lista1->buscar(4);
	cout << *encontrado << endl;
	Nodo* anterior = lista1->anterior(4);
	cout << *anterior << endl;
	lista1->del(4);
	lista1->ver();
	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
