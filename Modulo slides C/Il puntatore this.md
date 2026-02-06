Una **funzione membro della classe** può riferirsi ad un istanza della stessa anche per mezzo **del puntatore this**.

Il **puntatore this** è un puntatore costante che contiene **l'indirizzo dell'oggetto classe su cui stiamo lavorando**.

Solitamente il suo uso è auspicabile nei casi in cui la funzione membro **abbia bisogno esplicitamente dell'indirizzo dell'oggetto classe** su cui si applica: 
- distinzione tra **campo di dati** e **parametro**
- restituzione **dell'oggetto classe**

**Esempio:**

class Punto {
private:
    int x, y;

public:
    Punto(int x, int y) {
        this->x = x;   // uso di this per distinguere membro e parametro
        this->y = y;
    }
    Punto* sposta(int dx, int dy) {
        x += dx;
        y += dy;
        return this;   // restituisce l’indirizzo dell’oggetto corrente
    }
};

Questo puntatore ci permette di realizzare un metodo che prende il nome di [[costruttore]].