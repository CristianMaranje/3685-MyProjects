#include "Vector.h"

/*
UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE							   
Titulo: Genera e imprime un arreglo de numeros 
Autor: Cristian maranje											       
Fecha: 06/07/2021													   
Fecha de modificacion: 7/07/2021								   
*/

int* generar()
{
    int *_vector = (int *)malloc(100);
    for (int i = 0; i < 100; i++)
    {
        *(_vector + i) = rand() % (1001);
    }
    return _vector;
}

void imprimir (Vector vector)
{
    int *tmpVector;
    tmpVector = vector.getVector();
    for(int i = 0 ; i<100 ; i++)
    {
    std::cout<<"Posicion "<<i+1<<" Valor: "<<*(tmpVector + i)<<std::endl;
    }
}