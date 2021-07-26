#include <climits>
#include <fstream>
#include <iostream>
#include <sstream>
#include "BPlusTree.h"
using namespace std;

/*
UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE							   
Titulo: B+ Trees 
Autor: Cristian maranje											       
Fecha: 24/07/2021													   
Fecha de modificacion: 26/07/2021								   
*/

int main()
{
    int grade, x, c;
    BPTree tree;
    cout << "\t\t\t\tB+ tree" << endl;
    cout << "Select the grade of the tree (>=3): ";
    cin >> grade;
    tree.setMax(grade);
    do
    {
        cout << "\n\n1.Display of tree data";
        cout << "\n2.Insert";
        cout << "\n3.Search\n";
        cout << "\n0.Exit\n";
        cout << "\nChoice: ";

        cin >> c;

        switch (c)
        {
        case 1:
            cout << "\n The contents of the tree are:\n";
            tree.display(tree.getRoot());
            break;

        case 2:
            cout << "\nEnter no. ";
            cin >> x;
            tree.insert(x);
            break;

        case 3:
            cout << "\nWhat to Search? ";
            cin >> x;
            tree.search(x);
            break;

        case 0:
            break;
        }

    } while (c != 0);

    return 0;
}