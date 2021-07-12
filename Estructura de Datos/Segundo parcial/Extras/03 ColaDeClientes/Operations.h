#include <iostream>
#include <conio.h>
#include <windows.h>
#include <stdio.h>
#pragma once
using namespace std;
HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
COORD CursorPosition;

//numro de clientes en la cola
// el tiempo promedio de servicios
// promedio entre llegadas
// promedio del tiempo de espera
// tiempo promedio que no trabaja el cajero

void gotoXY(int x, int y)
{
	CursorPosition.X = x;
	CursorPosition.Y = y;
	SetConsoleCursorPosition(console, CursorPosition);
}

float average(float addition, float total)
{
    return addition / total;
}

void marquee2(std::string& text) {
    std::string temp = text;
    text.erase(0, 1);
    text += temp[0];
}

void marquee()
{
   std::string test = " Simulacion de colas ";
    while (true)
    {
        marquee2(test);
        SetConsoleTitleA(test.c_str());
        gotoXY(38,0);
        std::cout<<test.c_str();
        Sleep(500);
    }
}