#include <iostream>
#include "Movements.h"
#include "Client.h"
#include "Cashier.h"
/*
UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE							   
Titulo: Colas 
Autor: Cristian maranje											       
Fecha: 07/07/2021													   
Fecha de modificacion: 08/07/2021								   
*/
using namespace std;
class Node
{
private:
    Movements movements;
    Client client;
    Cashier cashier;
    Node *next = nullptr;
    Node *previous = nullptr;

public:
    Node(Movements _movements, Client _client, Cashier _cashier)
    {
        this->movements = _movements;
        this->client = _client;
        this->cashier = _cashier;
    }
    Node();
    void setNext(Node *_next) { next = _next; }
    Node *getNext() { return next; }
    void setPrevious(Node *_previous) { previous = _previous; }
    Node *getPrevious() { return previous; }
    Movements getMovements() { return movements; }
    Client getClient() { return client; }
    Cashier getCashier() { return cashier; }

    friend class Queue;
};
