//
// Created by eli on 2/12/26.
//

#include "compito.h"

GestoreMessaggi::GestoreMessaggi(int nUtenti) {
    if (nUtenti<2) {
        nUtenti=2;
    }
    this->nUtenti=nUtenti;
    utenti=new Utente*[nUtenti];

    for (int i=0;i<nUtenti;i++) {
        utenti[i]=new Utente;
        utenti[i]->DaLegg=0;
        for (int j=0;j<maxDaLeggere;j++) {
            utenti[i]->casella[j]=nullptr;
        }
    }
}

int GestoreMessaggi::contaRegistrati() {
    int cont=0;
    for (int i=0;i<nUtenti;i++) {
        if (strlen(utenti[i]->nickname)!=0) {
            cont++;
        }
    }
    return cont;
}

int GestoreMessaggi::contaDaRegistrare() {
    int cont=0;
    for (int i=0;i<nUtenti;i++) {
        if (strlen(utenti[i]->nickname)==0) {
            cont++;
        }
    }
    return cont;
}

bool GestoreMessaggi::registra_utente(const char* id) {
    if (strlen(id)==0 || strlen(id)>maxCar) {
        return false;
    }
    for (int i=0;i<nUtenti;i++) {
        if (strcmp(utenti[i]->nickname, id)==0) {
            return false;
        }
        if (strlen(utenti[i]->nickname)==0) {
            strcpy(utenti[i]->nickname, id);
            return true;
        }
    }
    return false;
}

void GestoreMessaggi::invia_messaggio(char* destinatario, char* mittente, char *testo) {
    if (strlen(testo)==0 || strlen(testo)>maxLenMes) {
        return;
    }

    bool mittenteTrov=false, destinatarioTrov=false;

    Utente* destinPun=nullptr;
    Utente* mittPun=nullptr;

    for ( int i=0; i<nUtenti; i++) {
        if (strcmp(utenti[i]->nickname, mittente)==0) {
            mittenteTrov=true;
            mittPun=utenti[i];
        }
        if (strcmp(utenti[i]->nickname,destinatario)==0) {
            if (utenti[i]->DaLegg==maxDaLeggere) {
                return;
            }
            destinatarioTrov=true;
           destinPun=utenti[i];
        }
    }

    if (mittenteTrov==false || destinatarioTrov==false) {
        return;
    }

    int index= destinPun->DaLegg;
    destinPun->casella[index] = new Messaggio;
    strcpy(destinPun->casella[index]->messaggio,testo);
    destinPun->casella[index]->Mittente = mittPun;
    destinPun->DaLegg++;
}

ostream& operator<<(ostream& os, GestoreMessaggi& g) {
    os<<"Numero utenti registrati: "<<g.contaRegistrati()<<endl;
    os<<"Numero spazi disponibili: "<<g.contaDaRegistrare()<<endl;
    os<<endl;
    for (int i=0;i<g.nUtenti;i++) {
        if (strlen(g.utenti[i]->nickname)!=0) {
            os<<g.utenti[i]->nickname<<": "<<g.utenti[i]->DaLegg<<" messaggi da leggere"<<endl;
        }
    }
    return os;
}

GestoreMessaggi::~GestoreMessaggi() {
    for (int i = 0; i < nUtenti; i++) {
        for (int j = 0; j < utenti[i]->DaLegg; j++) {
            delete utenti[i]->casella[j];
        }
        delete utenti[i];
    }
    delete[] utenti;
}

const char* GestoreMessaggi::leggi_messaggio(const char *destinatario, char* mittente) {
    bool destinatarioTrov=false;

    Utente* destinPun=nullptr;

    for ( int i=0; i<nUtenti; i++) {
        if (strcmp(utenti[i]->nickname,destinatario)==0) {
            if (utenti[i]->DaLegg==maxDaLeggere) {
                return nullptr;;
            }
            destinatarioTrov=true;
            destinPun=utenti[i];
            break;
        }
    }
    if (destinatarioTrov==false || destinPun->DaLegg==0) {
        return nullptr;
    }

    Messaggio* daLeggere = destinPun->casella[0];
    strcpy(mittente, daLeggere->Mittente->nickname);
    const char* testo = daLeggere->messaggio;

    for (int j = 0; j < destinPun->DaLegg - 1; j++) {
        destinPun->casella[j] = destinPun->casella[j+1];
    }

    destinPun->casella[destinPun->DaLegg - 1] = nullptr;
    destinPun->DaLegg--;

    return testo;
}

GestoreMessaggi::GestoreMessaggi(GestoreMessaggi &g) {
    this->nUtenti=g.nUtenti;
    utenti=new Utente*[nUtenti];

    for (int i=0;i<nUtenti;i++) {
        utenti[i]=new Utente;
        strcpy(utenti[i]->nickname,g.utenti[i]->nickname);
        utenti[i]->DaLegg=g.utenti[i]->DaLegg;
        for (int j = 0; j < g.utenti[i]->DaLegg; j++) {
            utenti[i]->casella[j] = new Messaggio;
            strcpy(utenti[i]->casella[j]->messaggio, g.utenti[i]->casella[j]->messaggio);
        }
        for (int j = utenti[i]->DaLegg; j < maxDaLeggere; j++) {
            utenti[i]->casella[j] = nullptr;
        }
    }
}

GestoreMessaggi operator+(int n, const GestoreMessaggi& g) {
    if (n<0) {
        n=0;
    }
    GestoreMessaggi g1(g.nUtenti+n);
    for (int i=0;i<g.nUtenti;i++) {
        strcpy(g1.utenti[i]->nickname,g.utenti[i]->nickname);
        g1.utenti[i]->DaLegg=g.utenti[i]->DaLegg;
        for (int j=0;j<g.utenti[i]->DaLegg;j++) {
            if (g.utenti[i]->casella[j] != nullptr) {
                g1.utenti[i]->casella[j] = new Messaggio;
                strcpy(g1.utenti[i]->casella[j]->messaggio, g.utenti[i]->casella[j]->messaggio);
                g1.utenti[i]->casella[j]->Mittente = g.utenti[i]->casella[j]->Mittente;
            }
        }
    }
    return g1;
}
