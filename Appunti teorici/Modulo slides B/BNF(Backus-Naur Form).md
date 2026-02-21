Una grammatica BNF definisce quindi un linguaggio sull’alfabeto terminale V mediante un meccanismo di derivazione (ossia di riscrittura).

![[BNF.png]]

Le sue regole di **produzione** rispecchiano la forma :

X = A1, A2 ...An --> X è una **sequenza di simboli**

**Si dice che A deriva da X se esiste una sequenza di derivazioni da X ad A.**


Nel metalinguaggio BNF possiamo trovare i seguenti costrutti:
- **One of**: Indica un **unica alternativa** tra più termini.
- **Opt**: Indica **l'opzionalità** di un determinato termine o ulteriore costrutto ( come può essere l'uso della clausola else in un espressione di controllo if )
- **Seq**: Indica una **sequenza di termini di un determinato tipo sintattico** ( ad esempio una sequenza di nomi sarà composta da un insieme di nomi, una di verbi da un insieme di verbi e così via).