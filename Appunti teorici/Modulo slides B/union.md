Le **unioni** sono oggetti simili alle strutture ma con la differenza sostanziale che **tutti i membri sono allocati nella stessa cella di memoria** (vengono sovrapposti).

La dichiarazione e la definizione e la definizione avvengono con la seguente sintassi :

union {tipoMembro membro1; tipoMembro membro2 } nomeUnione;

==Nota:== Se i membri non dovessero essere della stessa dimensione, il compilatore riserva lo spazio in relazione al più grande.

Possiamo notare i vantaggi delle union confrontandole con le struct. Prendiamo ad esempio l'union citata prima, e ne costruiamo una struct identica:

struct { int i; double d; } x; --> Dimensione=32 (dim intero) + 64 (dim double)= 96 
union {int i; double d } y; --> Dimensione=64 --> E' la dimensione del double ossia del membro più grande.

L'inizializzazione di un unione può avvenire in due modi:

- Specificando fra parentesi graffe **il valore del primo membro** della struct:

  union { char c; int i; double f; } a = {' X '};

- Associandola ad **un'altra unione dello stesso tipo**.

**L'accesso ai membri delle unioni** avviene attraverso gli **operatori di selezione**.(vedere [[strutture (o struct)]]).

Può avvenire anche **la copia di un oggetto union esistente** così:

Numero n,m;

m.intero=4;

n=m; // L'union n prende il valore intero di m

==Approfondimento: Le strutture con parti varianti==

Le unioni permettono di definire strutture con **parti varianti**. 

Per **parte variante** si intende un gruppo di membri che dipende da un membro specifico che prende il nome di **discriminante**.

Ad esempio:

enum Tipo { Intero, Reale }; //Possiamo scegliere tra il tipo intero e il tipo reale

struct Sensore {
    Tipo tipo;   // parte fissa: discriminante
    union {      // parte variabile: parti varianti
        int i;       // variante 1
        double d;    // variante 2
    };
};

Il tipo che possiamo scegliere => membro dell'union relativo.

==Nota:== Ogni volta che cambiamo il valore del discriminante dobbiamo modificare ogni membro che corrisponde alla parte variante.

