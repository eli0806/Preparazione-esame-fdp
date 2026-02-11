//
// Created by eli on 2/10/26.
//

#include "compito.h"

UfficioPostale::UfficioPostale(int nSportelli) {
    if (nSportelli<0) {
        nSportelli=1;
    }
    this->nSportelli=nSportelli;

    sportelli= new Utente*[nSportelli];
    for (int i=0;i<nSportelli; i++) {
        sportelli[i]=nullptr;
    }
}

int UfficioPostale::contaUtenti() {
    int cont=0;
    for (int i=0;i<nSportelli;i++) {
        Utente* p=sportelli[i];
        while (p!=nullptr) {
            cont++;
            p=p->next;
        }
    }
    return cont;
}

int UfficioPostale::contaPrioritari() {
    int cont=0;
    for (int i=0;i<nSportelli;i++) {
        Utente* p=sportelli[i];
        while (p!=nullptr) {
            if (p->prioritario) {
                cont++;
            }
            p=p->next;
        }
    }
    return cont;
}

bool UfficioPostale::cercaUtente(const char *nome, int sportello) {
    Utente* p=sportelli[sportello-1];
    while (p!=nullptr) {
        if (strcmp(p->nome, nome) == 0) {
            return true;
        }
        p = p->next;
    }
    return false;
}

void UfficioPostale::ausilioAccodaP(Utente* user, int index) {

    Utente* curr=sportelli[index];
    Utente* prev=nullptr;

    while (curr!=nullptr) {
        if (curr->prioritario==false) {
            break;
        }
        prev=curr;
        curr=curr->next;
    }
    user->next=curr;
    if (prev==nullptr) {
        sportelli[index]=user;
    }else {
        prev->next=user;
    }
}

ostream &operator<<(ostream &os, UfficioPostale &up) {
    os<<"Utenti totali: "<<up.contaUtenti()<<endl;
    os<<"Prioritari: "<<up.contaPrioritari()<<endl;
    for (int i=0;i<up.nSportelli;i++) {
        os<<"- Sportello "<<i+1<<" : ";
        Utente* p = up.sportelli[i];
        while (p!=nullptr) {
            os<<p->nome;
            if(p->prioritario) {
                os<<" (P)";
            }
            if (p->next!=nullptr) {
                os<<", ";
            }
            p=p->next;
        }
        os<<endl;
    }
    return os;
}

void UfficioPostale::accodaUtente(char *nome, int sportello) {
    if (strlen(nome)==0 ||strlen(nome)>maxCar || sportello<1 || sportello>nSportelli) return;
    if (cercaUtente(nome, sportello)) return;

    // creo il nuovo utente da accodare
    Utente* nuovo= new Utente;
    strcpy(nuovo->nome,nome);
    nuovo->prioritario=false;
    nuovo->next=nullptr;

    //Scorro tutta la coda ( poichè l'utente NON è prioritario) per posizionarlo in coda
    Utente* curr=sportelli[sportello-1];
    Utente* prev=nullptr;
    while (curr!=nullptr) {
        prev=curr;
        curr=curr->next;
    }
    if (prev==nullptr) {
        sportelli[sportello-1]=nuovo;
    }else {
        prev->next=nuovo;
    }
}

void UfficioPostale::serviUtente(int sportello) {
    if (sportello<1 || sportello>nSportelli) return;

    //Procedo a rimuovere l'utente da tale sportello --> Si tratta di un eliminazione in testa
    Utente* p =sportelli[sportello-1];
    if (p==nullptr) return ;
    sportelli[sportello-1]=p->next;
    delete p;
}

UfficioPostale::~UfficioPostale() {
    for (int i=0;i<nSportelli;i++) {
        Utente* p=sportelli[i];
        Utente* del=nullptr;
        while (p!=nullptr) {
            del=p;
            sportelli[i]=p->next;
            p=p->next;
            delete del;
        }
    }
    delete[] sportelli;
}

void UfficioPostale::accodaPrioritario(char* nome) {
    if (strlen(nome)==0 || strlen(nome)>maxCar) return;

    //Cerco La coda con il minor numero di prioritari
    int cont=0;
    int minPrioritari=contaPrioritari();
    int indexMin=0;

    for (int i=0;i<nSportelli;i++) {
        if (cercaUtente(nome,i+1)==true) {
            return;
        }
        Utente* p=sportelli[i];
        while (p!=nullptr) {
            if (p->prioritario) {
                cont++;
            }
            //Per evitare cicli inutili, se noto che la coda ha più utenti prioritari del minimo neanche la scorro
            if (cont>minPrioritari) {
                break;
            }
            p=p->next;
        }
        //Caso in cui devo aggiornare il minimo
        if (cont<minPrioritari) {
            minPrioritari=cont;
            indexMin=i;
        }
        cont=0;
    }
    Utente* nuovo= new Utente;
    strcpy(nuovo->nome,nome);
    nuovo->prioritario=true;
    ausilioAccodaP(nuovo,indexMin);
}

void UfficioPostale::passaAvanti(char *nome, int sportello, int nPos) {
    if (strlen(nome)==0 ||strlen(nome)>maxCar || sportello<1 || sportello>nSportelli || nPos<0) return;
    if (cercaUtente(nome,sportello)==false) {
        return;
    }

    int index=0;

    Utente* p=sportelli[sportello-1];
    Utente* q=nullptr;

    while (p!=nullptr) {
        if (strcmp(p->nome,nome)==0) {
            break;
        }
        q=p;
        index++;
        p=p->next;
    }

    if (!p || index == 0) return;

    // Diciamo al precedente (q) di saltare p
    if (q != nullptr) q->next = p->next;
    else sportelli[sportello - 1] = p->next;

    //Cerco index spostato di nPosizioni
    int indSwap = index - nPos;
    if (indSwap < 0) indSwap = 0;

    Utente* curr = sportelli[sportello - 1];
    Utente* prev = nullptr;

    for (int i = 0; i < indSwap; i++) {
        prev = curr;
        curr = curr->next;
    }

    p->next = curr;
    if (prev == nullptr) {
        sportelli[sportello - 1] = p;
    } else {
        prev->next = p;
    }

    if (p->next != nullptr && p->next->prioritario) {
        p->prioritario = true;
    }
}

UfficioPostale& UfficioPostale::operator!() {
    for (int i=0; i<nSportelli; i++) {
        Utente* p = sportelli[i];
        sportelli[i] = nullptr;

        while (p != nullptr) {
            Utente* temp = p->next;

            p->prioritario = !(p->prioritario); // Inverto la priorità
            p->next = nullptr;

            if (p->prioritario) {
                // Lo inserisco con la tua funzione helper
                ausilioAccodaP(p, i);
            } else {
                // Lo accodo in fondo alla lista che sto ricostruendo
                if (sportelli[i] == nullptr) {
                    sportelli[i] = p;
                } else {
                    Utente* coda = sportelli[i];
                    while (coda->next != nullptr) {
                        coda = coda->next;
                    }
                    coda->next = p;
                }
            }
            p = temp;
        }
    }
    return *this;
}