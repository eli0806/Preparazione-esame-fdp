//
// Created by eli on 2/8/26.
//

#include "compito.h"

Supermercato::Supermercato() {
    listaProdotti=nullptr;
    for (int i=0;i<maxCarrelli;i++) {
        carrelli[i]=nullptr;
    }
}

Prodotto::~Prodotto() {
    delete[] nome;
}

Carrello::~Carrello() {
    Prodotto* p = listaProdotti;
    while (p != nullptr) {
        Prodotto* del = p;
        p = p->next;
        delete del;
    }
}

Supermercato::~Supermercato() {
    Prodotto* p=listaProdotti;
    Prodotto* del=p;

    while (p!=nullptr) {
        del=p;
        p=p->next;
        delete del;
    }

    for (int i=0;i<maxCarrelli;i++) {
        delete carrelli[i];
        carrelli[i]=nullptr;
    }
}

Prodotto* Supermercato::cercaProdotto(char* prod) {
    Prodotto* p = listaProdotti;

    while (p!=nullptr) {
        if (strcmp(p->nome, prod) == 0) {
            return p;
        }
        p=p->next;
    }
    return nullptr;
}

int Supermercato::cercaCliente(int id) {
    for (int i=0;i<maxCarrelli;i++) {
       if (carrelli[i] != nullptr && carrelli[i]->idCliente == id) {
           return i;
       }
    }
    return -1;
}

void Supermercato::crea_prodotto(char *prod, float prezzoUn) {
    if (cercaProdotto(prod)==nullptr) {
        if (prod==nullptr || prezzoUn<0.0) {
            return;
        }
        Prodotto* p=listaProdotti;
        Prodotto* q= nullptr;

        Prodotto* n= new Prodotto;
        n->nome=new char[strlen(prod)+1];
        strcpy(n->nome,prod);
        n->quantita=0;
        n->prezzoUnitario=prezzoUn;
        while (p != nullptr && strcmp(p->nome, prod) < 0) {
            q = p;
            p = p->next;
        }

        if (q== nullptr) {
            n->next = listaProdotti;
            listaProdotti = n;
        } else {
            n->next = p;
            q->next = n;
        }
    }
}

void Supermercato::esponi(char* prod , int quant, float prezzoUn) {
    if (prezzoUn<0.0) {
        return ;
    }
    if (cercaProdotto(prod)==nullptr) {
        return;
    }

    Prodotto* p=listaProdotti;

    while (p!=nullptr) {
        if (strcmp(p->nome, prod) == 0) {
            if (prezzoUn>0.0) {
                p->prezzoUnitario=prezzoUn;
            }
            p->quantita+=quant;
            break;
        }
        p=p->next;
    }
}

ostream& operator<<(ostream& os, const Supermercato& s) {
    os << "Prodotti:" << endl;
    Prodotto* p = s.listaProdotti;
    while (p != nullptr) {
        os << p->nome << " " << p->quantita << " " << p->prezzoUnitario << endl;
        p = p->next;
    }

    os << endl << "Clienti:" << endl;

    int clientiPresenti = 0;
    for (int i = 0; i < maxCarrelli; i++) {
        if (s.carrelli[i] != nullptr) {
            clientiPresenti++;
        }
    }

    if (clientiPresenti == 0) {
        os << "Nessun cliente presente." << endl;
    } else {
        for (int i = 0; i < maxCarrelli; i++) {
            if (s.carrelli[i] != nullptr) {
                os << "[" << i+1<< "-" <<s.carrelli[i]->idCliente<<"]:";
                Prodotto* acq = s.carrelli[i]->listaProdotti;
                while (acq!=nullptr) {
                    os << ' ' << acq->nome << " (" << acq->quantita << ") |";
                    acq = acq->next;
                }
                os << endl;
            }
        }
    }
    return os;
}

Supermercato& Supermercato::operator+=(int c) {
    if (cercaCliente(c)!=-1) {
        return (*this);
    }
    for (int i=0;i<maxCarrelli;i++) {
        if (carrelli[i]==nullptr) {
            carrelli[i]=new Carrello;
            carrelli[i]->idCliente=c;
            carrelli[i]->listaProdotti = nullptr;
            return *this;
        }
    }
    return *this;
}

void Supermercato::metti_nel_carrello(int c, char *prod, int q) {
    if (cercaProdotto(prod)== nullptr ||cercaCliente(c)==-1  || q<=0) {
        return;
    }

    Prodotto* p=cercaProdotto(prod);

    if (cercaProdotto(prod)->quantita<q) {
        q=p->quantita;
    }

    int index=cercaCliente(c);

    Prodotto* cercaCar=carrelli[index]->listaProdotti;

    while (cercaCar!=nullptr) {
        if (strcmp(cercaCar->nome,prod)==0) {
            cercaCar->quantita+=q;
            return;
        }
        cercaCar=cercaCar->next;
    }
    Prodotto* n=new Prodotto;
    n->nome=new char[strlen(prod)+1];
    strcpy(n->nome,prod);
    n->prezzoUnitario=p->prezzoUnitario;
    n->quantita=q;
    p->quantita=p->quantita-q;


    Prodotto* acq=carrelli[index]->listaProdotti;
    Prodotto* prev=nullptr;

    if (acq == nullptr || strcmp(prod, acq->nome) < 0) {
        n->next = acq;
        carrelli[index]->listaProdotti = n;
        return;
    }

    while (acq != nullptr) {
        if (strcmp(prod, acq->nome)==0) {
            acq->quantita+=q;
        }
        if (strcmp(prod, acq->nome) < 0) {
            n->next = acq;
            prev->next = n;
            return;
        }
        prev = acq;
        acq = acq->next;
    }

    prev->next = n;
    n->next = nullptr;
}

float Supermercato::acquista(int c) {
    if (cercaCliente(c)==-1) {
        return -1;
    }
    int index=cercaCliente(c);

    float spesaTot=0;

    Prodotto*  p =carrelli[index]->listaProdotti;

    while (p!=nullptr) {
        spesaTot+=p->prezzoUnitario*(p->quantita);
        p=p->next;
    }

    delete carrelli[index];
    carrelli[index]=nullptr;
    return spesaTot;
}
