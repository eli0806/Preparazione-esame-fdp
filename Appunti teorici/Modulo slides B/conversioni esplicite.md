Le **conversioni esplicite** sono quelle che **il programmatore** richiede quando le ritiene più necessarie.

Per eseguire una **conversione esplicita** abbiamo a disposizione ++cinque operatori:**
- Il **cast**. (deriva del linguaggio C )
- Il **const_cast**
- La **notazione funzionale**. (deriva dal linguaggio C)
- Lo **static_cast**.
- Il **reinterpret_cast**.

Il **cast** segue la forma :

(int) numero reale  ; // Questa conversione ci permette di forzare il numero reale che abbiamo scritto alla sua rappresentazione nella forma intera.

Il **const_cast**, non esegue una conversione propria **di tipo** ma piuttosto serve a **rendere costante** o **rimuovere il fatto di essere una costante di** una variabile. La sua sintassi è la seguente: 

const_cast< tipo >(espressione)

e lo possiamo usare anche con [[i puntatori]].

con seguente sintassi:
const_cast<tipo*>(puntatore_costante)

Invece, la **notazione funzionale** :

int numero reale; //Funziona pressoché allo stesso modo della conversione che abbiamo visto per il cast.

Lo **static_cast** , meno ambiguo e più spesso usato in ambito professionale :

static_cast < int > numero reale; //  Dove int , indicato tra parentesi angolari e indica **il tipo di arrivo**.

Esso ha due utilizzi :
1) **indicare esplicitamente** una conversione che altrimenti sarebbe stata **implicita**. (in caso di conversioni con perdita dell'ordine di grandezza).
2) **effettuare ulteriori conversioni di tipo** quando ne abbiamo già un'altra contraria (Ad esempio mantenere un int , quando ad un intero abbiamo un double assegnato).

Più l'utilizzo bonus nel caso dell'effettuazione di una **conversione prevista tra quelle implicite** ma che **non sarebbe avvenuta** se non l'avessimo esplicitata noi. (ad esempio nel caso di un risutato di un espressione).

Infine il **reinterpret_cat** ci permette **qualsiasi tipo di conversione** e lavora **a livello dei singoli bit**. La sua sintassi è:

reinterpret_cast < nuovo_tipo > (espressione);

e lo possiamo usare anche con [[i puntatori]].