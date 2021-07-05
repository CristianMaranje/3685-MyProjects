#include <iostream>
#include <string>
#include "Pila.h"

using namespace std;

inline bool esOperatorPostfijo(char var);
inline int precedenciaPostfijo(char var);
inline bool validarFuncionTrigoPostfijo(string ejercicio, int i);

string transformarAPostfijo(string ejercicio)
{
    Pila pilaPostfijo;
    string resultado, tmp;
    //recorre el string ejercicio de derecha a izquierda
    for (int i = 0; i <= ejercicio.length(); i++)
    {
        //inserta los digitos
        if (isdigit(ejercicio[i])) //que tambien ingrese caracteres
        {
            resultado += ejercicio[i];
        }

        //revisa por funciones trigonometricas
        else if (ejercicio[i] == 's' || ejercicio[i] == 'c' || ejercicio[i] == 't')
        {
            if (validarFuncionTrigoPostfijo(ejercicio, i))
            {
                string funcion;
                funcion = ejercicio[i];
                funcion += ejercicio[i + 1];
                funcion += ejercicio[i + 2];
                resultado += funcion;
                i += 2;
            }
        }

        //ingresa a la pilaPostfijo los operadores
        else if (ejercicio[i] != ')')
        {
            char ultimoOperador;
            //mira que no sea nulla la pila, que no sea ( , si el ultimo elemento de la pila tiene mayor procedencia
            //de cumplirse se hace un pop al resultado del ultimo operador ingresado y se agraga el nuevo
            if (ultimoOperador = pilaPostfijo.top() != '!' && ejercicio[i] != '(' && (precedencia(ultimoOperador = pilaPostfijo.top()) > precedencia(ejercicio[i])))
            {
                resultado += pilaPostfijo.pop();
                pilaPostfijo.push(tmp = ejercicio[i]);
                //i + 3;
            }
            else
            {
                pilaPostfijo.push(tmp = ejercicio[i]);
            }
        }

        //saca de la pilaPostfijo los operadores que estan dento de los parentesis y los pone en el resultado
        else if (ejercicio[i] == ')')
        {
            string tmpPop;
            do
            {
                tmpPop = pilaPostfijo.pop();
                if (tmpPop != "(" && tmpPop != "!")
                {
                    resultado += tmpPop;
                }
                if (tmpPop == "!")
                {
                    tmpPop = "(";
                }
            } while (tmpPop != "(");
        }

        //pone los oreradorres restantes de la pilaPostfijo en el resultado
        if (i == ejercicio.length())
        {
            string tmpPop;
            do
            {
                tmpPop = pilaPostfijo.pop();
                if (tmpPop != "(" && tmpPop != "!")
                {
                    resultado += tmpPop;
                }
                if (tmpPop == "!")
                {
                    tmpPop = "(";
                }
            } while (tmpPop != "(");
        }
        // cout << "resultado: " << resultado << "\nPila:\n";
        // pilaPostfijo.mostrar();
    }
    return resultado;
}

inline bool esOperatorPostfijo(char var)
{
    return precedencia(var) != 0;
}

inline int precedenciaPostfijo(char var)
{
    return (var == '+' || var == '-') ? 1 : (var == '*' || var == '/') ? 2
                                        : (var == '^')                 ? 3
                                                                       : 0;
}

inline bool validarFuncionTrigoPostfijo(string ejercicio, int i)
{
    string funcion;
    funcion = ejercicio[i];
    funcion += ejercicio[i + 1];
    funcion += ejercicio[i + 2];
    if (funcion == "cos" || funcion == "sen" || funcion == "tan" || funcion == "cot" || funcion == "csc" || funcion == "sec")
    {
        return true;
    }
    else
    {
        return false;
    }
}