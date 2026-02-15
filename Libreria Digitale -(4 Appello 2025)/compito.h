//
// Created by eli on 2/13/26.
//

#ifndef INC_4_APPELLO_2025_COMPITO_H
#define INC_4_APPELLO_2025_COMPITO_H

#include<iostream>
#include <cstring>
using namespace std;

const int maxCarS=20;
const int maxCarL=30;

struct Libro {
    char titolo[maxCarL];
    bool usato;
};

struct Scaffale {
    char nome[maxCarS];
    unsigned int capacita;
    Libro** mensola;
    Scaffale* next;
    Scaffale(int capacita);
    ~Scaffale();
    int contaLibri();
    int contaUsati();
};



class LibreriaDigitale {
   Scaffale* primo;

public:
    LibreriaDigitale();
    friend ostream& operator<<(ostream& os, LibreriaDigitale& ld);
    void aggiungiScaffale(char* nome, unsigned int capacita);
    bool aggiungiLibro(char* nomeScaffale, char* titolo, bool condizione);
    LibreriaDigitale(const LibreriaDigitale& ld);
    ~LibreriaDigitale();
    void rimuoviLibro(char* nomeScaffale, char* titolo);
    LibreriaDigitale operator~();
    LibreriaDigitale& operator!();

};


#endif //INC_4_APPELLO_2025_COMPITO_H