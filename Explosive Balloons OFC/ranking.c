#include "funcoesMenu.h"
#include "ranking.h"
#include "jogo.h"
#include "menuPrincipal.h"

int i;
int y,x, aux;
char aux2[15];

void salvarJogador(int pontos){       // Grava o nome do player da rodada
char jogador[14];
    printf("Digite seu nome: ");
    fgets(jogador, 11*sizeof(char), stdin);
    arquivoPontos(jogador, pontos);
    return;
}

void arquivoPontos(char nome[14], int pontos){      //  Salva a pontuação e o nome no txt

    FILE *pont_arq;
    pont_arq = fopen("ranking.txt", "a");

    if(pont_arq == NULL){
        printf("Arquivo ranking.txt nao pode ser aberto.");
        exit(0);
            }
            fprintf(pont_arq, "\n%s - %i", nome, pontos);
            fclose(pont_arq);
            return;
}

int quantidadeJogador()         // Adiciona jogadores no txt, consequentemente, alterando a quantidade dos mesmos presentes
{

    FILE *pont_arq;
    pont_arq = fopen("ranking.txt","r");

    if(pont_arq == NULL){
        printf("Arquivo ranking.txt nao pode ser aberto.");
        exit(0);
    }
    fclose(pont_arq);
    return 1;
}

void exibirRanking(struct ranqueamento jogador[20])       //Mostrar ranking dentro do jogo
{
int i;
char opcao;

    if(quantidadeJogador() > 10){
        FILE *pont_arq;
        pont_arq = fopen("ranking.txt", "w");

            if(pont_arq == NULL){
            printf("Arquivo ranking.txt nao pode ser aberto.");
            exit(0);
            }

            for(i=0; i<9; i++){      //Ordenar o ranking
            fprintf(pont_arq, "%s - %i\n", jogador[i].nome, jogador[i].pontos);
        }
        fprintf(pont_arq, "%s - %i", jogador[i].nome, jogador[i].pontos);
        fclose(pont_arq);
    }

    do{
        system("cls");
        for(x=0; x<10; x++){
                for(y = x + 1; y < 20; y++){          //BubbleSort (Ordenar ranking)
                    if(jogador[x].pontos < jogador[y].pontos){
                            strcpy(aux2,jogador[x].nome);
                            aux  = jogador[x].pontos;
                            jogador[x].pontos = jogador[y].pontos;
                            strcpy(jogador[x].nome,jogador[y].nome);
                            strcpy(jogador[y].nome,aux2);
                            jogador[y].pontos = aux;
                            }
                    }
                    printf("\n\t\t\t%s - %d\n", jogador[x].nome, jogador[x].pontos);
            }
            printf("\n\t\t1 - V O L T A R\n");
            opcao=getch();
    }
    while(opcao!= '1');
    system("cls");
    menu();
    return;
}

void printarRanking()  //funcao para ler o ranking
{
int pontos;
struct ranqueamento jogador[20];
char nome[14];

    for(i=0; i<20; i++){
        strcpy(jogador[i].nome, " ");
        jogador[i].pontos= 0;
    }
    FILE *pont_arq;
    pont_arq = fopen("ranking.txt", "r");

    if(pont_arq == NULL){
        fclose(pont_arq);
        pont_arq = fopen("ranking.txt", "w");

            if(pont_arq == NULL){
                printf("Arquivo ranking.txt nao pode ser aberto.");
                exit(0);
            }
            fclose(pont_arq);
            pont_arq = fopen("ranking.txt", "r");
    }

    i=0;
    while((fscanf(pont_arq, "%s - %i", nome, &pontos)!=EOF)){
        if(i<15){
            strcpy(jogador[i].nome,nome );
            jogador[i].pontos = pontos;
            i++;
            }
        }
        fclose(pont_arq);
        exibirRanking(jogador);
        return;
}
