#include <stdio.h>
#include "pedine.h"
#include "campo.h"
#include "turni_players.h"


void turni_players(char campo[15][10])
{
    int colonna, riga,punteggio_player_O=0, punteggio_player_W=0,check_sconfitta=0,scelta_pedina,rotazione,j, break_loop=0,max_ped=20;
    while(1)
    {
        /*TURN DEL PRIMO PLAYER*/
        /*TURN DEL PRIMO PLAYER*/
        /*TURN DEL PRIMO PLAYER*/
        /*TURN DEL PRIMO PLAYER*/
        /*TURN DEL PRIMO PLAYER*/
        /*TURN DEL PRIMO PLAYER*/

        stampa_campo(campo);        /*print il campo*/
        printf("turno PL4Y3R_1! inserisci il numero della colonna in cui vuoi posizionare la pedina: ");
        scanf("%d",&colonna);
        if(colonna<0 || colonna >9)
        {
            while(break_loop == 0)
            {
                printf("attenzione!! hai inserito una colonna fuori dal campo!! inserire una colonna compresa tra 0 e 9 inclusi: ");
                scanf("%d", &colonna);
                if(colonna<0 || colonna>9)
                    break_loop = 0;
                else
                    break_loop=1;
            }
            break_loop=0;
        }
        printf("tipologie pedine:|| 1 = quadrata || 2 = i || 3 = Z || 4 = T || 5 = L ||\n");
        printf("inserisci la tipologia di pedina che vuoi: ");
        scanf("%d",&scelta_pedina);
        if(scelta_pedina<1 || scelta_pedina>5)
        {
            while(break_loop == 0)
            {
                printf("attenzione!! hai inserito una tipologia inesistente!! inserire una tipologia tra quelle elencate di seguito: \n");
                printf("tipologie pedine:|| 1 = quadrata || 2 = i || 3 = Z || 4 = T || 5 = L ||: ");
                scanf("%d",&scelta_pedina);
                if(scelta_pedina<1 || scelta_pedina>5){
                    break_loop=0;
                }
                else{
                    break_loop=1;
                }
            }
            break_loop=0;
        }
        check_sconfitta = controllo_colonna(campo,colonna,scelta_pedina);
        if (check_sconfitta == 1)
        {
            printf("PL4Y3R_2 ha vinto!!!\n");
            printf("PL4Y3R_1 è uscito dal campo in altezza!!!\n");
            return;
        }
        riga = caduta_pedina(campo,colonna,scelta_pedina);
        if(scelta_pedina == 1)
        {
            c_e_pedina_quadrata(campo, riga, colonna, scelta_pedina);
        }
        if(scelta_pedina == 2)
        {
            rotazione=c_e_pedina_i(campo,riga,colonna,scelta_pedina);
            if(rotazione == 0){
                printf("la pedina è uscita in altezza\n");
                printf("il player2 ha vinto");
                return;
            }
            if(rotazione==1)
            {
                if(riga<3){
                    printf("la pedina è uscita in altezza\n");
                    printf("il player2 ha vinto");
                    return;
                }
            }
            if(rotazione==2){
                if(riga<0){
                    printf("la pedina è uscita in altezza\n");
                    printf("player2 ha vinto");
                    return;
                }
            }
        }
        if(scelta_pedina == 3)
        {
            rotazione=c_e_pedina_z(campo, riga, colonna, scelta_pedina);
            if(rotazione ==1)
            {
                if(riga<1 || (riga==1 && campo[riga][colonna+1]!='.' ))
                {
                    printf("la pedina è uscita in altezza\n");
                    printf("player2 ha vinto");
                    return;
                }
            }
            if(rotazione==2)
            {
                if(riga<1 || (riga==1 && campo[riga+1][colonna+1]!='.' && campo[riga+1][colonna+2]!='.' ))
                {
                    printf("la pedina è uscita in altezza\n");
                    printf("player2 ha vinto");
                    return;
                }
            }
            if(rotazione==3 || rotazione==4)
            {
                if(riga<2){
                    printf("la pedina è uscita in altezza\n");
                    printf("player2 ha vinto");
                    return;
                }
            }
        }
        if(scelta_pedina == 4)
        {
            rotazione=c_e_pedina_t(campo, riga, colonna, scelta_pedina);
            if(rotazione == 1 || rotazione ==2){
                if(riga < 1){
                    printf("la pedina è uscita in altezza\n");
                    printf("player2 ha vinto");
                    return;
                }
            }
            if(rotazione==3 || rotazione ==4) {
                if(riga<2){
                    printf("la pedina è uscita in altezza\n");
                    printf("player2 ha vinto");
                    return;
                }
            }
        }
        if(scelta_pedina == 5)
        {
            rotazione = c_e_pedina_L(campo, riga, colonna, scelta_pedina);
            if(rotazione==1 || rotazione ==2 || rotazione ==5 || rotazione == 6){
                if(riga<2){
                    printf("la pedina è uscita in altezza\n");
                    printf("player2 ha vinto");
                    return;
                }
            }
            if(rotazione==3 || rotazione == 4){
                if(riga<1){
                    printf("la pedina è uscita in altezza\n");
                    printf("player2 ha vinto");
                    return;
                }
            }
        }
        punteggio_player_O = count(campo, punteggio_player_O);
        cancella_riga_piena(campo);
        if (punteggio_player_O == 30)
        {
            printf ("PL4Y3R_1 ha vinto!!!\n");
            return;
        }
        if (punteggio_player_O < 30)
        {
            printf ("il punteggio del PL4Y3R_1 è: %d\n", punteggio_player_O);   /*punteggio attuale del giocatore*/
            for(j=0; j<10; j++)
            {
                printf("----");
            }
            printf("\n");
        }

        /*TURN DEL SECONDO PLAYER*/
        /*TURN DEL SECONDO PLAYER*/
        /*TURN DEL SECONDO PLAYER*/
        /*TURN DEL SECONDO PLAYER*/
        /*TURN DEL SECONDO PLAYER*/
        /*TURN DEL SECONDO PLAYER*/

        stampa_campo(campo);
        printf("turno PL4Y3R_2! inserisci il numero della colonna in cui vuoi posizionare la pedina: ");
        scanf("%d",&colonna);
        if(colonna<0 || colonna >9)
        {
            while(break_loop == 0)
            {
                printf("attenzione!! hai inserito una colonna fuori dal campo!! inserire una colonna compresa tra 0 e 9 inclusi: ");
                scanf("%d", &colonna);
                if(colonna<0 || colonna>9)
                    break_loop=0;
                else
                    break_loop=1;
            }
            break_loop=0;
        }
        printf("tipologie pedine:|| 1 = quadrata || 2 = i || 3 = Z || 4 = T || 5 = L ||\n");
        printf("inserisci la tipologia di pedina che vuoi: ");
        scanf("%d",&scelta_pedina);
        if(scelta_pedina<1 || scelta_pedina>5)
        {
            while(break_loop == 0)
            {
                printf("attenzione!! hai inserito una tipologia inesistente!! inserire una tipologia tra quelle elencate di seguito: \n");
                printf("tipologie pedine:|| 1 = quadrata || 2 = i || 3 = Z || 4 = T || 5 = L ||: ");
                scanf("%d",&scelta_pedina);
                if(scelta_pedina<1 || scelta_pedina>5){
                    break_loop=0;
                }
                else{
                    break_loop=1;
                }
            }
            break_loop=0;
        }
        check_sconfitta = controllo_colonna(campo,colonna,scelta_pedina);
        if (check_sconfitta == 1)
        {
            printf("PL4Y3R_1 ha vinto!!!\n");
            printf("PL4Y3R_2 è uscito dal campo in altezza!!!\n");
            return;
        }
        riga = caduta_pedina(campo,colonna,scelta_pedina);
        if(scelta_pedina == 1)
        {
            c_e_pedina_quadrata(campo, riga, colonna, scelta_pedina);
        }
        if(scelta_pedina == 2)
        {
            rotazione=c_e_pedina_i(campo,riga,colonna,scelta_pedina);
            /*if(rotazione == 0){
                printf("la pedina è uscita in altezza\n");
                printf("il player1 ha vinto");
                return;
            }*/
            if(rotazione==1)
            {
                if(riga<3){
                    printf("la pedina è uscita in altezza\n");
                    printf("il player1 ha vinto");
                    return;
                }
            }
            if(rotazione==2){
                if(riga<0){
                    printf("la pedina è uscita in altezza\n");
                    printf("player1 ha vinto");
                    return;
                }
            }
        }
        if(scelta_pedina == 3)
        {
            rotazione=c_e_pedina_z(campo, riga, colonna, scelta_pedina);
            if(rotazione ==1 )
            {
                if(riga<1 || (riga==1 && campo[riga][colonna+1]!='.'))
                {
                    printf("la pedina è uscita in altezza\n");
                    printf("player1 ha vinto");
                    return;
                }
            }
            if(rotazione==2)
            {
                if(riga<1 || (riga==1 && campo[riga+1][colonna+1]!='.' && campo[riga+1][colonna+2]!='.' ))
                {
                    printf("la pedina è uscita in altezza\n");
                    printf("player1 ha vinto");
                    return;
                }
            }
            if(rotazione==3 || rotazione==4)
            {
                if(riga<2){
                    printf("la pedina è uscita in altezza\n");
                    printf("player1 ha vinto");
                    return;
                }
            }
        }
        if(scelta_pedina == 4)
        {
            rotazione=c_e_pedina_t(campo, riga, colonna, scelta_pedina);
            if(rotazione == 1 || rotazione ==2){
                if(riga < 1){
                    printf("la pedina è uscita in altezza\n");
                    printf("player1 ha vinto");
                    return;
                }
            }
            if(rotazione==3 || rotazione ==4) {
                if(riga<2){
                    printf("la pedina è uscita in altezza\n");
                    printf("player1 ha vinto");
                    return;
                }
            }
        }
        if(scelta_pedina == 5)
        {
            rotazione = c_e_pedina_L(campo, riga, colonna, scelta_pedina);
            if(rotazione==1 || rotazione ==2 || rotazione ==5 || rotazione == 6){
                if(riga<2){
                    printf("la pedina è uscita in altezza\n");
                    printf("player1 ha vinto");
                    return;
                }
            }
            if(rotazione==3 || rotazione == 4){
                if(riga<1){
                    printf("la pedina è uscita in altezza\n");
                    printf("player1 ha vinto");
                    return;
                }
            }
        }
        punteggio_player_W = count(campo, punteggio_player_W);
        cancella_riga_piena(campo);
        if (punteggio_player_W == 30)
        {
            printf ("PL4Y3R_2 ha vinto!!!\n");
            return;
        }
        if (punteggio_player_W < 30)
        {
            printf ("il punteggio del PL4Y3R_2 è: %d\n",punteggio_player_W);      /*punteggio attuale del giocatore. ogni volta che viene cancellata una riga il giocatore che l'ha cancellata guadagna un punto*/
            for(j=0; j<10; j++)
            {
                printf("---");
            }
            printf("\n");
        }
        max_ped = max_ped -1;
        if(max_ped==0){
            printf("le 20 pedine sono finite, chi ha il punetggio più alto vince:\n");
            if(punteggio_player_O>punteggio_player_W){
                printf("player_1 ha vinto!");
                return;
            }
            else if(punteggio_player_W>punteggio_player_O){
                printf("player_2 ha vinto!");
                return;
            }
            else{
                printf("entrambi i giocatori hanno finito le pedine e hanno lo stesso punteggio: pareggio!!");
                return;
            }
        }
        printf("------------------------------------------------------------\n");
        printf("il numero di pedine disponibili per entrambi i players è: %d\n", max_ped);
        printf("------------------------------------------------------------\n");
    }    /* --> fine while loop*/
}    /* --> fine function*/

int controllo_colonna(char campo[15][10], int colonna, int scelta_pedina)  /*se la colonna è già piena, il giocatore ha perso*/
{
    if(scelta_pedina==1)   /*funziona*/
    {
        if(campo[0][colonna]!='.' || campo[0][colonna+1]!='.' || campo[1][colonna]!='.' || campo[1][colonna+1]!='.'){
            return 1;
        }
        else
        {
            return 0;
        }
    }
    else
    {
        if (campo[0][colonna] != '.')
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
}

int caduta_pedina(char campo[15][10], int colonna, int scelta_pedina)     /*scegliere prima riga disponibile in cui mettere la pedina*/
{
    int i, riga;
    for (i=0; i<14; i++)
    {
        if(scelta_pedina==1)
        {
            if (campo[i+1][colonna] != '.' || campo[i+1][colonna+1] != '.')
            {
                break;
            }
            else
            {
                continue;
            }
        }
        if(scelta_pedina==3)
        {
            if (campo[i+1][colonna] != '.' || campo[i][colonna+1] != '.')
            {
                break;
            }
            else
            {
                continue;
            }
        }
        else
        {
            if (campo[i+1][colonna] != '.')
            {
                break;
            }
            else
            {
                continue;
            }
        }
    }
    riga = i;
    return riga;
}

int count(char campo[15][10], int punteggio)     /*conto punteggio*/
{
    int i, j, x, punteggio_appoggio = punteggio;
    for (i=0; i<15; ++i)                        /*controllo righe: se una riga è piena, viene eliminata e sostituita con '+'*/
    {
        for (j=0; j<10; ++j)
        {
            if (campo[i][j] != '.')
            {
                for (x=1; x<10; x++)                    /*controllo se tutta la riga è != '+'*/
                {
                    if (campo[i][x] != '.')
                    {
                        continue;
                    }
                    else
                    {
                        break;
                    }
                }
                if (x==10)                        /*se la riga è piena, rimetto '+' ed elimino la riga*/
                {
                    punteggio=punteggio+1;
                    break;
                }
            }
        }
    }
    if(punteggio - punteggio_appoggio == 2){
        punteggio = punteggio +1;
        return punteggio;
    }

    if(punteggio - punteggio_appoggio == 3){
        punteggio = punteggio +3;
        return punteggio;
    }
    if(punteggio - punteggio_appoggio == 4){
        punteggio = punteggio +8;
        return punteggio;
    }
    return punteggio;
}




