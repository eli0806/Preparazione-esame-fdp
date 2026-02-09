I preprocessori vengono invocati per fare il pre-processing --> Interpretazione di testo al quale il compilatore non attua controllo sintattico/lessicale

Il ruolo del processore è quello di risolvere tutte le istruzioni che iniziano per # e si chiamano **direttive del preprocessore**.

Un esempio ne è la funzione # include

Il preprocessore può anche **espandere i simboli definiti dall'utente secondo le loro definizioni** e **includere o escludere parti** del codice che verrà compilato.

Possiamo includere file anche non nella stessa cartella del file sorgente ma **dobbiamo specificare il percorso.**

**sintassi:** # include "c:\ .................."

**Definizione di un nuovo simbolo**

La **sintassi** di questa operazione è : # define  NomeSimbolo;

Possiamo anche assegnare un valore al nuovo simbolo però è **opzionale**.

Ci permette di estendere il linguaggio donandogli sintassi nuove . 

![[nuovo simbolo.png]]

**Macro** -> Equivalenti alle funzioni inline ma relative al pre-processore 

![[Macro.png]]

Nella chiamata di funzione scompare  ((a>b)? (a) : (b)) e viene definito solo max e i relativi dati che gli vogliamo assegnare

Conviene isolare max è metterlo tra parentesi per ottenere il risultato desiderato.

Abbiamo anche il costrutto if-else nel preprocessore : --> si tratta di **compilazione condizionale**
- .# if
- .# elif -> sta per else if
-  .# else
-  .# endif

La compilazione condizionale è usata per usare i comandi appropriati per i relativi sistemi operativi o per evitare la ripetizione di inclusioni.

$#$ ifndef è una direttiva che equivale a alla contratta di # if ! defined ( che significa **se questo simbolo non è stato definitio**).