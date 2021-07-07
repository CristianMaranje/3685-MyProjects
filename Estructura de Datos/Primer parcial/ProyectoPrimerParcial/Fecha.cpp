/*
UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE							   
Titulo: Proyecto tabla de amortizacion
Autor: Cristian maranje											       
Fecha: 27/06/2021													   
Fecha de modificacion: 28/06/2021								   
*/

#include <iostream>
#include "Fecha.h"
#include "Validaciones.h"
#include <time.h>
#include <string>

using namespace std;
Fecha::Fecha()
{
	this->year = 0;
	this->month = 0;
	this->day = 0;
}

Fecha::Fecha(int day, int month, int year)
{
	this->year = year;
	this->month = month;
	this->day = day;
}

Fecha *Fecha::ingresarFecha()
{
	int year2, month2, day2; //fecha nacimiento
	string s_year, s_month, s_day;

	//ingreso y validacion del anio
	fflush(stdin);
	cout << "Ingresar Anio (xxxx): ";
	getline(cin, s_year);
	if (esInt(s_year))
	{
		year2 = stoi(s_year);
	}
	while (!esInt(s_year) || year2 < 1900 || year2 > 2021)
	{
		cout << "Dato no valido, volver a ingresar: ";
		fflush(stdin);
		getline(cin, s_year);
		if (esInt(s_year))
		{
			year2 = stoi(s_year);
		}
	}

	//ingreso y validacion del mes
	fflush(stdin);
	cout << "Ingresar Mes (xx): ";
	getline(cin, s_month);
	if (esInt(s_month))
	{
		month2 = stoi(s_month);
	}
	while (!esInt(s_month) || month2 < 1 || month2 > 12)
	{
		cout << "Dato no valido, volver a ingresar: ";
		fflush(stdin);
		getline(cin, s_month);
		if (esInt(s_month))
		{
			month2 = stoi(s_month);
		}
	}

	//ingreso y validacion del dia
	fflush(stdin);
	cout << "Ingresar Dia (xx): ";
	getline(cin, s_day);
	if (esInt(s_day))
	{
		day2 = stoi(s_day);
	}
	while (!esInt(s_day) || !validarLosDias(day2, month2) || !validarDiaLaborable(year2, month2, day2))
	{
		cout << "Dato no valido, volver a ingresar: ";
		fflush(stdin);
		getline(cin, s_day);
		if (esInt(s_day))
		{
			day2 = stoi(s_day);
		}
	}

	Fecha *tmp = new Fecha(day2, month2, year2);
	return tmp;
}

int Fecha::_edad()
{

	char currDate[30];
	time_t t = time(NULL);
	struct tm tm = *localtime(&t);

	int respDia, respMes;
	int year2 = year, month2 = month, day2 = day;						      //fecha nacimiento
	int year1 = tm.tm_year + 1900, month1 = tm.tm_mon + 1, day1 = tm.tm_mday; //fecha actual

	if (day1 < day2)
	{
		day1 = day1 + 30;
		month1 = month1 - 1;
		respDia = day1 - day2;
	}
	else
		respDia = day1 - day2;

	if (month1 < month2)
	{
		month1 = month1 + 12;
		year1 = year1 - 1;
		respMes = month1 - month2;
	}
	else
		respMes = month1 - month2;

	int yearT;
	yearT = year1 - year2;
	return yearT;
}

//---------------setters--------------
void Fecha::setYear(int _year)
{
	year = _year;
}
void Fecha::setDay(int _day)
{
	day = _day;
}
void Fecha::setMonth(int _month)
{
	month = _month;
}

//----------------getters-------------
int Fecha::getDay()
{
	return day;
}
int Fecha::getMonth()
{
	return month;
}
int Fecha::getYear()
{
	return year;
}
