#ifndef ENERGIA_H
#define ENERGIA_H
#include "player.h"

class energia
{
    public:
        energia(int _x, int _y):x(_x),y(_y){};
        void dibujar();
        void movimiento();
        void golpe(class player &N);
        int X(){return x;}
        int Y(){return y;}
    private:
        int x,y;
};

#endif // ENERGIA_H
