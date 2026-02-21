Una **lista** è una "catena" di **elementi dello stesso tipo** di lunghezza (ossia numero di elementi) variabile.

Ogni **elemento** è rappresentato da **una struttura** (vedere [[strutture (o struct)]]) costituita da uno o più membri contenenti informazioni ma sopratutto **da un membro puntatore** che punta **all'indirizzo dell'elemento successivo**. --> Inoltre sono **variabili dinamiche** che vengono create e distrutte a tempo d'esecuzione, garantendo una grande flessibilità.


**Il primo elemento della lista** è indirizzato da **una variabile puntatore** ( che prende il nome di **puntatore della lista**).

**Il puntatore dell'ultimo elemento è un puntatore nullo**.


![[Schema lista generale.png]]

Se la lista dovesse **essere vuota** avremmo che **il puntatore della lista sia nullo**.

**Implementazione della lista:**

**Definizione del tipo di un elemento:**

struct elem{
	tipoDato dato;
	.......                       
	elem* pun ;         
}
typedef elem* lista; //Scrivendo così possiamo definire il tipo di "puntatore a lista"

**Stampa di una lista:**

void stampaLista(lista p0){
	elem* p=p0;
	while(p!=NULLPTR){
		cout<< p->dato <<'  ';
		p=p->pun;
	}
}

**Deallocazione di una lista (che avviene per singolo elemento alla volta):**

void dealloca(elem* p0){
	elem* p=p0;
	elem* q;
	while(p!=nullptr){
		q=p;
		p=p->pun;
		delete q;
	}
}

==Nota:== E' possibile nell'implementazione della deallocazone della lista ricadere nell'errore di deallocare l'elemento prima di aver salvato il puntatore all'elemento successivo. --> Ciò porterebbe ad un undefined behiavour.

Su una lista possiamo svolgere due principali operazioni: **L'inserimento** e **l'estrazione**.
Entrambe possono avvenire **sia in testa** (all'inizio della lista), **che in coda**(ossia al termine di essa).

**Implementazione:**

**Inserimento in testa:**

void instest(lista& p0, int a){
	elem* p = new elem;
	p->dato=a;
	p->pun=p0;
	p0=p
}

![[Creazione di una lista con inserimenti in testa ( ossia della natura delle funzione che abbiamo utilizzato per crearla ).png]]

**Estrazione dalla testa:**

bool esttes(lista& p0, int& a){
	elem* p=p0;
	if(p0$==$NULLPTR){
		return false;
	}else{
		a=p0->dato;
		p0=p0->pun;
		delete p;
		return true;
	}
}

==Possiamo generalizzare così:==

**Estrazione passaggi:**

1) Recupero il primo componente dell'elemento in testa.
2) Bypasso dal punto di vista logico il primo elemento.
3) Distruggo il puntatore P


![[Estrazione dalla testa (liste).png]]

**Inserimento in fondo:**

void insfondo(elem*& p0, int a) {
    elem* n = new elem;
    n->inf = a;
    n->pun = nullptr;
    if (p0 == nullptr) {
        p0 = n;
    } else {
        elem* p = p0;
        while (p->pun != nullptr) {
            p = p->pun;
        }
        p->pun = n;
    }
}

Tal caso la lista fosse vuota p0 punterebbe subito all'elemento da noi inserito con la funzione.

![[Inserimento in fondo ad una lista.png]]

**Estrazione dal fondo:**

bool estfondo(elem*& p0, int& a) {
    if (p0 == nullptr)
        return false;
    // Caso: un solo elemento
    if (p0->pun == nullptr) {
        a = p0->inf;
        delete p0;
        p0 = nullptr;
        return true;
    }
    // Caso generale: almeno due elementi
    elem* q = p0;        // penultimo
    elem* p = p0->pun;   // ultimo
    while (p->pun != nullptr) {
        q = p;
        p = p->pun;
    }
    a = p->inf;
    q->pun = nullptr;
    delete p;
    return true;
}

![[estrazione dal fondo della lista.png]]

==Nota sui due puntatori nell’inserimento e nell’estrazione in fondo==

Quando si opera in fondo a una lista semplicemente concatenata, è necessario usare due puntatori ausiliari che puntano a due elementi consecutivi:

- **q** → penultimo elemento
- **p** → ultimo elemento (quello con `pun == nullptr`)

**Caso estrazione dal fondo**

Si scorre la lista mantenendo:

- `q` = penultimo
- `p` = ultimo

Una volta raggiunto il fondo:

q->pun = nullptr; delete p;

`q` diventa il nuovo ultimo elemento, mentre `p` viene eliminato.

**E se volessi estrarre un elemento specifico ?

bool estrprec(lista& p0, int a){
    elem* p = nullptr;
    elem* q = p0;
    // cerco un nodo con dato == a
    while(q != nullptr && q->dato != a){
        p = q;
        q = q->pun;
    }
    // non trovato
    if(q == nullptr){
        return false;
    }
    // rimozione in testa
    if(q == p0){
        p0 = q->pun;
    }
    // rimozione in mezzo o in coda
    else {
        p->pun = q->pun;
    }
    delete q;
    return true;
}

**E per le liste ordinate come si fa ?**

**Inserimento:**

//Dove a corrisponde al membro informazione del nuovo elemento della lista
void inserimentoOrd(lista& p0; int a){ 
	elem* p=nullptr;
	elem* q=p0;
	elem* r;
	//Creo una copia della lista
	while(q!=nullptr && p->inf<a){
		p=q;
	}
	//Creazione nuovo elemento
	r= new elem;
	r-> inf;
	r->pun=q;
	if(q$==$p0){ //Inserimento in testa?
		p0=r;
	}else{
		p->pun=r;
	}
}
![[Inserimento di un elemento all'interno di una lista ordinata.png]]

**Estrazione:**
bool estrord(lista& p0, int a){
    elem* p = nullptr;
    elem* q = p0;
    // avanzo finché i valori sono minori di a
    while(q != nullptr && q->dato < a){
        p = q;
        q = q->pun;
    }
    // se ho finito la lista o il valore è diverso, non trovato
    if(q == nullptr || q->dato != a){
        return false;
    }
    // rimozione in testa
    if(q == p0){
        p0 = q->pun;
    } 
    // rimozione in mezzo o in coda
    else {
        p->pun = q->pun;
    }
    delete q;
    return true;
}
![[Estrazione di un elemento da una lista ordinata.png]]
**Liste con puntatore ausiliario:**

E' possibile gestire le liste con **più di un puntatore**.

Nello specifico in questo tipo di liste abbiamo un puntatore **alla testa della lista** e uno **alla coda**.

**Codice:**

**Definizione elemento:**

struct lista{
	elem* p0; //Puntatore alla testa della lista
	elem p1; //Puntatore alla coda della lista
};


![[Immagine lista con puntatore ausiliario.png]]

In breve sulle liste con puntatore ausiliario si può affermare che :

- **Le funzioni sulle liste rimangono le stesse delle liste normali, ad esclusione delle funzioni che operano sul fondo della lista, e per cui quindi usiamo il puntatore alla coda della lista.**
- **Ci permetto di garantire una maggiore sicurezza nel caso di perdita di p0.**

Insomma ci facilitano il lavoro!

Sulla base di questo ragionamento allora possiamo creare delle **liste complesse**.

Un esempio di lista complessa è la **lista doppia**.

Nella **lista doppia** abbiamo 2 puntatori **uno all'elemento precedente** e **uno e all'elemento successivo**.

