In una classe **un campo dati** può **essere definito costante**. => Gli oggetti di quella classe hanno tutti **lo stesso valore** in corrispondenza del campo dati tale definito.

==Nota:== Se definito costante il campo dati deve essere **static**(vedere [[Le classi di memorizzazione di un oggetto]]).

Oppure 

un campo dati può **avere l'attributo const** => Non è uguale in tutte le istanze della classe.

In questo caso **il costruttore** si compone di due parti:
1) **Una lista di inizializzazione:** Vengono specificati i valori dei campi const. --> Può anche mancare , tranne se esistono campi costanti.
2) **Un corpo del costruttore:** Assegna valori iniziali agli altri campi. --> Può essere vuoto ma è necessario mantenere le parentesi graffe.

Il costruttore li esegue in ordine al fine di **garantire che i campi di dati con l'attributo const siano già inizializzati quando si svolgono le istruzioni presenti nel corpo del costruttore.

![[Esempio const attribute.png]]

Anche **una funzione membro** può essere definita costante. --> Può modificare altre entità.

**Com'è possibile realizzarle?**

Scrivendo dopo le parentesi che racchiudono gli argomenti formali la keyworld **const** .

Se **oggetti classi costanti** -->possiamo applicare **solo funzioni membro costanti**.

==Nota:== Se esistono **due versioni della stessa funzione membro** , una **costante** e una **non costante** , il compilatore sceglierà sempre la **versione costante** se l'**oggetto su cui si lavora è costante** , **non costante** altrimenti. 