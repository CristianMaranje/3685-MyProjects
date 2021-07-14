#include <iostream>
#include "Vector.h"
#include "Operations.h"

/*
UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE							   
Titulo: Genera e imprime un arreglo de numeros 
Autor: Cristian maranje											       
Fecha: 06/07/2021													   
Fecha de modificacion: 7/07/2021								   
*/

int main(int, char **)
{
    Vector vector;
    Vector bubble;
    Vector quick;
    Vector insertion;
    Vector shell;
    vector.setVector(generate());
    quick = vector;
    insertion = vector;
    shell = vector;
    print(vector);
    // bubble.setVector(bubbleSort(vector.getVector()));
    // print(bubble);
    // quickSort(quick.getVector());
    // print(quick);
    // insertionSort(insertion.getVector());
    // print(insertion);
    shellSort(shell.getVector());
    print(shell);
}
