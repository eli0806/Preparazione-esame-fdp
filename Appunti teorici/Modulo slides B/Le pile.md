Una **pila** è un **insieme ordinato di dati dello stesso tipo** che sfrutta la **tecnica di accesso LIFO (Last In First Out )**.

**Come funziona questa tecnica?**
Questa tecnica ci permette di accede solo all'ultimo dato inserito in un array e di estrarlo.
(Come ad esempio se avessimo una pila di libri prenderemmo sempre quello più in alto).

**Implementazione:**

Una pila può essere implementata attraverso un **array** e un **indice top** .

- L'**array** viene popolato da sinistra verso destra.
- L'**indice top** individua l'ultimo dato inserito.

![[Una pila.png]]

Possiamo svolgere su una pila :
- **L'inserimento:** avviene nella posizione successiva a quella indicata dalla variabile top, a meno che top=DIM-1
- **L'estrazione:** avviene nella posizione indicata dalla variabile top.
- **Controllo sulla condizione di pienezza.** --> top= DIM - 1 
- **Controllo sulla condizione di vuoto**. --> top=-1

**Codice:**

**Dichiarazione e definizione:**
const int DIM=valoreDim;

struct pila{
	int top;  //Non abbiamo inizializzato top qua perchè in realtà qui stiamo solo dichiarando la pila, non inizializzandola.
	int arr$[DIM]$;
}

**Inizializzazione della pila:**

void inip(pila& p){
	p.top=-1;
}

//Ora la pila è piena di valori casuali ma la consideriamo vuota poiché la variabile top è definita in maniera da farci capire di non aver nessun dato da noi specificato all'interno di essa.

**Controllo della condizione di vuoto:**

bool vuoto(pila p){
	if(p.top$==$ -1){
		return true;
	}else{
		return false;
	}
}

**Controllo della condizione di pienezza:**

bool pieno(pila p){
	if(p.top$==$DIM){
		return true;
	}else{
		return false;
	}
}

**Inserimento:**

bool inserimento(pila p, int val){
	if(pieno(p)$==$true){
		return false;
	}else{
		p.arr$[++p.top]$=val;
		return true;
	}
}

**Estrazione:**

bool estrazione(pila& p, int &val){
	if(vuoto(p)$==$true){
		return false;
	}else{
		val=p.arr$[p.top--]$;
		return true;
	}
}

==Chiarimento:==

Potrebbe sorgere spontanea la domanda **perchè in alcune funzioni abbiamo la pila passata per riferimento** ( come nell'inizializzazione, nell'inserimento, nell'estrazione) **e in altre** ( come i controlli di condizione di pienezza e di vuoto) **no?**

La risposta è semplice! Le funzioni dove abbiamo la pila ( o nel caso dell'estrazione anche il valore) passata per riferimento è perché in quella determinata funzione dobbiamo andare a **modificare il valore** di top nel caso della pila e della variabile in caso dell'estrazione. 