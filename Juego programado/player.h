#ifndef PLAYER_H
#define PLAYER_H
#include<iostream>
#include<windows.h>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<list>

class player
{
    public:
        player(int _x, int _y, int _barra, int _vidas): x(_x),y(_y),barra(_barra),vidas(_vidas){};
        void dibujar();
        void borrar();
        void mover();
        void vida();
        void muerte();
        void eliminar();
        int X(){return x;}
        int Y(){return y;}
        int vid(){return vidas;}
        void danar(){barra--;}

    private:
        int x,y;
        int barra;
        int vidas;
};

#endif // PLAYER_H
