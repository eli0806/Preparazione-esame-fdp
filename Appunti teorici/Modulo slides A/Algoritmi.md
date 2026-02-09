**Algoritmo**=sequenza precisa e finita di operazioni, comprensibili e perciò **eseguibili da uno strumento informatico**, che portano alla realizzazione di un compito.

Il compito spesso è rappresentato dalla **risoluzione di un problema** ossia dalla produzione di un risultato corretto e concreto a partire da uno o più dati in ingresso ( definiti dal programmatore oppure da input dell'utente).

Gli algoritmi hanno:
1) Un dominio di ingresso --> E' il set di dati che l'algoritmo può prendere in ingresso.
2) Un dominio di uscita --> E' il risultato che il nostro algoritmo può produrre.

Gli algoritmi devono essere **generali :** 
L'esecuzione di un algoritmo deve essere applicabile a più set di dati differenti ma **coerenti**.

**Cosa si intende per coerenti?**

Per set di dati coerenti si fa riferimento ad un insieme di dati che segue ciò che il programma richiede.

Ad esempio se ho un programma che tratta un espressione matematica , il set di dati non può essere composto da stringhe ...


In un algoritmo abbiamo 3 grandi gruppi di operazioni, divise per tipo di esecuzione:
1) **Sequenziali:**  sono singole operazioni e al loro termine si procede con quelle successive.
2) **Condizionali:**  sono operazioni che effettuano il controllo di una condizione e successivamente riportano a parti del codice differenti. Si tratta  delle espressioni di controllo (in c++: if-else, switch).
   Esempio:
   
   Se (if) il numero è positivo stampa P, altrimenti (else) stampa N. --> Espressione di controllo.

3) **Iterative:** Sono operazioni che permettono la ripetizione di blocchi di istruzioni a seconda di una condizione. E' il caso dei cicli ( in c++ : while, for)

   Esempio:
   Mentre (while) il numero inserito è negativo, lo faccio reinserire all'utente -> Ciclo 
   //L'operazione fa reinserire all'utente un numero finché questo non sia positivo (condizione).

Gli algoritmi devono garantire :
1) **Eseguibilità:** indica che l'algoritmo va eseguito in un intervallo di tempo finito.
2) **Non-ambiguità:** indica che le espressioni debbano essere interpretate in uno e in un solo modo dal compilatore.
3) **Finitezza:** indica il numero finito di operazioni che debbano essere eseguite dall'algoritmo.

e hanno due proprietà:
1) **Correttezza:** La correttezza è la capacità di un programma di produrre risultati **corretti.**

   **Cosa si intende per risultato corretto?**
   Per risultato corretto si intende un risultato che, al massimo delle sue possibilità ( quindi trattando di approssimazioni o contesti particolari) riporta un valore ( o una parola) che risolvano il problema proposto.
   
2) **Efficienza:** L'efficienza di un programma rappresenta la sua velocità di esecuzione. 
   Per definirla si usano gli ordini:
   o -> E' l'ordine generale di tempo di esecuzione.
   O -> E' l'ordine di tempo di esecuzione nel caso peggiore.

