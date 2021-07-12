#include <iostream>
#pragma once

/*
UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE							   
Titulo: Programa colas 
Autor: Cristian maranje											       
Fecha: 08/07/2021													   
Fecha de modificacion: 12/07/2021								   
*/

class Cashier
{
private:
    int noWorkTime=0;
    int serviceTime;

public:
    int generateServiceTime();
    int calculateNoWorkTime(int arrivalTime, int previousExitTime);

    void setNoWorkTime(int);
    int getNoWorkTime();
    void setServiceTime(int);
    int getServiceTime();
};
