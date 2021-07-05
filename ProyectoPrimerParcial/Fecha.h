/*
UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE							   
Titulo: Proyecto tabla de amortizacion
Autor: Cristian maranje											       
Fecha: 27/06/2021													   
Fecha de modificacion: 28/06/2021								   
*/

#include <iostream>
#pragma once
using namespace std;

class Fecha
{
public:
	Fecha();
	Fecha(int day, int month, int year);
	Fecha *ingresarFecha();
	int _edad();
	void setYear(int);
	void setMonth(int);
	void setDay(int);
	int getYear();
	int getMonth();
	int getDay();
	friend class Persona;
	friend class Tabla;

private:
	int year;
	int month;
	int day;
};
