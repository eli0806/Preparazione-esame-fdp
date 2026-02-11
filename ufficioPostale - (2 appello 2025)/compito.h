//
// Created by eli on 2/10/26.
//

#ifndef UFFICIOPOSTALE_COMPITO_H
#define UFFICIOPOSTALE_COMPITO_H

#include <iostream>
#include <cstring>
using namespace std;

const int maxCar=25;

struct Utente {
    char nome[maxCar+1];
    bool prioritario;
    Utente* next;
};

class UfficioPostale {
    int nSportelli;
    Utente** sportelli;
    int contaUtenti();
    int contaPrioritari();
    bool cercaUtente(const char* nome, int sportello);
    void ausilioAccodaP(Utente* user, int index);

public:
    UfficioPostale(int nSport=2);
    ~UfficioPostale();
    friend ostream& operator<<(ostream& os, UfficioPostale& up);
    void accodaUtente(char* nome, int sportello);
    void serviUtente(int sportello);
    void accodaPrioritario(char* nome);
    void passaAvanti(char* nome, int sportello, int nPos);
    UfficioPostale& operator!();
};


#endif //UFFICIOPOSTALE_COMPITO_H