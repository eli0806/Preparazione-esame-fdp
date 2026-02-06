//
// Created by eli on 2/4/26.
//

#include "CampoMinato.h"

CampoMinato::CampoMinato(int n) {
    this->dim=n;
    this->StatoGioco=MODIFICA;
    this->totMin=0;
    this->nCaselle=dim*dim;

    schema=new char*[dim];
    for (int i=0;i<dim;i++) {
        schema[i]=new char[dim];
    }

    for (int i=0;i<dim;i++) {
        for (int j=0;j<dim;j++) {
            schema[i][j]='X';
        }
    }
}

CampoMinato::~CampoMinato() {
    for (int i=0;i<dim;i++) {
        delete[] schema[i];
    }
    delete [] schema;
}

char CampoMinato::contaAdiacenti(int r, int c) {
    int cont=0;
    char contInChar='0';
    for (int i=r-1;i<=r+1;i++) {
        for (int j=c-1;j<=c+1;j++) {
            if (i>= 0 && i < dim && j >= 0 && j < dim) {
                if (schema[i][j]=='M') {
                    cont++;
                }
            }
        }
    }
    contInChar+=cont;
    return contInChar;
}

bool CampoMinato::aggiungi_mina(int r, int c) {
    if (r<0 || c<0 || r>=dim || c>=dim) {
        return false;
    }
    if (StatoGioco==MODIFICA || StatoGioco==AVVIABILE) {
        if (schema[r][c]!='X') {
            return false;
        }else {
            schema[r][c]='M';
            totMin++;
            StatoGioco= AVVIABILE;
            return true;
        }
    }else {
        return false;
    }
}

void CampoMinato::scopri(int r, int c) {
    if (StatoGioco==MODIFICA ||StatoGioco==PERSO || StatoGioco==VINTO){
        return;
    }

    if (c<0 || r<0 || c>dim || r>dim) {
        return;
    }

    if (schema[r][c] != 'X' && schema[r][c] != 'M') return;

    StatoGioco=AVVIATO;

    if (schema[r][c]=='M') {
        StatoGioco=PERSO;
        return;
    }

    if (contaAdiacenti(r,c)>0) {
        schema[r][c]=contaAdiacenti(r,c);
        nCaselle--;

    }else {
        for (int i=r-1;i<=r+1;i++) {
            for (int j=c-1;j<=c+1;j++) {
                if (i>= 0 && i < dim && j >= 0 && j < dim) {
                    if (schema[i][j]!='M') {
                        schema[i][j]=' ';
                    }
                }
            }
        }
        nCaselle--;
    }

    if (nCaselle-totMin==0) {
        StatoGioco=VINTO;
    }
}

ostream& operator<<(ostream& os, CampoMinato& c){
    if (c.StatoGioco==MODIFICA) {
        os<<"Inserire una mina per avviare il gioco"<<endl;
    }else if (c.StatoGioco==PERSO) {
        os<<"Game over"<<endl;
    }else if (c.StatoGioco==VINTO) {
        os<<"Vittoria!"<<endl;
    }else {
        os<<"Campo Minato "<<c.dim<<"x"<<c.dim<<" - Mine da trovare: "<<c.totMin<<endl;
        for (int i=0;i<c.dim;i++) {
            for (int j=0;j<c.dim;j++) {
                if (c.schema[i][j]=='M') {
                    os<<'X';
                }else {
                    os<<c.schema[i][j];
                }
            }
            os<<endl;
        }
    }
    return os;
}

CampoMinato::CampoMinato(const CampoMinato &c1) {
    this->dim=c1.dim;
    this->totMin=c1.totMin;
    this->nCaselle=dim*dim;

    schema=new char*[dim];

    for (int i=0;i<dim;i++) {
        schema[i]=new char[dim];
    }

    for (int i=0;i<dim;i++) {
        for (int j=0;j<dim;j++) {
            if (c1.schema[i][j]=='M') {
                schema[i][j]=c1.schema[i][j];
            }else {
                schema[i][j]='X';
            }
        }
    }

    this->StatoGioco=AVVIABILE;
}

CampoMinato CampoMinato::operator+(CampoMinato &c2) {
    int newDim=2*dim;
    CampoMinato risultato (newDim);
    risultato.StatoGioco=AVVIABILE;
    risultato.totMin=totMin+c2.totMin;
    for (int i=0;i<newDim;i++) {
        for (int j=0;j<newDim;j++) {
            if (j<dim && i<dim) {
                risultato.schema[i][j]=schema[i][j];
            }else if (j>=dim && i>=dim) {
                risultato.schema[i][j]=c2.schema[i-dim][j-dim];
            }else {
                risultato.schema[i][j]='X';
            }
        }
    }
    return risultato;
}

