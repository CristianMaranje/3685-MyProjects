#include <iostream>
#include "Prefijo.h"
#include "Postfijo.h"


int main() {
    std::string ejercicio,resultado;
    std::cout<<"Ingrese el ejercicio en infijo: "; getline(std::cin, ejercicio);
    resultado = transformarAPrefijo(ejercicio);
    cout<<"Prefijo: "<<resultado<<endl;
    resultado = transformarAPostfijo(ejercicio);
    cout<<"Postfijo: "<<resultado<<endl; 
    return 0;
}
