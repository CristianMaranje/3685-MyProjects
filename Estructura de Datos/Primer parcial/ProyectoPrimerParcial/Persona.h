/*
UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE							   
Titulo: Proyecto tabla de amortizacion
Autor: Cristian maranje											       
Fecha: 27/06/2021													   
Fecha de modificacion: 28/06/2021								   
*/

#include "Fecha.h"
#include <iostream>
#pragma once
using namespace std;

class Persona
{

private:
    string nombre;
    string apellido;
    long int CI;
    Fecha *fechaNacimiento;
    string localizacion;
    string telefono;
    string sueldo;
    string correo;

public:
    Persona(string _nombre, string _apellido, long int _CI, Fecha *_edad, string _localizacion, string _telefono, string _sueldo, string _correo);
    Persona();
    Persona nuevaPersona();
    void generarCorreo(int);

    void setNombre(string);
    void setApellido(string);
    void setCI(long int);
    void setLocalizacion(string);
    void setTelefono(string);
    void setSueldo(string);
    void setCorreo(string);

    string getNombre();
    string getApellido();
    long getCI();
    string getLocalizacion();
    string getTelefono();
    string getSueldo();
    string getCorreo();
    Fecha *getFechaNacimiento();
};
