Per **membro** (o meglio campo di dati) **statico** si intende **una variabile appartenente alla classe nel suo complesso** e non ai singoli oggetti.

Un **campo di dati statico** esiste in una sola copia in memoria e la sua **definizione** è esterna alla classe ed **è unica** in TUTTO il programma. --> Lo riferiamo con gli operatori di selezione '.' e '->'.

==Nota:== Per la definizione noi scriviamo nomeClasse::nomeMembroStatico.

**Perché è meglio dell'uso di una variabile globale?**

Perché abbiamo un **controllo di protezione** --> Possiamo scegliere se essere un membro privato o pubblico.

**Esempio:**
![[campo di dati static.png]]

Anche **le funzioni membro** possono essere **dichiarate statica**.

Una **funzione membro statica** è una funzione che svolge operazioni sulla classe in quanto classe e non sulle singole istanze.

![[Funzione membro static.png]]
==Nota:== Una **funzione membro static** può essere richiamata anche su **un’istanza della classe**, ma **non fa riferimento a nessun oggetto in particolare**.  
Di conseguenza **non può accedere a membri non statici** e **non può usare il puntatore this**.  
In compenso, se le viene fornito un oggetto (o un puntatore a oggetto), può accedere ai suoi membri tramite i selettori **'.'** e **'->'**, perché in quel caso non usa this ma l’oggetto passato esplicitamente.
