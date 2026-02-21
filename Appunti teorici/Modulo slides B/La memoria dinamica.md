Nel caso non riuscissimo a stabilire il numero di oggetti di un certo tipo, possiamo sfruttare un meccanismo particolare: il meccanismo della **memoria libera** o della **memoria dinamica**.

Ciò è reso possibile grazie all'uso dei puntatori, che ci permettono di allocare oggetti durante l'esecuzione del programma ( e non in fase di programmazione).

Gli oggetti così allocati prendono il nome di **oggetti dinamici**.

La loro allocazione avviene attraverso l'operatore **new** che ha come argomento **il nome dell'oggetto da allocare** e restituisce **l'indirizzo della zona di memoria libera per l'allocazione**.

==Nota:== Se lo spazio di allocazione necessario non fosse disponibile, **l'operatore new fallisce** e viene generato un messaggio d'errore. (==Per approfondimento:== nella libreria <new.h> c'è una funzione chiamata set_new_handler() che mi permette di gestire il comportamento del codice nel caso new fallisse).

Quando non servono più, gli oggetti dinamici possono **essere distrutti** attraverso l'**operatore delete**. 

L'**operatore delete** ha come argomento un **puntatore all'oggetto da distruggere**.

In caso ci si dimenticasse di chiamarlo, tutti gli oggetti dinamici verrebbero distrutti al termine del programma.

==Nota:== Posso usare l'operatore **delete** puntando solo ad oggetti **creati mediante l'operatore new** o **a puntatori nulli** (per quanto superfluo.) --> Se non si dovesse rispettare la cosa, verrebbe segnalato a tempo di esecuzione l'errore riscontrato 

**Sintassi di new e delete:**

var = new tipo(espressione); // ==Nota:== L'espressione non deve MAI essere un aggregato.

delete var; 

**Usare new e delete per l'allocazione di array:**

L'**allocazione** di un array avviene così:

tipoArr* nomeArr; int dim=dimensione;

nomeArr = new tipoArr $[dimensione]$; //new restituisce il **primo elemento dell'array**.

Per accedere agli elementi di un array dinamico possiamo :
- Usare l'aritmetica degli indirizzi : $*$(p+i)
- Usare la notazione dell'indice : p$[i]$

La **deallocazione** invece:

delete$[]$ pi;

In questa maniera possiamo implementare : [[le liste]].

