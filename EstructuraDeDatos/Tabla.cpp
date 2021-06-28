/*
UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE							   
Titulo: Proyecto tabla de amortizacion
Autor: Cristian maranje											       
Fecha: 27/06/2021													   
Fecha de modificacion: 28/06/2021								   
*/

#include "Tabla.h"
#include <iostream>
#include <math.h>
#include "Validaciones.h"

using namespace std;

Tabla::Tabla(Fecha *_fecha,float _total,float _pagos,int _numCuotas,float _porcentajeInteres){
    this->fechaPago =_fecha;
    this->total=_total;
    this->cuotas=_pagos;
    this->plazo=_numCuotas;
    this->porcentajeInteres = _porcentajeInteres;
}

Tabla::Tabla(){
  total=0;
  cuotas=0;
  plazo=0;
  porcentajeInteres=0;
}

Tabla Tabla::generarTabla(){
  string s_total,s_porcentajeInteres,s_pagos,s_plazo;
  float f_total,f_porcentajeInteres,f_pagos;
  int i_plazo;

  Fecha *_fechaPago = new Fecha();

  cout<<"Tabla.\n";
  cout<<"Ingrese el valor del Total: "; getline(cin,s_total);
  while(!esFloat(s_total)){
    cout<<"El dato ingresado no es valido intente nuevamente.\nIngrese el valor del Total: "; getline(cin,s_total);
  }
  f_total = stof(s_total);

  cout<<"Ingrese el porcentaje de interes: "; getline(cin,s_porcentajeInteres);
  while(!esFloat(s_porcentajeInteres)){
    cout<<"El dato ingresado no es valido intente nuevamente.\nIngrese el porcentaje de interes: "; getline(cin,s_porcentajeInteres);
  }
  f_porcentajeInteres = stof(s_porcentajeInteres);

  cout<<"Ingrese el numero de cuotas: "; getline(cin,s_plazo);
  while(!esFloat(s_plazo)){
    cout<<"El dato ingresado no es valido intente nuevamente.\nIngrese el numero de cuotas: "; getline(cin,s_plazo);
  }
  i_plazo = stoi(s_plazo);
  
  cout<<"Ingrese la fecha de la primera cuota.\n";
  _fechaPago = fechaPago->ingresarFecha();
  f_pagos = f_total/i_plazo;

  Tabla temp = Tabla(_fechaPago,f_total,f_pagos,i_plazo,f_porcentajeInteres);
  return temp;
}


float Tabla::calcularPagos(){
  float pagos,interes = getPorcentajeInteres(),_plazo = getNumCuotas(),_total = getTotal(),tmp;
  interes=interes/100;
  tmp=pow((1+interes),_plazo);
  tmp=interes/--tmp;
  pagos=_total*tmp;
  return pagos;
}

float Tabla::calcularInteres(float saldo){
  float interes = getPorcentajeInteres(),_total = saldo,resultado;
  interes=interes/100;
  resultado=_total*interes;
  return resultado;
}

//imprimir tabla
void Tabla::imprimirTabla(){
    cout<<"Vencimiento\t\tPago\t\tInteres\t\tAmortizacion\t\tSaldo\n";
    int cont=0;
    float amortizacion=0,saldo= getTotal(),pagos=0,interes=0;
    while (cont<=plazo)
    {
      diaDePago(getFechaPago(),cont);
      cout<<"\t\t"<<pagos<<"\t\t"<<interes<<"\t\t"<<amortizacion<<"\t\t"<<saldo<<endl;
      pagos=calcularPagos();
      interes = calcularInteres(saldo);
      amortizacion=pagos-interes;
      saldo=saldo-amortizacion;
      cont++;
    }
    
}

void diaDePago (Fecha *fecha,int periodo);

//metodo de sakamoto regresa el dia de la semana domingo=0,lunes=1...
int Tabla::diaSemana(int anio,int  mes,int dia){
  static int t[] = {0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4};
  if(mes < 3 ){
    anio -= 1;
  }
  return (anio + anio/4 - anio/100 + anio/400 + t[mes-1] + dia) % 7;
}


void Tabla::diaDePago (Fecha *fecha,int periodo){
  int cont = 0;
  int mes = fecha->getMonth();
  int dia = fecha->getDay();
  int anio = fecha->getYear();

  while(cont <periodo){
    bool validacionDias = false,validacionDiaLaborable = false;
    mes++;
    cont++;
    if(mes > 12){
      mes = 1;
      anio++;
    }
    while (validacionDias == false){
      validacionDias = validarLosDias(dia,mes);
      if(validacionDias == false){
        dia--;
      }
    }
    while(validacionDiaLaborable == false){
      validacionDiaLaborable = validarDiaLaborable(anio,mes,dia);
      if(validacionDiaLaborable == false){
        dia++;
      }
      if((mes==4)||(mes==6)||(mes==9)||(mes==11))
          if(dia>30){
            do{
              dia--;
              validacionDiaLaborable = validarDiaLaborable(anio,mes,dia);
            }while(validacionDiaLaborable == false);
          }
        if((mes==1)||(mes==3)||(mes==5)||(mes==7)||(mes==8)||(mes==10)||(mes==12))
          if(dia>31){
            do{
              dia--;
              validacionDiaLaborable = validarDiaLaborable(anio,mes,dia);
            }while(validacionDiaLaborable == false);
          }
        if((mes==2))
          if(dia>28){
            do{
              dia--;
              validacionDiaLaborable = validarDiaLaborable(anio,mes,dia);
            }while(validacionDiaLaborable == false);
          }
    }
  }
  cout<<dia<<"/"<<mes<<"/"<<anio;
}

string Tabla::guardarDiaDePago (Fecha *fecha,int periodo){
  int cont = 0;
  int mes = fecha->getMonth();
  int dia = fecha->getDay();
  int anio = fecha->getYear();

  while(cont <periodo){
    bool validacionDias = false,validacionDiaLaborable = false;
    mes++;
    cont++;
    if(mes > 12){
      mes = 1;
      anio++;
    }
    while (validacionDias == false){
      validacionDias = validarLosDias(dia,mes);
      if(validacionDias == false){
        dia--;
      }
    }
    while(validacionDiaLaborable == false){
      validacionDiaLaborable = validarDiaLaborable(anio,mes,dia);
      if(validacionDiaLaborable == false){
        dia++;
      }
      if((mes==4)||(mes==6)||(mes==9)||(mes==11))
          if(dia>30){
            do{
              dia--;
              validacionDiaLaborable = validarDiaLaborable(anio,mes,dia);
            }while(validacionDiaLaborable == false);
          }
        if((mes==1)||(mes==3)||(mes==5)||(mes==7)||(mes==8)||(mes==10)||(mes==12))
          if(dia>31){
            do{
              dia--;
              validacionDiaLaborable = validarDiaLaborable(anio,mes,dia);
            }while(validacionDiaLaborable == false);
          }
        if((mes==2))
          if(dia>28){
            do{
              dia--;
              validacionDiaLaborable = validarDiaLaborable(anio,mes,dia);
            }while(validacionDiaLaborable == false);
          }
    }
  }
  string tmp;
  tmp=to_string(dia)+"/"+to_string(mes)+"/"+to_string(anio);
  return tmp;
}

//--------------------setters------------------
void Tabla::setFechaPago(Fecha *_fecha){
    fechaPago =_fecha;
}
void Tabla::setTotal(float _total){
    total=_total;
}
void Tabla::setNumCuotas(int num_cuotas){
    plazo=num_cuotas;
}
void Tabla::setCuotas(float _pagos){
    cuotas=_pagos;
}
void Tabla::setPorcentajeInteres(float _restante){
    porcentajeInteres=_restante;
}


//---------------getters--------------

Fecha* Tabla::getFechaPago(){
    return fechaPago;
}
float Tabla::getTotal(){
    return total;
}
int Tabla::getNumCuotas(){
    return plazo;
}
float Tabla::getPorcentajeInteres(){
    return porcentajeInteres;
}
float Tabla::getCuotas(){
    return cuotas;
}
