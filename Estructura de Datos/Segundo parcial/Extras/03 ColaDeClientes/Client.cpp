#include "Client.h"

/*
UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE							   
Titulo: Programa colas 
Autor: Cristian maranje											       
Fecha: 08/07/2021													   
Fecha de modificacion: 12/07/2021								   
*/

Client::Client()
{
    this->ordClients = 0;
}

void Client::setOedClients(int _ordClients)
{
    this->ordClients = _ordClients;
}

int Client::getOedClients()
{
    return ordClients;
}