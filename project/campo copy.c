#include "campo.h"
#include "turni_players.h"
#include "pedine.h"
#include <stdio.h>

#define RESET      "\033[0m"
#define BOLD       "\033[1m"
#define SFUMATO    "\033[2m"
#define ITALIC     "\033[3m"
#define UNDERLINE  "\033[4m"
#define BLINK      "\x1b[5m"

#define BLACK      "\033[30m"
#define RED        "\033[31m"
#define GREEN      "\033[32m"
#define YELLOW     "\033[33m"
#define BLUE       "\033[34m"
#define MAGENTA    "\033[35m"
#define CIANO      "\033[36m"
#define WHITE      "\033[37m"

#define BG_BLACK    "\033[40m "
#define BG_RED      "\033[41m "
#define BG_GREEN    "\033[42m "
#define BG_YELLOW   "\033[43m "
#define BG_BLUE     "\033[44m "
#define BG_MAGENTA  "\033[45m "
#define BG_CIANO    "\033[46m "
#define BG_WHITE    "\033[47m"

void riaggiorna_campo(char campo[15][10], int riga)    /*dopo aver eliminato una riga piena, sposto tutte le pedine che stanno sopra di una riga più in basso*/
{
    int i, j;
    for (i=riga; i>=1; i--)
    {
        for (j=0; j<10; j++)
        {
            campo[i][j] = campo[i-1][j];
        }
    }
}

void stampa_pedine_colorate(char campo[15][10], int i, int x)
{
    /*
    if(campo[i][x] == '#')
    {
        printf("\033[0;33m");    
        printf(" %c ", campo[i][x]);
        printf("\033[0m");     
    }
    if(campo[i][x] == '&')
    {
        printf("\033[0;32m");    
        printf(" %c ", campo[i][x]);
        printf("\033[0m");     
    }
    if(campo[i][x] == '$')
    {
        printf("\033[0;34m");    
        printf(" %c ", campo[i][x]);
        printf("\033[0m");     
    }
    if(campo[i][x] == '*')
    {
        printf("\033[0;35m");    
        printf(" %c ", campo[i][x]);
        printf("\033[0m");     
    }
    if(campo[i][x] == '@')
    {
        printf("\033[0;36m");    
        printf(" %c ", campo[i][x]);
        printf("\033[0m");    
    }
    */
    if(campo[i][x] == '#'){
        printf("\033[0;33mA\033[0m"); 
    }
    if(campo[i][x] == '&'){
        printf("\033[0;33m◼\033[0m"); 
    }

    if(campo[i][x] == '$'){
        printf("\033[0;33m◼\033[0m"); 
    }

    if(campo[i][x] == '*'){
        printf("\033[0;33m◼\033[0m"); 
    }
    if(campo[i][x] == '@'){
        printf("\033[0;33m◼\033[0m"); 
    }

}

void stampa_campo(char campo[15][10])    /*stampo il campo di 15 righe e 10 colonne*/
{
    int i,h,j,x;
    for (i=0; i<15; i++)
    {
        for(x=0; x<10; x++)
        {
            if(campo[i][x] != '.')
            {
                stampa_pedine_colorate(campo,i,x);
            }
            else
            {
                printf(" %c ", campo[i][x]);
            }
        }
        printf ("\n");
    }
    for(j=0; j<10; j++)
    {
        printf("---");
    }
    printf("\n");
    for(h=0; h<10;h++)
    {
        printf(" %d ", h);
    }
    printf("\n");
    for(j=0; j<10; j++)
    {
        printf("---");
    }
    printf("\n");
}

void cancella_riga_piena(char campo[15][10])     /*cancellare riga piena*/
{
    int i, j, x, y;
    for (i=0; i<15; ++i)                        /*controllo righe: se una riga è piena, viene eliminata e sostituita con '+'*/
    {
        for (j=0; j<10; ++j)
        {
            if (campo[i][j] != '.')
            {
                for (x=0; x<10; x++)                    /*controllo se tutta la riga è != '+'*/
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
                    for (y=0; y<10; y++)
                    {
                        campo[i][y] = '.';
                    }
                    riaggiorna_campo(campo,i);
                }
            }
        }
    }
}

void iniz_campo(char campo[15][10])
{
    int i,j;
    for (i=0; i<15; i++)
    {
        for (j=0; j<10; j++)
        {
            campo[i][j] = '.';     /*carattere scelto per il campo*/
        }
    }
}
