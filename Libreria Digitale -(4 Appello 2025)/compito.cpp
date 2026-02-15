//
// Created by eli on 2/13/26.
//

#include "compito.h"

LibreriaDigitale::LibreriaDigitale() {
    primo=nullptr;
}

Scaffale::Scaffale(int capacita) {
    this->capacita=capacita;
    mensola=new Libro*[capacita];
    for (int i=0;i<capacita;i++) {
        mensola[i]=nullptr;
    }
}

Scaffale::~Scaffale() {
    for (int i = 0; i < capacita; i++) {
        if (mensola[i] != nullptr) {
            delete mensola[i];
        }
    }
    delete[] mensola;
}

int Scaffale::contaLibri() {
    int cont=0;
    for (int i=0;i<capacita;i++) {
        if (mensola[i]!=nullptr) {
            cont++;
        }
    }
    return cont;
}

int Scaffale::contaUsati() {
        int cont=0;
        for (int i=0;i<capacita;i++) {
            if (mensola[i]==nullptr) {
                break;
            }
            if (mensola[i]->usato==true) {
                cont++;
            }
        }
        return cont;
}

ostream &operator<<(ostream &os, LibreriaDigitale &ld) {
    Scaffale* p=ld.primo;

    while (p!=nullptr) {
        os<<"-Scaffale: "<<p->nome<<endl;
        for (int i=0;i<p->capacita;i++) {
            if (p->mensola[i]!=nullptr){
                os<<i+1<<". '"<<p->mensola[i]->titolo<<"' (";
                if (p->mensola[i]->usato==true) {
                    os<<"Usato)"<<endl;
                }else {
                    os<<"Nuovo)"<<endl;
                }
            }
        }
        os<<"Totale libri: "<<p->contaLibri()<<"/"<<p->capacita<<endl;
        p=p->next;
    }
    return os;
}

void LibreriaDigitale::aggiungiScaffale(char *nome, unsigned int capacita) {
    if (strlen(nome)==0 || strlen(nome)>maxCarS || capacita<1) { //Suppongo che uno scaffale debba contenere almeno un libro
        return;
    }
    Scaffale* p=primo;
    Scaffale* q=nullptr;

    while (p!=nullptr) {
        if (strcmp(p->nome,nome)==0) {
            return;
        }
        q=p;
        p=p->next;
    }
    Scaffale* nuovo = new Scaffale(capacita);
    nuovo->next=nullptr;
    strcpy(nuovo->nome,nome);

    if (q==nullptr) {
        primo=nuovo;
    }else {
        q->next=nuovo;
    }
}

bool LibreriaDigitale::aggiungiLibro(char* nomeScaffale, char* titolo, bool condizione) {
    if (strlen(nomeScaffale)==0 || strlen(nomeScaffale)>maxCarS || strlen(titolo)==0 || strlen(titolo)>maxCarL) {
        return false;
    }
    Scaffale* p=primo;
    bool scaffaleTrovato=false;
    while (p!=nullptr) {
        if (strcmp(p->nome,nomeScaffale)==0) {
            scaffaleTrovato=true;
            break;
        }
        p=p->next;
    }
    if (scaffaleTrovato==false) {
        return false;
    }
    if (p->contaLibri()==p->capacita) {
        return false;
    }

    int index=0;
    for (int i=0;i<p->capacita;i++) {
        if (p->mensola[i]!=nullptr) {
            if (strcmp(p->mensola[i]->titolo,titolo)==0) {
                return false;
            }
        }else {
            index=i;
            break;
        }
    }
    p->mensola[index] = new Libro;
    strcpy(p->mensola[index]->titolo,titolo);
    p->mensola[index]->usato=condizione;
    return true;
}

LibreriaDigitale::~LibreriaDigitale() {
    Scaffale* p=primo;
    while (p!=nullptr) {
        Scaffale* del=p;
        p=p->next;
        delete del;
    }
}

LibreriaDigitale::LibreriaDigitale(const LibreriaDigitale &ld) {
    if (ld.primo == nullptr) {
        primo = nullptr;
        return;
    }
    primo = new Scaffale(ld.primo->capacita);
    strcpy(primo->nome, ld.primo->nome);

    for (int i=0;i<ld.primo->capacita;i++) {
        if (ld.primo->mensola[i]!=nullptr) {
            primo->mensola[i]=new Libro;
            strcpy(primo->mensola[i]->titolo, ld.primo->mensola[i]->titolo);
            primo ->mensola[i]->usato=ld.primo->mensola[i]->usato;
        }else {
            primo->mensola[i]=nullptr;
        }
    }
    Scaffale* p = ld.primo->next;
    Scaffale* curr = primo;

    while (p != nullptr) {
        curr->next = new Scaffale(p->capacita);
        curr = curr->next;

        strcpy(curr->nome, p->nome);

        for (int i = 0; i < p->capacita; i++) {
            if (p->mensola[i] != nullptr) {
                curr->mensola[i] = new Libro;
                strcpy(curr->mensola[i]->titolo, p->mensola[i]->titolo);
                curr->mensola[i]->usato = p->mensola[i]->usato;
            } else {
                curr->mensola[i] = nullptr;
            }
        }
        p = p->next;
    }
    curr->next = nullptr;
}

void LibreriaDigitale::rimuoviLibro(char *nomeScaffale, char *titolo) {
    Scaffale* p=primo;
    bool trovaScaffale=false;
    while (p!=nullptr) {
        if (strcmp(p->nome,nomeScaffale)==0) {
            trovaScaffale=true;
            break;
        }
        p=p->next;
    }
    if (trovaScaffale==false) {
        return;
    }

    for (int i=0; i<p->capacita; i++) {
        if (p->mensola[i]!=nullptr) {
            if (strcmp(p->mensola[i]->titolo,titolo)==0) {
                if (p->mensola[i+1]==nullptr) {
                    p->mensola[i]=nullptr;
                    return;
                }else {
                    p->mensola[i]=p->mensola[i+1];
                    p->mensola[i+1]=nullptr;
                }
                return;
            }
        }
    }
}

LibreriaDigitale LibreriaDigitale::operator~() {
    LibreriaDigitale risultato(*this);
    Scaffale* p=risultato.primo;
    while (p!=nullptr){
        for (int i = 0; i < p->capacita; i++) {
            if (p->mensola[i] != nullptr) {
                p->mensola[i]->usato = !(p->mensola[i]->usato);
            }
        }
        p = p->next;
    }
    return risultato;
}

LibreriaDigitale& LibreriaDigitale::operator!() {
    Scaffale* p= primo;
    while (p!=nullptr) {
        if (p->contaUsati()>=(p->contaLibri()/2)) {
            for (int i=0;i<p->capacita;i++) {
                if (p->mensola[i]!=nullptr && p->mensola[i]->usato==true) {
                        delete p->mensola[i];
                        p->mensola[i]=nullptr;
                }
            }
        }
        p=p->next;
    }
    return *this;
}