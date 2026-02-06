Quando andiamo a rappresentare un numero in una base β dobbiamo considerare che avremmo a disposizione  β-n cifre .

Le basi  β che possiamo incontrare più frequentemente sono :
- La base 2 (0,1) --> Sequenze di bit
- La base 8 (0,1,2,3,4,5,6,7) --> Numero ottale
- La base 10 (0,1,2,3,4,5,6,7,8,9) --> Numero decimale 
- La base 16 (0,1,2,3,4,5,6,7,8,9,A,B,C,D,E,F) --> Codifica esadecimale , solitamente usata per la rappresentazione di colori in RGB.

Ogni cifra avrà un peso intrinseco che ne rappresenterà l'importanza all'interno della sequenza rappresentata --> SI tratta di **rappresentazione posizionale**.

Ne segue la **formula della sommatoria**:

![[Formula della sommatoria.png]]

**Esempio pratico dell'uso della formula sommatoria:**

Prendiamo come esempio il numero decimale 307 .

Esso lo possiamo scrivere come 3 * 10^2 +7 * 10^0

2 e 0 rappresentano **i pesi** dei numeri 3 e 7 e di conseguenza ne determinano **l'importanza**.

==! NOTA IMPORTANTE== : Il peso più significativo è sempre quello più a sinistra, quello meno significativo quello più a destra.

Ciò ci fa intendere che sfruttando la formula della sommatoria potremmo fare una cosa molto importante : **il cambio dalla base β ad un'altra base** nella rappresentazione di uno specifico numero.

La prima cosa da fare è trasformare il numero in base β in base decimale.

Successivamente usufruiamo dell'algoritmo " Div & Mod "

![[Algoritmo div&mod.png]]

Questo algoritmo divide il numero per β e ne considera sia il quoziente che il resto ( che otteniamo attraverso l'operatore modulo) e reitera il procedimento sfruttando i quozienti risultanti finché  non ce ne sarà uno pari a 0 .
Avremmo così p iterazioni. 

p=numero di cifre necessarie per rappresentare il numero nella nuova base .

L'intervallo di rappresentazione sarà: ( **0,( β^p)-1** )

==Nota:== Quando andremo a scrivere il risultato partiremmo dalla cifra più significativa, perciò inizieremmo a scrivere dall'ultima iterazione ( ossia il valore a p-1) alla prima (ossia a 0).

Per tornare alla base iniziale basterà ripetere la formula della sommatoria con la base desiderata.

**Operazioni tra numeri naturali in rappresentazione binaria:**

Una volta rappresentato un numero in una qualsiasi base in base binaria, ci è possibile fare l'operazione di **somma modulare** ( ossia che forma un anello quando i numeri raggiungono il valore del modulo (2^p - 1 nel nostro caso )).

Ne segue un esempio con p=4 
![[Somma modulare.png]]
Se un risultato supera l'intervallo di rappresentazione (attraverso un riporto) allora si verificherà il fenomeno dell'**overflow** o traboccamento e il risultato **non** sarà corretto ( non può essere rappresentato e avremmo un numero con il bit più significativo in meno).

Esempio di somma binaria  su p=2 

0+0 = 0 ; -->Possibile 
0+1=1; -->Possibile 
1+1=10 -->Possibile
10+1=11 --> Possibile 
11 + 1 = ==1==00 --> Overflow --> Siamo tornati a 0 ! ( perchè il bit più significativo è andato perso ).





