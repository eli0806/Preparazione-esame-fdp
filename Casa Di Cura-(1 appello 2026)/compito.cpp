//
// Created by eli on 2/6/26.
//

#include "compito.h"

CasaDiCura::CasaDiCura(const char* n, int nOspiti) {
    if (strlen(n)==0 || strlen(n)>MaxLenNameCasa) {
        n="default";
    }

    strcpy(nome, n);

    this->nOspiti=nOspiti;

    ospiti=new farmaco*[nOspiti];

    for (int i=0; i<nOspiti; i++) {
        ospiti[i]=nullptr;
    }
}

ostream &operator<<(ostream &os, const CasaDiCura& cc) {
    os<<"Casa di cura '"<<cc.nome<<"'"<<endl;
    for (int i=0;i<cc.nOspiti;i++) {
        os<<"- Ospite "<<i+1<<": "<<endl;

        int indice=1;
        farmaco* p=cc.ospiti[i];

        while (p!=nullptr) {
            os<<"  "<<indice<<". '"<<p->nome<<"'"<<endl;
            if (p->assunto==true){
            os<<"     Assunto"<<endl;
            }else {
                os<<"     Non assunto"<<endl;
            }
            os<<"     Ore "<<p->oraAss<<endl;
            indice++;
            p=p->next;
        }
    }
    return os;
}

bool CasaDiCura::aggiungiFarmaco(int idOspite, const char* n, int orario) {
    if (idOspite<1|| idOspite>nOspiti || strlen(n)==0 || strlen(n)>MaxLenNameFar ||orario<0 || orario>23) {
        return false;
    }

    farmaco* p=ospiti[idOspite-1];
    farmaco* q=nullptr;

    while (p!=nullptr) {
        if (strcmp(p->nome,n)==0 || p->oraAss==orario) {
            return false;
        }
        q=p;
        p=p->next;
    }

    //Creo il farmaco da aggiungere
    farmaco* nuovo=new farmaco;
    strcpy(nuovo->nome, n);
    nuovo->oraAss=orario;
    nuovo->assunto=false;
    nuovo->next=nullptr;

    if (q==nullptr) {
        ospiti[idOspite-1]=nuovo;
    }else {
        q->next=nuovo;

    }
    return true;
}

bool CasaDiCura::assumiFarmaci(int idOspite, int orario) {
    if (idOspite<1 || idOspite>nOspiti ||orario<0 || orario>23) {
        return false;
    }
    farmaco*p=ospiti[idOspite-1];

    while (p!=nullptr) {
        if (p->oraAss==orario && p->assunto==false) {
            p->assunto=true;
            return true;
        }
        p=p->next;
    }
    return false;
}

CasaDiCura::CasaDiCura(const CasaDiCura& cc) {
    strcpy(nome,cc.nome);
    this->nOspiti=cc.nOspiti;

    ospiti=new farmaco*[nOspiti];

    for (int i=0;i<nOspiti;i++) {
        if (cc.ospiti[i] == nullptr) {
            this->ospiti[i] = nullptr;
        }
        else {
            this->ospiti[i] = new farmaco;
            strcpy(this->ospiti[i]->nome, cc.ospiti[i]->nome);
            this->ospiti[i]->assunto = cc.ospiti[i]->assunto;
            this->ospiti[i]->oraAss = cc.ospiti[i]->oraAss;

            farmaco* p = cc.ospiti[i]->next;
            farmaco* p2= this->ospiti[i];

            while (p != nullptr) {
                p2->next = new farmaco;
                p2 = p2->next;

                strcpy(p2->nome, p->nome);
                p2->assunto = p->assunto;
                p2->oraAss = p->oraAss;

                p = p->next;
            }
            p2->next = nullptr;
        }
    }
}

CasaDiCura::~CasaDiCura() {
    for (int i=0;i<nOspiti;i++) {
        farmaco* p=ospiti[i];
        while (p!=nullptr) {
            farmaco* q=p->next;
            delete p;
            p = q;
        }
    }
        delete[]ospiti;
}

CasaDiCura CasaDiCura::rimuoviFarmaco(int idOspite, char *nome) {
    CasaDiCura risultato(*this);
    if (idOspite<0 ||idOspite>nOspiti || strlen(nome)<0 || strlen(nome)>MaxLenNameFar) {
        return risultato;
    }

    int indice=idOspite-1;
    farmaco* p=risultato.ospiti[indice];
    farmaco* q=nullptr;

    while (p!=nullptr) {
        if (strcmp(p->nome, nome)==0) {
            if (q==nullptr)
                risultato.ospiti[indice] = p->next;
            else
                q->next=p->next;
            delete p;
            break;
        }
        q= p;
        p = p->next;
    }
    return risultato;
}

CasaDiCura& CasaDiCura::operator!() {
    for (int i=0;i<nOspiti;i++) {
        farmaco* p = ospiti[i];
        while (p!=nullptr) {
            if (p->oraAss<=12) {

                p->assunto=!(p->assunto);
            }
            p=p->next;
        }
    }
    return(*this);
}