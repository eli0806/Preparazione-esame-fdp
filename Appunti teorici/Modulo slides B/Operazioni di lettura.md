L'**operazione di lettura** avviene attraverso lo **stream di ingresso** cin.
I dati che cin prende in input vengono **inseriti solitamente dalla tastiera del terminale** ma non si esclude un possibile inserimento da file memorizzati sulla memoria di massa ( per windows di tipo txt, vedere [[input e output da file]]).
L'operazione avviene attraverso un **puntatore** (vedere [[puntatori]]) che punta alla prima casella di un **buffer** (ossia una  zona di memoria temporanea) e segue la **seguente sintassi**:

cin >> nomeVar;
per i file: leggi.exe<file.in;

Ed è la composizione di due azioni sequenziali:
1) Il prelievo della sequenza di caratteri con sintassi **coerente al dominio** del tipo della variabile richiesta.
2) Un'**eventuale conversione** per adattare il dato alla variabile (vedere [[conversioni implicite]])

==Nota:== Con il solo cin **non è possibile l'inserimento degli spazi**, per ovviare al problema si usa la funzione:

**cin.get**(variabile);

Insomma però a livello di memoria, come avviene questa operazione?

Il puntatore scorre tutto lo stream, ignorando eventuali spazi iniziali, fin quando trova caratteri **coerenti al dominio del tipo**.

==Nota:== Se ad esempio, avessimo uno spazio (non iniziale) poi seguito da una sequenza di numeri, questa verrebbe ignorata dallo stream.

Inoltre il corpo dell'istruzione di lettura è costituito da un espressione di lettura e **ha un risultato** rappresentato **dall'indirizzo dello stream coinvolto.**

==Nota:== Se usiamo **lo stesso stream** possiamo **combinare più operazioni di lettura**

**come?**

cin>> Var1 >> Var2

==Nota:== Durante l'esecuzione **il programma rimane in attesa** se l'utente non inserisce nessun tipo di input.
All'utente è data la possibilità di monitorare il proprio inserimento attraverso l'eco del terminale e l'input diventerà definito solo quando sarà definito il tasto di ritorno carrello ( ossia il tasto enter).

**Cosa succede se l'input inserito non rispecchia il dominio della variabile ?**

Se l'input non rispecchia il dominio della variabile, l'operazione di prelievo non ha luogo e lo stream assume **uno stato d'errore**.

Per gestire gli errori nello stream di ingresso possiamo usare **2 funzioni** predefinite dal c++:
1) **cin.clear()** --> Questa funzione mi permette di resettare lo stato d'errore e di conseguenza di reinserire l'input precedentemente errato. --> Insomma è **una funzione di ripristino**.
2) **cin.fail()** -->E' una funzione di tipo booleano che è vera solo quando è in uno stato di errore   ( compreso l'input della marca di fine stream) e serve per controllare e limitare l'input.
   Ciò non significa che correggerà l'errore.

Ora che abbiamo visto come funziona l'operazione di lettura in generale possiamo concentrarci sui vari tipi di input:
1) **L'inserimento del tipo carattere** avviene così:
==se il carattere contenuto nella casella selezionata dal puntatore non è uno spazio bianco:==
- viene prelevato
- viene assegnato alla variabile c
- il puntatore si sposta sulla casella successiva
==se il carattere contenuto nella casella selezionata dal puntatore è uno spazio bianco:==
- viene ignorato
- il puntatore si sposta sulla casella successiva, e così via, **finché non viene letto un carattere che non sia uno spazio bianco.**
2) **L'inserimento del tipo intero** avviene così:
- il puntatore si sposta da una casella alla successiva fintanto che trova **caratteri consistenti con la sintassi delle costanti intere**, saltando eventuali spazi bianchi in testa, e **si ferma sul primo carattere non previsto dalla sintassi stessa**.
- il numero intero corrispondente alla **sequenza di caratteri letti viene assegnato alla variabile i.**
3) **L'inserimento del tipo reale** avviene così:
   - il puntatore si sposta **da una casella alla successiva fintanto che trova caratteri consistenti con la sintassi delle costanti reali**, saltando eventuali spazi bianchi in testa, **e si ferma sul primo carattere non previsto dalla sintassi stessa**
   - il numero reale corrispondente alla **sequenza di caratteri letti viene assegnato alla variabile f**
