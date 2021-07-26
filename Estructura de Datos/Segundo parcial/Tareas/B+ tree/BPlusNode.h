#include <iostream>
#pragma once
using namespace std;
/*
UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE							   
Titulo: B+ Trees 
Autor: Cristian maranje											       
Fecha: 24/07/2021													   
Fecha de modificacion: 26/07/2021								   
*/
class Node
{
    bool IS_LEAF;
    int *key, size;
    Node **ptr;
    int MAX;
    friend class BPTree;

public:
    Node(int _max);
    void setNodeMax(int _max) { MAX = _max; }
    int getNodeMax() { return MAX; }
};