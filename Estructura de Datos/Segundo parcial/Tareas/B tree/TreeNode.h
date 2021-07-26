#include <iostream>
using namespace std;
#pragma once
/*
UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE							   
Titulo: B trees
Autor: Cristian maranje											       
Fecha: 23/07/2021													   
Fecha de modificacion: 26/07/2021								   
*/
class TreeNode
{
    int *keys;
    int t;
    TreeNode **C;
    int n;
    bool leaf;

public:
    TreeNode(int temp, bool bool_leaf);

    void insertNonFull(int k);
    void splitChild(int i, TreeNode *y);
    void traverse();

    TreeNode *search(int k);

    friend class BTree;
};