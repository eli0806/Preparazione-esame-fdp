Un **oggetto classe** o **istanza di una classe** per essere definito segue la sintassi:

NomeOggetto Nomeclasse;

oppure equivalentemente:

class {
 //.....
}nomeOggetto;

o ancora:

nomeClasse nomeOggetto = oggettoGiàIniz;

o ancora:

nomeOggetto(oggettoGiàIniz);

Negli ultimi due casi (dove assegnamo ad un nuovo oggetto classe un oggetto classe che avevamo precedentemente inizializzato) abbiamo una **ricopiatura membro a membro dei campi di dati**.

**Come avviene la copiatura membro a membro?**
Il compilatore scorre i membri della classe **uno alla volta** e, per ogni campo, **copia nel nuovo oggetto esattamente lo stesso valore che si trova nel campo dell’oggetto originale**.  
Non controlla nulla, non decide nulla: **copia tutto così com’è**, seguendo la normale regola di copia del tipo. (vedere [[Il costruttore di copia - Uno zoom sull'operatore di assegnamento]])

Inoltre un oggetto classe **può essere definito costante** e perciò deve essere inizializzato al momento della creazione e non può essere mai modificato in fase di esecuzione.

==Nota:== Le **funzioni membro** possono accede a **TUTTI** i membri ( sia privati che pubblici) di oggetti definiti nella medesima classe in cui si trova.

**Esempio esplicativo:**

class uno{
	int n;
public:
	int f(uno cu);
	};
int uno::f(uno cu){
	return (n + cu.n);
}
}

**Su un oggetto classe possiamo svolgere le seguenti operazioni:**
- Operazioni **delle funzioni membro** dichiarate nella parte pubblica.
- Selezione con l'operatore '$.$ ' per accedere a campi di dati dichiarati nella parte pubblica.
- Selezione con l'operatore "->" per accedere (via puntatore) a campi di dati dichiarati nella parte pubblica.
- Inizializzazione --> Può avvenire fornendo i valori necessari oppure un oggetto già definito ( avviene copiatura membro a membro).
- Assegnazione --> Stesso discorso dell'inizializzazione.
==Nota:== Sugli oggetti di tipo classe **NON** esistono le operazioni di confronto
Anche gli oggetti classe possono **essere argomenti di fuzioni** o restituiti da funzioni(sia per valore che per riferimento).
