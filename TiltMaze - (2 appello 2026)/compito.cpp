//
// Created by eli on 2/10/26.
//

#include "compito.h"

TiltMaze::TiltMaze(int R, int C, int rSt, int cSt, int rEx, int cEx) {

    if (R<3 ||C<3) {
        R=3;
        C=3;
    }

    if (rSt<0) {
        rSt=0;
    }

    if (rSt>R-1) {
        rSt=R-1;
    }

    if (cSt<0) {
        cSt=0;
    }

    if (cSt>C-1) {
        cSt=C-1;
    }

    if (rEx<0) {
        rEx=0;
    }

    if (rEx>R-1) {
        rEx=R-1;
    }

    if (cEx<0) {
        cEx=0;
    }

    if (cEx>C-1) {
        cEx=C-1;
    }

    this->R=R;
    this->C=C;
    this->rSt=rSt;
    this->cSt=cSt;
    this->rEx=rEx;
    this->cEx=cEx;

    this->statoPartita=MODIFICA;

    schema=new char*[R];

    for (int i=0; i<R; i++) {
        schema[i]=new char[C];
    }

    for (int i=0;i<R;i++) {
        for (int j=0;j<C; j++) {
            schema[i][j]='.';
        }
    }

    schema[rSt][cSt]='S';
    schema[rEx][cEx]='E';
}

bool TiltMaze::aggiungiMuro(int r1,int c1, int r2, int c2) {
    if (statoPartita!=MODIFICA) {
        return false;
    }

    if (r1<0 || r1>R-1 || c1<0 || c1>C-1 || r2<0 ||r2>R-1 || c2<0 ||c2>C-1 ||( r1==rSt && c1==cSt) ||( r1==rEx && c1==cEx)||(r2==rSt && c2==cSt) || (r2==rEx && c2==cEx)) {
        return false;
    }

    if (c1==c2) {
        if (r2<r1) {
            return false;
        }
        for (int i=r1; i<=r2; i++) {
            schema[i][c1]='#';
        }
        return true;
    }

    if (r1==r2) {
        if (c2<c1) {
            return false;
        }
        for (int i=c1;i<=c2;i++) {
            schema[r1][i]='#';
        }
        return true;
    }

    return false;
}

bool TiltMaze::aggiungiBuca(int r, int c) {
    if (statoPartita!=MODIFICA) {

    }

    if (r<0 || r>R-1 || c<0 || c>C-1 || (r==rSt && c==cSt) || (r==rEx && c==cEx)) {
        return false;
    }

    schema[r][c]='O';
    return true;
}

void TiltMaze::avvia() {
    rPallina=rSt;
    cPallina=cSt;
    schema[rPallina][cPallina]='x'; // X è la pallina
    statoPartita=AVVIATO;
}

Stato TiltMaze::stato() {
    return statoPartita;
}

const char *TiltMaze::StringaStato() {
    char* statoStr=nullptr;
    switch (statoPartita) {
        case MODIFICA:
            statoStr="MODIFICA";
            break;
        case AVVIATO:
            statoStr="AVVIATO";
            break;
        case VINTO:
            statoStr="VINTO";
            break;
        case PERSO:
            statoStr="PERSO";
    }
    return statoStr;
}

ostream& operator<<(ostream& os, TiltMaze& t) {
    os<<"Stato: "<<t.StringaStato()<<endl;
    for (int i=t.R-1;i>=0;i--) {
        os<<i<<" ";
        for (int j=0;j<t.C;j++) {
            os<<t.schema[i][j]<<" ";
        }
        os<<endl;
    }
    os<<"  ";
    for (int j=0;j<t.C;j++) {
        os<<j<<" ";
    }
    return os;
}

TiltMaze::~TiltMaze() {
    for (int i=0;i<R;i++) {
        delete[] schema[i];
    }
    delete [] schema;
}

void TiltMaze::inclina(int dirV, int dirH) {
    if (statoPartita!=AVVIATO) {
        return;
    }
    if (dirV<-1 || dirV>1 || dirH<-1 || dirH>1 || (dirV==0 && dirH==0) || (dirV!=0 && dirH!=0)) {
        return;
    }
    while (rPallina+dirV>=0 && rPallina+dirV<R && cPallina+dirH>=0 && cPallina+dirH<C) {
        if (schema[rPallina+dirV][cPallina+dirH] == '#') {
            break;
        }
        if (rPallina==rSt && cPallina==cSt) {
            schema[rPallina][cPallina]='S';
        }else {
            schema[rPallina][cPallina]='.';
        }
        rPallina+=dirV;
        cPallina+=dirH;
        if (schema[rPallina][cPallina]=='O') {
            statoPartita=PERSO;
            return;
        }
        if (schema[rPallina][cPallina]=='E') {
            statoPartita=VINTO;
            return;
        }
    }
    schema[rPallina][cPallina]='x';
}

TiltMaze::TiltMaze(const TiltMaze& t1) {
    this->R=t1.R;
    this->C=t1.C;
    this->rSt=t1.rSt;
    this->cSt=t1.cSt;
    this->rEx=t1.rEx;
    this->cEx=t1.cEx;

    this->statoPartita=MODIFICA;

    schema=new char*[R];

    for (int i=0; i<R; i++) {
        schema[i]=new char[C];
    }

    for (int i=0;i<R;i++) {
        for (int j=0;j<C;j++) {
            if (t1.schema[i][j]=='x') {
                schema[i][j]='.';
            }
            schema[i][j]=t1.schema[i][j];
        }
    }
}

TiltMaze TiltMaze::operator +(const TiltMaze& t2) {
    if (R==t2.R) {
        int colonneTot= C+t2.C;
        TiltMaze risultato(R,colonneTot,rSt,cSt,t2.rEx,t2.cEx);
        for (int i=0;i<R;i++) {
            for (int j=0;j<colonneTot;j++) {
                if (j<C) {
                    if (schema[i][j]=='x' || schema[i][j]=='E') {
                        risultato.schema[i][j]='.';
                    }else {
                        risultato.schema[i][j]=schema[i][j];
                    }
                }else {
                    if (t2.schema[i][j-C]=='x' || t2.schema[i][j-C]=='S') {
                        risultato.schema[i][j]='.';
                    }else {
                        risultato.schema[i][j]=t2.schema[i][j-C];
                    }
                }
            }
        }
        risultato.statoPartita=MODIFICA;
        return risultato;
    }else {
        return *this;
    }
}