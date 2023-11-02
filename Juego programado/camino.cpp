#include "camino.h"
#include<iostream>
#include<windows.h>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<list>
using namespace std;

void gotoxy3(int x, int y){
    HANDLE jugador;
    jugador=GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos;
    pos.X = x;
    pos.Y = y;

    SetConsoleCursorPosition(jugador, pos);

}

void camino::dibujar(){
    gotoxy3(x,y); printf("%c%c%c%c%c%c%c%c",176,176,176,176,176,176,176,176);
}

void camino::movimiento(){
    gotoxy3(x,y); printf("          ");
    x--;
    if(x<5){
        y=rand()%1+25;
        x=77;
    }
    dibujar();
}
