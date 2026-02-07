//
// Created by eli on 2/6/26.
//

#ifndef CASADICURA_COMPITO_H
#define CASADICURA_COMPITO_H

#include <iostream>
#include <cstring>
using namespace std;

const int MaxLenNameCasa=21;
const int MaxLenNameFar=16;

struct farmaco {
    char nome[MaxLenNameCasa];
    bool assunto;
    int oraAss;
    farmaco* next;
};

class CasaDiCura {
    char nome[MaxLenNameCasa];
    int nOspiti;
    farmaco** ospiti;
public:
    CasaDiCura(const char* nome, int nOspiti);
    friend ostream& operator<<(ostream& os, const CasaDiCura &cc);
    bool aggiungiFarmaco(int idOspite,const char*n, int orario);
    bool assumiFarmaci(int idOspite, int orario);
    CasaDiCura(const CasaDiCura& cc);
    ~CasaDiCura();
    CasaDiCura rimuoviFarmaco(int idOspite, char* nome);
    CasaDiCura& operator!();
};


#endif //CASADICURA_COMPITO_H