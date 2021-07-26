#include <iostream>
#include "BPlusNode.h"
#pragma once
using namespace std;
/*
UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE							   
Titulo: B+ Trees 
Autor: Cristian maranje											       
Fecha: 24/07/2021													   
Fecha de modificacion: 26/07/2021								   
*/
class BPTree
{
    Node *root;
    Node *findParent(Node *, Node *);
    int MAX;

public:
    void insertInternal(int, Node *, Node *);
    BPTree();
    void search(int);
    void insert(int);
    void display(Node *);
    Node *getRoot();
    void setMax(int _max) { MAX = _max; }
    int getMax() { return MAX; }
};