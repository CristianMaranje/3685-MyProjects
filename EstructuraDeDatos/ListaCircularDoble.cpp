#include <iostream>
#include "ListaCircularDoble.h"

ListaCircularDoble::ListaCircularDoble()
{
	primero = nullptr;
}

void ListaCircularDoble::insertar(int dato){
	
	Nodo *nuevo= new Nodo(dato); 
	if(primero == NULL){		
		primero = nuevo;		
		primero->setSiguiente(primero);
		primero->setAnterior(primero);		
	}else if(primero->getSiguiente() == primero){		
		ultimo = nuevo;
		ultimo->setSiguiente(primero);
		ultimo->setAnterior(primero);
		primero->setSiguiente(ultimo);
		primero->setAnterior(ultimo);		
	}else{
		ultimo->setSiguiente(nuevo);
		nuevo->setAnterior(ultimo);
		nuevo->setSiguiente(primero);
		primero->setAnterior(nuevo);
		ultimo = nuevo;
	}	
}

bool ListaCircularDoble::eliminar(int dato){
	//pendiente
}

void ListaCircularDoble::imprimir(){
	//pendiente
}
