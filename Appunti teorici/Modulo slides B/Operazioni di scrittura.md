L'**operazione di scrittura** avviene attraverso lo **stream d'uscita** cout.
I dati che cout  stampa vengono **mostrati solitamente sul terminale** ma non si esclude un possibile prelievo da file memorizzati sulla memoria di massa ( per windows di tipo txt, vedere [[input e output da file]]).

L'operazione di scrittura ha la seguente **sintassi**:

cout << espressione ;
per i file: scrivi.exe>file.out;

Dove **l'espressione** può essere di ogni tipo, dai tipi aritmetici, alle singole variabili, alle stringhe.

==Nota:== Per le espressioni **di tipo booleano** e di **tipo enumerazione** , il valore restituito dall'espressione sarà **sempre convertito in intero**:

Ed è la composizione di due azioni sequenziali:
1) Il calcolo dell'espressione definita dal programmatore e la sua conversione in caratteri.
2) Il trasferimento dei caratteri risultati nelle varie celle della stream d'uscita. 
   Esso avviene dalla prima casella puntata, che abbiamo precedentemente visto essere la marca di fine stream.

==Nota:== Nello stream di uscita l’inserimento dei caratteri avviene in modo **sequenziale** e il puntatore di scrittura avanza sempre verso destra. La **marca di fine stringa** è quindi “fissata” sull’ultima posizione raggiunta, ossia il carattere più a destra della sequenza. 

==Nota:== Se usiamo **lo stesso stream** possiamo **combinare più operazioni di scrittura**

**come?**

cout<< espressione1 << espressione2

Inoltre nello stream di uscita è possibile avere le combinazioni di caratteri( chiamati caratteri di escape) che abbiamo specificato in [[Generalità del linguaggio c++]].

Per andare a capo, durante l'operazione di scrittura abbiamo 2 possibilità:
1) La combinazione di caratteri "\n"
2) La scrittura della keyword **endline**

