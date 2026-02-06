I puntatori posso puntare anche ad **indirizzi di funzioni.** --> Li possiamo trovare in array di puntatori a funzione (magari nell'implementazione di un menù), nelle [[strutture (o struct)]] o nelle[[union]] o come argomento di funzione di un'altra funzione ( vedere [[funzioni]]).

==Nota:== Nel caso di puntatori a funzione come parametro di altre funzioni , possiamo anche sfruttarli come parametro di riferimento. (ossia $*&$pun)
Essi hanno per valore **l'indirizzo delle funzioni** dello specifico tipo e **se deferenziati**(con l'operatore $*$) producono **la chiamata della funzione puntata.**

La **definizione** di un puntatore a funzione avviene con la seguente **sintassi**:

return ($*$nomePun)(arg); --> Dove nomePun=indirizzo della funzione.

Aggiungiamo una particolarità alla chiamata di funzione ( vista nelle [[funzioni]]):

Sappiamo già che nella chiamata di funzione abbiamo **l'identificativo di una funzione** ma talvolta potrebbe occorrerci la **deferenziazione di un puntatore a funzione**.

Questo tipo di chiamata di funzione segue la sintassi:

1) **Con deferenziazione esplicita**

($*$nomePun)(argomenti);

2) **Senza deferenziazione (forma abbreviata)**

nomePun(argomenti);
