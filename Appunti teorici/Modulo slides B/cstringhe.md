Una c-stringa è un **vettore di caratteri** di lunghezza arbitraria e che contenga almeno un occorrenza della sequenza di caratteri \0 ( la marca di fine stringa).

==Nota:== Se il nostro codice non dovesse presentare una marca di fine stringa, il compilatore lo aggiungerebbe in automatico alla fine della c-stringa da noi specificata.

La dichiarazione e inizializzazione di un oggetto del seguente tipo avviene così:

char $[lunghezzaStringa]$ stringa; //Nel caso di singola dichiarazione

char$[ ]$ stringa="stringa"; //Nel caso di inizializzazione c'è da ricordarsi che la dimensione dell'array può essere omessa

char$[ ]$ stringa ={ 's' , 't', 'r', 'i',' n', 'g', 'a','\0'}; //Questa notazione è perfettamente equivalente a quella superiore.

$char *stringa=" Stringa ";$//Però è sconsigliata perché può generare facilmente anomalie 

==Nota:== Le dimensioni che diamo alla stringa le dobbiamo sempre considerare del tipo n-1 poiché le stringhe contengono sempre la marca di fine stringa ed occupa un posto all'interno della dimensione che abbiamo scelto. 

Ad esempio per scrivere "stringa" avremmo bisogno di 8 posizioni e non di 7, anche se la parola è lunga 7 caratteri!

La stringa d'esempio ha 2 lunghezze:
- Una logica rappresentata dal numero di caratteri : 5
- Una fisica che è rappresentata da tutta la stringa (compresa la marca di fine stringa): 6
e la lunghezza logica si misura attraverso la funzione, presente della libreria $<cstring, strlen.

==Nota:== L'operatore = applicato alle c-stringhe **non permette l'assegnazione** bensì **solo l'inizializzazione**, per manipolare le stringhe usiamo **gli stream di ingresso e di uscita**.

**E allora come ovviamo a questo problema ?

La libreria $<cstring>$ ci offre una funzione chiamata **stringcpy** che copia la stringa in tutta la sua interezza ( compreso il carattere nullo) e ne restituisce la copia.

Il codice che ne permette il funzionamento è il seguente :

$# include <iostream.h>$
void strcpy(char $[]$ destinazione, char$[]$ sorgente){
	int i=0;
	s$[i]$=t$[i]$;
	while(s$[i]$ != '\0'){
	i++;
	s$[i]$ = t$[i]$;
	}
}

==Nota:== Potremmo anche scrivere s$[i]$ = t$[i]$ != '\0' nel while per rendere il codice più sintetico o addirittura sostituire l'espressione con l'equivalente utilizzando l'aritmetica dei puntatori ( la stringa come argomento funzionale viene considerata come un puntatore a stringa ossia char $* s$)

$*s++$ = $*t++$ ; //che gestisce contemporaneamente la copia (indirizzo s --> indirizzo t ) e l'incremento della posizione **senza l'uso di un indice ausiliario i**. 

**Altre funzioni della libreria $<c- string >$ :**

- La funzione **strcmp(s,t)** , compara due stringhe e restituisce:
1) Un valore negativo se s viene prima di t alfabeticamente.
2) 0 se le stringhe sono uguali.
3) Un valore positivo se s viene dopo di t .

==Nota:== La funzione considera i caratteri minuscoli e maiuscoli diversi , nello specifico i caratteri maiuscoli valgono meno di quelli minuscoli (per codifica ascii). In caso si voglia eguagliare le stringhe ( ossia avere i caratteri minuscoli ad entrambe ) dovremmo usare la funzione strcasecmp().

Il codice di questa funzione è pressoché:

int strcmp(char s[], char t[]) {
    int i = 0;
    while (s$[i]$ != '\0' && t$[i]$ != '\0' && s$[i]$ == t$[i]$) {
        i++;
    }
    return s$[i]$ - t$[i]$;
}

- La funzione **strcat(s,t)** mi permette di concatenare due stringhe e pone la marca di fine stringa solo al termine della stringa concatenata. (concatena t al termine di s e resituisce s). 
  Insomma abbiamo destinazione = destinazione + altrastringa;
  
**Input di una stringa da tastiera:**

Per prendere in input una stringa da tastiera è necessario innanzitutto pre-allocarla;

(ossia digitare char $[dimensione]$ ;)

Poi si aprono 2 possibilità:

1) Usare **lo stream di ingresso cin** : Esso però presenta un difetto, nel caso incontrasse uno spazio ignorerebbe ogni cosa che viene dopo.
   ( esempio se volessi scrivere "fondamenti di programmazione" , risulterebbe solo fondamenti)
2) Usare **la funzione cin.get()**: Ne segue un esempio:

    char autori[MAXCHAR];
    cout << "Inserisci il autori (max " << MAXCHAR - 1 << " caratteri): ";
    cin.getline(autori, MAXCHAR); // supponiamo l'utente inserisca "Andrea Domenici e Graziano Frosini"
    
    if (std::cin.fail()){
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ripulisce lo stream di ingresso
    }