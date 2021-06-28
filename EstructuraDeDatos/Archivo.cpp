/*
UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE							   
Titulo: Proyecto tabla de amortizacion
Autor: Cristian maranje											       
Fecha: 27/06/2021													   
Fecha de modificacion: 28/06/2021								   
*/
#include "Archivo.h"
#include <time.h>
#include <windows.h>
#include <string>
#include <ctime>
#include <iostream>
#include <fstream>
#include <stdlib.h>


using namespace std;
Archivo::Archivo()
{
}


void Archivo::escribirArchivo(ListaCircularDoble lista)
{
    fstream archivo;
    archivo.open("Datos.txt", ios::out | ios::app | ios::in|ios::binary);

    if (archivo.fail())
    {
        cout << "ERROR!! EL ARCHIVO NO SE HA CREADO ";
        exit(1);
    }

    lista.recorrer([&](Persona persona, Tabla tabla) {
        archivo.write( reinterpret_cast<char*>(&persona),sizeof(persona));
    });
    archivo.close();
}

void Archivo::leerArchivo(ListaCircularDoble lista)
{
    fstream archivo;
    archivo.open("Datos.txt", ios::in);
    cout<<"here";
    if (archivo.fail())
    {
        cout << "ERROR!! EL ARCHIVO NO SE HA CREADO ";
        exit(1);
    }

    lista.recorrer([&](Persona persona, Tabla tabla) {
        archivo.read( reinterpret_cast<char*>(&persona),sizeof(persona));
        lista.insertar(persona,tabla);
    });
    archivo.close();
}

