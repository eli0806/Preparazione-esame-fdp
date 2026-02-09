Il **meccanismo di overloading** è **definito anche per gli operatori.**

Il **processo di ridefinizione** degli **operatori** consiste nel scrivere la funzione di overloading anteponendo la keyworld **operator** seguita dall'operatore che si vuole andare a modificare.

Un operatore può essere ridefinito in due modi diversi:

$1)$**Come funzione membro:**
- Ha **un solo operando esplicito** (quello a destra dell’operatore).
- L’oggetto a sinistra è implicito: è il this.

**Esempio:**
classe classe::operator+(const classe& other) const;

$2)$ **Come funzione globale**:
- Ha **due operandi espliciti**.
- Necessaria quando:
    $*$ il primo operando **non è** un oggetto della classe (es. `3 + obj`);
    $*$ l’operatore deve essere simmetrico.

**Esempio:**
classe operator+(const classe& a, const classe& b);

E in entrambi i casi abbiamo 3 modalità:

1) Si modifica l'oggetto e la ridefinizione restituisce void.

   class Classe {
public:
    int x;

    void operator+=(const Classe& other) {
        x += other.x;   // modifico l’oggetto
    }
};


2) Non viene modificato l'oggetto passato come operando e viene restituito un nuovo oggetto come risultato dell'operazione --> Ritorno per valore, NON per riferimento.

class Classe {
public:
    int x;

    Classe operator+(const Classe& other) const {
        Classe risultato(*this);   // non modifico this
        risultato.x += other.x;    // creo un nuovo oggetto
        return risultato;          // ritorno per valore
    }
};

3) Si va a modificare l'oggetto ma a differenza dei casi precedenti restituisco un riferimento all'oggetto modificato.

class Classe {
public:
    int x;

    Classe& operator+=(const Classe& other) {
        x += other.x;   // modifico l’oggetto
        return *this;   // ritorno per riferimento
    }
};

==Nota:== Il codice scritto nelle modalità è solo per funzione membro, l'unica differenza sostanziale è la firma della funzione di ridefinizione.

==Nota:== Possiamo ridefinire **solo gli operatori definiti dal linguaggio** e non ne possiamo modificare le proprietà.

==Nota:== Non è possibile ridefinire operatori per tipi già esistenti del linguaggio. Va associata una classe o struttura.

Attraverso le funzioni globali o le funzioni friend noi possiamo **mantenere la simmetria degli operatori**.

**Cosa si intende per simmetria degli operatori?**

Per **simmetria degli operatori** si intende la possibilità di usare un operatore binario senza che l’ordine degli operandi imponga vincoli dovuti all’implementazione.

In pratica:  
l’operatore deve funzionare sia quando l’oggetto della classe è **a sinistra**, sia quando è **a destra**.

![[Operatori che si possono ridefinire.png]]
Per la ridefinizione dell'operatore di assegnamento vedere [[Il costruttore di copia - Uno zoom sull'operatore di assegnamento]].