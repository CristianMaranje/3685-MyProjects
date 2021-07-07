/*
UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE							   
Titulo: Proyecto tabla de amortizacion
Autor: Cristian maranje											       
Fecha: 27/06/2021													   
Fecha de modificacion: 28/06/2021								   
*/

#include <iostream>
#include "Fecha.h"
#pragma once


class Tabla{
private:
    Fecha *fechaPago;
    float total;
    float cuotas;//valor de las cuotas
    int plazo;//numero de cuatas a pagar
    float porcentajeInteres=5;

public:
    Tabla(Fecha *fecha,float total,float cuotas,int plazo,float porcentajeInteres);
    Tabla();
    Tabla generarTabla();
    void imprimirTabla();
    void guardarTabla();
    float calcularPagos();
    float calcularInteres(float);
    void diaDePago (Fecha *,int);
    int diaSemana(int,int,int);
    string guardarDiaDePago (Fecha *,int);

    void setFechaPago(Fecha*);
    void setTotal(float);
    void setNumCuotas(int);
    void setPorcentajeInteres(float);
    void setCuotas(float);
    Fecha* getFechaPago();
    float getTotal();
    int getNumCuotas();
    float getPorcentajeInteres();
    float getCuotas();
    friend class Persona;

};



