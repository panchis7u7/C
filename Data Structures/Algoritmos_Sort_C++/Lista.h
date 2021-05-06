#pragma once
using namespace std;
#include <String>
#include "Nodo.h"

class Lista
{
public:
	Lista(string id);
	~Lista();
	void ins(int dato);
	void insInicio(int dato);
	Nodo* buscar(int dato);
	Nodo* anterior(int dato);
	void del(int dato);
	void ver();
	Nodo* obtenerPorIndice(int indice);
	int cantidad();
	bool estaVacia();

private:
	Nodo* le;
	Nodo* ancla;
	string identificacion = "Lista Nueva";
};

