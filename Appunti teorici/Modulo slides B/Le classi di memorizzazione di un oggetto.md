La **classe di memorizzazione*** (o storage class) **di un oggetto** è una proprietà che ne riguarda il **tempo di vita**.

Per **tempo di vita** di un oggetto si intende **l'intervallo di tempo** in cui **l'oggetto viene mantenuto in memoria** durante l'esecuzione di un programma.

Abbiamo 3 classi di memorizzazione:
1) statica
2) dinamica
3) automatica

$1)$ **Gli oggetti di classe statica**: sono chiamati anche oggetti statici e sono definiti **fuori dalle funzioni**. Essi "nascono" all'inizio del programma principale e vengono deallocati al termine dello stesso.
L'inizializzazione di un oggetto statico avviene al momento della sua creazione, altrimenti equivale a 0.

$2)$ **Gli oggetti di classe dinamica**: li abbiamo conosciuti in [[La memoria dinamica]]!

$3)$ **Gli oggetti di classe automatica:** sono gli oggetti definiti a livello di blocco (vedere [[visibilità]]) e vengono creati alla propria definizione e deallocati al termine del blocco in cui operano.
L'inizializzazione di un oggetto automatico avviene al momento della sua creazione, altrimenti vale un valore indefinito. --> Un esempio di oggetto dinamico può essere un argomento formale della funzione. --> Ad ogni chiamata della funzione, se l'oggetto automatico non è inizializzato avremmo valori diversi ( casuali).

==Nota:== Possiamo rendere un oggetto **automatico** , **statico** attraverso la keyword **static**. Si noti però che il campo di visibilità rimane invariato ( quindi resta a livello di blocco) e l'inizializzazione se presente avviene solo alla prima esecuzione del blocco.

![[Classi di memorizzazione.png]]