#include<stdlib.h>
class Nodo
{
	private:
		int dato;
		Nodo *siguiente;
		Nodo *anterior;

	public:
		Nodo(int);
		
		int getDato();
		void setDato(int);
		
		Nodo *getSiguiente();
		void setSiguiente(Nodo *);
		
		Nodo *getAnterior();
		void setAnterior(Nodo *);
};