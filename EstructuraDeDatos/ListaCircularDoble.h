#include "Nodo.h"
#include <iostream>

class ListaCircularDoble
{
	public:
		ListaCircularDoble();
		void insertar(int);
		bool eliminar(int);
		void imprimir();
	private:
		Nodo *primero;
		Nodo *ultimo;
};

