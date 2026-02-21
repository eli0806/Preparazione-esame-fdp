In c++ un **oggetto** è  un **gruppo di celle consecutive** che vengono **considerate** dal programmatore **come un’unica cella informativa**.

Le **celle** sono **partizioni di memoria** solitamente di **un byte** di dimensione, sono individuate ciascuna da un **indirizzo univoco specifico** e hanno un **determinato contenuto.**

Ora che conosciamo le celle possiamo dire che **un oggetto ha come indirizzo quello della prima cella occupata** e come **contenuto il valore dell'insieme delle celle** che occupa.

![[Oggetto in memoria.png]]
Ogni **oggetto**:
- è **identificato da un nome** ( o un identificatore) che **rappresenta l'indirizzo della prima cella di memoria occupata.**
- Può essere **costante** se non può e non deve essere modificato, oppure **variabile**, altrimenti.
==Nota:== Ad essere **variabile** è solamente **il valore**, l'indirizzo dell'oggetto subisce modifiche solamente in caso di chiusura e riapertura del programma ( altrimenti rimane intoccato).
- Ha un tipo ( vedere [[Tipi di oggetti]]).

**Come posso accedere all'indirizzo di un oggetto?**

All'indirizzo di un oggetto posso accedere **anteponendo il simbolo "&"** al **nome** dell'oggetto.



