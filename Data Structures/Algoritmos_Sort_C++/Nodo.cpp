#include <iostream>
#include "Nodo.h"
#include <sstream>
using namespace std;

Nodo::Nodo(int dato) {
	info = dato;
	sig = NULL;
}

Nodo::Nodo() {
	info = -1;
	sig = NULL;
}

Nodo::~Nodo() {
	cout << "[" << info << "]" << " ha sido destruido" << endl;
}