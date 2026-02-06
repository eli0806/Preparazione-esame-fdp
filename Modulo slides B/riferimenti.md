Un **riferimento** è **un identificatore** che individua **l'indirizzo** di un oggetto --> Insomma assegniamo ad un oggetto nuovi nomi o **alias**.

Quando usiamo i riferimenti ci rifacciamo al processo di **aliacing** appunto.

==Nota:== Il nome di un oggetto è il riferimento per default ad esso.

Come per ogni tipo di oggetto abbiamo una **dichiarazione** e una **definizione**, ma in questo caso sono **contestuali** (ossia **non separabili**) seguono la sintassi:

tipo& NomeDelRiferimento = nomeOggettoRiferito; //La & ci permette di identificare che stiamo istanziando un riferimento e **non** un nuovo oggetto.

==Nota:== L'**indirizzo dell'oggetto** e quello del **nuovo oggetto riferimento** sono **gli stessi**.

==Nota:== Il riferimento che istanziamo deve essere dello stesso tipo dell'oggetto a cui andiamo a riferire .

E' inoltre possibile **creare un riferimento ad un riferimento** e avviene così:

tipo var1;
tipo& rif=var1;
tipo& rif2=rif;

**Perché posso farlo?** 
Perché il riferimento non è un riferimento ad un nome significativo ma piuttosto all'indirizzo di memoria dove è stata inizializzata la variabile di riferimento default ( e così tutte le derivate).

I riferimenti possono avvenire anche per **oggetti definiti costanti** e seguono la sintassi:

const  tipo& nomeRiferimento = variabileRiferita.

Una volta istanziato il riferimento costante **non può più essere modificato** e ogni tentativo di farlo rappresenta **un errore**.

==Nota:== E' possibile riferire ad oggetti **non costanti** con riferimenti **costanti**, al fine di gestire meglio le operazioni che possiamo svolgere su un determinato oggetto (garantendo [[information hiding]], ma al contrario per creare un riferimento ad un oggetto costante **è assolutamente necessario che anche il riferimento sia costante**.

Bisogna fare però attenzione, la scrittura int& nomeRiferimento la possiamo trovare **solo come  left-value** di un operazione di assegnamento (vedere [[Operazione di assegnamento]] ).

==Note:== E' possibile avere **più riferimenti nella stessa definizione** ma ciò può generare **ambiguità** quindi è fortemente sconsigliato.

==Nota:== Gli **oggetti riferiti** verranno modificati tutti **indipendentemente dal nome** ma non verrà modificato mai il tipo fondamentale (int, bool, double...) e la loro stampa sarà sempre coerente alla modifica applicata .

**Dove troviamo in maniera pratica i riferimenti?**

In maniera pratica il **tipo riferimento** è usato principalmente come argomento o risultato di una funzione (vedere [[funzioni]]).




