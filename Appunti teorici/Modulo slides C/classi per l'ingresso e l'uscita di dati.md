In c++, **le librerie di ingresso/uscita** ( come iostream) utilizzano il meccanismo dell'overloading per ridefinire **le operazioni di lettura/scrittura più adeguate**.

Citando iostream, spesso noi usiamo **istream** per l'ingresso e **ostream** per l'uscita:

**Istream**:

![[Istream.png]]

**Ostream:**

![[Ostream.png]]
Ad ogni **stream** è associato **uno stato** --> ios per la classe iostream.

**Un valore di stato** è una configurazione di bit ( i bit di stato), che se vale tutta 0 ci garantise la correttezza dell'informazione.

Per le condizione di errore:
- **bit fail:** Viene posto a 1 ogni volta che si verifica un errore.
- **bit bad:** Viene posto a 0 se l'errore è risolvibile, 1 altrimenti.--> Per errori come l'inserimento di una stringa non coerente al tipo di dati richiesti --> risulterebbe 0 e potrebbe far riaprire la stream.
- **bit eof:** Viene posto a 1 quando si tenta di leggere la marca di fine stream **'\0'** (vedere [[Lo stream]]).

Sono rappresentati da enumeratori nella classe ios, dove abbiamo costanti 1 i bit di stato:
- ios::eofbit
- ios::failbit
- ios::badbit

Otteniamo il valore dello stato con il loro **OR bit a bit**.

O possiamo esaminarli con le funzioni membro cin.eof(), cin.fail() o cin.bad(). => Resitutiscono un valore che equivale al bit esaminato.

Noi possiamo manipolare lo stato di uno stream attraverso **la funzione membro** clear(), che ha per argomento **il nuovo valore di stato** ma di default ha 0.

**Oltre agli errori possiamo controllare** ==**il formato**== **di un valore che si vuole stampare.**

Il **formato** di uscita dei dati dipende da **una serie di parametri** ad esempio:
- La base di numerazione ( veder [[Rappresentazione dell'informazione]])
- Il numero di caratteri per dato.
- Il numero di cifre significative.

==Nota:== Il compilatore ha già dei valori di default per questi parametri ma **il programmatore può ridefinirli**.

**Come?**

Attraverso l'uso dei **manipolatori**.

I **manipolatori** sono **puntatori a funzione definiti dalla libreria < iostream>** .

**Esempi di manipolatori: < iostream>**

- endl --> inserisce '\n' nello stream d'uscita e svuota il buffer
- dec, hex, oct --> Cambiano al base di rappresentazione del numero che ne segue. --> Di default abbiamo dec. --> Hanno effetto anche sulle operazioni di lettura.
- Boolalpha --> Rende booleani valori estratti che altrimenti sarebbero stati numerici

==Nota:== L'effetto di un manipolatore  **rimane invariato finché non viene sostituito da un altro**.

Ma iostream non è l'unica libreria che ci offre manipolatori.

**La libreria < iomanip.h> ha come manipolatori:**

 ![[iomanip.png]]
==Nota:== A differenza degli altri manipolatori, setw() agisce **solo sull'operazione di scrittura successiva.**

**Se volessimo inserire file come input o scrivere su un file come output ci assiste:**

![[fstream.png]]