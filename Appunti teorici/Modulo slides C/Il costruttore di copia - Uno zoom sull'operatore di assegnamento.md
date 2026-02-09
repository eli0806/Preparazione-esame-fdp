Il **costruttore di copia** è un costruttore predefinito delle classi che **agisce tra due oggetti della stessa classe, effettuando una copia membro a membro**.

**Cioè quando:**
- Un oggetto viene inizializzato con un altro oggetto della stessa classe.
- Un oggetto viene passato ad una funzione per valore.
- Un oggetto viene restituito per valore da una funzione.

==Nota:== In realtà sono tutte e tre forme di **inizializzazione**.

**Esempio:**

![[Esempi costruttore di copia.png]]

**Esempio grafico:**

![[Esempio costruttore di copia.png]]
Il costruttore di copia **può andare in conflitto con [[il distruttore]]** perciò talvolta è necessario che il programmatore lo **ridefinisca**.--> prende il nome di **deep copy**. --> La **ridefinizione** sostituirà sicuramente **il costruttore di copia di default**. 

**Casistiche in cui succede sono:**
- due oggetti che puntano alla **stessa area di memoria**
**Esempio:**

![[corruzione shallow copy 1.png]]
- doppia delete nel distruttore → **comportamento indefinito**
![[Corruzione cosruttore di copia 2.png]]

**Ridefinizione costruttore di copia** (esempio):

**Dichiarazione** :

Stringa (const stringa & s);

**Definizione** 

stringa (const stringa & s){
	str=new char[strlen(s.str) + 1];
	strcpy(str,s.str);
}

**Altro esempio:**

class Vettore {
private:
    int* dati;
    int n;

public:
    Vettore(int dim) {
        n = dim;
        dati = new int$[n]$;
    }
    // Costruttore di copia
    Vettore(const Vettore& v) {
        n = v.n;
        dati = new int$[n]$;
        for(int i = 0; i < n; i++)
            dati$[i]$ = v.dati$[i]$;
    }

    ~Vettore() {
        delete[] dati;
    }
};
**Se noi non volessimo che il costruttore di copia venga invocato?**

Esso deve essere dichiarato nella parte privata della classe. --> Non è necessaria una ridefinizione!

**MA**

Se nascondiamo il costruttore di copia non possiamo più svolgere nessuna funzione che abbia bisogno della copia.

**Maggiori informazioni sull'operazione di assegnamento:**

![[Asseganmento.png]]
![[Assegnazione 2.png]]