#include <iostream>
#include "Node.h"
#include <functional>
#pragma once
using namespace std;

/*
UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE							   
Titulo: Colas 
Autor: Cristian maranje											       
Fecha: 07/07/2021													   
Fecha de modificacion: 08/07/2021								   
*/


class Queue
{
private:
    Node *first;
    Node *actual;
    int dimQueue = 0;

public:
    Queue()
    {
        this->first = NULL;
        this->actual = NULL;
    }
    bool emptyQueue() { return (first == NULL); };
    void push(Movements, Client , Cashier );
    Node* top();
    Node* pop();
    Node* lastNode();
    void insert(string);
    void insertIn(int, Movements, Client, Cashier);
    void deleteBy(int);
    //void show();
    void goOver(std::function<void(Node*, int)> callback);
    void goOverLTF(std::function<void(Node*, int)> callback);
    void recursiveShow(Node *, int);

    Node *getNode(int);
    Node *getFirst() { return first; }
    void setFirst(Node *pri) { first = pri; }
    Node *getActual() { return actual; }
    void setActual(Node *act) { actual = act; }
    int getDimQueue() { return dimQueue; }
    void setDimQueue(int dim) { dimQueue = dim; }
};