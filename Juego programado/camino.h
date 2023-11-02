#ifndef CAMINO_H
#define CAMINO_H
#include<iostream>
#include<windows.h>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<list>
using namespace std;

class camino
{
    public:
        camino(int _x, int _y):x(_x),y(_y){};
        void dibujar();
        void movimiento();
    private:
        int x,y;
};

#endif // CAMINO_H
