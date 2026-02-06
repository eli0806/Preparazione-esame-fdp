//
// Created by eli on 2/5/26.
//

#ifndef LISTACARATTERI_COMPITO_H
#define LISTACARATTERI_COMPITO_H

#include <iostream>
#include<cstring>
using namespace std;

struct carattere {
    char car;
    carattere* next;
};

class ListaCaratteri {
    carattere* head;
    bool rimuoviUno(const char c);
    bool rimuoviTutti(const char c);
    bool confrontaStr(const carattere* lista, const carattere* subStr);
    int indiceDaTogliere(int n);
public:
    ListaCaratteri();
    ListaCaratteri(const ListaCaratteri& lc1);
    void inserisci(char carattere, bool fine);
    bool rimuovi(const char c, bool tutti);
    friend ostream& operator<<(ostream& os, const ListaCaratteri& lc);
    ~ListaCaratteri();
    bool operator==(ListaCaratteri& lc1);
    ListaCaratteri& operator ~();
    bool controllaPalindroma();
    bool cercaSottostringa(const ListaCaratteri& lc2);
    char* estraiNultimoCarattere(int n);
};


#endif //LISTACARATTERI_COMPITO_H