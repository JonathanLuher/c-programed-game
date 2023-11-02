#ifndef DISPARO_H
#define DISPARO_H

class disparo
{
    public:
        disparo(int _x, int _y):x(_x),y(_y){};
        int X(){return x;}
        int Y(){return y;}
        void mover();
        bool salir(){if (x>82) { return true; } return false;};;
    private:
        int x,y;
};

#endif // DISPARO_H
