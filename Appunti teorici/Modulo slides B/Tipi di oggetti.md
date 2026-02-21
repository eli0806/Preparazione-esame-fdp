Il **tipo di un oggetto** assume un importanza notevole all'interno del linguaggio c++.
Esso è **individuato da** due entità:
1) Un **insieme di valori**: prendono il nome di **elementi** o **costanti** del tipo .
2) Un insieme di operazioni definite sui suoi elementi. --> Insomma il dominio visto negli ([[Algoritmi]])
E viene specificato attraverso una **dichiarazione**.

Una **dichiarazione** crea un **entità non associata** dal compilatore a **locazioni di memoria** .
E' una dichiarazione ad esempio se scrivo :

int a ; // Ho creato un oggetto variabile di tipo intero di nome a .

Se assegnassi inoltre un valore all'oggetto che ho creato (che sia costante o no ) allora si tratta, invece, di una definizione.

Una definizione crea un **entità** che il compilatore **associa ad una o più locazioni di memoria** o fa riferimento ad azioni eseguibili tali le  [[funzioni]] .

I tipi di oggetti si dividono in due grandi famiglie:
- [[I tipi fondamentali]]
- [[I tipi derivati]]

I tipi però non sono **limitanti** e possiamo eseguire delle espressioni che ne contengano di diversi 
(ad esempio sommare un double ad un intero, il cui risultato sarà, per garantire maggior precisione un double). 
Ma per far si che questo avvenga ci rifacciamo alle **conversioni** (possibili perché il c++ **NON** è un **linguaggio tipizzato** e perciò presenta una discreta flessibilità).
Le **conversioni** trasformano un valore espresso secondo una **determinata rappresentazione** nello stesso valore ma espresso con **diversa rappresentazione**.
Esse posso essere:
- [[conversioni implicite]]
- [[conversioni esplicite]]

Inoltre il **c++** ci permette di **definire oggetti costanti** , ossia oggetti che non potranno **mai** essere modificati in fase di esecuzione (grazie al controllo del compilatore).

**Come?** 

Scrivendo la keyword **const** prima di un tipo seguito da un **inizializzatore** (sempre richiesto).Gli **oggetti costanti** prendono il nome di **costanti con nome** .

==Nota:== La variabile costante va inizializzata SUBITO ! (Altrimenti ci ritroveremmo con un valore casuale e non ci sarà possibile avere il nostro valore significativo).