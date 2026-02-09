Come citato in [[Operazioni di scrittura]] e [[Operazioni di lettura]] , è possibile utilizzare file memorizzati su una memoria di massa (che chiamiamo file-stream) per ottenere input ed output per il nostro codice.
Tutto ciò è permesso dalla libreria < fstream.h>.

I **file-stream** seguono la seguente **sintassi**:

**fstream** id1, eventuale id2 , eventuale id3...

I **file-stream** sfruttano la funzione **id.open()** per associarsi ad un file in diverse modalità quali appunto:
- **la lettura** (modalità specificata da **ios::in**) --> Se si apre un flusso con questa modalità, il file da associare **deve essere già stato creato e popolato** coi dati che useremo come input e il puntatore della funzione di lettura punta inizialmente alla prima casella del file-stream.
- **la scrittura** (modalità specificata da **ios::out**) --> Se si apre un flusso con questa modalità, il file se non esiste viene creato e il puntatore della funzione di scrittura punta inizialmente alla prima casella del file-stream.
- **l'append** (ossia la scrittura a fine del file, specificata da **ios::append**)--> Se si apre un flusso con questa modalità, il file se non esiste viene creato e il puntatore della funzione di scrittura punta inizialmente alla fine del file stream (ossia alla cella della marca di fine stream).

E presenta la seguente **sintassi**:

id.open("nomeFile.txt", modalità1);

e **se volessimo sfruttare più modalità contemporaneamente:**

id.open("nomeFile.txt", modalità1 || modalità2);

**Una volta aperto un file-stream è possibile svolgere tutte le operazioni relative agli stream di default** 

**Terminato l'uso del file-stream** esso si chiude mediante la funzione **id.close()**.

Se dimenticassimo di chiudere un file-stream, questo verrebbe chiuso comunque al termine del programma.

==Nota:== Un file-stream chiuso **può essere riaperto** con **stessa o differente** modalità.

==Nota:== Gli errori vengono gestiti così come li gestiremmo nell'operazione cin ([[Operazioni di lettura]])



