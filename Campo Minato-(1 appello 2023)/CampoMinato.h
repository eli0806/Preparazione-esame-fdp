//
// Created by eli on 2/4/26.
//

#ifndef CAMPOMINATO_CAMPOMINATO_H
#define CAMPOMINATO_CAMPOMINATO_H
#include <iostream>
using namespace std;

enum stato{MODIFICA,AVVIABILE,AVVIATO,PERSO,VINTO};

class CampoMinato {
    int dim;
    int nCaselle;
    char** schema;
    int totMin;
    stato StatoGioco;

    char contaAdiacenti(int r, int c);

public:
    CampoMinato(int n);
    CampoMinato(const CampoMinato& c1);
    ~CampoMinato();
    bool aggiungi_mina(int r, int c);
    void scopri(int r, int c);
    friend ostream& operator<<(ostream& os, CampoMinato& c);
    CampoMinato operator + (CampoMinato& c2);

};


#endif //CAMPOMINATO_CAMPOMINATO_H