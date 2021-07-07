#include <iostream>
#include <string>
#include "Pila.h"

/*
UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE							   
Titulo: Transforma de infijo a prefijo 
Autor: Cristian maranje											       
Fecha: 03/07/2021													   
Fecha de modificacion: 5/07/2021								   
*/

bool esOperator(char var);
int precedencia(char var);
bool validarFuncionTrigo(string ejercicio, int i);

string transformarAPrefijo(string ejercicio)
{
    Pila pilaPrefijo;
    string resultado, tmp;
    //recorre de izquierda a derecha el string
    for (int i = ejercicio.length() - 1; i >= 0; i--)
    {
        //inserta los digitos
        if (isdigit(ejercicio[i])||(ejercicio[i] >= 97 && ejercicio[i] <= 122)) //que tambien ingrese caracteres
        {
            resultado += ejercicio[i];
        }

        //revisa por funciones trigonometricas
        else if (ejercicio[i] == 'n' || ejercicio[i] == 's' || ejercicio[i] == 't' || ejercicio[i] == 'c')
        {
            if (validarFuncionTrigo(ejercicio, i))
            {
                string funcion;
                funcion = ejercicio[i];
                funcion += ejercicio[i - 1];
                funcion += ejercicio[i - 2];
                resultado += funcion;
                i -= 2;
            }
        }

        //ingresa a la pilaPrefijo los operadores
        else if (ejercicio[i] != '(')
        {
            char ultimoOperador;
            if (ultimoOperador = pilaPrefijo.top() != '!' && ejercicio[i] != ')' && (precedencia(ultimoOperador = pilaPrefijo.top()) > precedencia(ejercicio[i])))
            {
                resultado += pilaPrefijo.pop();
                pilaPrefijo.push(tmp = ejercicio[i]);
            }
            else
            {
                pilaPrefijo.push(tmp = ejercicio[i]);
            }
        }

        //saca de la pilaPrefijo los operadores que estan dento de los parentesis y los pone en el resultado
        else if (ejercicio[i] == '(')
        {
            string tmpPop;
            do
            {
                tmpPop = pilaPrefijo.pop();
                if (tmpPop != ")" && tmpPop != "!")
                {
                    resultado += tmpPop;
                }
                else if (tmpPop == "!")
                {
                    tmpPop = ")";
                }
            } while (tmpPop != ")");
        }

        //pone los oreradorres restantes de la pilaPrefijo en el resultado
        if (i == 0)
        {
            string tmpPop;
            do
            {
                tmpPop = pilaPrefijo.pop();
                if (tmpPop != ")" && tmpPop != "!")
                {
                    resultado += tmpPop;
                }
                if (tmpPop == "!")
                {
                    tmpPop = ")";
                }
            } while (tmpPop != ")");
        }
    }

    //le tenemos que dar la vuelta al resultado pra que este correcto
    string reverse;
    for (int i = resultado.length(); i >= 0; i--)
    {
        reverse += resultado[i];
    }
    return reverse;
}

bool esOperator(char var)
{
    return precedencia(var) != 0;
}

int precedencia(char var)
{
    return (var == '+' || var == '-') ? 1 : (var == '*' || var == '/') ? 2
                                        : (var == '^')                 ? 3
                                                                       : 0;
}

bool validarFuncionTrigo(string ejercicio, int i)
{
    string funcion;
    funcion = ejercicio[i - 2];
    funcion += ejercicio[i - 1];
    funcion += ejercicio[i];
    if (funcion == "cos" || funcion == "sen" || funcion == "tan" || funcion == "cot" || funcion == "csc" || funcion == "sec")
    {
        return true;
    }
    else
    {
        return false;
    }
}
