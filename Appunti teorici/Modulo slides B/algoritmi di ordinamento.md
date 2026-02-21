Per operare meglio su un array è utile che questo sia ordinato.

**Ma come possiamo ordinare un array?**

Semplice! Attraverso gli algoritmi di ordinamento.
Ogni algoritmo di ordinamento ha una specifica complessità del tipo o(funzione di n).

La complessità o indica il numero massimo di passi che la funzione dovrà reiterare al fine di ottenere l'array ordinato. --> Numero massimo perchè andiamo a considerare il caso peggiore, ossia quello in cui nessun numero è in ordine.

I migliori (come il merge-sort o l'heap sort)ad esempio ha complessità $o(nlogn)$

Noi vedremo il bubble-sort e il selection-sort, con complessità entrambi di $o(n^2)$ . 

**Il bubble-sort:**

Questo algoritmo funziona per scambio di elementi adiacenti, effettuando confronti .
All'inizio si confronta l'ultimo argomento con il penultimo e se esso è maggiore,  avviene lo scambio. ( es. ultimo=1, penultimo=2 --> avviene lo scambio). 
Finito il primo controllo del vettore, esso riavviene ma su lunghezza da n-1 a i+1 e così via finchè il vettore non è ordinato.

![[Immagine bubble sort.png]]
void bubble(int vettore[], int n) {

    for(int i = 0; i < n - 1; i++) {

        bool ordinato = true;

        for(int j = n - 1; j > i; j--) {

            if(vettore[j] < vettore[j - 1]) {

                int temp = vettore[j];
                vettore[j] = vettore[j - 1];
                vettore[j - 1] = temp;

                ordinato = false; 
            }
        }

        if(ordinato)
            return;  
    }
}

**Il selection-sort:**

Questo algoritmo ricerca all'interno del vettore il numero più piccolo e lo mette in posizione i=0,
prosegue poi con una strategia di compare. (Analizzando i valori dalla posizione i+1 a n-1, ad ogni passaggio e spostando in posizione i, il minore di essi).

![[Immagine selection sort.png]]

void SelectionSort(T vettore[], int n) {

    int min;
    for(int i = 0; i < n-1; i++) {

        min = i;
        for(int j = i+1; j < n; j++) {

            if(vettore[j] < vettore[min]) {
                min = j;
            }
        }
        if(min != i) {
            temp = vettore[i];
            vettore[i] = vettore[min];
            vettore[min] = temp;
        }
    }
}



==Nota:== Andrebbe preferito il bubble-sort al selection-sort perché gestisce meglio la memoria cache lavorando NON su tutto il vettore ma solamente su valori adiacenti.

Avendo un array ordinato possiamo cercare meglio le informazioni. Difatti un applicazione che funziona bene su un array ordinato è la **ricerca lineare**.

La **ricerca lineare** è una funzione booleana che, **data una chiave K** (il criterio di ricerca), controlla la presenza di tale chiave all’interno di un **array di tipo tabella**, dove ogni posizione è **indicizzata da una chiave univoca**.  
In caso affermativo la funzione restituisce true ed **assegna alla variabile di output (passata per riferimento) il valore contenuto nella posizione corrispondente alla chiave trovata**.  
In caso negativo restituisce false e **non modifica** la variabile di output.

L'**algoritmo di ricerca lineare** (di complessità o(n)) confronta k con l'elemento a metà dell'elenco (implementiamo in partenza un valore inferiore e un valore superiore per delimitare la "zona di ricerca") della tabella, in caso fossero uguali **termina**, altrimenti :

- Se **la chiave fosse minore dell'elemento** --> L'algoritmo prosegue nella **prima parte dell'elenco** (insomma da 0 a n/2). --> Abbiamo modificato il valore superiore!
- Se **la chiave fosse maggiore dell'elemento** --> L'algoritmo prosegue nella **seconda parte dell'elenco** (insomma da n/2+1 a n-1). --> Abbiamo modificato il valore inferiore!

Se la metà **è considerata vuota** significa che **la chiave NON è presente all'interno dell'array tabellare**.

Esso in c++ si implementa così: 

bool ricLin(int v[], int inf, int sup, int k, int &pos){
	bool trovato = false;
	while ((!trovato) && (inf <= supe))
	{	
		if (v$[sup]$ == k)
		{
			pos = sup;
			trovato = true;
   		}
		supe--;
   	}
	return trovato;
}

La versione **ottimizzata** della **ricerca lineare** lavora **solo su array ordinati** e il codice che ne permette l'implementazione è:


bool ricBin(int ordVett[], int inf, int sup, int k, int &pos){
	while (infe <= supe){
       	int medio = (inf + sup) / 2; // calcola l'indice centrale
		if (ordVett$[medio]$ == k){
			pos = medio;   			   // trovato
			return true;
		}else{
			if (ordVett$[medio]$> k)
				sup = medio - 1;      // ricerca nella meta' inferiore
			else
				inf = medio + 1;      // ricerca nella meta' superiore
		}
	}
    return false;
}