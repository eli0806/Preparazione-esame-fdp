Un **espressione** è formata da **espressioni letterali, identificatori e operatori** (vedere [[Generalità del linguaggio c++]] ).
L'espressione però è **opzionale** e può essere sostituita con il carattere **;** . 

Tra le espressioni troviamo:
- **le espressioni di assegnamento**.
- **gli incrementi e i decrementi**.
- **le espressioni aritmetiche e logiche** .
- **le espressioni costanti**
- **le espressioni con operatore condizionale**
- **le espressioni con operatore virgola**

Le **espressioni di assegnamento** ci permettono di **calcolare** il valore di un espressione e **sostituirlo** a quello di una variabile e producono come **risultato l'indirizzo della variabile che vogliamo modificare**.

La **sintassi** delle **operazioni di assegnamento** è :

**left-value** = **right value;**

Dove la **left-value** rappresenta **l'indirizzo della variabile a cui vogliamo cambiare il valore** e la **right-value** rappresenta il valore che verrà assegnato alla variabile del **left-value** .

==Nota:== Mentre **l'indirizzo di una variabile** può essere sia **un left-value** che un **right-value** , un singolo valore o un'espressione algebrica **non** potranno **mai** essere **left-value**.

==Nota:== Una variabile usata come **left-value** , potrà essere utilizzata come **right-value** in'un'altra espressione e **viceversa**.

Le operazioni di assegnamento possono **cumularsi** e seguiranno l'ordine con cui sono scritte.

==Nota:== Se però come **right-value** ci fosse **un'espressione algebrica** , questa avverrebbe **prima** dell'espressione di **assegnamento**.

Gli **incrementi** e i **decrementi** si usano per incrementare/decrementare il valore di una variabile di 1 ( Difatti il loro uso più comune lo troviamo nelle funzioni **contatore**).

L'**incremento** (ossia **x=x+1**) avviene con **sintassi**:

**++** nomeVariabile; // E' il caso in cui l'operatore sia **prefisso** (vedere [[Generalità del linguaggio c++]])

nomeVariabile **++** ; //E' il caso in cui l'operatore sia **postfisso**  (vedere [[Generalità del linguaggio c++]])

Il **decremento** (ossia **x=x-1**) avviene con **sintassi**:

**--** nomeVariabile; // E' il caso in cui l'operatore sia **prefisso** (vedere [[Generalità del linguaggio c++]])

nomeVariabile **--** ; //E' il caso in cui l'operatore sia **postfisso**  (vedere [[Generalità del linguaggio c++]])

==Nota:== **Operatori prefissi** -> restituiscono **left-value** 
      **Operatori postfissi** -> restituiscono **right-value** 


Le **espressioni aritmetiche** sono espressioni che producono **risultati aritmetici** mentre le **espressioni logiche** producono **risultati booleani**.
In entrambi i casi abbiamo che **vengano rispettate le precedenze e le associatività** degli operatori (nel caso delle espressioni logiche vedere [[Regola del cortocircuito]]).

Per lo schema sull'ordine precedenziale delle operazioni (vedere [[Ordine operazioni pt,1.png]] e [[Ordine operazioni pt.2.png]] ). 

Ma riassumendo brevemente, **prima** vengono **valutati i fattori** (calcolando i valori delle funzioni e applicando gli operatori unari , **prima incremento e decremento postfissi, poi incremento e decremento prefissi, NOT logico ( ! ), meno unario ( -) e più unario (+)));
Poi vengono valutati i termini, applicando gli operatori binari nel seguente ordine**:
1) quelli moltiplicativi ( *, / , % );
2)  quelli additivi ( + , -); 
3) quelli di relazione ( <, … ); 
4) quelli di uguaglianza ( == , !=) 
5) quelli logici (nell’ordine, &&, || ); 
6) quelli di assegnamento ( = , … );

==Nota:== L'uso di **separatori** come le **parentesi tonde** isola un'operazione rendendola **un fattore** e facendo sì che essa venga svolta prima di altre.

Se non definita dal programmatore **l'associatività** dipende da quella **degli operatori**.

**Operatori aritmetici** -> Associatività **da sinistra** --> Associa i valori più a sinistra.

esempio:  x\3 * 2  viene svolto (x\3) * 2

**Operatore assegnamento** -> Associatività **da destra** 

esempio:  x=y=3+2 viene svolto x=(y=2+3)

==Nota:== In c++ non è possibile avere operazioni di confronto come 2<x<=4  perché non verrebbe calcolata come noi la consideriamo bensì (2<x)<=4 e dove (2<x) dà un risultato booleano.
Per esprimere l'operazione in **maniera corretta** dovremmo scriverla x>2 && x<=4.

**Operatore logico** -> Associatività **da sinistra** --> Associa i valori più a sinistra.

Nei **casi dell'AND e dell'OR logico** c'è una proprietà particolare: La [[Regola del cortocircuito]].

Le **espressioni costanti** sono definite tali **se e solo se** vi compaiono **solo** operandi come letterali, enumeratori ed identificatori di costanti e restituiscono **sempre** il valore che il programmatore ha definito in principio .

Le **espressioni condizionali** o più banalmente **espressioni di controllo** mettono in rapporto **almeno 2 espressioni, di cui la prima di tipo logico** , valutando la prima se vera o no e procedendo a restituire il valore associato alla risposta ( espressione 2 se vero , espressione 3 se falso). 

==Nota:== L'espressione 3 può essere omessa.

Esse seguono la seguente **sintassi**:

espressione 1 (logica) ? 1) (Se verificata) espressione 2 : (che significa **altrimenti**)  espressione 3 .

Dove e2 ed e3 rappresentano **valori di ritorno** o **serie di istruzioni**.

==Nota:== In ordine di precedenza esecutiva OR logico< operatore condizionale < operatore di assegnamento.

Le **espressioni con virgola** permettono **lo svolgimento sequenziale** di più espressioni, da quella più a sinistra a quella più a destra.

Esse seguono la seguente **sintassi**:

espressione 1, espressione 2, ... espressione N.

Dove e1 indica una qualunque operazione che **produce risultato** ma che **può essere anche ignorato** ed e2 un'espressione **il cui risultato rappresenta quello dell'espressione completa**.

Da ciò riconosciamo che  **i valori intermedi** prodotti dalle espressioni e1-eN-1 **verranno ignorati** e il risultato **sarà sempre quello dell'espressione eN**.


==Nota:== In ordine di precedenza esecutiva operatore virgola < operatore di assegnamento.