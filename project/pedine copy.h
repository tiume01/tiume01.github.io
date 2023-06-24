
/**
* @file pedine.h
* @author Mattia
* @brief Libreria per la creazione dei tetramini e le loro relative condizioni di esistenza (se escono dal campo in larghezza)
* @date 21/06/2022
**/

#include <stdio.h>
#ifndef PROJECT_COPIA_PEDINE_H
#define PROJECT_COPIA_PEDINE_H
#endif

/**
 * creazione del tetramino quadrato
 * @param campo il campo di gioco
 * @param riga scelta dal giocatore
 * @param colonna scelta dal giocatore
 * @return void
 * **/
void crea_pedina_quadrata(char campo[15][10],int riga, int colonna);
/**
 * c.e. pedina quadrata : controllo che la pedina non esca dal campo in lareghezza
 * @param campo il campo di gioco
 * @param colonna colonna scelta dal giocatore
 * @param riga riga scelta dal giocatore
 * @param scelta_pedina pedina scelta dal giocatore
 * @return void
 * **/
void c_e_pedina_quadrata(char campo[15][10], int riga, int colonna, int scelta_pedina);
/**
 * creazione del tetramino 'i'
 * @param campo il campo di gioco
 * @param riga scelta dal giocatore
 * @param colonna scelta dal giocatore
 * @param rotazione scelta dal giocatore
 * @return void
 * **/
void crea_pedina_i(char campo[15][10], int riga, int colonna,int rotazione);
/**
* c.e. pedina 'i' : controllo che la pedina non esca dal campo in lareghezza e decido rotazione
* @param campo il campo di gioco
* @param colonna colonna scelta dal giocatore
* @param riga riga scelta dal giocatore
* @param scelta_pedina pedina scelta dal giocatore
* @return rotazione pedina
* **/
int c_e_pedina_i(char campo[15][10], int riga, int colonna,int scelta_pedina);
/**
 * creazione del tetramino quadrato
 * @param campo il campo di gioco
 * @param riga scelta dal giocatore
 * @param colonna scelta dal giocatore
 * @param rotazione scelta dal giocatore
 * @return void
 * **/
void crea_pedina_z(char campo[15][10], int riga, int colonna, int rotazione);
/**
* c.e. pedina 'z' : controllo che la pedina non esca dal campo in lareghezza e decido rotazione
* @param campo il campo di gioco
* @param colonna colonna scelta dal giocatore
* @param riga riga scelta dal giocatore
* @param scelta_pedina pedina scelta dal giocatore
* @return rotazione pedina
* **/
int c_e_pedina_z(char campo[15][10], int riga, int colonna, int scelta_pedina);
/**
 * creazione del tetramino quadrato
 * @param campo il campo di gioco
 * @param riga scelta dal giocatore
 * @param colonna scelta dal giocatore
 * @param rotazione scelta dal giocatore
 * @return void
 * **/
void crea_pedina_t(char campo[15][10], int riga, int colonna, int rotazione);
/**
* c.e. pedina 't' : controllo che la pedina non esca dal campo in lareghezza e decido rotazione
* @param campo il campo di gioco
* @param colonna colonna scelta dal giocatore
* @param riga riga scelta dal giocatore
* @param scelta_pedina pedina scelta dal giocatore
* @return rotazione pedina
* **/
int c_e_pedina_t(char campo[15][10], int riga, int colonna,int scelta_pedina);
/**
 * creazione del tetramino quadrato
 * @param campo il campo di gioco
 * @param riga scelta dal giocatore
 * @param colonna scelta dal giocatore
 * @param rotazione scelta dal giocatore
 * @return void
 * **/
void crea_pedina_L(char campo[15][10], int riga, int colonna, int rotazione);  /*MANCANO 2 ROTAZIONI!!!!!*/
/**
* c.e. pedina 'L' : controllo che la pedina non esca dal campo in lareghezza e decido rotazione
* @param campo il campo di gioco
* @param colonna colonna scelta dal giocatore
* @param riga riga scelta dal giocatore
* @param scelta_pedina pedina scelta dal giocatore
* @return rotazione pedina
* **/
int c_e_pedina_L(char campo[15][10], int riga, int colonna,int scelta_pedina);
