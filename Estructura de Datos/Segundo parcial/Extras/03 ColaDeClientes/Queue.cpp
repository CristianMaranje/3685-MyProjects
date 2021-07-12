#include <iostream>
#include "Queue.h"
#include <functional>
#include <string>
using namespace std;

/*
UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE							   
Titulo: Colas 
Autor: Cristian maranje											       
Fecha: 07/07/2021													   
Fecha de modificacion: 08/07/2021								   
*/

void Queue::push(Movements _movements, Client _client, Cashier _cashier)
{
    Node *newNode = new Node(_movements, _client, _cashier);
    first = newNode;
    if (dimQueue == 0)
    {
        first->setNext(actual);
    }
    else
    {
        first->setNext(actual);
        actual->setPrevious(first);
    }
    actual = first;
    dimQueue++;
}

//in progres
Node *Queue::pop()
{
    Node *temp;
    Node *temp2;
    temp = lastNode();
    temp2 = temp->getPrevious();
    temp2->setNext(nullptr);
    return temp;
}

Node *Queue::top()
{
    if (first == nullptr)
    {
        return nullptr;
    }
    return first;
}

Node *Queue::lastNode()
{
    Node *tmp = first;

    if (tmp == nullptr)
    {
        return nullptr;
    }

    while (tmp->getNext() != nullptr)
    {
        tmp = tmp->getNext();
    }

    return tmp;
}

void Queue::deleteBy(int index)
{
    //elimina el primero
    if (index == 0)
    {
        first = first->getNext();
    }
    //elimina el ultimo
    else if (index == dimQueue)
    {
        Node *penultimo = getNode(index - 2);
        penultimo->setNext(nullptr);
    }
    //elimina entre el primero y el ultimo
    else
    {
        Node *actual = getNode(index - 1);
        Node *tmp = getNode(index + 1);
        actual->setNext(tmp);
    }
    dimQueue--;
}

Node *Queue::getNode(int index)
{
    int cont = 0;
    Node *tmp = first;
    while (tmp->getNext() != nullptr)
    {
        if (cont == index)
        {
            break;
        }
        cont++;
        tmp = tmp->getNext();
    }
    return tmp;
}

void Queue::insertIn(int index, Movements _movements, Client _client, Cashier _cashier)
{
    Node *newNode = new Node(_movements, _client, _cashier);
    if (index == 0)
    {
        Node *tmp = first;
        first = newNode;
        first->setNext(tmp);
    }
    else
    {
        Node *anterior = getNode(index - 1);
        Node *tmp = anterior->getNext();
        anterior->setNext(newNode);
        anterior = anterior->getNext();
        anterior->setNext(tmp);
    }
    dimQueue++;
}

void Queue::goOver(std::function<void(Node *node, int index)> callback)
{
    Node *tmp = first;
    int index = 0;
    while (tmp != nullptr)
    {
        callback(tmp, index++);
        tmp = tmp->getNext();
    }
}

void Queue::goOverLTF(std::function<void(Node *node, int index)> callback)
{
    Node *tmp = lastNode();
    int index = dimQueue;
    while (tmp->getPrevious() != nullptr)
    {
        callback(tmp, index--);
        tmp = tmp->getPrevious();
    }
}
