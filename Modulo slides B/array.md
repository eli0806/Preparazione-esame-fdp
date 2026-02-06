Un **array** è una **struttura dati a dimensione fissa**, contenente elementi **omogenei** (tutti dello stesso tipo), memorizzati in posizioni **contigue** di memoria.
Ogni elemento è accessibile tramite un **indice**,  che ne determina la **posizione**.

La **dichiarazione** e la **definizione** di un array sono contestuali e la loro sintassi è:

tipo nomeArray $[dimensioneArray]$;

==Nota:== La dimensione dell'array deve essere un valore costante ( che sia una variabile definita const int oppure un numero).

==Nota:== In alcuni casi non è necessario definire la dimensione dell'array nella dichiarazione/definizione, ma che vengano inizializzati dal primo momento i valori contenuti nelle varie celle dell'array. 

tipo nomeArray{ val1, val2 ...};

==Nota:== E' possibile definire più array nella stessa definizione.

tipo arr1$[n]$,  arr2$[n2]$, arr3$[n3]$;

Gli array possono anche essere **definiti costanti**. In tal caso è necessario inizializzarli subito e i valori inseriti nelle varie celle non potranno essere modificati.
La loro definizione avviene così:

const tipo arr$[2]$ = {val1,val2,val3};

**Operazioni sugli array**
Sugli array in generale non possiamo svolgere le stesse operazioni che applichiamo ai tipi fondamentali, sui singoli elementi che li compongono sì.
Infatti l'unica operazione possibile su un array è **la selezione con indice** che si occupa di selezionare **i singoli elementi che lo compongono** e su cui poi lavoreremo.
La sua sintassi è :

nomeArray$[indice]$;

==Nota:==  Le posizioni di un array sono numerate da 0 a dim-1.

==Nota:== Essendo che il compilatore **non svolge controlli sugli indici** potremmo riscontrare errori logici nel caso in ci sia stato inserito un indice negativo o superiore a dim-1. In tal caso in una cella di memoria di cui non abbiamo controllo (non facente parte dell'array) verrà inserito un nuovo valore (casuale). --> undefined behavior

Gli array si classificano secondo **il numero di dimensioni su cui operano**:
- Gli array comunemente usati, del primo tipo, vengono chiamati anche **vettori** e operano su una sola dimensione.
- Gli array multidimensionali, chiamati anche **matrici** si compongono di un insieme di array del primo tipo e operano su dimensioni da 2 a n.

Negli array multidimensionali gli elementi sono memorizzati **per righe** infatti possiamo avere:

int mat$[nRighe][nColonne]$ ={1, 2, 3, 4, 5, 6};

e la memorizzazione avviene :

mat$[0][0]$ =1;
mat$[0][1]$ =2;
mat$[0][2]$ =3;
mat$[1][0]$ =4;
mat$[1][1]$ =5;
mat$[1][2]$ =6;

Una matrice può essere inizializzata:

int mat$[nRighe][nColonne]$={{1,2,3} , {4,5,6}};

inoltre, in questa fase possiamo omettere la prima dimensione e scrivere:
int mat$[][nColonne]$ ={1, 2, 3, 4, 5, 6};

==Note:== Scrivendo la notazione mat$[i]$ otteniamo la riga con indice i.


**Come stampiamo una matrice?**

Esempio di funzione stampaMatrice:

void stampaMatrice(int M[][3], int R){  //La prima dimensione verrà ignorata e avremmo M$[*][3].$
--> Quindi ci è necessario passare il numero di righe.
int* p=&m1$[0][0]$; //E' il valore della prima posizione della prima riga --> Primo indirizzo allocato in memoria dell'array (==Ricordiamo che gli array sono memorizzati in celle consecutive nello stack di memoria==) --> Stiamo trattando la matrice come **un array un monodimensionale:**
for(int j=0;j<$nRighe*Ncolonne$;++j){ //La dimensione di tutta la matrice è data dal prodotto delle due dimensioni 
    cout<<$*(p+j)$<<" "; posizione j della riga p
  }
}

**Le dimensioni** si ottengono **dall'argomento**.

==Nota:== Il tipo della **dimensione delle righe** è **diverso da quello delle colonne** : il **primo** rappresenta un **puntatore** passato per **riferimento** , il **secondo un intero**
definibile all'interno delle parentesi dell'argomento della funzione.

**Il tipo di appoggio è l'indirizzo della variabile intera.**

Tra gli array troviamo anche le [[cstringhe]].



cout<<*(p + r*c1 + c)<<" "; --> Questa è la formuletta che ci permette di accedere all'elemento [r][c]

! Il nostro prezzo da pagare è non poter usare più la notazione [r][c] e l'uso di un solo slot per entrambe le dimensioni.

! La notazione int mat [][] non è ammessa se non abbiamo argomenti nella seconda dimensione ( che significherebbe avere una costante come numero di colonne ).

Inoltre gli array possono essere: 
- **Ordinati** attraverso gli [[algoritmi di ordinamento]].
- **Dinamici** ( vedere [[La memoria dinamica]] )