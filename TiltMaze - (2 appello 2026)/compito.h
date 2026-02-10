//
// Created by eli on 2/10/26.
//

#ifndef TILTMAZE_COMPITO_H
#define TILTMAZE_COMPITO_H

#include <iostream>
using namespace std;

enum Stato{MODIFICA, AVVIATO, VINTO , PERSO};

class TiltMaze {
    int R; //numero massimo di righe
    int C; //Numero massimo di colonne
    int rSt; //Riga del punto di start
    int cSt; //Colonna del punto di start
    int rEx; //riga del punto di uscita
    int cEx; //colonna del punto di uscita
    char** schema; //Rappresenta lo schema di gioco , che è una matrice di caratteri
    int rPallina; //Riga in cui è posizionata la pallina
    int cPallina; //COlonna in cui è posizionata la pallina
    Stato statoPartita; //Indica lo stato della partita

   const char* StringaStato();
public:
    TiltMaze(int R, int C, int rSt, int cSt, int rEx, int cEx);
    bool aggiungiMuro(int r1, int c1, int r2, int c2);
    bool aggiungiBuca(int R, int C);
    void avvia();
    friend ostream& operator<<(ostream& os, TiltMaze& t);
    Stato stato();
    ~TiltMaze();
    void inclina (int dirV, int dirH);
    TiltMaze (const TiltMaze& t1);
    TiltMaze operator +(const TiltMaze& t2);
};


#endif //TILTMAZE_COMPITO_H