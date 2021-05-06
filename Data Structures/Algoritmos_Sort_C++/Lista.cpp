#include <iostream>
#include "Lista.h"
#include <sstream>
using namespace std;

Lista::Lista(string id) {
	identificacion = id;
	ancla = new Nodo(-1);
	ancla->sig = NULL;
	le = ancla;
}

Lista::~Lista() {
	cout << "{" << identificacion << "}" << " ha sido destruida" << endl;
}

void Lista::ins(int dato) {
	le = ancla;
	Nodo* nuevo = new Nodo(dato);
	while (le->sig != NULL) {
		le = le->sig;
	}
	le->sig = nuevo;
	nuevo->sig = NULL;
}

void Lista::insInicio(int dato) {
	le = ancla;
	Nodo* nuevo = new Nodo(dato);
	nuevo->sig = ancla->sig;
	ancla->sig = nuevo;
}

Nodo* Lista::buscar(int dato) {
	le = ancla;
	while (le->sig != NULL) {
		le = le->sig;
		if (le->info == dato) {
			return le;
		}
	}
	return NULL;
}

Nodo* Lista::anterior(int dato) {
	le = ancla;
	while (le->sig != NULL && le->sig->info != dato)
		le = le->sig;
	return le;
}

void Lista::del(int dato) {
	le = ancla;
	Nodo* tmp = le;
	Nodo* encontrado = buscar(dato);
	do {
		tmp = encontrado;
		anterior(dato)->sig = tmp->sig;
		tmp->sig = NULL;
		delete tmp;
		tmp = le; 
		encontrado = buscar(dato);
	} while ((encontrado != NULL) && (estaVacia() != true));
}

void Lista::ver() {
	le = ancla;
	cout << "la lista " << identificacion << " tiene los elementos:" << endl;
	cout << "<";
	while (le->sig != NULL) {
		le = le->sig;
		cout << "-[" << le->info << "]";
	}
	cout << "-|" << endl;
}

Nodo* Lista::obtenerPorIndice(int indice) {
	le = ancla;
	int contador = -1;
	while (le->sig != NULL) {
		le = le->sig;
		if (contador == indice)
			return le;
	}
	return le;
}

int Lista::cantidad() {
	le = ancla;
	int contador = 0;
	while (le->sig != NULL) {
		le = le->sig;
		contador++;
	}
	return contador;
}

bool Lista::estaVacia() {
	return (ancla == NULL) ? true : false;
}
