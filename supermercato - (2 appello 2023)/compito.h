//
// Created by eli on 2/8/26.
//

#ifndef SUPERMERCATO_COMPITO_H
#define SUPERMERCATO_COMPITO_H

#include <iostream>
#include <cstring>
using namespace std;

const int maxCarrelli=5;

struct Prodotto {
    char* nome;
    float prezzoUnitario;
    int quantita;
    Prodotto* next;
    ~Prodotto();
};

struct Carrello {
    int idCliente;
    Prodotto* listaProdotti;
    ~Carrello();

};

class Supermercato {
    Prodotto* listaProdotti;
    Carrello* carrelli[maxCarrelli];
    Prodotto* cercaProdotto(char* prod);
    int cercaCliente(int id);
public:
    Supermercato();
    ~Supermercato();
    void crea_prodotto(char* prod, float prezzoUn=0.0);
    void esponi(char* prod, int q, float prezzoUn=0.0);
    friend ostream& operator<<(ostream& os, const Supermercato& c);
    Supermercato& operator+=(int c);
    void metti_nel_carrello(int c, char* prod, int q);
    float acquista(int c);
};


#endif //SUPERMERCATO_COMPITO_H
