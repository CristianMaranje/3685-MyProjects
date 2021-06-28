/*
UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE							   
Titulo: Proyecto tabla de amortizacion
Autor: Cristian maranje											       
Fecha: 27/06/2021													   
Fecha de modificacion: 28/06/2021								   
*/

#include <iostream>
#include <string>
#include "Archivo.h"
#include "Menu.h"
#include "Validaciones.h"

int main()
{
	ListaCircularDoble lista;
	string dato;
	int numero, opcion;
	long int indice1;
	Persona persona;
	Tabla tabla;
	Archivo archivo;
	Menu menu;
	long int cedula;

	archivo.leerArchivo(lista);

	do
	{
		opcion = menu.menu();
		switch (opcion)
		{
		case 0:
			do
			{
				system("cls");
				persona = persona.nuevaPersona();
				tabla = tabla.generarTabla();
				lista.revisarCorreo(persona, tabla);
				lista.insertar(persona, tabla);
				system("pause");
			} while (menu.repetir() != 1);
			system("cls");
			archivo.escribirArchivo(lista);
			break;

		case 1:
			do{
				system("cls");
				cout<<"Ingrese el numero de cedula de la persona a eliminar: ";cin>>cedula;
				cedula = validarCedula(cedula);
				lista.eliminar(cedula);
			}while(menu.repetir() != 1);
			break;
		case 2:
			system("cls");
			lista.imprimir();
			system("pause");
			break;
		default:
			
			cout << "Saliendo.....\n";
			break;
		}
	} while (opcion != 3);

	system("pause");
	return 0;
}
