#include "BTree.h"
/*
UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE							   
Titulo: B trees
Autor: Cristian maranje											       
Fecha: 23/07/2021													   
Fecha de modificacion: 26/07/2021								   
*/
void BTree::insert(int k)
{
    if (root == NULL)
    {
        root = new TreeNode(t, true);
        root->keys[0] = k;
        root->n = 1;
    }
    else
    {
        if (root->n == 2 * t - 1)
        {
            TreeNode *s = new TreeNode(t, false);

            s->C[0] = root;

            s->splitChild(0, root);

            int i = 0;
            if (s->keys[0] < k)
                i++;
            s->C[i]->insertNonFull(k);

            root = s;
        }
        else
            root->insertNonFull(k);
    }
}

void BTree::traverse()
{
    if (root != NULL)
        root->traverse();
    else cout<<"\nTree is empty\n";
}

TreeNode *BTree::search(int k)
{
    return (root == NULL) ? NULL : root->search(k);
}