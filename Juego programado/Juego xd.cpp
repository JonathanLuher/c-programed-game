#include<iostream>
#include<windows.h>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<list>
using namespace std;
#include "player.h"
#include "energia.h"
#include "camino.h"
#include "enemigo.h"
#include "disparo.h"

void gotoxy(int x, int y){
    HANDLE jugador;
    jugador=GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos;
    pos.X = x;
    pos.Y = y;

    SetConsoleCursorPosition(jugador, pos);

}

void invisible(){
    HANDLE jugador;
    jugador=GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cci;
    cci.dwSize = 2;
    cci.bVisible = FALSE;

    SetConsoleCursorInfo(jugador, &cci);
}

void limites(){
    int i;
    for(i=2;i<88;i++){
        gotoxy(i,2); printf("%c",205);
        gotoxy(i,28); printf("%c",205);
        gotoxy(i,22); printf("%c",205);
    }
    for(i=3;i<28;i++){
    gotoxy(2,i); printf("%c",186);
    gotoxy(87,i); printf("%c",186);
    }
    //esquinas
    gotoxy(2,2); printf("%c",201);
    gotoxy(2,28); printf("%c",200);
    gotoxy(87,2); printf("%c",187);
    gotoxy(87,28); printf("%c",188);

    gotoxy(2,22); printf("%c",204);
    gotoxy(87,22); printf("%c",185);
}

void borrartexto(){
    int y;
    for(y=1;y<30;y++){
        gotoxy(1,y);printf("                                                                        ");
    }

}

int main(){


    int lista;
    printf("\t\t\t\t >>LUCHA ENTRE GUERREROS<< \n\n\t\t Creado por Galicia Andrade Arturo y... \n\n\n\t");
    printf("Un extrano sujeto llego al planeta y es capaza de disparar\n\tmultiples esferas de energia a la vez.");
    printf("  Dispara y destruye la\n\tmayor cantidad de sus \tesferas de energia \n\tpara salvar al mundo.");
    printf("\n\n\n\tCONTROLES\n\n\t  S=Moverte hacia abajo.\n\t  W=Moverte hacia arriba.");
    printf("\n\t  A=Moverte hacia la izquierda.\n\t  D=Moverte hacia la dercha.");
    printf("\n\t  C=Disparar tus esferas de energia");
    printf("\n\n\t");
    system("pause");

    borrartexto();

    enemigo malo(80,12);
    invisible();
    limites();
    player jugador (6,18,6,5);
    jugador.dibujar();
    jugador.vida();
    camino ruta1(10,25),ruta2(24,25),ruta3(38,25),ruta4(51,25),ruta5(66,25);
    int puntos=0;

    list<energia*> A;
    list<energia*>::iterator itA;
    int i;
    for(i=0;i<10;i++){
        A.push_back(new energia(rand()%20+59,rand()%17+4));

    }

    list<disparo*> B;
    list<disparo*>::iterator it;

    bool findeljuego=false;
    while(!findeljuego){

        gotoxy(70,3);printf("Puntos %d",puntos);
        jugador.mover();
        if(kbhit()){

            char teclamover=getch();
            if (teclamover == 'c')
                B.push_back(new disparo(jugador.X()+2,jugador.Y()-1));
                Beep(500,10);

        }

        for(it=B.begin();it!=B.end(); it++){
            (*it)->mover();
            if ((*it)->salir()){
                gotoxy((*it)->X(),(*it)->Y()); printf(" ");
                delete(*it);
                it=B.erase(it);
            }
        }

        for(itA=A.begin();itA!=A.end();itA++){
            (*itA)->movimiento();
            (*itA)->golpe(jugador);
        }

        for(itA=A.begin();itA!=A.end();itA++){
            for(it=B.begin();it!=B.end();it++){
                if(((*itA)->X()==(*it)->X()||(*itA)->X()+1==(*it)->X())&&(*itA)->Y()-2==(*it)->Y()){
                    gotoxy((*it)->X(),(*it)->Y());printf("  "); delete(*it);
                    it=B.erase(it);
                    A.push_back(new energia(rand()%20+59,rand()%17+4));

                    gotoxy((*itA)->X(),(*itA)->Y());printf("  "); delete(*itA);
                    itA=A.erase(itA);
                    puntos+=100;
                }
            }

        }

        jugador.muerte();
        ruta1.movimiento();
        ruta2.movimiento();
        ruta3.movimiento();
        ruta4.movimiento();
        ruta5.movimiento();
        malo.dibujar();
        if(jugador.vid()==0){
            findeljuego=true;
            system("pause");
        }
        Sleep(30);

    }

    std::cout << ">>" <<std::endl;
}
