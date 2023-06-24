
/**
* @file turni_players.h
* @author Mattia
* @brief Libreria per i turni dei players, la caduta della pedina, conteggio del punteggio e il controllo della colonna (se è piena o meno)
* @date 21/06/2022
**/

#ifndef PROJECT_COPIA_TURNI_PLAYERS_H
#define PROJECT_COPIA_TURNI_PLAYERS_H
#endif

/**
 * funzione principale: stampa il campo e stabilisce di chi è il turno
 * @param campo il campo di gioco
 * @return void
 * **/
void turni_players(char campo[15][10]);
/**
 * se il tetramino che scegliamo esce dal campo in altezza in altezza, la funzione ci avvisa
 * @param campo il campo di gioco
 * @param colonna la colonna da controllare
 * @param scelta_pedina la pedina che ho scelto
 * @return 1 se il giocatore è uscito dal campo, 0 altrimenti
 * **/
int controllo_colonna(char campo[15][10], int colonna, int scelta_pedina);
/**
 * caduta della pedina fino al primo spazio disponibile
 * @param campo il campo di gioco
 * @param colonna la colonna scelta dal giocatore
 * @param scelta_pedina pedina scelta dal giocatore
 * @return riga in cui viene posizionato il tetramino
 * **/
int caduta_pedina(char campo[15][10], int colonna, int scelta_pedina);
/**
 * conteggio dei punti della partita
 * @param campo il campo di gioco
 * @param punteggio punteggio attuale
 * @return nuovo punteggio
 * **/
int count(char campo[15][10], int punteggio);


