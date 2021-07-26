#include <iostream>
#include "BTree.h"
using namespace std;

/*
UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE							   
Titulo: B trees
Autor: Cristian maranje											       
Fecha: 23/07/2021													   
Fecha de modificacion: 26/07/2021								   
*/

int main()
{
    int grade,c,x;
    cout<<"\t\t\t\tB tree"<<endl;
    cout<<"Select the grade of the tree (>=3): "; cin>>grade;
    BTree t(grade);
    do{
        cout<<"\n\n1.Display of tree data";
        cout<<"\n2.Insert";
        cout<<"\n3.Search\n";
        cout<<"\n0.Exit\n";
        cout<<"\nChoice: ";

        cin>>c;

        switch (c)
        {
        case 1:
        cout<<"\n The contents of the tree are ->";
            t.traverse();
            break;
                  
        case 2:
            cout<<"\nEnter no. ";
            cin>>x;
            t.insert(x);
            break;
        
        case 3:
            cout<<"\nWhat to Search? ";
            cin>>x;
            (t.search(x) != NULL) ? cout << endl
                 << x << " is found"
              : cout << endl
                 << x << " is not Found";

            break;
            
        case 0:
            break;
        }

     } while(c!=0);
    return 0;
}