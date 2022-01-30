#include "jogo.h"
#include "funcoesMenu.h"
#include "ranking.h"
#include "menuPrincipal.h"

void printarLogo(){             // Logotipo do Game
    printf("\n\t\t\t\t                                             ___            ");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 69);
    printf("     \n");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
    printf("\t\t\t\t __      __       __   __  -        __      |   \\         ");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 69);
    printf("        \n");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
    printf("\t\t\t\t|__ \\ / |__| |   |  | |__  |  \\  / |__      |___/        ");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 69);
    printf("  ");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 250);
    printf("  ");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 69);
    printf("      \n");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
    printf("\t\t\t\t|__ / \\ |    |__ |__|  __| |   \\/  |__      |   \\        ");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 69);
    printf("  ");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 250);
    printf("  ");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 69);
    printf("      \n");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
    printf("\t\t\t\t                                            |___/  o     ");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 69);
    printf("  ");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 250);
    printf("  ");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 69);
    printf("      \n");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
    printf("\t\t\t\t                                                          ");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 69);
    printf("        \n");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
    printf("\t\t\t      E  X  P  L  O  S  I  V  E        \tB  A  L  L  O  O  N  S      ");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 69);
    printf("    \n");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
    printf("\t\t\t                                                                     ");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 250);
    printf(" \n");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
    printf("\t\t\t                                                                       ");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 250);
    printf(" \n");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
    printf("\t\t\t                                                                         ");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 250);
    printf(" ");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
    return;
}

void confirmarSair(){           //  Funcao de saida do game
char confirmarSair;
do{
        system("cls");
        printarLogo();
        printf("\n\n\n\t\t\t\t    D E S E J A  S A I R  D O  J O G O ?\n\n\t\t\t\t\t   1 - S I M \t 2 - N A O\n");
           confirmarSair = getch();
        if(confirmarSair == '1'){       //se sim, o jogo fecha
            break;
        }
        else if(confirmarSair == '2'){      // se nao, o jogo retorna ao menu
            system("cls");
            menu();
        }
        else{

            printf("\t\t\t\t\t O P C A O  I N V A L I D A");

        }
        }while (confirmarSair != '1' || confirmarSair != '2');
    return;
}

void tutorial(){        // Tela com as instruções do game

        system("cls");
        printarLogo();
        printf("\n\n\n\t  U S E  A S  S E T A S  P A R A  A T I R A R  N A S  R E S P E C T I V A S  D I R E C O E S\n\n");
        printf("\t\t|-----------------------------------------------------------------------------------|\n");
        printf("\t\t| 1 | F A C I L: 1  P O N T O  P O R  B A L A O\t\t | \t18   F L E C H A S  |\n");
        printf("\t\t|-----------------------------------------------------------------------------------|\n");
        printf("\t\t| 2 | M E D I O: 3  P O N T O S  P O R  B A L A O\t | \t10   F L E C H A S  |\n");
        printf("\t\t|-----------------------------------------------------------------------------------|\n");
        printf("\t\t| 3 | D I F I C I L: 6  P O N T O S  P O R  B A L A O\t | \t7   F L E C H A S   |\n");
        printf("\t\t|-----------------------------------------------------------------------------------|\n");
        system("pause");
        system("cls");
        menu();
        return;
}
