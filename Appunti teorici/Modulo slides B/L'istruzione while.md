L'**istruzione while** ci permette, **fino al verificarsi di una condizione di controllo**, l'esecuzione **ricorsiva** di una **sequenza di istruzioni**.

Segue la **sintassi**:

**while** ( condizione){
	 ...codice ;
}

In particolare, **l'istruzione while valuta**, per prima cosa, **una condizione di controllo**.  
Se essa **risulta verificata** già in partenza, **non si accede mai al blocco di istruzioni racchiuso tra le parentesi graffe**, altrimenti, il blocco viene eseguito.  
Al **termine della prima esecuzione del blocco**, la **condizione** viene **nuovamente rivalutata** e, se **non risulta ancora verificata**, **si reitera l’esecuzione del blocco** di istruzioni.

==Nota:== E' possibile anche avere **una definizione** all'interno della condizione dell'istruzione while ma la variabile lì definita potrà essere utilizzata **solamente nel codice** che viene eseguito prima del verificarsi della condizione.
Inoltre ogni volta che il codice viene reiterato, la **variabile viene ridefinita** con un nuovo valore e la possiamo considerare come **una nuova variabile**.

==Nota:== Per convenzione è più comodo ma non necessario usare i separatori { }  dopo il while ma è necessario ricordare che le istruzioni che ne compaiono all'interno **non sono soggette a restrizioni**.

==Nota:== Possiamo dare vita ad un ciclo infinito scrivendo 
**while** (true){
	codice;
}


