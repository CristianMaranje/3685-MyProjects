#include <iostream>
#include <string>
#include <cctype>
#include <cstdlib>
#pragma once
#define dim 10

long int validarCedula(long int cedula){
    int A[dim],i=9,sumapar=0,sumaimp=0,sumatot,mult=0,digito;
    long int coc=0,tmpCedula=0;
    do
    {
        i=9;
        sumapar=0;
        sumaimp=0;
        mult=0;
        digito=0;
        tmpCedula=cedula;
        do
        {
            coc=cedula/10;
            A[i]=cedula%10;
            i--;
            cedula=coc;
        }while (coc!=0);

        for(i=0;i<dim-1;i+=2){
            mult=A[i]*2;
            if (mult>9){
                mult-=9;
            }
            sumapar+=mult;
        }
        for (i=1;i<dim-2;i+=2){
            sumaimp+=A[i];
        }
        sumatot=sumapar+sumaimp;
        digito=10-(sumatot%10);
        if (digito==10){
            digito=0;
        }if (digito==A[9]){
            printf("Cedula valida.\n");
        }else{
            printf("\nCedula invalida\nIngrese nuevamente: ");
            fflush(stdin);
            scanf("%ld",&cedula);
            fflush(stdin);
        }

    }while (digito!=A[9]);
    return tmpCedula;
}

bool esInt(std::string dato) {
	bool esInt = true;
	int longitud = dato.size();
	
	if (longitud == 0) {
		esInt = false;
	} else if (longitud == 1 && !isdigit(dato[0])) {
		esInt = false;
	} else {
		int i = 0;
		if (dato[0] == '+' || dato[0] == '-') {
			i++;
		}
		
		while (i < longitud) {
			if (!isdigit(dato[i])) {
				esInt = false;
				break;
			}
			i++;
		}
	}
	return esInt;	
}

bool esFloat(std::string dato){
	bool esFloat = true;
	int longitud = dato.size();
	int punto = 0;
		
	if (longitud == 0) {
		esFloat = false;
	} else if (longitud == 1 && !isdigit(dato[0])) {
		esFloat = false;			
	} else{
		int i = 0;
		if(dato[0] == '-' || dato[0] =='+'){
			i ++;
		}
		if(dato[i] == '.'){
			return false;
		}
		
		while (i < longitud) {
			if(dato[i] == '.'){
				punto++;
			}
			if (!(isdigit(dato[i]) || dato[i] == '.') || punto == 2) {				
				esFloat = false;
				break;
			}
			i++;
		}		
	}
	return esFloat;
}

bool esCadena(std::string dato){
	int longitud = dato.size();
	int i = 0;
	if (longitud == 0) {
		return false;
	}
	while(i < longitud){
		if(isdigit(dato[i])){
			return false;
		}
	}
	return true;
}
