Una **coda** è un **insieme ordinato di dati dello stesso tipo** che sfrutta la **tecnica di accesso FIFO (Fast In First Out )**.

**Come funziona questa tecnica?**
Questa tecnica ci permette di estrarre i dati **solo nell'ordine in cui sono stati inseriti.**

**Implementazione:**

Una pila può essere implementata attraverso un **array circolare** , un **indice front** e un **indice bottom .

- L'**array circolare** viene popolato e viene considerato **circolare** perché sul piano teorico l'ultima componente è adiacente alla prima.
- L'**indice back** individua la posizione in cui va inserito il prossimo elemento. --> Dopo l'inserimento viene incrementata.
- L'**Indice front** individua la posizione dell'elemento da estrarre.  -->  Dopo l'estrazione viene incrementata.


![[Una coda.png]]

Possiamo svolgere su una coda:
- **L'inserimento (enqueue):** avviene nella posizione indicata da **back**.
- **L'estrazione (dequeue):** avviene nella posizione indicata da **front.**
- **Controllo sulla condizione di pienezza.** --> front=(back+1)%DIM
- **Controllo sulla condizione di vuoto**. --> front=back=0

==Nota:== Nel controllo di pienezza notiamo che front non deve essere uguale a back ma uguale a back+1. Perché questo?

Questo avviene perchè altrimenti perderemmo la circolarità dell'array e non saremmo più capaci di distinguere se l'array è pieno o vuoto e riscontreremmo anomalie.

**Codice:** 

**Dichiarazione e definizione:**
const int DIM=valoreDim;

struct coda{
	int front, back;  //Non abbiamo inizializzato front e back qua perché in realtà qui stiamo solo dichiarando la coda, non inizializzandola.
	int arr$[DIM]$;
}

**Inizializzazione della coda:**

void inic(coda& c){
	c.front=0;
	c.back=0;
}

**Controllo della condizione di vuoto:**

bool vuoto(coda c){
	if(c.fornt$==$c.back){
		return true;
	}else{
		return false;
	}
}

**Controllo della condizione di pienezza:**

bool pieno(coda c){
	if(c.front$==$(c.back + 1)%DIM){
		return true;
	}else{
		return false;
	}
}

**Inserimento:**

bool inserimento(coda& c, int val){
	if(pieno(c)$==$true){
		return false;
	}else{
		c.arr$[c.back]$=val;
		c.back=(c.back+1)%DIM;
		return true;
	}
}

**Estrazione:**

bool estrazione(coda& c, int &val){
	if(vuoto(c)$==$true){
		return false;
	}else{
		val=c.arr$[c.front]$;
		c.front=(c.front + 1)%DIM;
		return true;
	}
}
