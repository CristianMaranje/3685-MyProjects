#include <iostream>
#pragma once
/*
UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE							   
Titulo: Genera e imprime un arreglo de numeros 
Autor: Cristian maranje											       
Fecha: 06/07/2021													   
Fecha de modificacion: 7/07/2021								   
*/

class Vector{
    private:
        int *vector;
    public:
        Vector();
        int* getVector();
        void setVector(int* _vector);
};