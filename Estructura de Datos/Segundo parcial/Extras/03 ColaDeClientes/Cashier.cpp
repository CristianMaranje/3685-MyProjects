#include "Cashier.h"

/*
UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE							   
Titulo: Programa colas 
Autor: Cristian maranje											       
Fecha: 08/07/2021													   
Fecha de modificacion: 12/07/2021								   
*/

int Cashier::generateServiceTime()
{
    serviceTime = 1 + rand() % (16 - 1);
    return serviceTime;
}

int Cashier::calculateNoWorkTime(int arrivalTime, int previousExitTime)
{
    if (arrivalTime <= previousExitTime)
    {
        noWorkTime = 0;
        return noWorkTime;
    }
    else if (arrivalTime > previousExitTime)
    {
        noWorkTime = arrivalTime - previousExitTime;
        return noWorkTime;
    }
}

void Cashier::setNoWorkTime(int _noWorkTime)
{
    this->noWorkTime = _noWorkTime;
}
int Cashier::getNoWorkTime()
{
    return noWorkTime;
}
void Cashier::setServiceTime(int _serviceTime)
{
    this->serviceTime = _serviceTime;
}
int Cashier::getServiceTime()
{
    return serviceTime;
}