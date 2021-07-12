#include "Movements.h"

/*
UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE							   
Titulo: Programa colas 
Autor: Cristian maranje											       
Fecha: 08/07/2021													   
Fecha de modificacion: 12/07/2021								   
*/

Movements::Movements()
{
    this->arrivalTime = 0;
    this->exitTime = 0;
    this->timeBetweenArrivals = 0;
    this->waitingTime = 0;
}

int Movements::calculateArrivalTime()
{
    arrivalTime =arrivalTime+( 1 + rand() % (26 - 1));
    return arrivalTime;
}

int Movements::calculateWaitingTime(int prevExitTime)
{
    if (arrivalTime >= prevExitTime)
    {
        waitingTime = 0;
        return waitingTime;
    }
    else if (arrivalTime < prevExitTime)
    {
        waitingTime = prevExitTime - arrivalTime- waitingTime;
        return waitingTime;
    }
}

int Movements::calculateExitTime(int serviceTime)
{
    exitTime = arrivalTime + waitingTime + serviceTime;
    return exitTime;
}

int Movements::calculateTimeBetweenArrivals(int prevArrival)
{
    timeBetweenArrivals = arrivalTime - prevArrival;
    return timeBetweenArrivals;
}

void Movements::setArrivalTime(int ArrivalTime)
{
    this->arrivalTime = ArrivalTime;
}
int Movements::getArraivalTime()
{
    return arrivalTime;
}
void Movements::setWaitingTime(int _waitingTime)
{
    this->waitingTime = _waitingTime;
}
int Movements::getWaitingTime()
{
    return waitingTime;
}
void Movements::setExitTime(int _exitTime)
{
    this->exitTime = _exitTime;
}
int Movements::getExitTime()
{
    return exitTime;
}
void Movements::setTimeBetweenArrivals(int _timeBetweenArrivals)
{
    this->timeBetweenArrivals = _timeBetweenArrivals;
}
int Movements::getTimeBetweenArrivals()
{
    return timeBetweenArrivals;
}
