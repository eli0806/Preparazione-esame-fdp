Un **puntatore** o **puntatore ad oggetto** è un tipo derivato che **ha per valore l'indirizzo** di un altro oggetto o di una funzione.

Ne esistono di due tipi:
1) I puntatori ad oggetti.
2) I puntatori a funzioni

==Nota:== A differenza dei [[riferimenti]], l'**indirizzo del puntatore** e dell'**indirizzo puntato** sono **diversi**.

Il **tipo dell'oggetto o della funzione** a cui il puntatore punta determina il **tipo del puntatore**.

1) I puntatori ad oggetti.

Come abbiamo visto nei [[riferimenti]], anche nel caso dei **puntatori** abbiamo una **dichiarazione** e una **definizione, contestuali** (ossia **non separabili**) seguono la sintassi:

tipo var = valoreVar;
tipo* pun = &var; //Dove l'inizializzazione può avvenire in un secondo momento rispetto alla dichiarazione e definizione del puntatore.

==Nota:== Le sintassi **tipo* pun** e **tipo  * pun** sono equivalenti.

==Note:== E' possibile avere **più puntatori nella stessa definizione** ma ciò può generare **ambiguità** quindi è fortemente sconsigliato.

L'indirizzo associato ad un puntatore può essere modificato (tranne se definiamo il puntatore come **puntatore costante**, e il suo aggiornamento avviene così:

pun=&nuovaVar;

Invece se vogliamo modificare il valore che è contenuto dalla cella puntata ci è necessario scrivere:

$*$pun = nuovoValore; --> Questa operazione prende il nome di **deferenziamento**.

Inoltre è possibile assegnare alla variabile un puntatore, così:

var = $*$ pun;

Possiamo schematizzare **le operazioni possibili**:

- Il **deferenziamento** attraverso l'operatore detto **di indirezione** -->Mi permette di accedere al valore della variabile a cui il puntatore punta .

  ==Nota:== Possiamo utilizzare l'operatore di indirezione talvolta ci trovassimo a lavorare su un indirizzo. Quindi è lecito avere espressioni tali * pun = * &i; o * &i=valore.
  
- L'**indirizzo** attraverso l'operatore **indirizzo** . --> Mi restituisce **l’indirizzo di memoria** della variabile puntata.
- I **confronti** di **uguaglianza** e **disuguaglianza** ( == , != ). --> I confronti possono avvenire **tra un puntatore e un indirizzo**:

  pun== &var;
  
  O tra **due puntatori**:

  pun == pun2;


Anche i puntatori possono **essere definiti costanti** e la loro dichiarazione/definizione avviene così:

tipo* const  =&var;

Se decidiamo di **rendere costante un puntatore** dobbiamo ricordarci che **è assolutamente necessario inizializzarlo subito e il suo indirizzo associato non può essere mai modificato.**

I **puntatori definiti costanti** non sono però da confondere con i puntatori che puntano ad oggetti non modificabili (appunto costanti). In questo secondo caso **non  è necessario inizializzare il puntatore** in quanto ad essere costante è solo il valore all'interno dell'indirizzo puntato.
La loro definizione avviene così:

const tipo* pun;

==Nota:== I puntatori che puntano ad oggetti costanti non è detto che puntino effettivamente a costanti, la propria non modificabilità talvolta è limitata all'uso del singolo puntatore al fine di garantire [[information hiding]]!
Infatti, non essendo il puntatore ma il valore ad essere costante noi possiamo cambiare indirizzo a cui il puntatore è associato.

==Nota:== E' assolutamente errato assegnare ad un puntatore ad oggetti non costanti un puntatore ad oggetti costanti, perché esso perderebbe la sua non modificabilità. Ma con <const_cast> (vedere [[conversioni esplicite]] ) sarebbe possibile, poiché stiamo convertendo un puntatore ad oggetti costanti ad un puntatore ad oggetti non costanti. 

E' inoltre possibile avere **puntatori di puntatori** (ossia puntatori verso l'indirizzo di un altro puntatore) e questi seguono la sintassi:

tipo** pun=&pun1;

**Possiamo realizzare puntatori nulli? Magari per usarli inseguito?

Ovvio, è possibile realizzare un **puntatore nullo** assegnando ad esso **nullptr**!
I puntatori nulli **non puntano a nessun oggetto** e di conseguenza non possono essere **né deferenziati , né generalmente usati.**

==Nota:== L'operatore di uscita "<<" può essere anche usato con un puntatore e restituisce il valore indirizzo da esso puntato.

Se volessimo stampare invece il valore contenuto nell'indirizzo dovremmo usare anche l'operatore di deferenziazione.
Così insomma:

1) cout<< pun; //Mi restiutisce l'indirizzo puntato dal puntatore pun 
2) cout<< * pun; //Mi restituisce il valore contenuto nell'indirizzo a cui pun punta.


**I puntatori a void** 

I **puntatori a void** sono dei particolari puntatori che sono stati ideati al fine di poter assegnare ad un puntatore **oggetti di più tipi diversi**.

**Com'è possibile?**

E' possibile attraverso l'uso delle [[conversioni implicite]] e delle [[conversioni esplicite]] (usando lo **static_cast**).

==Nota:== Posso assegnare un puntatore ad un puntatore a void **ma non posso assolutamente** assegnare un puntatore a void ad un normale puntatore.

==Nota:== Prime di deferenziare devo sempre aver svolto prima la conversione.

La **sintassi** del puntatore a void è la seguente :

tipo* pun1;
void* pun;
pun=pun1; //Caso in cui la conversione è implicita ( da void a tipo)
$*$ static_cast < tipo*> (pun) = ValoreDelTipoDiPun1 //caso in cui la conversione è esplicita (da void a tipo)

(e si ripete così per ogni nuovo tipo/valore che associamo al puntatore).











