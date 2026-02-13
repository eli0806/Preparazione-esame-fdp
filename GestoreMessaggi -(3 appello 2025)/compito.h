//
// Created by eli on 2/12/26.
//

#ifndef GESTOREMESSAGGI_COMPITI_H
#define GESTOREMESSAGGI_COMPITI_H

#include<iostream>
#include <cstring>

using namespace std;

const int maxCar=20;
const int maxLenMes=29;
const int maxDaLeggere=5;

struct Messaggio ;

struct Utente {
    char nickname[maxCar+1];
    Messaggio* casella[maxDaLeggere];
    int DaLegg;
};

struct Messaggio {
    Utente* Mittente;
    char messaggio[maxLenMes+1];
    Utente* Destinatario;
};

class GestoreMessaggi {
    int nUtenti;
    Utente** utenti;
    int contaRegistrati();
    int contaDaRegistrare();

public:
    GestoreMessaggi(int nUtenti=2);
    bool registra_utente(const char* id);
    void invia_messaggio(char* mittente, char* destinatario , char* testo);
    friend ostream& operator<<(ostream& os, GestoreMessaggi& g);
    ~GestoreMessaggi();
    const char* leggi_messaggio(const char* destinatario , char* mittente);
    GestoreMessaggi(GestoreMessaggi& g);
    friend GestoreMessaggi operator+(int, const GestoreMessaggi&);
};


#endif //GESTOREMESSAGGI_COMPITI_H