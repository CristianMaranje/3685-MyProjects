#include <iostream>
#include "Pila.h"
#include <functional>
#include <string>
using namespace std;

/*
UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE							   
Titulo: Pilas 
Autor: Cristian maranje											       
Fecha: 08/06/2021													   
Fecha de modificacion: 5/07/2021								   
*/

void Pila::push(string val)
{
    Nodo *nuevo = new Nodo(val);
    primero = nuevo;
    primero->setSiguiente(actual);
    actual = primero;
    dimPila++;
}

string Pila::pop()
{
    Nodo *temp = primero;
    if(temp == nullptr)
    {
        dimPila = 0;
        return "!";
    }
    primero = primero->getSiguiente();
    actual = actual->getSiguiente();
    dimPila--;
    return temp->getValor();
}

char Pila::top()
{
    if(primero == nullptr)
    {
        return '!';
    }
    string s;
    s = primero->getValor();
    return s[0];
}
void Pila::insertar(string val)
{
    Nodo *nuevo = new Nodo(val);
    if (Pila::pilaVacia())
    {
        primero = nuevo;
    }
    else
    {
        actual->setSiguiente(nuevo);
    }
    actual = nuevo;
    dimPila++;
}

void Pila::mostrar()
{
    Nodo *tmp = primero;
    while(tmp!=nullptr)
    {
        cout<<"valor: "<<tmp->getValor()<<endl;
        tmp = tmp->getSiguiente();
    }
}


void Pila::eliminar(int indice)
{
    //elimina el primero
    if (indice == 0)
    {
        primero = primero->getSiguiente();
        //elimina el ultimo
    }
    else if (indice == dimPila)
    {
        Nodo *penultimo = obtenerNodo(indice - 2);
        penultimo->setSiguiente(nullptr);
        //elimina entre el primero y el ultimo
    }
    else
    {
        Nodo *actual = obtenerNodo(indice - 1);
        Nodo *tmp = obtenerNodo(indice + 1);
        actual->setSiguiente(tmp);
    }
    dimPila--;
}

Nodo *Pila::obtenerNodo(int indice)
{
    int cont = 0;
    Nodo *tmp = primero;
    while (tmp->getSiguiente() != nullptr)
    {
        if (cont == indice)
        {
            break;
        }
        cont++;
        tmp = tmp->getSiguiente();
    }
    return tmp;
}

void Pila::insertarEn(int indice, string val)
{
    Nodo *nuevo = new Nodo(val);
    if (indice == 0)
    {
        Nodo *tmp = primero;
        primero = nuevo;
        primero->setSiguiente(tmp);
    }
    else
    {
        Nodo *anterior = obtenerNodo(indice - 1);
        Nodo *tmp = anterior->getSiguiente();
        anterior->setSiguiente(nuevo);
        anterior = anterior->getSiguiente();
        anterior->setSiguiente(tmp);
    }
    dimPila++;
}

void Pila::recorrer(std::function<void(string valor, int indice)> callback)
{
    Nodo *temporal = primero;
    int indice = 0;
    while (temporal != nullptr)
    {
        callback(temporal->getValor(), indice++);
        temporal = temporal->getSiguiente();
    }
}
