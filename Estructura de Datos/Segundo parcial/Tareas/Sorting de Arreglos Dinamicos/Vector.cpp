#include "Vector.h"
/*
UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE							   
Titulo: Genera e imprime un arreglo de numeros 
Autor: Cristian maranje											       
Fecha: 06/07/2021													   
Fecha de modificacion: 7/07/2021								   
*/

Vector::Vector()
{
    this->vector = nullptr;   
}

int* Vector::getVector()
{
    return vector;
}

void Vector::setVector(int *_vector)
{
    vector=_vector;
}