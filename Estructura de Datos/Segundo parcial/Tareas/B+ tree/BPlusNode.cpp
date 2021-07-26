#include "BPlusNode.h"
/*
UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE							   
Titulo: B+ Trees 
Autor: Cristian maranje											       
Fecha: 24/07/2021													   
Fecha de modificacion: 26/07/2021								   
*/
Node::Node(int _max)
{
  key = new int[_max];
  ptr = new Node *[_max + 1];
  MAX = _max;
}

