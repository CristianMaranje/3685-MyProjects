#include <iostream>
#include "Vector.h"
#include "Operaciones.h"

/*
UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE							   
Titulo: Genera e imprime un arreglo de numeros 
Autor: Cristian maranje											       
Fecha: 06/07/2021													   
Fecha de modificacion: 7/07/2021								   
*/

int main(int, char**) {
    std::cout << "Hello, world!\n";
    Vector vector;
    vector.setVector(generar());
    imprimir(vector);
}
