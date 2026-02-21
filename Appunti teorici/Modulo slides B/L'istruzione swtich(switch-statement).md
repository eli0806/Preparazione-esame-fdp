**L'istruzione if (if-statement) valuta un valore discreto** (come ad esempio un determinato **intero** o un determinato **carattere**) di una condizione ed esegue il codice ad esso correlato.

==Nota:== Al posto del valore discreto potremmo avere **la definizione di una variabile inizializzata** con **un espressione**. In questo caso viene valutato il valore della variabile ed essa è definita solo all'interno dello switch-body.

Segue la **sintassi**:

**switch** (condizione){
	 **case** val1:
		 ...codice
		 **break**; //Il flusso del programma salta al di fuori del costrutto
	**case** val2:
		 **break**;
	**default**:
	//E' il **caso in cui non si verifichino le altre condizioni;**
	**break**;
}

==Nota:== I **case** di un istruzione di controllo **switch** sono **cumulabili**.
Cosa intendo per cumulabili?
Che posso mettere più case uno di seguito all'altro (case 1: case 2: ... codice) e assegnare ad essi **lo stesso blocco di istruzioni** .

esempio:

switch (numero) {
        case 1: case 2: case 3:   // tutti questi casi portano allo stesso blocco
             cout << ì"numero piccolo " << endl;
            break;
}

Si notino le **3 componenti** di questa **istruzione condizionale**:
1) La parola chiave **switch** che contiene e valuta la condizione a cui segue **il corpo dello switch** (switch body).
2) La parola chiave **case** (in questa casistica si parla di switch-label) seguita dal **valore discreto** che rappresenta il risultato della condizione ( che può essere anche una variabile), a cui poi segue il blocco di codice correlato.
   Il case è **un espressione costante.**
   Tra i case troviamo inoltre il blocco di **default** , il cui codice viene eseguito solo **in caso nessuno degli altri casi sia verificato.**
   ==Nota:== Il caso default può anche essere omesso se non si desidera gestire l'eventualità in cui lo necessitiamo, altrimenti sarà sempre **il blocco terminale** dello switch-body.
   ==Nota:== Anche se sconsigliato possiamo avere dei case vuoti!
3) La parola chiave **break** ci permette di delimitare ogni caso e di interrompere lo swtich-body quando la nostra condizione è verificata. La sua omissione ci farebbe scorrere il resto dello switch-body.
   Quest'ultima affermazione ci fa capire che lo switch non si comporterebbe come da noi aspettato, ma può essere utile nel caso di **fall-through** volontario.
   ==Nota:== Per **fall-throught** si intende il costrutto per cui **il flusso continua nei case successivi.** Questo può essere usato intenzionalmente **per raggruppare più valori nello stesso blocco**.
   ==Nota:== Il **break** non è necessario **nell'ultima istruzione dell'ultima alternativa**.  
   ==Nota:== Il **break** può **essere sostituito con return** nei casi il programmatore desideri la **restituizione di un valore legato all'alternativa**. (Si noti che stiamo comunque lavorando all'interno di **istruzioni complesse** e quindi in parte a se stanti).

Un buon uso dello switch-statement può essere quello di aprire alla lettura/scrittura di oggetti di tipo enumerazione.