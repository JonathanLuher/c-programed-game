#include "disparo.h"
#include<iostream>
#include<windows.h>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<list>
using namespace std;

void gotoxy5(int x, int y){
    HANDLE jugador;
    jugador=GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos;
    pos.X = x;
    pos.Y = y;

    SetConsoleCursorPosition(jugador, pos);

}

void disparo::mover (){
    gotoxy5(x+2,y+2); printf(" ");
    if (x<82){ x++; gotoxy5(x+2,y+2); printf("%c",254); }
}

