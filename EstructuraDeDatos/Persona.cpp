/*
UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE							   
Titulo: Proyecto tabla de amortizacion
Autor: Cristian maranje											       
Fecha: 27/06/2021													   
Fecha de modificacion: 28/06/2021								   
*/

#include <iostream>
#include <string>
#include "Persona.h"
#include "Validaciones.h"

using namespace std;

Persona::Persona(string _nombre, string _apellido, long int _CI, Fecha *_edad, string _localizacion, string _telefono, string _sueldo, string _correo)
{
    this->nombre = _nombre;
    this->apellido = _apellido;
    this->CI = _CI;
    this->fechaNacimiento = _edad;
    this->localizacion = _localizacion;
    this->telefono = _telefono;
    this->sueldo = _sueldo;
    this->correo = _correo;
}
Persona::Persona()
{
    this->nombre = "usuario";
    this->apellido = "usuario";
    this->CI = 99999;
    this->localizacion = "no definido";
    this->telefono = "9999999999";
    this->sueldo = "99999";
    this->correo = "no definido";
}

Persona Persona::nuevaPersona()
{
    string _nombre, _apellido, _localizacion, _correo, _telefono, _sueldo;
    long int _CI;

    cout << "PERSONA" << endl;
    cout << "Digite su nombre: ";
    cin >> _nombre; //hacer que funcione con dos nombres
    nombre = _nombre;

    cout << "Digite su apellido: ";
    cin >> _apellido;
    apellido = _apellido;

    cout << "Numero de cedula: ";
    cin >> _CI;
    _CI = validarCedula(_CI);

    cout << "Ingrese su fecha de nacimiento.\n";
    fechaNacimiento = fechaNacimiento->ingresarFecha();

    cout << "Digite su lugar de localizacion: ";
    getline(cin, _localizacion);

    fflush(stdin);
    cout << "Numero celular: ";
    getline(cin, _telefono);
    while (!esInt(_telefono)||_telefono.size()!=10)
    {
        cout << "El dato ingresado no es valido intente nuevamente.\nNumero telefonico: ";
        fflush(stdin);
        getline(cin, _telefono);
    }

    fflush(stdin);
    cout << "Digite su sueldo: ";
    getline(cin, _sueldo);
    while (!esFloat(_sueldo))
    {
        cout << "El dato ingresado no es valido intente nuevamente.\nDigite su sueldo: ";
        getline(cin, _sueldo);
    }

    generarCorreo(0);

    Persona tmp(_nombre, _apellido, _CI, fechaNacimiento, _localizacion, _telefono, _sueldo, correo);
    return tmp;
}

void Persona::generarCorreo(int cont)
{
    string localNonbre = nombre;
    string localApellido = apellido;
        cout<<cont;
 
    for (int i = 0; i < localNonbre.length(); i++)
        localNonbre[i] = tolower(localNonbre[i]);
    for (int i = 0; i < localApellido.length(); i++)
        localApellido[i] = tolower(localApellido[i]);
    if (cont == 0)
    {
        correo = localNonbre[0] + localApellido + "@espe.edu.ec";
    }
    else
    {

        correo = localNonbre[0] + localApellido + to_string(cont) + "@espe.edu.ec";

    }
}

/*-----------------setters-----------------*/

void Persona ::setNombre(string _nombre)
{
    nombre = _nombre;
}
void Persona ::setApellido(string _apellido)
{
    apellido = _apellido;
}
void Persona ::setCI(long _CI)
{
    CI = _CI;
}
void Persona ::setLocalizacion(string _localizacion)
{
    localizacion = _localizacion;
}
void Persona ::setTelefono(string _telefono)
{
    telefono = _telefono;
}
void Persona ::setSueldo(string _sueldo)
{
    sueldo = _sueldo;
}
void Persona ::setCorreo(string _correo)
{
    correo = _correo;
}

/*-----------------getters------------------*/
Fecha *Persona::getFechaNacimiento()
{
    return fechaNacimiento;
}

string Persona ::getNombre()
{
    return nombre;
}
string Persona ::getApellido()
{
    return apellido;
}
long Persona ::getCI()
{
    return CI;
}
string Persona ::getLocalizacion()
{
    return localizacion;
}
string Persona ::getTelefono()
{
    return telefono;
}
string Persona ::getSueldo()
{
    return sueldo;
}
string Persona ::getCorreo()
{
    return correo;
}
