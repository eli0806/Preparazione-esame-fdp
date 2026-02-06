Abbiamo bisogno di **definire una funzione distruttore** quando termina **il tempo di vita di un oggetto automatico/dinamico**.

**Perché?**

Anche se l'oggetto viene deallocato, **la memoria dell’oggetto viene liberata automaticamente, ma le risorse esterne no**.

La funzione **distruttore** viene invocata **automaticamente dal compilatore** e ha **per identificatore** il nome della classe preceduto da '~' (codice per digitarla windows Alt+ 126).

**Esempio:**

class Buffer {
    int* data;
    int size;
public:
    Buffer(int n) : size(n) {
        data = new int[n];      // allocazione dinamica
        cout << "Costruttore: allocato buffer\n";
    }
    ~Buffer() {
        delete[] data;          // rilascio risorsa
        cout << "Distruttore: liberato buffer\n";
    }
};

int main() {
    {
        Buffer b(10);   // oggetto automatico
    }                   // fine blocco → chiamato automaticamente ~Buffer()
    Buffer* p = new Buffer(20);
    delete p;           // chiamato ~Buffer() per oggetto dinamico
}

==Nota:== Il distruttore **NON verrà mai chiamato esplicitamente dal programmatore**.

**Per le varie classi di memorizzazione (vedere [[Le classi di memorizzazione di un oggetto]]), il distruttore dell'oggetto viene invocato in momenti diversi del codice:**
1) **oggetti statici:** al termine del main del programma.
2) **oggetti automatici**: al termine del blocco dove sono definiti.
3) **oggetti dinamici:** quando si incontra l'operatore **delete**.
4) **membri di altri oggetti classe:** quando la classe esterna viene distrutta.

==Nota:== Oggetti con **lo stesso tempo di vita** --> distrutti **con lo stesso ordine con il quale sono stati definiti.**

