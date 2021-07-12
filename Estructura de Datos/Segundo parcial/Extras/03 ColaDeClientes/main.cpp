#include <iostream>
#include <ctime>
#include "Operations.h"
#include "Client.h"
#include "Movements.h"
#include "Cashier.h"
#include "Queue.h"
void program();

/*
UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE							   
Titulo: Programa colas 
Autor: Cristian maranje											       
Fecha: 08/07/2021													   
Fecha de modificacion: 12/07/2021								   
*/

int main()
{
    thread thProgram(program);
    thProgram.join();
    thread thMarquee(marquee);
    thMarquee.join();
    return 0;
}

void program()
{
    int numClients = 0, i = 1;
    Client client;
    Movements movements;
    Cashier cashier;
    Queue queue;
    int lastArrival = 0, tmp, serviceTime, lastExitTime = 0, arrivalTime, waitingTime, timeBetweenArrivals, exitTime, noWorkTime;
    srand(time(NULL));
    numClients = 1 + rand() % (301 - 1);
    do
    {
        client.setOedClients(i);
        movements.calculateArrivalTime();
        movements.calculateWaitingTime(movements.getExitTime());
        movements.calculateTimeBetweenArrivals(lastArrival);
        lastArrival = movements.getArraivalTime();
        serviceTime = cashier.generateServiceTime();
        movements.calculateExitTime(serviceTime);
        cashier.calculateNoWorkTime(movements.getArraivalTime(), lastExitTime);
        lastExitTime = movements.getExitTime();
        i++;
        queue.push(movements, client, cashier);
    } while (i <= numClients);
    int additionServiceTime = 0, additionArrivalTime = 0, additionWaitingTime = 0, additionCashierNotWorking = 0, prevWaitingtime =0;
    std::cout << "\nCliente\t\tLlegada\t\tEspera\t\tNo trabaja el cajero\tServicio\tSalida\t\tTiempo entre llegadas" << std::endl;
    queue.goOverLTF([&](Node *node, int index)
                 {
                     additionServiceTime += cashier.getServiceTime();
                     additionArrivalTime += movements.getTimeBetweenArrivals();
                     additionWaitingTime += movements.getWaitingTime();
                     additionCashierNotWorking += cashier.getNoWorkTime();
                     cashier = node->getCashier();
                     movements = node->getMovements();
                     client = node->getClient();
                     std::cout << client.getOedClients()
                               << "\t\t" << movements.getArraivalTime()
                               << "\t\t" << movements.getWaitingTime()
                               << "\t\t" << cashier.getNoWorkTime()
                               << "\t\t\t" << cashier.getServiceTime()
                               << "\t\t" << movements.getExitTime()
                               << "\t\t" << movements.getTimeBetweenArrivals() << std::endl;
                 });

    std::cout << "El tiempo promedio de servicios es: " << average(additionServiceTime, numClients) << std::endl;
    std::cout << "El tiempo promedio de llegada es: " << average(additionArrivalTime, numClients) << std::endl;
    std::cout << "El tiempo promedio de espera es: " << average(additionWaitingTime, numClients) << std::endl;
    std::cout << "El tiempo promedio que el cajero no trabaja es: " << average(additionCashierNotWorking, numClients) << std::endl;
}