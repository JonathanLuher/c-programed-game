#include "player.h"
#include<iostream>
#include<windows.h>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<list>

void gotoxy1(int x, int y){
    HANDLE jugador;
    jugador=GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos;
    pos.X = x;
    pos.Y = y;

    SetConsoleCursorPosition(jugador, pos);

}

void player::dibujar(){
    gotoxy1(x,y); printf("  %c",169);
    gotoxy1(x,y+1); printf(" %c%c%c",47,186,92);
    gotoxy1(x,y+2); printf(" %c %c",47,92);
}

void player::borrar(){
    gotoxy1(x,y); printf("         ");
    gotoxy1(x,y+1); printf("         ");
    gotoxy1(x,y+2); printf("        ");
}

void player::eliminar(){
    gotoxy1(x,y); printf("           ");
    gotoxy1(x,y+1); printf("             ");
    gotoxy1(x,y+2); printf("          ");

}

void player::mover(){
    if(kbhit()){
        char tecla = getch();
        borrar();
        if(tecla=='a'&&x>4)x--;
        if(tecla=='d'&&x<70)x++;
        if(tecla=='w'&&y>4)y--;
        if(tecla=='s'&&y+3<22)y++;
        if(tecla=='x')barra--;
        vida();
        dibujar();
        }
}

void player::vida(){
    gotoxy1(18,3); printf ("VIDAS %d", vidas);
    gotoxy1(3,3); std::cout<< "VIDA: ";
    gotoxy1(10,3); std::cout<< "      ";
    int i;
    for (i=0;i<barra; i++){
        gotoxy1(10+i,3); printf("%c",254);

    }
}

void player::muerte(){
    if (barra==0){
        eliminar();
        gotoxy1(x,y);   printf("   **   ");
        gotoxy1(x,y+1); printf("  ****  ");
        gotoxy1(x,y+2); printf("   **   ");
        Sleep(300);

        eliminar();
        gotoxy1(x,y);   printf(" * **  *");
        gotoxy1(x,y+1); printf("  ****  ");
        gotoxy1(x,y+2); printf(" * **  *");
        Sleep(300);
        eliminar();

        gotoxy1(x,y);   printf(" * *  *  *");
        gotoxy1(x,y+1); printf(" *  **  *  ");
        gotoxy1(x,y+2); printf(" * *  *  *");
        Sleep(300);
        eliminar();

        vidas--;
        barra=6;
        vida();
        dibujar();
        vida();
    }
}
