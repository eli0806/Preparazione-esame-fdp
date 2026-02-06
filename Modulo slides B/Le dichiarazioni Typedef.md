I **nomi typedef** sono **identificatori** utilizzati per riferirsi ai tipi in **fase di dichiarazione**.

Essi hanno la seguente **sintassi**:

typedef tipoRiferito oggettoDiTipoRIferito;

Esempi:

struct comp {double re, im; };

typedef comp$*$ pcomp;

typedef int v$[3]$;

typedef int ($*$tp)$[3]$;

typedef int* ff(int);

e possono essere utilizzati così:

pcomp pz; --> pcomp diventa pz

v a1, a2$[5]$; -->int v$[3]$ diventa a1 e a2 $[5][3]$

tp arp; --> tp diventa arp

ff fun; --> ff diventa fun

Insomma abbiamo capito che **le dichiarazioni tipedef NON creano nuovi tipi** bensì possiamo considerarle più come "ridenominazioni" dei tipi.

Esse sono molto utili soprattutto **per riferirsi ai tipi complessi** come gli array di puntatori.

Le definizioni typedef sono utili anche per favorire l’[[astrazione funzionale]]. Se, ad esempio, volessimo modificare il tipo di un insieme di variabili tutte dello stesso tipo, l’uso di typedef ci permetterebbe di farlo intervenendo unicamente sulla dichiarazione del typedef, senza dover aggiornare ogni singola variabile nel codice.