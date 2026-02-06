Un **effetto collaterale** (side effect) è **qualsiasi modifica allo stato esterno alla funzione**, cioè a qualcosa che **non è una sua variabile locale**.  
In pratica, la funzione **cambia qualcosa al di fuori del proprio scope**.

Possiamo trovare gli effetti collaterali quando:

- Passiamo per riferimento dei valori.
- Abbiamo un puntatore.
- Usiamo variabili condivise.
- Usiamo variabili globali.

Nel caso del **passaggio per riferimento**, la funzione lavora direttamente sull’oggetto originale, quindi ogni modifica è immediatamente visibile all’esterno.  
Con i **puntatori** il meccanismo è analogo: dereferenziando il puntatore si accede alla stessa memoria dell’oggetto chiamante, quindi anche qui si generano effetti collaterali.  
La differenza è che il riferimento è più “sicuro” (non può essere nullo) e più leggibile, mentre il puntatore è più flessibile ma richiede maggiore attenzione.

==Nota:== È comunque preferibile usare funzioni **pure** (senza effetti collaterali) quando possibile, perché rendono più chiaro il flusso delle informazioni.

In conclusione, la scelta di un meccanismo rispetto a un altro dipende sempre dalla leggibilità del codice.  
Il **passaggio per riferimento** è particolarmente adatto, ad esempio, all’operatore <<, perché per ordine degli operatori l’oggetto viene valutato prima, non si fanno copie inutili e la sintassi rimane più pulita.