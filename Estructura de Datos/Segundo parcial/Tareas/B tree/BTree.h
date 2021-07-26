#include <iostream>
#include "TreeNode.h"
#pragma once
/*
UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE							   
Titulo: B trees
Autor: Cristian maranje											       
Fecha: 23/07/2021													   
Fecha de modificacion: 26/07/2021								   
*/
class BTree
{
    TreeNode *root;
    int t;

public:
    BTree(int temp)
    {
        root = NULL;
        t = temp;
    }
    void traverse();
    TreeNode *search(int k);
    void insert(int k);
};