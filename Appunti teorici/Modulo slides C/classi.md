Una **classe** è un tipo di dato derivato che si divide in:

- **Una parte privata:** contiene le strutture dati del tipo.
- **Una parte pubblica:** contiene le dichiarazioni delle funzioni membro.

==Nota:== Per **funzione membro** si intendono tutte le funzioni **dichiarate in una classe** e sono **le uniche** (insieme alle [[funzioni friend]]) che **possono accedere alla parte privata della classe.**

La **dichiarazione** di **una classe** segue la sintassi:

class nomeClasse{
	// elenco **membri** privati
	public:
	// elenco **membri** pubblici --> Solitamente funzioni.
	
}

Un **membro** di una classe può essere:
- Un tipo. --> enum o struct.
- Un campo di dati. --> Definizione di oggetto non inizializzato. --> Può essere anche un puntatore ad un'altra classe, anche con dichiarazione incompleta.

**Esempio chiarificatore:**
class B;   // dichiarazione incompleta

class A {
private:
    B* ptr;   // OK: puntatore a tipo incompleto
};

- Una funzione. --> Sia dichiarazione che definizione
- Un'altra classe.

==Nota:==La dichiarazione di una classe (essendo tipo derivato) deve **essere ripetuta in tutte le unità di compilazione dove la utilizziamo.**

==Nota:== La classe **dichiarata all'interno dell'altra classe** sarà **locale** alla prima e per accedervi è necessario usare **il doppio operatore di risoluzione di visibilità**, sia per l'uso **delle funzioni membro** che per **i tipi e le enumerazioni.**

==Nota:== Nessuna delle **due classi annidate** può accedere alla **parte privata dell'altra**.

Nella definizione di una **funzione membro** si possono usare gli identificatori definiti nella classe **Senza indicazione dell'oggetto** nel quale sono contenuti.

==Nota:== Le funzioni membro **possono essere definite anche all'esterno della dichiarazione della classe,** ma è necessario che si usi prima l'operatore di risoluzione di visibilità (::).

**Esempio:**

class complesso{
	double re, im; //Membri privati --> campi di dati
public:
	void iniz_compl(double r, double i); //Funzione membro
	double reale();
	double immaginario();
};

void complesso::iniz_compl(double r, double i){
	re=r;
	im=i;
}
double complesso::reale(){
	return re;
}
double complesso:: immaginario(){
	return im;
}

==Nota:== E' molto probabile trovare questa notazione quando si decide di dichiarare la classe in unfile header e/o nel caso di programmazione modulare.

==Nota:== Le funzioni membro definite all'interno della classe sono **inline** ( vedere [[funzioni]]) e hanno sempre **collegamento interno** (vedere [[visibilità]]), al contrario hanno collegamento esterno.

==Nota:== Se applico una modifica all'interno del codice della classe, **la sua interfaccia non cambia** e quindi i suoi usi rimangono immutati.

Una classe individua **un campo di visibilità:**

- **Identificatori:** Dalla dichiarazione fino al termine della classe (ossia la sua deallocazione).
- **Funzioni membro:** Vengono trattate come se fossero definite tutte alla fine della classe. --> Ci sono anche gli identificatori **non ancora dichiarati**.
- **Identificatore dichiarato esterno alla classe:** La dichiarazione **interna** andrà a **nascondere la dichiarazione esterna**.
- **Identificatore dichiarato via unità di compilazione o spazio di nomi:** Usare l'operatore di risoluzione di visibilità (::).
- **Fuori dalla classe:** Posso rendere visibili alcuni identificatori applicando al nome della classe l'operatore di risoluzione di visibilità. --> Cosa valida solo per i membri nella **parte pubblica**.

==Nota:== L'operatore di risoluzione di visibilità **NON** può essere usato **sui campi di dati**.

**La programmazione modulare:** è possibile anche con le classi.
Il ruolo di **interfaccia** è dato alla parte pubblica **delle classi**.

Ricordiamo che ==la modifica di una classe non modifica MAI l'interfaccia.== --> Le modifiche dipendono tutte dalla parte privata . --> Tranne nel caso di estensione della classe, dove dovremmo applicare funzioni con argomenti di default e la tecnica dell'overloading.

==Nota:== E' sconveniente la separazione di una classe in interfaccia e struttura interna --> Meglio una divisione in file seguendo le regole di collegamento.

Per garantire la **modularità** sfruttiamo per ogni classe un file di intestazione **con le dichiarazioni necessarie** (file.h) e un file di realizzazione(file.cpp) con **le definizioni delle funzioni membro.**

client --> include intestazione --> Usa **solo** gli identificatori dei campi di dati e funzioni membro **della parte pubblica**.


