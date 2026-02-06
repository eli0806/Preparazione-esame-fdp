Una **libreria** è un insieme di [[funzioni]] precompilate.
Esse si compongono di due file:
- **Il file header** --> La sua estenzione è **.h** e contiene **la definizione** delle funzioni.
- **il file di compilazione delle funzioni**

Noi le includiamo all'interno del programma principale (**main.cpp**) scrivendo # include   
< nomeLib.h > o **se il file header è nella stessa cartella del main.cpp** # include "NomeLib.h".

**Librerie utili:**
- < cmath> -> Contiene le funzioni matematiche più usate.
- < cstlib> -> Contiene tutte le funzioni che permettono di generare un numero casuale. (srand)
