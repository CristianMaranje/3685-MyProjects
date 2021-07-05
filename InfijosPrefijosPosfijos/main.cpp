#include <iostream>
#include "Prefijo.h"
#include "Postfijo.h"

/*
UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE							   
Titulo: Transforma de infijo a postfijo y prefijo 
Autor: Cristian maranje											       
Fecha: 03/07/2021													   
Fecha de modificacion: 5/07/2021								   
*/

int main() {
    std::string ejercicio,resultado;
    std::cout<<"Este programa transforma un problema infijo a Prefijo y Postfijo."<<endl;
    cout<<"\nIngrese el problema en infijo: "; getline(std::cin, ejercicio);
    resultado = transformarAPrefijo(ejercicio);
    cout<<"Prefijo: "<<resultado<<endl;
    resultado = transformarAPostfijo(ejercicio);
    cout<<"Postfijo: "<<resultado<<endl; 
    return 0;
}
