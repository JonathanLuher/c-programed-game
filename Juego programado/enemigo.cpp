#include "enemigo.h"
#include<iostream>
#include<windows.h>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<list>
using namespace std;

void gotoxy4(int x, int y){
    HANDLE jugador;
    jugador=GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos;
    pos.X = x;
    pos.Y = y;

    SetConsoleCursorPosition(jugador, pos);

}

void enemigo::dibujar(){
    gotoxy4(x,y); printf("  %c",169);
    gotoxy4(x,y+1); printf(" %c%c%c",47,186,92);
    gotoxy4(x,y+2); printf(" %c %c",47,92);
}
