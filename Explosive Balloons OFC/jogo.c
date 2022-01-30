#include "funcoesMenu.h"
#include "jogo.h"
#include "menuPrincipal.h"
#include "ranking.h"

#define Cima 72
#define Direita 77
#define Esquerda 75

int i = 55;
int k = 25;
int *pi,*pk;
int j;
char tecla;
int xPos=20, yPos=15;
int xVel=1,yVel=-1;
int aux;
int pontuacao = 0;
int cont = 0;
int bala;
int quantBala;
int velo;
int pontdific;

void finalizarPartida(int x){       //  Chama a função de armazenar os dados, e, em seguida, imprime a pontuação na tela
    system("cls");
    salvarJogador(x);

    gotoxy(43,10);
    printf("SUA PONTUACAO FOI DE: %d pontos. \n", x);
    system("pause");
    system("cls");
    menu();
    return;
}

void definirDificuldade(){          //   Tela de configurações para definir a dificuldade antes de executar o jogo
    int op;
    printarLogo();
    printf("\n\t\t\t\t  U T I L I Z E  O S  R E S P E C T I V O S  N U M E R O S\n");
    printf("\t\t\t\tP A R A  N A V E G A R  P E L A S  O P C O E S  A B A I X O:");
    gotoxy(22,15);
    printf("S E L E C I O N E  A  D I F I C U L D A D E  E  P R E S S I O N E  E N T E R:");
    gotoxy(40,17);
    printf("1 - FACIL  2 - MEDIO  3 - DIFICIL\n\n\t\t\t\t\t\tDificuldade: ");
    scanf("%d", &op);

    if(op == 1){
        velo = 120;
        pontuacao = 0;
        pontdific = 1;
        quantBala = 18;
    }else if(op == 2){
        velo = 90;
        pontuacao = 0;
        pontdific = 3;
        quantBala = 10;
    }else if(op == 3){
        velo = 60;
        pontuacao = 0;
        pontdific = 6;
        quantBala = 7;
    }else{
    system("cls");
    menu();
    }
    fflush(stdin);
    return;
}


void HideCursor(){
    CONSOLE_CURSOR_INFO cursor = {1, FALSE};
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor);
    return;
}
void gotoxy(int x, int y){ // funcao que atribui coordenadas no console

    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    return;
}
void parabolaRefatorada(){
    gotoxy(xPos,yPos);
    putchar(' ');
    if(aux==12)
        yVel=-yVel;
    if(aux==27) {
        xPos = 15 + ( rand() % 20 ), yPos= 13 + ( rand() % 16 );
        yVel=-yVel;
        aux=0;
    }
    xPos+=xVel+1;
    yPos+=yVel;
    aux++;
    gotoxy(xPos,yPos);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
    printf("Q");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
    Sleep(velo);

    return;
}

void arcoEflecha(){                 //arco apontando para cima
    gotoxy(55, 25);
    printf("     |          ");
    gotoxy(55, 26);
    printf("    /|\\          ");
    gotoxy(55, 27);
    printf("   / | \\          ");
    gotoxy(55, 28);
    printf("  /__|__\\          ");
    gotoxy(55, 29);
    printf("     |          ");
    gotoxy(55, 30);
    printf("     |          ");
    return;
}
void arcoEflechaDireito(){          //arco apontando para a direita
    gotoxy(55, 25);
    printf("      ____/");
    gotoxy(55, 26);
    printf("      \\  /|");
    gotoxy(55, 27);
    printf("       \\/ |");
    gotoxy(55, 28);
    printf("       /\\ |");
    gotoxy(55, 29);
    printf("      /  \\|");
    gotoxy(55, 30);
    printf("     /");
    return;
}
void arcoEflechaEsquerdo(){         //arco apontando para a esquerda
    gotoxy(55, 25);
    printf("\\____           ");
    gotoxy(55, 26);
    printf("|\\  /           ");
    gotoxy(55, 27);
    printf("| \\/            ");
    gotoxy(55, 28);
    printf("| /\\            ");
    gotoxy(55, 29);
    printf("|/  \\           ");
    gotoxy(55, 30);
    printf("     \\          ");
    return;
}

void movimentosArco(){      // Movimentação e tiro do arco
int a;
    pi = &i;
    pk = &k;

tecla = getch();
    if(tecla == Direita){
        arcoEflechaDireito();
        int b = 0;
        int c = 0;
        for(a = 0; a < 10; a++){
            if(((67+b) == xPos)&&((24-c)== yPos)){  //CHECAGEM DO TIRO
                gotoxy(5,5);
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
                printf("  VOCE ACERTOU");
                Sleep(150);
                gotoxy(5,5);
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
                printf("                    ");
                gotoxy(xPos,yPos);
                printf(" ");
                gotoxy(xPos,yPos);
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
                printf("X");
                Sleep(250);
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
                pontuacao++;
            }

            gotoxy(67+b,24-c);
            printf("/");
            Sleep(30);
            gotoxy(67+b,24-c);
            printf(" ");
            b++;
            c++;

        }
        bala++;
    }
    if(tecla == Esquerda){

        arcoEflechaEsquerdo();
        int b = 0;
        int c = 0;
        for(a = 0; a < 20; a++){
            if(((53-b) == xPos)&&((24-c)== yPos)){  //CHECAGEM DO TIRO
                gotoxy(5,5);
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
                printf("  VOCE ACERTOU");
                Sleep(150);
                gotoxy(5,5);
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
                printf("                      ");
                gotoxy(xPos,yPos);
                printf(" ");
                gotoxy(xPos,yPos);
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
                printf("X");
                Sleep(250);
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
                pontuacao++;
            }

            gotoxy(53-b,24-c);
            printf("\\");
            Sleep(30);
            gotoxy(53-b,24-c);
            printf(" ");
            b++;
            c++;

        }
        bala++;
    }
    if(tecla == Cima){           //ATIRAR O PROJETIL
        for(j = 1; j < 20; j++){
            if((60 == xPos)&&((25-j)== yPos)){    //CHECAGEM DO TIRO
                gotoxy(5,5);
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);        //Aparece ao estourar balao (logo encima da parte de pontuacao)
                printf("  VOCE ACERTOU");
                Sleep(150);
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
                gotoxy(5,5);
                printf("                       ");
                gotoxy(xPos,yPos);
                printf(" ");
                gotoxy(xPos,yPos);
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);        //Aparece ao estourar balao
                printf("X");
                Sleep(250);
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
                pontuacao++;
            }
            arcoEflecha();
            //parabolaRefatorada();
            gotoxy(60,25-j);
            printf("|");
            Sleep(30);
            gotoxy(60,25-j);
            printf(" ");

        }
    bala++;
    }
    return;
}

void iniciarJogo(){         //  Função que da inicio ao jogo

    system("cls");
    definirDificuldade();
    system("cls");
    arcoEflecha();

    while(1){                   //  Laço para imprimir algo semelhante a correntes de vento
        int pos1 = rand()%120;
        int pos2 = rand()%30;

        gotoxy(pos1,pos2);
        printf("~~~");

            if(kbhit()){
          movimentosArco();
        }

        parabolaRefatorada();       //  Movimentação do balão (nao necessariamente é uma parabola)
        gotoxy(5,6);
        printf("  Pontuacao: %d pts.", pontuacao*pontdific);
        gotoxy(5,7);
        printf("  Flechas: %d ", quantBala - bala);
        if((quantBala - bala == 0)){
            bala = 0;
            int p = pontuacao*pontdific;
            finalizarPartida(p);
            pontuacao = 0;
            pontdific = 0;
            system("pause");
            break;
        }
        gotoxy(pos1,pos2);
        printf("   ");
    }

    return;
}
