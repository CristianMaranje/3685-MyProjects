/*
UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE							   
Titulo: Proyecto tabla de amortizacion
Autor: Cristian maranje											       
Fecha: 27/06/2021													   
Fecha de modificacion: 28/06/2021								   
*/

#include <stdlib.h>
#include "Persona.h"
#include "Tabla.h"
#pragma once
class Nodo
{
private:
	Persona persona;
	Tabla tabla;
	Nodo *siguiente;
	Nodo *anterior;

public:
	Nodo(Persona, Tabla);

	Persona getPersona();
	void setPersona(Persona persona);

	Tabla getTabla();
	void setTabla(Tabla tabla);

	Nodo *getSiguiente();
	void setSiguiente(Nodo *);

	Nodo *getAnterior();
	void setAnterior(Nodo *);
};