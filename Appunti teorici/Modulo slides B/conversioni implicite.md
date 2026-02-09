Le **conversioni implicite** sono conversioni **messe in atto dal compilatore** e possono avvenire anche **consecutivamente**.
Solitamente esse avvengono per tutti **i tipi aritmetici** ( vedere [[I tipi fondamentali]]).
Difatti sono:
- Quelle tra **interi di diversa lunghezza**  (ad esempio uno short int convertito in un long int)
- Quelle tra **reali di diversa lunghezza** (ad esempio un double normale convertito in un long double)
- Quelle tra **interi** e **reali**
- Quelle che trasformano **valori booleani, caratteri** (tipo char) e variabili di **tipo enumeratore** in valori **interi.**
- Quelle che trasformano un valore **intero** in un **carattere**  (tipo char) .

Si chiamano **promotion**, le conversioni che avvengono **da rappresentazioni di lunghezza minore a rappresentazioni di lunghezza maggiore** e **non si ha una perdita di informazioni.**

**Non si ha perdita di informazioni** neanche nel caso di una conversione da **intero** a **reale** poiché l'ordine di grandezza degli itneri è minore di quello dei reali .

In caso opposto, abbiamo **perdita di informazioni** nel caso di conversioni da **intero** a **carattere** o **da rappresentazioni di lunghezza maggiore a rappresentazioni di lunghezza minore**.

C'è da aprire una parentesi anche sulla conversione **da reali a interi** poiché avverrebbe un **arrotondamento** essendo che i **reali** sono rappresentati in **forma approssimata** mentre gli interi in **forma esatta**. --> Abbiamo dunque una perdita sia di **ordine di grandezza** che un **troncamento della parte frazionaria.**

==Nota:== Se è prevista la perdita di informazioni, il tipo di conversione è fortemente sconsigliato.

Per gli **operatori binari** invece abbiamo che :
- Per operandi **entrambi interi** o **entrambi reali di lunghezze diverse** , viene convertito **l'operando di lunghezza minore** nella **grandezza** dell'**operando di grandezza maggiore.**
- Per operandi **uno intero** e **uno reale**, l'**operando intero** viene convertito in **tipo reale** e il loro risultato sarà, appunto, **un reale**.

Le **conversioni implicite** le troviamo anche quando **assegniamo una variabile  ad un altra** ( vedi[[Operazione di assegnamento ]]) e possiamo :
- Assegnare ad  **una variabile intera** un valore **reale** **e viceversa**.
- Assegnare ad **una variabile di tipo intero** un valore **booleano, char o enumerazione**.
==Nota:== **Non è possibile**, invece, assegnare ad una **variabile booleana** o **enumerazione** un valore **intero**.
- Assegnare ad **una variabile di tipo carattere** un valore **intero, booleano** o **enumerazione**.

Ne segue uno schema che riassume le possibili conversioni implicite che possiamo trovare nell'affrontare un'espressione all'interno del nostro codice.
![[Schema contenente alcune conversioni implicite nei casi di espressioni.png]]