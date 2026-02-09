
Linguaggio --> **Sintassi + semantica** --> Le risolviamo con un **metalinguaggio.** 

Il **metalinguaggio del c++** deriva dal **linguaggio naturale** (ossia il nostro parlato), reso **non ambiguo** ( altrimenti non sarebbe possibile la traduzione degli algoritmi (vedere  [[Algoritmi]])).

Nello specifico segue il **formalismo** che prende il nome di [[BNF(Backus-Naur Form)]] e che ci permetterà di comprendere la **struttura** dei vari operatori che incontreremo nel linguaggio.

Inoltre sappiamo che segue una **semplificazione sintattica del linguaggio inglese.**

**La semplificazione sintattica dipende da regole.**

Una **regola** **descrive** una categoria sintattica, utilizzando altre **categorie sintattiche, costrutti di metalinguaggio ,simboli terminali.**

![[Schema metalinguaggio.png]]
==Nota:== Una **sintassi corretta non implica** una **semantica corretta!**

Più nello specifico **i programmi in c++** si possono comporre con i seguenti elementi:
- **I token** : Sono sequenze di parole.
- **I white space**: Sono le **spaziature.** 
Esse sono indispensabili per **separare più elementi** e inoltre garantiscono la **leggibilità di un programma** .
==Nota:== Per **leggibilità** di un programma si intende **la chiarezza a livello visivo** di un programma, la sua **mancanza** non impatta in nessun modo sul codice interpretato dal compilatore, **ma può causare confusione al programmatore** o ai colleghi che lavorano allo stesso progetto.
- **I commenti:** I commenti sono frasi che il programmatore scrive per **spiegare porzioni di codice** o semplicemente per **prendere appunti** sullo stesso. Essi **non modificano** in alcun modo il programma e sono **delimitati** da **\\** se il commento occupa **una sola linea**, altrimenti \* ...* \ se **multilinea**.

Gli elementi lessicali del c++ sono:
- **Gli identificatori:** Sono **i nomi delle entità istanziate dal programmatore** (come le variabili ad esempio). 
==Nota:== Il c++ è un linguaggio **case sensitive** e perciò riconosce la **differenza** tra lettere **maiuscole** e **minuscole**.
==Nota:== Il carattere "-" ( sottolineatura) è una lettera e rappresenta lo spazio nel processo di definizione ( dove gli spazi non sono ammessi ).
==Nota:== La doppia sottolineatura " - -" è sconsigliata perché usata nelle implementazioni e nelle librerie.
- **Le keyword (parole chiave):** Le keyword sono **parole inglesi definite dal linguaggio** e il cui significato **non è modificabile dal programmatore** ( ad esempio if, else, while ...)
- **Le espressioni letterali:** Le **espressioni letterali** servono a **denotare costanti** ( definite dal programmatore) all'interno del codice.
  Esse possono essere composte da caratteri, stringhe, numeri interi o numeri reali.
  I **caratteri** sono **delimitati da apici (' ')** e tra loro possiamo notare dei caratteri particolari che prendono il nome di **sequenze di escape** ( come '\n' usato per andare a capo).
 ![[Tabella caratteri di escape.png]]
 I **numeri interi** invece vengono rappresentati da un **segno** seguito da una **sequenza di numeri** che seguono la **base scelta** per la loro rappresentazione (vedere [[Rappresentazione dei numeri naturali]] per il discorso delle basi di rappresentazione). Se essa non dovesse essere definita dal programmatore sarà di **default 10**.
 Se si vuole definire un **intero in esadecimale** troveremo i **caratteri 0x / 0X** ( che riconteremo anche nella stampa degli indirizzi ).
 - **Gli operatori:** Gli **operatori** sono **caratteri o combinazioni di caratteri** che servono a **denotare operazioni** ( come +, - , ma anche new e delete).
   Ogni operatore ha delle proprietà:
   1) La **posizione** : Un operatore può essere **prefisso o postfisso** rispetto ad una variabile ( o meglio un **operando**). Se **prefisso** l'operazione **modifica subito la variabile**, invece, se **postfisso** **usa la variabile e poi esegue la modifica** su di essa.
   2) Il numero di operandi: Alcune operazioni , come quelle di controllo o quelle logiche hanno bisogno di più operandi per funzionare.
   3) La **precedenza**: è l'**ordine di priorità** con cui vengono **svolte le operazioni**. Solitamente segue quella aritmetica (Può essere utile vedere [[espressioni]], [[Ordine operazioni pt,1.png]] e [[Ordine operazioni pt.2.png]] .
   4) **L'associatività:** **E' l'ordine con cui vengono svolte operazioni con operatore di pari priorità.** Può essere **a sinistra** ( quindi priorità da sinistra a destra) o **a destra** (da destra a sinistra).
   (Può essere utile vedere [[espressioni]], la [[Regola del cortocircuito]] e [[Ordine operazioni pt,1.png]], [[Ordine operazioni pt.2.png]]  )

==Nota:== Anche la **virgola** è un **operatore** e permette di **svolgere più espressioni contemporaneamente.**

 - **I separatori:** I **separatori** sono **simboli di interpunzione** che **delimitano un istruzione** (ad esempio ; indica il termine di un istruzione sequenziale oppure , separa due elementi ...)
 
Ne segue lo schema di operatori ( in alto) e separatori (in basso): 
  ![[Operatori e separatori.png]]