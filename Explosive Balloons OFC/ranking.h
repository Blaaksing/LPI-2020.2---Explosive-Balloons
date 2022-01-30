#ifndef RANKING_H_INCLUDED
#define RANKING_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <string.h>

struct ranqueamento{
char nome[14];
int pontos;
};

void arquivoPontos(char name[14], int pontos);
void salvarJogador(int pontos);
int quantidadeJogador();
void exibirRanking(struct ranqueamento jogador[20]);
void printarRanking();

#endif // RANKING_H_INCLUDED
