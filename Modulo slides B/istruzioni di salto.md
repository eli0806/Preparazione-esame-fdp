Le **istruzioni di salto interrompono il flusso lineare del programma** e spostano il controllo dell’esecuzione **verso un’altra istruzione specificata**. In questo modo **il programma** non segue più l’ordine naturale delle istruzioni, ma **“salta” direttamente a un punto diverso del codice**(precedente o successivo).
Tra queste troviamo:
- L’istruzione **break**, usata tipicamente **all’interno dei cicli o delle istruzioni di controllo** come lo **switch**, **interrompe immediatamente l’esecuzione del blocco in cui si trova**. Quando viene incontrata, il programma esce dal ciclo o dallo switch e **prosegue con l’istruzione successiva al blocco terminato**.
- L'istruzione **continue** può essere usata **solo** all'interno del **corpo di un ciclo** o di uno **switch** Quando viene incontrata, il programma **passa all'istruzione di controllo del ciclo**. Essa si applica solo alle **singole iterazioni** e **non al ciclo completo**.  
  Se il corpo del ciclo fosse composto da istruzioni strutturate, l'istruzione **continue** provocherebbe comunque il salto **verso l'istruzione finale del ciclo**, riprendendo poi la nuova iterazione.

==Nota:== Come abbiamo visto in [[L'istruzione swtich(switch-statement)]] , non è importante mettere il break finale. Ora possiamo dire che esso può essere sostituito anche dall'istruzione continue. 
Da notare però che si fa riferimento solo e solo all'ultimo caso... se mettessimo continue negli altri casi lo switch procederebbe con i case successivi.

- Le [[istruzioni etichettate]]
- L'**istruzione return** ci permette di terminare l'esecuzione di una funzione. 
  Solitamente restituisce un valore del tipo della funzione stessa o può essere anche vuota nel caso di funzioni void. (vedere [[funzioni]]).

==Nota:== Se usiamo un return al termine di un'istruzione if (sia che la condizione si verifichi o no) , il codice successivo ad esso non verrà eseguito e la funzione/il programma terminerà.
Stessa cosa vale se usiamo uno switch.