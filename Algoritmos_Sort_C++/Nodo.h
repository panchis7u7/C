#pragma once
#include <iostream>
using namespace std;

struct Nodo
{
	int info;
	Nodo* sig;
	Nodo(int dato);
	Nodo();
	~Nodo();
	friend ostream& operator<<(ostream& stream, const Nodo& other) {
		if (other.info != NULL) {
			stream << "[" << other.info << "]";
			return stream;
		}
		else {
			stream << "";
		}
	}
};
