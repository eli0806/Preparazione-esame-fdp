Per **funzione di un programma** si intende **una sequenza di istruzioni del codice** (insomma un sottoprogramma)  che rappresenta **un modulo autonomo** dal codice principale (vedere[[modulazione di un programma c++]] ).

==Nota:== Tra le **funzioni** troviamo anche la funzione **int main()** , che rappresenta **la funzione principale del nostro codice** e che contiene tutti i collegamenti alle altre funzioni.

Spesso si implementano in due dei seguenti casi:
1) Nel nostro codice si ripresenta più volte quella determinata sequenza di istruzioni, a maggior ragione con operandi diversi.
2) Al fine dell' [[astrazione funzionale]].

Ogni funzione ( a parte la funzione int main()) si compone di tre parti distinte:
- **La dichiarazione** di una funzione **specifica il nome, il tipo dei parametri necessari** (detti **argomenti formali** ) e il **tipo di valore che restituisce**. --> Costituisce la creazione di un tipo a partire da quelli fondamentali.--> I valori associati sono tutti funzioni.
  Essa segue la **sintassi**:

  TipoDiRitorno nomeFunzione (...tipo1, ....tipo2); 

Il **tipo di ritorno** e il **nome della funzione** fanno parte dell' **intestazione della definizione**, mentre **l'insieme degli argomenti formali** del **corpo della definizione**:

==Nota:== I parametri non sono sempre necessari per l'esecuzione di una funzione e posso essere talvolta omessi o sosituiti con la keyword void. --> E' il caso delle **funzioni senza argomenti formali**.

==Nota:== E' possibile avere funzioni che non hanno il ritorno di un valore, il tipo di quelle funzioni si chiama **void**  (procedure in altri linguaggi).

==Nota:== La dichiarazione con seguente sintassi si trova spesso nell'header ( vedi [[Le librerie]]) di un programma c++

- **La definizione** di una funzione consiste nel codice che essa deve eseguire, insomma il corpo della stessa.
  Essa segue la **sintassi**:

TipoDiRitorno nomeFunzione (...tipo1 param1, ....tipo2 param2){
	// corpo della funzione
	return ...;
}

==Nota:== Se abbiamo una funzione di tipo void possiamo omettere il return o altrimenti scrivere return;

==Nota:== Solitamente troviamo la definizione di una funzione in un file sorgente separato dal main (vedere [[modulazione di un programma c++]]) 

==Nota:== Solitamente nei programmi più semplici troviamo che la definizione coincida con la dichiarazione e avvenga nello stesso file del main.cpp

- **La chiamata** ( o **il designatore**) di una funzione **può avvenire** in **altre funzioni** ma solitamente all'interno della funzione **main** e serve a "lanciare" l'esecuzione della stessa.
  Essa segue la **sintassi**:

  nomeFunzione(arg1,arg2....);

  Dove gli argomenti prendono il nome di **argomenti attuali** e rappresentano il valore che assumeranno i **parametri formali** che abbiamo preparato nella definizione.
  
==Nota:== Gli **argomenti attuali** devono **sempre** essere:
- lo stesso numero dei **parametri formali**
- Nello stesso ordine dei **parametri formali**
- Dello stesso tipo dei **parametri formali**

==Nota:== Le dichiarazioni degli argomenti formali posso avere degli inizializzatori, questi sono **i valori di default** degli argomenti.
Essi rappresentano i valori che vengono inseriti negli argomenti formali della chiamata di funzione nel caso il rispettivo argomento attuale venisse omesso.

==Nota:== Se si sceglie di assegnare un valore di default solo ad alcuni parametri formali essi devono essere posizionati per ultimi.

**Come li assegnamo?**

tipoFun nomeFun (tipo var, tipo 2 var2, tipo3 var3=valore, tipo4 var4=val2)

==Nota:== Se abbiamo dei valori di default non dobbiamo omettere per forza tutti i parametri che li contengono, ma in tal caso dobbiamo posizionare questi per ultimi comunque.

Andiamo ora ad analizzare nello specifico i **parametri formali** e gli **argomenti attuali**.

Un **parametro formale** ( o **contenitore**) è **un oggetto istanziato in memoria inizializzato con il valore del corrispettivo argomento attuale** ( che cambia **per ogni diversa chiamata di funzione**).

**Il suo nome rappresenta l'indirizzo del contenitore.**

Abbiamo **2 tipi** di argomenti formali:
1) Gli argomenti **passati per valore**: Se ho un argomento passato per valore, a cambiare è solo il valore presente all'interno del contenitore e non si ha nessuna ripercussione sulle entità del codice. 
   Insomma se scegliamo di passare un argomento **per valore** noi lavoriamo **su una copia del valore**. 
   ==Nota:== Possiamo avere anche un puntatore come argomento formale, per valore.
   Esso inoltre può essere anche ad oggetti costanti (vedere [[puntatori]]) e abbiamo che l'argomento attuale non è necessario che sia costante.
2) Gli argomenti **passati per riferimento:** Se ho un argomento passato per riferimento, il valore del contenitore è associato all'indirizzo (che si tratti di [[riferimenti]] o [[puntatori]] o riferimenti di puntatori(forma tipo*& pun)) e l'entità (riferita o puntata) subisce modifiche.
   Insomma se scegliamo di passare un argomento **per riferimento** noi lavoriamo **sul valore stesso**.

==Nota:== Possiamo avere anche argomenti formali **definiti costanti** che la funzione **non può modificare**. A livello di assegnamento dei **valori attuali** mediante la chiamata di funzione in corrispondenza di questi oggetti possiamo avere **sia una costante** che una **variabile non costante**.
Si tratta del concetto di [[information hiding]].

==Nota:== Non è possibile avere due funzioni con lo stesso nome e gli stessi parametri con la sola differenza del passaggio per riferimento o valore, poiché il compilatore non è capace di distinguerle.

Un **argomento attuale** è **un espressione che produce risultato dello stesso tipo del corrispettivo parametro formale** (escluse le conversioni di tipo).

Quando andiamo a definire **variabili** ( o anche gli stessi **argomenti formali**) in una funzione , esse sono **locali** secondo il concetto della [[visibilità]].

**Cosa si intende per variabile locale?**

Per **variabile locale** si intende una variabile **definita all’interno della funzione** in cui compare.  
Essa viene **allocata in memoria al momento della chiamata della funzione** e **deallocata al termine della sua esecuzione**. Inoltre può essere utilizzata esclusivamente all’interno del corpo della funzione stessa.

==Nota:== È possibile dichiarare variabili con lo stesso nome in funzioni diverse, poiché ciascuna è locale alla propria funzione. Il compilatore le considera quindi **variabili distinte**, ciascuna associata a un **indirizzo di memoria diverso**.

Per il concetto di località delle funzioni possiamo dire che **ad ogni chiamata** vengono ricreate e successivamente distrutte sia le variabili locali sia i parametri formali. Di conseguenza, i valori assegnati non persistono tra esecuzioni successive della funzione.

==Nota:== Quando restituiamo un valore con la funzione esso può essere anche **un riferimento** ( vedere [[riferimenti]]) indicando **return** 

int& f() {
    return x;   // restituisco un alias di x
}

o **un puntatore** (vedere [[puntatori]]).
int* g() {
    return ...;
}

Per restituire un puntatore a oggetti costanti a partire da un puntatore non costante è necessaria una conversione esplicita con const_cast <$*$ tipo>.

==Nota:== Il **riferimento restituito**  è preferibile che non sia a variabili locali della funzione o ad argomenti formali.

Tra le funzioni abbiamo delle funzioni particolari:
- **Le funzioni ricorsive:** Le funzioni ricorsive sono funzioni che **invocano se stesse durante la propria esecuzione**.

  La **sintassi** di questo tipo di funzioni è:

TipoRestituito nomeFunzione (parametri){
    //**Caso base** 
	if(condizione ...){ // ci permette di terminare la ricorsione della funzione 
		return risultato;
	//**Passo ricorsivo**
	}else{
	     return nomeFunzione(nuovoPar) ... eventuale espressione aggiuntiva;
	}
}

==Nota:== Nelle funzioni ricorsive possiamo avere **più casi base**, ogni caso base è legato ad una condizione che permetta di terminare la ricorsione della funzione.
Così **valido anche per i passi**: a seconda della condizione possiamo avere più passi ricorsivi differenti.
Quello specificato in questi appunti è il caso più semplice

==Nota:== La **chiamata delle funzioni ricorsive** a se stesse e la **loro esecuzione** avvengono in maniera inversa: la prima funzione ad essere chiamata sarà l'ultima ad essere restituita!
![[Funzioni ricorsive schema.png]]

==Nota:== Abbiamo una singola definizione che da vita a diverse istanze ! 
Ciò significa che abbiamo **tante variabili omonime** ma che hanno un **indirizzo in memoria e un valore contenuto diverso** , insomma lavoriamo su una copia della variabile anche se essa rimane memorizzata( e deallocata solo quando la funzione ricorsiva termina).
**Ogni variabile fa riferimento solo e solamente alla ricorsione in cui viene allocata**.
Ed un esempio di funzione ricorsiva può essere:

**fattoriale:** n->n(n-1)(n-2)...1

fattoriale (n) = {1 se n == 0              n* fattoriale (n-1) se n>0

int fattoriale (int n){
	if(n == 0){
		return 1;
	}else{
	    return n* fattoriale (n-1);
	}
}

int main(){
	int n=fattoriale(3);
	 return 0;

}

quando abbiamo fattoriale(1) abbiamo l'ultima esecuzione della funzione.

Il modo di operare delle funzioni ricorsive è parallelo a quello delle computazioni iterative.

Per computazione iterativa si intende quella in cui rieseguo un blocco di istruzioni con un valore diverso nella variabile di controllo 

Le funzioni ricorsive però presentano due svantaggi importanti: 
- consumo maggiore di memoria
- prestazioni inferiori

Ma sono più semplici da implementare e limitano il rischio di commettere errori.

- **Le funzioni inline:** Le funzioni inline sono funzioni dove il corpo della funzione si sostituisce alla chiamata della funzione stessa.

Segue la **sintassi**:

**inline** tipoRitorno nomeFunzione (parametro){
	//corpo della funzione
}

**Non tutte le funzioni possono essere definite come funzioni inline.:**
- Se una funzione è troppo grossa, il fatto di renderla inline causerebbe **code bloat** (ossia appesantirebbe troppo tutto il programma ) e di conseguenza avremmo un calo delle prestazioni della funzione.
- Se una funzione contiene cicli.

Il rendere le funzioni inline presenta notevoli vantaggi perché si evita:
- Il salvataggio dell'indirizzo dell'istruzione da eseguire una volta terminata la funzione
- Il passaggio dei parametri
- Il salto all'indirizzo della funzione chiamata 
- La creazione dello stack frame
- Il ritorno al chiamante

Un esempio pratico di funzione inline può essere: 

$#$ include < iostream >
using namespace std;

// Funzione inline: calcola il quadrato di un numero
inline int quadrato(int x) {
    return x * x;
}

int main() {
    int a = 5;
    int b = 10;

    cout << "Quadrato di " << a << " = " << quadrato(a) << endl;
    cout << "Quadrato di " << b << " = " << quadrato(b) << endl;

    return 0;
}

==Nota:== La keyword **inline non obbliga** il compilatore a sostituire la chiamata con il corpo della funzione. Essa rappresenta soltanto un **suggerimento di ottimizzazione**: il compilatore può decidere di ignorarlo e trattare la funzione come una normale funzione.

**Le funzioni come argomento formale di un altra funzione:**

Abbiamo specificato, all'inizio della spiegazione che la dichiarazione di una funzione genera la creazione di un nuovo tipo funzione.
A seguito di questo possiamo notare allora che è possibile **avere una funzione come argomento formale di un'altra funzione.**
La più esterna prende il nome di **funzione principale**, quella usata come argomento è **la funzione secondaria.** --> La funzione secondaria all'interno della principale è composta dall'identificatore (il proprio nome) e contiene l'indirizzo della funzione secondaria.

La **definizione** di una funzione del seguente tipo avviene così:

tipoFun nomeFun ( tipoFunSec funSec (argomenti funSec), tipoVar var1, tipoVar var2){
	...//codice;
	funSec(arg);
}

[[I puntatori a funzioni]]

**L'overloading delle funzioni:**

Per **overloading** si intende avere **più funzioni con lo stesso nome ( o identificatore)ma con diversi parametri formali**.

==Nota:== Un argomento formale può anche differire solo per l'attributo const.

**Come facciamo a distinguerle?**

Le funzioni di questo tipo si distinguono per **numero e tipo di argomenti formali.**
==Eventuale approfondimento:==

La libreria **< stdlib.h >** offre una funzione che termina l'intero programma se invocata in una qualsiasi funzione, questa funzione è **la funzione exit().**
La **funzione exit() chiude qualsiasi istanza in esecuzione** del programma e svuota i vari buffer. **Restituisce** , inoltre, **un valore intero a seconda della presenza di errori o no** ( 0 se programma corretto, altri numeri altrimenti).
Il valore intero restituito si chiama **valore di stato.**
Qualsiasi istruzione successiva all'invocazione di exit() **non viene eseguita**.
