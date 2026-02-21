I **tipi fondamentali** (o **aritmetici**) definiscono **informazioni semplici** e si dividono in due categorie:
1) **I tipi predefiniti:** si chiamano così perché **definiti dal compilatore** e **non modificabili.**
2) **I tipi enumerazione**: vengono **definiti dal programmatore**.

Tra i **tipi predefiniti** troviamo:
- **Int** : il tipo **intero** --> E' detto anche tipo **numerico** o tipo **discreto.**
- **Unsigned Int** : il tipo **naturale** (spesso possiamo trovarlo nella forma int numero U).
- **Double** ( o **float**, meno preciso ): i tipi **reali**  --> E' detto anche tipo **numerico**
- **Bool:** il tipo **booleano** --> E' detto anche tipo **discreto**.
- **Char**: il tipo **carattere** --> E' detto anche tipo **discreto.**

Nello specifico del **tipo intero** possiamo dire che:

Il tipo intero definisce **oggetti numerici la cui rappresentazione** ( vedere [[Rappresentazione dei numeri interi]] ) avviene su **16** (**short**), **32**  o **64** (**long**) **bit**

Le **operazioni** che possiamo svolgere su questo tipo sono:
- **Assegnazione:** E' la **modifica del valore sulla variabile** e segue una delle seguenti sintassi:
1) **s=j;**  // La variabile s prende il valore della variabile j.
2) **s(j);**  // La variabile s prende il valore della variabile j.
- **Meno unario** : cambia il segno al numero.
- **Somma**
- **Sottrazione**
- **Moltiplicazione**
- **Divisione (/)** ( non comprende il resto e rimane nei termini di numeri **interi**) 
==Nota:== Se abbiamo la **divisione** tra due numeri di **stesso segno**, il quoziente è arrotondato al **valore assoluto minore,** altrimenti al **maggiore**.
- **Modulo** (**%**): E' il **resto della divisione** (anche questo rimane nei termini dei numeri **interi**)
- **Condizione di egualità ( = = )** : E' un **operatore di confronto** ( o meglio di **relazione**) che considera due valori interi e **controlla se sono uguali.**
- **Condizione di diversità ( != ):** E' un **operatore di confronto** ( o meglio di **relazione**) che considera due valori interi e **controlla se sono diversi.**
- **Condizione di maggioranza (> se strettamente  maggiore, >= altrimenti):**  E' un **operatore di confronto** che controlla se un valore intero è maggiore di un altro.
- **Condizione di minoranza (< se strettamente minore, <= altrimenti):**  E' un **operatore di confronto** che controlla se un valore intero è minore di un altro.
Quelle che abbiamo definito come **operazioni di confronto** non producono un **risultato** intero bensì **booleano** a seconda che la condizione da loro definita si verifichi o no ( quindi **true** se **verificata**, **false** altrimenti).

Nello specifico del **tipo naturale** possiamo dire che:

A definire il tipo naturale sono le parole **unsigned int** ( che possiamo definire già così oppure scrivendo **int** U e poi il numero , per la rappresentazione vedere [[Rappresentazione dei numeri naturali]] .
Come per gli interi esistono anche le versioni **short (US) (16 bit )** e **long (UL) (64 bit).**
Le **operazioni** che possiamo svolgere su questo tipo (operazioni di **basso livello**, perché lavorano sulle **configurazioni di bit** ), chiamate anche **operazioni bit a bit sono:**
- **Assegnazione**
- **Or  bit a bit (|):** Questo operatore **confronta** se **almeno uno dei due bit** ( tra il **numero** e una **machera**) in **posizione i** (  i come indice, perché scorre una rappresentazione binaria del numero naturale) **è  1** , e **restituisce 1** in caso **affermativo,** **0** altrimenti.
![[Schema or bit a bit con maschera.png]]
- **And bit a bit(&):** Questo operatore **confronta** se **entrambi i bit** ( tra il **numero** e una
  **maschera**) in **posizione i** (  i come indice, perché scorre una rappresentazione binaria del numero naturale) **sono 1** , e **restituisce 1** in caso **affermativo,** **0** altrimenti.
![[Schema and bit a bit con maschera.png]]
- **Or esclusivo bit a bit (^):** Questo operatore **confronta** se **uno e un solo bit** ( tra il **numero** e una **machera**) in **posizione i** (  i come indice, perché scorre una rappresentazione binaria del numero naturale) **è 1** , se **entrambi** i bit fossero **1** **oppure nessuno dei due** fosse 1 **restituirebbe 0**, **altrimenti** restituisce **1** .
![[Schema xor ( or esclusivo) bit a bit.png]]
- **Complemento bit a bit (~):** Questo operatore **inverte il valore dei bit** del numero reale su cui stiamo lavorando. (Insomma funziona come l'operatore logico **not** ).
- **Traslazione a sinistra(<<):** Questo operatore **sposta il valore in posizione i nella 
  posizione i-n ( dove n numero di posizioni definito dal programmatore).**
==Nota:== Il **bit più significativo** (ossia quello più a sinistra), usando questo operatore verrà **perso** e sostituito con 0! 
- **Traslazione a destra (>>):** Questo operatore **sposta il valore in posizione i nella 
  posizione i+n( dove n numero di posizioni definito dal programmatore).**
==Nota:== Il **bit meno significativo** (ossia quello più a destra), usando questo operatore verrà **perso** e sostituito con 0! 

==Nota:== Potremmo **usare anche le operazioni** viste per gli **interi** ma è **sconveniente** operare sui **due tipi** nella **stessa espressione.**

Ne segue del codice riassuntivo delle operazioni:
$#$include< iostream >
using namespace std;

int main() {
    unsigned int a = 6;   // 110
    unsigned int b = 3;   // 011

    cout << "a & b  = " << (a & b)  << endl;   // AND
    cout << "a | b  = " << (a | b)  << endl;   // OR
    cout << "a ^ b  = " << (a ^ b)  << endl;   // XOR
    cout << "~a     = " << (~a)     << endl;   // NOT

    cout << "a << 1 = " << (a << 1) << endl;   // shift sinistra
    cout << "a >> 1 = " << (a >> 1) << endl;   // shift destra

    // Operatori di assegnazione
    unsigned int x = 5;   // 101
    x &= 3;               // x = x & 3
    cout << "x &= 3  → " << x << endl;

    x = 5;
    x |= 3;               // x = x | 3
    cout << "x |= 3  → " << x << endl;

    x = 5;
    x ^= 3;               // x = x ^ 3
    cout << "x ^= 3  → " << x << endl;

    x = 5;
    x <<= 1;              // x = x << 1
    cout << "x <<= 1 → " << x << endl;

    x = 5;
    x >>= 1;              // x = x >> 1
    cout << "x >>= 1 → " << x << endl;

    return 0;
}


Nello specifico dei tipi **reali** possiamo dire che:

A seconda della lunghezza ( numero di bit su cui vengono memorizzate le istanze ) abbiamo a disposizione due tipi:
- Il **float** su 4 byte ( difatti è più spreciso e presenta una possibilità molto più limitata di cifre decimali).
- I **double** su 8 byte (inoltre avremmo anche i **long double** (80-128 byte) molto più precisi dei double)
Entrambi però sfruttano la tecnica della **virgola mobile** ( vedere [[Rappresentazione dei numeri reali]])

La **struttura di dichiarazione** avviene **definendo il tipo** e può avvenire in due modi diversi:
1. **double** f = 1,23e-4 ; //Qui andiamo a definire il numero attraverso la propria notazione scientifica (1,23 * β^4) 
2. **double** f= 4.321; //Qui lo definiamo semplicemente .

Le **operazioni** che possiamo svolgere su questo tipo sono:
- **Assegnazione** 
- **Meno unario**: I**nverte il segno** del numero reale.
- **Somma**
- **Sottrazione**
- **Moltiplicazione**
- **Quoziente della divisione** (Produce un risultato **reale**)
- **Condizione di egualità ( = = )
- **Condizione di diversità ( != )
- **Condizione di maggioranza (> se strettamente  maggiore, >= altrimenti)
- **Condizione di minoranza (< se strettamente minore, <= altrimenti)**
==Nota:== Le ultime **operazioni** sono **di confronto** e funzionano esattamente come quelle del tipo intero.

Nello specifico del **tipo booleano** possiamo dire che:

Ha come **insieme di valori** solo le due costanti **true** (**1**) o **false**(**0**) e la sua **struttura di dichiarazione** è sintatticamente uguale a quella degli interi.
Le **operazioni** che possiamo svolgere su questo tipo sono:
- **Assegnazione**
- **Or logico(||):** Controlla se **almeno una** fra più variabili ( o condizioni) è  **vera**, in caso **affermativo** **stampa "True"**, altrimenti **"False"** --> viene chiamata anche **disgiunzione**
- **And logico(&&):** Controlla se **più variabili** (o condizioni) sono **tutte vere**, in caso **affermativo stampa "True"** , altrimenti **"False"**.
- **Not logico(!):** **Inverte il valore** della variabile.

Nello specifico del **tipo carattere** possiamo dire che:

Ha come **insieme di valori** i **caratteri codificati**  solitamente con il codice ASCII) e il **peso** in memoria di un **singolo byte.**
La sua **struttura di dichiarazione** è sintatticamente uguale a quella degli interi, se non fosse che il valore va messo **tra apici** (' ').
Tra i char,  troviamo dei caratteri particolari che prendono il nome di **sequenze di escape**. 
Ne segue una tabella :
 ![[Tabella caratteri di escape.png]]
Le **operazioni** che possiamo svolgere su questo tipo sono:
- **Assegnazione**
- **Meno unario** : cambia il segno al numero.
- **Somma**
- **Sottrazione**
- **Moltiplicazione**
- **Divisione (/)**: (rimane nei termini dei numeri **interi**)
- **Modulo** (**%**): E' il **resto della divisione** (rimane nei termini dei numeri **interi**)
- **Condizione di egualità ( = = )
- **Condizione di diversità ( != )
- **Condizione di maggioranza (> se strettamente  maggiore, >= altrimenti).**
- **Condizione di minoranza (< se strettamente minore, <= altrimenti)**.
==Nota:== Questo accade perché noi consideriamo i caratteri **non** come carattere ma come numero che lo codifica, e quindi possiamo svolgere **tutte le operazioni degli interi**.
Non per questo però non mancano variabili (esplicitate dal programmatore) come i **signed char** o gli **unsigned char**.

==Appendice(codice esempio )==

int main() {
    char a = 'A';   // Assegnazione (codice ASCII 65)
    char b = 'C';   // Assegnazione (codice ASCII 67)

    // Meno unario (cambia segno al numero)
    cout << "Meno unario: " << -a << endl; // -65

    // Somma
    cout << "Somma: " << (a + b) << endl; // 65 + 67 = 132

    // Sottrazione
    cout << "Sottrazione: " << (b - a) << endl; // 67 - 65 = 2

    // Moltiplicazione
    cout << "Moltiplicazione: " << (a * 2) << endl; // 65 * 2 = 130

    // Divisione intera
    cout << "Divisione: " << (b / 2) << endl; // 67 / 2 = 33

    // Modulo (resto della divisione intera)
    cout << "Modulo: " << (b % 2) << endl; // 67 % 2 = 1

    // Condizione di uguaglianza
    if (a == 'A') {
        cout << "a è uguale a 'A'" << endl;
    }

    // Condizione di diversità
    if (a != b) {
        cout << "a è diverso da b" << endl;
    }

    // Condizione di maggioranza
    if (b > a) {
        cout << "b è strettamente maggiore di a" << endl;
    }
    if (b >= a) {
        cout << "b è maggiore o uguale ad a" << endl;
    }

    // Condizione di minoranza
    if (a < b) {
        cout << "a è strettamente minore di b" << endl;
    }
    if (a <= b) {
        cout << "a è minore o uguale a b" << endl;
    }

    return 0;
}

I tipi **enumerazione** sono composti da **un'insieme di costanti** definite dal programmatore e si usano per **rappresentare** un **numero limitato di valori** associati ad **informazioni non numeriche** ( che prendono il nome di **variabili categoriche**.
La sua **struttura di dichiarazione** è la seguente:

**enum** nomeVariaible  {VaCat1, VaCat2,...,VaCatN};

esempio:
**enum**  Giorni{LUN, MAR ,MER, GIOV,VEN,SAB, DOM}; // è un insieme di categorie letterali da noi definite.

e di **definizione** di un oggetto al seguente:

nomeVariabile = **opt**; //Per opt intendo una delle variabili categoriche che sono state definite quando abbiamo creato l'istanza enumerata .

esempio:
Giorni oggi= MAR. //Il valore deve essere presente all'interno delle categorie.

==Nota== L'**identificatore** che sappiamo essere il nome dell'istanza (vedere [[Generalità del linguaggio c++]]) può mancare, dando vita ad un tipo **anonimo**. Ma in tal caso è **assolutamente necessario** **definire** già in principio **l'oggetto** del tipo enumerato.

Ad **ogni** istanza di tipo enumeratore **è associato un numero intero** ( di default ) che il programmatore può cambiare eseguendo un **override** (sovrascrizione).

L'**ovveride** avviene così:

enum{ vC1=nuovoValInt, vC2=nuovoValInt2,....}; //Alle due variabili categoriche che ho istanziato sto modificando il valore di default (altrimenti 1 e 2) inserendo i due nuovi valori che le definiranno.

==Nota:== Se decidiamo di fare l'override solo su determinate variabili categoriche , il resto di essere rimarrà associato ai propri **valori di default**

==Nota:== Non è ammissibile assegnare ad un intero il valore della variabile categorica (ossia fare l'inverso di ciò che è stato precedentemente spiegato).

==Nota:== Una volta che abbiamo definito un tipo enumeratore **non** possiamo più aggiungere variabili categoriche ad esso.





