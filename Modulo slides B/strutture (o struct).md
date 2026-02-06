Una **struttura** è un n-upla (ossia un insieme ) di elementi chiamati **membri** o **campi** .

Ad ogni membro posso applicare **tutti gli operatori** del rispettivo tipo.

Ogni membro ha **un proprio nome, un proprio tipo e una propria informazione associata**.
Nello specifico il **tipo struttura** è costituito da **tutte le strutture** con **membri, nomi e tipi specifici.**

La dichiarazione di una struttura avviene con la seguente sintassi:

struct nomeStruct{
	tipo membro1
	tipo membro2;
	....
}

==Nota:== L'identificatore (ossia il nome della struttura) può anche mancare --> Si tratta del tipo anonimo .

L'insieme delle caratteristiche di un singolo membro si chiama **sezione**.

Inoltre **una struttura può essere membro di un'altra struttura**, però essa deve differire dal tipo di struttura in cui è contenuta, tranne se si tratti del caso di un **puntatore a struttura.**

==Nota:== E' possibile avere un puntatore che punti ad un tipo di struttura **non ancora dichiarato**, è il caso in cui si ricorre alla **dichiarazione incompleta**.

La dichiarazione incompleta ha la seguente sintassi:

struct nomeStruct2 ;

e deve avvenire prima della dichiarazione della struct in cui si vuole includere.

Ma la sua definizione può avvenire anche in un secondo momento .

**Esempio struttura dentro una struttura:**

struct persona{
	char nome$[20]$;
	char cognome $[20]$;
	struct {int giorno, mese, anno} d-nascita;
}

**Struttura "autoreferente" al tipo struttura:** (la troveremo soprattutto ne [[Le liste]])

struct elemento{
	int inf;
	elemento* pun;
}

**Mentre la creazione di oggetti di tipo struttura?** 

La sintassi è la seguente:

nomeStruct nomeOggetto;

oppure 

struct {tipoMembro var1, var2,....; } nomeOggetto;

oppure 

struct nomeStruct {tipoMembro var1, var2 ,....;} nomeOggetto;

(Sono tutte equivalenti ad esclusione dell'anonima).

==Nota:== In una definizione possiamo avere anche **più oggetti diversi dello stesso tipo.**

L'**inizializzazione** invece avviene scrivendo tra **parentesi graffe** i valori che i vari membri dovranno assumere. 

Ad esempio:

rettangolo a ={1,2 }; //Dove 1 rappresenterà l'altezza e 2 la lunghezza.

Oppure può avvenire associandola ai valori di un'altra struttura:

Ad esempio:

rettangolo b=a;

oppure

rettangolo c(a);

In questo caso avviene una **copiatura membro a membro**, ossia,ad esempio:

s.alt=t.alt; 
s.larg=t.larg

==Nota:== L'assegnazione è possibile ed avviene nella stessa identica maniera dell'inizializzazione .

Che significa ? Che ogni valore presente nei vari membri di a verrà copiato, tale e quale, nei membri corrispondenti di b.

==Nota:== Anche un oggetto struttura **può essere definito costante**, ciò implica però che esso debba subito essere inizializzato e che i suoi valori non possano essere mai modificati all'interno del codice.

**E se io volessi riferirmi ad un singolo membro di una struttura?**

Per riferirmi ad uno **specifico membro** di una struttura, scrivo il nome della stessa, seguito da un punto e poi dal nome del membro. Così:

nomeStruct.nomeMembro;

Nel caso di una struttura **indirizzata da un puntatore** invece scriviamo:

($*$ nomeStruttruraPuntata).nomeMembro;

==Nota:== L'uso delle parentesi è assolutamente necessario dato che l'operatore '.' ha una priorità maggiore di quello di deferenziazione.  ( vedere [[Ordine operazioni pt,1.png]] e[[Ordine operazioni pt.2.png]] ).

Una notazione equivalente è : strutturaPuntata -> membro;

Ad esempio:

rettangolo* p = &r;

p-> alt =2; 
p-> larg=3;

==Nota:== Se non applicato a **puntatori non nulli** ' ->' restituisce un messaggio d'errore, perchè per sua natura comporta una **indirezione**.

**$'.'$** e **->** prendono il nome di **selettori di membro.**

Le strutture **possono essere argomenti formali di funzioni** o **restituite da funzione.**

Alcuni tipi particolari di strutture sono:
- [[Le pile]]
- [[Le code]]
- [[Le liste]]