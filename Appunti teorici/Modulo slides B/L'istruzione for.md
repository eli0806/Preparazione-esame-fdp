L'**istruzione for** ci permette di **rieseguire un blocco di istruzioni un numero definito di volte**.

Essa presenta la seguente **sintassi:**

**for**( inizializzazione ; condizione ; step){
	codice;
}

Analizziamo ora le parti che compongono questa istruzione singolarmente:
1)  L'**inizializzazione** è un istruzione che **inizializza una variabile di controllo** (che potremmo utilizzare solo all'interno del ciclo for). Spesso la troviamo sottoforma di definizione-inizializzazione (ossia ad esempio int i=0). Essa è **la prima istruzione ad essere eseguita** nel ciclo e **viene eseguita una volta sola** ossia **all'inizio di tutta l'istruzione**.
2) La **condizione** è un istruzione rappresentata da **un'espressione** (contenente la variabile che abbiamo precedentemente inizializzato) con un risultato **di tipo booleano** (ossia ad esempio i<10, il quale risultato può essere solamente vero o falso) e ha il compito di definire il limite del nostro ciclo for.
3) Lo **step** è un istruzione che **"aggiorna"** il valore della variabile del ciclo (ossia quella che abbiamo inizializzato). Essa viene anche chiamata **passo** e solitamente la troviamo sottoforma di **incremento** o **decremento**. E' **l'ultima istruzione ad essere eseguita** e segue al **corpo del ciclo for** (Ovviamente al termine della ricorsione dell'istruzione, non del ciclo intero).

Il ciclo for **termina definitivamente** quando **la condizione definita** è verificata.

Il corpo del **for** insieme allo **step** prendono il nome di **corpo esteso** del for, questo nel caso  non venga eseguita l'inizializzazione.

==Nota:== Possiamo omettere **l'inizializzazione** se questa è già avvenuta **prima dell'esecuzione del ciclo**. Ciò comporterebbe che  la variabile inizializzata possa essere utilizzata anche all'esterno del blocco relativo al ciclo for.

==Nota:== Possiamo omettere **il passo** , ma solo nel caso esso  sia definito all'interno del corpo del ciclo for.

==Nota:== La **condizione** può anche mancare , ciò rende il ciclo un ciclo infinito.
Infatti come abbiamo visto per [[L'istruzione while]] , anche il ciclo for ha una sorta di "while true" , che si scrive con seguente sintassi :

for( ; ; )

==Nota:== Se abbiamo fatto l'inizializzazione all'interno del ciclo for, per il concetto di [[visibilità]] , potremmo riutilizzarla in altri cicli che vengono seguiti al termine di quello dove è stata inizializzata.

