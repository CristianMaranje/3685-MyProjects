#include <iostream>
#include "Nodo.h"
#include <functional>
#pragma once
using namespace std;
/*
UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE							   
Titulo: Listas simples 
Autor: Cristian maranje											       
Fecha: 08/06/2021													   
Fecha de modificacion: 16/06/2021								   
*/

//Posibles operaciones: insertar(inserta al ultimo), insertar en una posicion, eliminar (indice del item), mostrar.

class Pila
{
private:
    Nodo *primero;
    Nodo *actual;
    int dimPila = 0;

public:
    Pila()
    {
        this->primero = NULL;
        this->actual = NULL;
    }
    Nodo *obtenerNodo(int indice);
    bool pilaVacia() { return (primero == NULL); };
    void push(string val);
    char top();
    string pop();
    void insertar(string val);
    void insertarEn(int indice, string val);
    void eliminar(int indice);
    void mostrar();
    Nodo *getPrimero() { return primero; }
    void setPrimero(Nodo *pri) { primero = pri; }
    Nodo *getActual() { return actual; }
    void setActual(Nodo *act) { actual = act; }
    int getDimLista() {return dimPila;}
    void setDimLista(int dim) {dimPila = dim; }
    void recorrer(std::function<void(string valor, int indice)> callback);
    void mostrarRecursivo(Nodo *valor,int indice);
};