#include <iostream>
#include <thread>
#pragma once

/*
UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE							   
Titulo: Programa colas 
Autor: Cristian maranje											       
Fecha: 08/07/2021													   
Fecha de modificacion: 12/07/2021								   
*/

class Movements
{
private:
    int arrivalTime;
    int waitingTime;
    int exitTime;
    int timeBetweenArrivals;

public:
    Movements();

    int calculateArrivalTime();
    int calculateWaitingTime(int prevExitTime);
    int calculateExitTime(int serviceTime);
    int calculateTimeBetweenArrivals(int prevArraival);

    void setArrivalTime(int);
    int getArraivalTime();
    void setWaitingTime(int);
    int getWaitingTime();
    void setExitTime(int);
    int getExitTime();
    void setTimeBetweenArrivals(int);
    int getTimeBetweenArrivals();
};