/**
* @file campo.h
* @author Mattia
* @brief Libreria per la stampa e il riaggiornamneto del campo, eliminazione di una riga (o più) piena e l'inizializzazione della matrice di caratteri
* @date 21/06/2022
**/

#include <stdio.h>
#ifndef PROJECT_CAMPO_H
#define PROJECT_CAMPO_H
#endif

/**
 * dopo aver eliminato una riga sposto i tetramini verso il basso
 * @param campo il campo di gioco
 * @param riga cancellata
 * @return void
 * **/
void riaggiorna_campo(char campo[15][10], int riga);
/**
 * stampo i caratteri del campo
 * @param campo il campo di gioco
 * @return void
 * **/
void stampa_campo(char campo[15][10]);
/**
 * cancella una riga se piena
 * @param campo il campo di gioco
 * @return void
 * **/
void cancella_riga_piena(char campo[15][10]);     /*cancellare riga piena*/
/**
 * inserisco il carattere '.' in tutti gli spazi del campo
 * @param campo il campo di gioco
 * @return void
 * **/
void iniz_campo(char campo[15][10]);
