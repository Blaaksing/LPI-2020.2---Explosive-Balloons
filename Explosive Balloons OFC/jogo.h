#ifndef JOGO_H_INCLUDED
#define JOGO_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <string.h>

void definirDificuldade();
void HideCursor();
void gotoxy(int xPos, int yPos);
void parabolaRefatorada();
void arcoEflecha();
void arcoEflechaDireito();
void arcoEflechaEsquerdo();
void movimentosArco();
void iniciarJogo();
void finalizarPartida(int x);

#endif // JOGO_H_INCLUDED
