**L'istruzione if (if-statement) valuta il risultato booleano** di una condizione e esegue la parte di codice corrispondente.

Segue la **sintassi**:

**if (condizione)** then (allora) **... codice** ; 
//Caso in cui abbiamo solo il caso in cui la condizione sia verificata --> viene eseguito il codice scritto dopo la condizione (dove ho indicato then).

**if (condizione)** then (allora) ... codice **else** ...codiceAltern  ; 
//Caso in cui abbiamo sia la gestione della condizione verificata sia il caso contrario. --> viene eseguito il codice scritto dopo la condizione (dove ho inidicato then) in caso affermativo, altrimenti quello dopo la parola chiave else.

==Nota:== Le **condizioni** ( quella **dopo then** e quella **dopo else**) vengono anche chiamate **corpo della funzione**.

==Nota:== Possiamo avere anche **condizioni aritmetiche** dove troveremo che **il valore falso** sia **0**, **il valore vero** qualsiasi numero **diverso da 0**.

 ==Nota:== E' possibile anche avere **una definizione** all'interno della condizione dell'istruzione if, ma la variabile lì definita potrà essere utilizzata **solamente nel codice** o meglio negli **statement** che seguono o la condizione ( caso vero ) o la keyword **else** (caso falso).

==Nota:== Per convenzione è più comodo ma non necessario usare i separatori { }  dopo l'if-statement ma è necessario ricordare che le istruzioni che ne compaiono all'interno **non sono soggette a restrizioni**.

Ossia le sintassi :

**if (condizione)** then (allora) ... codice **else** 

e
**if(condizione)**{
	... codice
} **else**{
 ..codice
}

**sono equivalenti** tranne in casi in cui abbiamo **due if annidati**.

Allora in quel caso i separatori { } sono **assolutamente necessari** per gestire **a quale dei due blocchi** di condizione (interno ed esterno) si riferisce una clausola **else**.

Ricordo inoltre che nel caso della **prima notazione** vista , le operazioni seguono **l'associatività da sinistra**.

==Nota:== Lo **statement-if** ha valore equivalente all'espressione con operatore di condizione ( vedere [[espressioni]] ).