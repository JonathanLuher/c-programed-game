#include "energia.h"
#include<iostream>
#include<windows.h>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<list>

void gotoxy2(int x, int y){
    HANDLE jugador;
    jugador=GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos;
    pos.X = x;
    pos.Y = y;

    SetConsoleCursorPosition(jugador, pos);

}

void energia::dibujar(){
    gotoxy2(x,y); printf("%c%c",174,174);
}

void energia::movimiento(){
    gotoxy2(x,y); printf("  ");
    x--;
    if(x<5){
        y=rand()%17+4;
        x=77;
    }
    dibujar();
}

void energia::golpe(class player &jugador){
    if (x>=jugador.X()&&x<jugador.X()+4&&y>=jugador.Y()&&y<=jugador.Y()+2)
    {
        jugador.danar();
        jugador.eliminar();
        jugador.dibujar();
        jugador.vida();
        y=rand()%17+4;
        x=77;
    }
}
