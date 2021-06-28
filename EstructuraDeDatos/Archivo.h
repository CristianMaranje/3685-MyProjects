/*
UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE							   
Titulo: Proyecto tabla de amortizacion
Autor: Cristian maranje											       
Fecha: 27/06/2021													   
Fecha de modificacion: 28/06/2021								   
*/
#include"ListaCircularDoble.h"
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <string>
#include <ctime>
using namespace std;
#pragma once


class Archivo{

    public: 
    Archivo();
    void escribirArchivo(ListaCircularDoble lista);
    void leerArchivo(ListaCircularDoble lista);

};
