#include <iostream>
#include <queue>
#include <unordered_map>
#include "AVLTree.h"
using namespace std;

int main(){

    AVL b;
    int c,x;

    do{
        cout<<"\n1.Display levelorder on newline";
        cout<<"\n2.Insert";
        cout<<"\n3.Delete\n";
        cout<<"\n0.Exit\n";
        cout<<"\nChoice: ";

        cin>>c;

        switch (c)
        {
        case 1:
            b.levelorder_newline();
            // to print the tree in level order
            break;
                  
        case 2:
            cout<<"\nEnter no. ";
            cin>>x;
            b.setRoot(b.insert(b.getRoot(),x));
            break;
        
        case 3:
            cout<<"\nWhat to delete? ";
            cin>>x;
            b.setRoot(b.deleteNode(b.getRoot(),x));
            break;
            
        case 0:
            break;
        }

     } while(c!=0);
     
  return 0;
}