/*
progetto suﬀiciente se permette a due utenti di giocare alternando l’inserimento delle proprie mosse
tramite input da tastiera; l’implementazione delle regole del gioco può essere ragionevolmente parziale.
progetto buono se permette a due utenti di giocare alternando l’inserimento delle proprie mosse tramite input da tastiera;
 l’implementazione delle regole deve essere corretta.
progetto ottimo se implementa una strategia in grado di giocare contro l’utente; avete piena libertà di definire una strategia.
 La rimozione di una riga vale 1 punto, la rimozione di due righe con un solo pezzo vale 3 punti, tre righe 6 punti, quattro righe 12 punti.
 Il gioco termina quando finiscono i pezzi o il giocatore non riesce a posizionare un tetramino nel campo di gioco rispettando il limite di altezza.
 */
/*gcc -Wall -ansi -pedantic main.c turni_players.c pedine.c campo.c*/



#include <stdio.h>
#include "campo.h"
#include "turni_players.h"

void stampa_scritta_iniziale()
{

    printf("--------------------------------------------------------------\n");
    printf("\033[0;36m");
    printf("##########  ##########  ###########  ##########  #  ##########\n");
    printf("    #       #                #       #        #  #  #         \n");
    printf("    #       #                #       #        #  #  #         \n");
    printf("    #       ##########       #       ##########  #  ##########\n");
    printf("    #       #                #       #      #    #           #\n");
    printf("    #       #                #       #       #   #           #\n");
    printf("    #       ##########       #       #        #  #  ##########\n");
    printf("\033[0m");
    printf("--------------------------------------------------------------\n");
    
}

int main()
{
    char ch;
    char campo[15][10];
    printf("Press a character or a number or a symbol button to see the introduction: ");
    scanf("%c",&ch);
    stampa_scritta_iniziale();
    iniz_campo(campo);
    turni_players(campo);
    return 0;
}
