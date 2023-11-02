#ifndef ENEMIGO_H
#define ENEMIGO_H

class enemigo
{
    public:
        enemigo(int _x, int _y):x(_x),y(_y){};
        void dibujar();
    private:
        int x,y;
};

#endif // ENEMIGO_H
