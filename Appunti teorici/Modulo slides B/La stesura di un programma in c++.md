Un programma c++ si compone generalmente di un insieme di [[funzioni]] ( che possaimo trovare su più file , vedere [[Concetto di collegamento]]).

La **funzione indispensabile** per la stesura del programma è il programma **main** (dall'inglese, *principale*).
In essa troviamo eventuali collegamenti ad altre funzione esterne ( vedere [[Le librerie]] ) e soprattutto un **flusso logico** di operazioni **in ordine sequenziale** ma che possono comprendere [[istruzioni di salto]].
Il **main restituisce un intero** per eseguire il **controllo degli errori** sul flusso di dati:
Se esso è **0**, il nostro **codice** è **corretto** , **altrimenti** verrà restituito il **numero dell'errore** a cui siamo venuti incontro. 

==Nota:== Se non troviamo l'istruzione **return** riceveremo un messaggio di errore poiché essa implica la **terminazione della funzione** .

Le operazioni in un codice c++ sono:
- **Le dichiarazioni di tipo** (vedere[[Tipi di oggetti]] )
- **Le definizioni di variabili** ( e di variabili **costanti**)  (vedere[[Tipi di oggetti]] )
- Le [[espressioni]]
- Le [[istruzioni strutturate]]
- Le [[istruzioni di salto]] 
- Le [[istruzioni etichettate]] 

==Nota:== **ogni simbolo introdotto dal programmatore** deve essere **dichiarato e definito** prima dell'utilizzo.