//
// Created by eli on 2/5/26.
//

#include "compito.h"

ListaCaratteri::ListaCaratteri() {
    head=nullptr;
}

void ListaCaratteri::inserisci(char car, bool fine) {
    carattere* n=new carattere;
    n->car=car;
    if (head==nullptr) {
        head=n;
    }else {
        carattere* p=head;
        carattere* q = nullptr;
        if (fine==true) {
            while (p!=nullptr) {
                q=p;
                p=p->next;
            }
            q->next=n;
            n->next=nullptr;
        }else {
            n->next = head;
            head = n;
        }
    }
}

bool ListaCaratteri::rimuoviUno(const char c) {
    if (head==nullptr) {
        return false;
    }
    carattere* p=head;
    carattere* q = nullptr;
    while (p!=nullptr) {
        if (p->car==c) {
            if (q==nullptr) {
                head = p->next;
                delete p;
                p = head;
                return true;
            }else {
                q->next=p->next;
                delete p;
                p=q->next;
                return true;
            }
        }else {
            q=p;
            p=p->next;
        }
    }
    return false;
}

bool ListaCaratteri::rimuoviTutti(const char c) {
    if (head==nullptr) {
        return false;
    }
    carattere* p=head;
    carattere* q = nullptr;
    bool trovato=false;

    while (p!=nullptr) {
        if (p->car==c) {
            trovato=true;
            if (q==nullptr) {
                head = p->next;
                delete p;
                p = head;
            }else {
                q->next=p->next;
                delete p;
                p=q->next;
            }
        }else {
            q=p;
            p=p->next;
        }
    }
    return trovato;
}

bool ListaCaratteri::rimuovi(char c, bool tutti) {
    if (tutti==true) {
        return rimuoviTutti(c);
    }else {
        return rimuoviUno(c);
    }
}

ostream& operator<<(ostream& os, const ListaCaratteri& lc) {
    carattere* p=lc.head;
    while (p!=nullptr) {
        os << p->car << "->";
        p=p->next;
    }
    os<<"@";
    return os;
}

ListaCaratteri::~ListaCaratteri() {
    carattere* p = head;
    while (p!=nullptr) {
        head = p;
        p=p->next;
        delete head;
    }
    head=nullptr;
}

bool ListaCaratteri::operator==(ListaCaratteri& lc1) {
    bool isEqual=false;

    carattere* p=lc1.head;
    carattere* p2=head;
    if ((p == nullptr) && (p2 == nullptr)) {
        return true;
    }
    while (p!=nullptr && p2!=nullptr) {
        if (p->car==p2->car) {
            isEqual=true;
        }else {
            isEqual=false;
            break;
        }
        p=p->next;
        p2=p2->next;
    }
    return isEqual;
}

ListaCaratteri& ListaCaratteri::operator~() {
    carattere * q =nullptr;
    carattere* p=head;
    carattere* prox=nullptr;
    while (p!=nullptr) {
        prox=p->next; //L'elemento successivo è effettivamente l'elemento successivo di p
        p->next=q; //P punta al suo elemento precedente
        q=p; //Q diventa l'elemento corrente
        p=prox; //P "scorre" finchè non è nullptr
    }
    head=q;
    return (*this);
}

ListaCaratteri::ListaCaratteri(const ListaCaratteri& lc1) {
    if (lc1.head == nullptr) {
        this->head = nullptr;
        return;
    }

    this->head = new carattere;
    this->head->car = lc1.head->car;


    carattere* p= lc1.head->next;
    carattere* p2 = this->head;

    while (p!= nullptr) {
        p2->next = new carattere;
        p2 = p2->next;
        p2->car = p->car;
        p = p->next;
    }

 p2->next = nullptr;
}

bool ListaCaratteri::controllaPalindroma() {

    ListaCaratteri copia(*this);
    ~copia;
    return copia==*this;
}

bool ListaCaratteri::confrontaStr(const carattere* lista, const carattere* subStr) {
    while (subStr != nullptr) {
        if (lista == nullptr || lista->car != subStr->car) {
            return false;
        }
        lista =lista->next;
        subStr = subStr->next;
    }
    return true;
}

bool ListaCaratteri::cercaSottostringa(const ListaCaratteri& lc2) {
    if (head==nullptr|| lc2.head==nullptr) {
        return false;
    }
    const carattere* p = head;
    while (p != nullptr) {
        if (confrontaStr(p, lc2.head)) {
            return true;
        }
        p = p->next;
    }
}

int ListaCaratteri::indiceDaTogliere(int n) {
    int cont=0;
    carattere* p=head;
    while (p!=nullptr) {
        cont++;
        p=p->next;
    }
    return cont-n;
}
char* ListaCaratteri::estraiNultimoCarattere(int n) {
    if (head==nullptr || n<0) {
        return nullptr;
    }

    carattere* p=head;
    carattere* q=nullptr;

    int indice=indiceDaTogliere(n);

    if (indice<0) {
        indice=0;
    }

    if (indice==0) {
        head=p->next;

    }else {
        for (int i=0;i<indice;i++) {
            q=p;
            p=p->next;
        }
        q->next=p->next;
    }
    char estr = p->car;
    delete p;

    char* result = new char(estr);
    return result;
}
