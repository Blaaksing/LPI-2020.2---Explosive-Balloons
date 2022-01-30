#include "jogo.h"
#include "funcoesMenu.h"
#include "ranking.h"
#include "menuPrincipal.h"

void menu(){        //exibir o menu principal
int menuSelect;
    HideCursor();
    printarLogo();
    printf("\n\t\t\t\t  U T I L I Z E  O S  R E S P E C T I V O S  N U M E R O S\n");
    printf("\t\t\t\tP A R A  N A V E G A R  P E L A S  O P C O E S  A B A I X O:");
    printf("\n\n\n\n\t\t1 - J O G A R\t2 - R A N K I N G\t3 - T U T O R I A L\t 4 - S A I R\t\n\t       |Configuracoes|\n\t       |  inclusas!  |\n\n\n");
        menuSelect = getch();
    switch(menuSelect){
    case '1': iniciarJogo();         // iniciar o jogo
    break;
    case '2': printarRanking();        // abrir o ranking
    break;
    case '3': tutorial();        // abrir o tutorial
    break;
    case '4': confirmarSair(); // abre tela de confirmar saida
    break;
    default:
    system ("cls");
    menu();                // imprime novamente o menu, em caso de apertar algum botao fora das cases.
    break;
    }
    return;
}
