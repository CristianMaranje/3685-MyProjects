#include <iostream>
#include <string>

/*
UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE							   
Titulo: Pilas 
Autor: Cristian maranje											       
Fecha: 08/06/2021													   
Fecha de modificacion: 5/07/2021								   
*/

using namespace std;
class Nodo
{
private:
    string valor;
    Nodo *siguiente;

public:
    Nodo(string val, Nodo *sig = NULL)
    {
        this->valor = val;
        this->siguiente = sig;
    }
    void setSiguiente(Nodo *sig) { siguiente = sig; }
    Nodo *getSiguiente() { return siguiente; }
    string getValor() { return valor; }
    friend class Pila;
};
