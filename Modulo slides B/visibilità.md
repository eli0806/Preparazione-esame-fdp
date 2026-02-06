Un programma **può essere suddiviso in diverse parti, su file diversi, MA collegate tra loro**.

**Come avviene?**

Ciò avviene grazie agli identificatori: --> Vengono verificate dal compilatore!

- delle **regole di visibilità:** Esse agiscono su un singolo file e **determinano le zone del programma dove possiamo riferirci con un determinato identificatore ad una determinata entità.**
  Quindi ci permettono **a più partizioni del programma** di riferirsi **alla stessa entità** oppure ad **impedirne l'accesso.**

  Esse sono basate sul **campo di visibilità** (o scope) ossia **la parte del programma in cui quell'identificatore può essere usato:** --> L'identificatore **è visibile**.

  Tra i **campi di visibilità** in c++ troviamo:

  1)  **I blocchi:** sono sequenze di  istruzioni racchiuse tra { } . Un identificatore **a livello di blocco** è visibile dalla **dichiarazione** fino al termine **del blocco**. 
  
Nel caso di **blocchi annidati** , un identificatore può **essere ridefinito** e rappresenta in realtà **due entità distinte**. --> Insomma il blocco interno "nasconde" quello esterno.
**E' comunque sconsigliato.**
  

**Ecco un esempio di blocco:**

int main(){

//Blocco di istruzioni --> Prende anche il nome di **Stack** (pila) o sofisticazione
	{
			int a=0; // è la mia varabile di blocco
	}
	cout<<a; // mi dà errore poichè la variabile è stata richiamata fuori dal blocco e perciò è già stata deallocata/distrutta
}

L'identificatore dichiarato **in un blocco** ha **visibilità di blocco** o **visibilità locale**.

==Nota:== Anche **le** [[funzioni]] rappresentano un blocco!
Possiamo trovare variabili di blocco inoltre nei casi di [[L'istruzione if (if-statement)]], [[L'istruzione while]]. [[L'istruzione for]], e nelle [[istruzioni etichettate]].
  
  2) **Le unità di compilazione:** sono costituite da **un file sorgente** e  dai file inclusi tramite **#include**. --> Possono essere sia [[Le librerie]] che creati dal programmatore. --> Si tratta di identificatore **a livello file** o **globale**.
  ==Nota:== Nel secondo caso se il file **NON** è nella stessa cartella del file sorgente **va scritto tra " "** altrimenti **tra < >**.
  
  Un identificatore **a livello di file** è visibile dalla **dichiarazione** fino al termine **dell'unità di compilazione**. 

Le variabili definite con questo tipo di visibilità sono **condivise da tutte le funzioni** definite **nel file stesso**. => Le funzioni possono "comunicare tra loro" attraverso queste variabili.

==Nota:== Anche gli identificatori a funzioni **sono dichiarati a livello file**. --> **NON** possiamo avere **funzioni annidate**.

==Nota:== E' possibile escludere porzioni di testo attraverso **direttive di** [[compilazione condizionale]].

**Ecco un esempio di unità di compilazione:** 

//file ff.h --> E' un file in estensione .header (vedere [[Le librerie]]).

... dichiarazioni varie;

//file main.cpp

$#$ include "ff.h"
int main(){
	...variabile dichiarata in ff.h;
}

**E se avessi un identificatore di file uguale ad un identificatore di blocco?

All' **interno del blocco** l'identificatore si **riferisce alla variabile locale**. 
Se ci si vuole riferire alla **dichiarazione globale** dell'identificatore si utilizza **l'operatore** di **risoluzione di visibilità (::)**

**Esempio:**

$#$ include <iostream.h>

int i=3; //Rappresenta la variabile con visibilità **globale**

int main(){
	int i=5;
	cout<<"locale: "<< i <<endl;
	cout<<"globale: "<< ::i <<endl;
}

3) **Gli spazi di nomi:** sono costituiti da **un'insieme di dichiarazioni e definizioni chiusi tra { }** --> introducono **i membri**. 
   Si noti che uno spazio di nomi è **aperto** (alla modifica) ciò ci permette di **ridichiarare lo stesso identificatore** per inserire **nuovi membri**.
   ==Note:== Un **membro** può anche essere **un altro spazio di nomi!**
   Un identificatore **relativo al membro di uno spazio di nomi** è visibile **dal punto in cui è stato dichiarato** fino al termine **dello spazio stesso**. => Se usassimo lo **stesso identificatore** in **spazi di nomi diverso** esso riferirebbe **a due entità distinte**.

**Esempio:**

namespace nome{
	struct st {
		int a;
		double d;
	}
	int n;
	void ff(int a){
		// ...
	}
}


   Se voglio **rendere visibile** un identificatore **di un membro** contenuto nello spazio di nomi devo usare **l'operatore** di **risoluzione di visibilità (::)** sull'identificatore **dello spazio di nomi**.

   ==Nota:== Se ci riferiamo spesso ad uno spazio di nomi --> Possiamo usare la direttiva **using namespace**. 
   Ma con parsimonia poiché potrebbe generare ambiguità => in tal caso sarebbe meglio l'uso dell'operatore di risoluzione di visibilità.

  ==Nota:== In c++ ne esiste uno **globale** e per riferircisi si digita L'operatore di risoluzione di visibilità senza avere prima nessun namespace. => E' possibile dichiarare **uno spazio di nomi anonimo MA** non è possibili rendere visibili i suoi membri **all'esterno di esso**.


-  **regole di collegamento**: Esse vengono rispettate **dal collegatore** e hanno pressoché la stessa funzione delle regole di visibilità. Insomma trattiamo le regole di collegamento quando **abbiamo più unità di compilazione sviluppate e tradotte separatamente** poi unite nel **main.cpp**. --> ciò avviene grazie al concetto di **collegamento (** linkage **)**.

Un' entità ha **collegamento interno** se è riferibile **solo dall'unita di compilazione dove è stata riferita.** --> Come ad esempio un identificatore **a livello di blocco** o **a livello di file costante**.

Ha **collegamento esterno**, invece, se ci si può riferire anche da unità di compilazione diverse da quella della dichiarazione. => **L'entità è unica in tutto il programma**. --> Prende il nome di **entità globale**. --> Come ad esempio un identificatore **a livello di file**.

Per sfruttare il collegamento esterno **bisogna dichiarare** l'entità **NON COSTANTI** --> Si ha una **definizione** anteposta dalla parola **extern** (nel caso di oggetti) , keyword **extern** facoltativa invece nel caso delle funzioni.

==Nota:== Funzione --> dichiarabile **solo a livello di file** --> Nella dichiarazione a prescindere viene       considerata con collegamento esterno.
Oggetto --> dichiarabile **sia a livello file che di blocco**.

==Nota:== Nel caso di dichiarazioni di tipo **NON è possibile avere una dichiarazione di tipo globale**. => Il tipo deve essere ridichiarato **in ogni unità di collegamento.** => Possiamo avere tipi equivalenti ( vedere [[Le dichiarazioni di tipo]]) => Se due tipi sono equivalenti ma la loro struttura no = **ERRORE LOGICO**. --> Non ci verrebbe segnalato se non a tempo di esecuzione.

Anche le variabili globali ci permettono la comunicazione tra funzioni senza passaggio di argomenti o restituzione di risultati.

==Nota:== Essendo che **l'identificatore di un oggetto** non viene esteso per numero, un oggetto con collegamento esterno **può essere dichiarato in altre unita di compilazione con tipo diverso** --> Genera **ERRORE LOGICO**.

==Nota:== Regole dello spazio di nomi globale --> Valgono le stesse regole per gli altri spazi di nomi.

**E' possibile modificare le regole di collegamento che il c++ mi da di default?

Sì, è possibile attraverso la keyword **static**.

La keyword **static** mi permette di **rendere interno un collegamento esterno**.

==Nota:== Se in un unità di compilazione una definizione usa un identificatore che ha sia collegamento interno che esterno, ogni uso dell'identificatore **in quella unità** fa riferimento all'**identificatore con collegamento interno.**

==Nota:== Possiamo ottenere lo stesso effetto della keyword static **usando gli spazi di nomi**.

**Esempio:**

 ==Versione con static==

$#$include static int valore = 0; // visibile solo in questo file
static void incrementa() { 
	// funzione con visibilità limitata al file valore++; 
} 
int main() {
	incrementa();
	 incrementa(); std::cout << "Valore: " << valore << std::endl; 
	 return 0; }

**Caratteristiche:**

- static limita la visibilità **al file** (collegamento interno).
- valore  e incrementa() esistono **una sola volta** nel programma.
- Tipico uso: evitare collisioni di nomi tra file diversi.

==Versione equivalente usando uno namespace==

$#$include namespace Contatore {
	int valore = 0; // unica istanza globale
	 void incrementa() {
		  valore++;
	   } 
   } 
	  int main() { 
		  Contatore::incrementa(); 
		  Contatore::incrementa(); 
		  std::cout << "Valore: " << Contatore::valore << std::endl;
		  return 0;
	   }

**Caratteristiche:**

- Lo namespace crea un contenitore unico per variabili e funzioni.
- Anche qui valore e incrementa() esistono **una sola volta**.
- Non limita la visibilità al file, ma **evita collisioni di nomi**.

