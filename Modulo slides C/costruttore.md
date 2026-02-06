Un oggetto classe può **essere inizializzato** sia per mezzo di una qualsiasi funzione membro che sfruttando **la funzione membro costruttore**.

Il **costruttore** è una funzione membro con **lo stesso nome della classe** che ci permette un'inizializzazione di un oggetto classe **contestualmente** ( ossia con la stessa operazione) **alla sua definizione**.

Esso se presente **viene automaticamente invocato dal compilatore** durante la fase di creazione **dell'oggetto** => Ovviamente dopo l'allocazione. => Metodo dell'overloading.

==Nota:== Quando si usa un costruttore spesso è necessaria l'allocazione in memoria dinamica (vedere [[La memoria dinamica]])

==Nota:== Per la stessa classe possiamo avere **più metodi costruttori** che differiscono solo per numero e tipo di parametri formali.

**Esempio di costruttore:**

complesso::complesso(double re, double im){
	this-> re=re;
	this->im=im;
}

Se un costruttore prevede argomenti -> l'oggetto richiede un inizializzatore-->insieme degli argomenti attuali richiesti dal costruttore

Altrimenti:

**Costruttore di defualt:** ci permette di definire oggetti **senza inizializzatori** --> sfruttiamo l'overloading o gli argomenti di default.

**Tecnica dell'overloading (esempio):**

class complesso{
	double re,im;
public:
	complesso();
	complesso(double r, double i);
   };

complesso::complesso(){ //Nostro costruttore di default
	re=0;
	im=0;
 }

complesso::complesso(double r, double i){
	re=r;
	im=i;
}

**Tecnica degli argomenti di default:**

class complesso{
	double re,im;
public:
	complesso(double r=0, double i=0);
};

complesso::complesso(double r, double i){
	re=r;
	im=i;
}

==Nota:== Si noti che a livello di risultatole due tecniche sono completamente equivalenti, spesso possiamo addirittura trovarle in combinazione l'una con l'altra --> Come ad esempio se volessimo inizializzare solo una parte dell'oggetto classe.

==Nota:== Nel caso di un costruttore con singolo  ( o anche un singolo argomento NON di default) è possibile la notazione

nomeClasse nomeOggetto = valore;

**E per gli oggetti dinamici come si fa?**

Il costruttore viene invocato lo stesso.

Troviamo la notazione:

nomeClasse* nomeOgg= new nomeClasse(arg);

O in presenza di un costruttore di default:

nomeClasse* nomeOgg= new nomeClasse;

**Per le varie classi di memorizzazione (vedere [[Le classi di memorizzazione di un oggetto]]), il costruttore dell'oggetto viene invocato in momenti diversi del codice:**
1) **oggetti statici:** all'inizio del programma.
2) **oggetti automatici**: al momento della loro definizione.
3) **oggetti dinamici:** al momento della loro creazione( con new).
4) **membri di altri oggetti classe:** al momento della loro costruzione.

Per deallocare un oggetto dinamico che abbiamo allocato in una classe usiamo [[il distruttore]].