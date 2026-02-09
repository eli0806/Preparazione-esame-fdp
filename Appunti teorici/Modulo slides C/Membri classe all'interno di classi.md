Abbiamo detto in [[classi]] che possiamo avere una classe secondaria come membro di una classe.

==Nota:== Classe **primaria** e **secondaria** devono essere **forzatamente diverse**.

Dichiarazione di un oggetto della classe principale --> Si attiva il costruttore di **tutte le classi coinvolte** ( ossia delle classi annidate).--> Ordine dei costruttori:
1) Costruttori delle classi secondarie. --> In ordine di apparizione nella dichiarazione della classe.
2) Corpo del costruttore principale (qualora fosse definito).

==Nota:== Il corpo del costruttore principale **DEVE** essere definito nel caso **le classi secondarie** necessitino di parametri formali.

Se classe secondaria ha costruttore di default --> Vengono richiamati.

Tutte le classi secondarie hanno costruttore di default --> costruttore della classe principale=costruttore di default o assenze.

Vogliamo distruggere un oggetto della classe principale --> Si attivano i distruttori di tutte le classi secondarie in ordine inverso alla loro apparizione --> infine il corpo del distruttore della classe principale.