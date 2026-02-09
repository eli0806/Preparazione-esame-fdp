I **numeri reali** , identificati con la lettera **r** e composti da una **parte fissa I(r)** e una **frazionaria (F(r))**.
![[Sommatoria reali.png]]
Essi possono essere rappresentati secondo due modalità:
1) **In virgola fissa.**
2) **In virgola mobile.** 

**Nella virgola fissa:**

Nella virgola fissa si predispone un numero n di bit per la parte intera e un numero k di bit per la parte frazionaria .

Troviamo che il numero p è il numero di cifre che prefissiamo per la rappresentazione totale del numero è affermiamo che p=n+k

Per la **parte intera** possiamo sfruttare le tecniche conosciute per i naturali ([[Rappresentazione dei numeri naturali]]) e gli interi([[Rappresentazione dei numeri interi]]).

Per la **parte frazionaria**:

![[Procedura iterativa parte frazionaria reali.png]]
Per fare la riprova della parte frazionaria basta semplicemente decodificare il numero ! 

Se il numero di bit non viene raggiunto si aggiungono **0 a sinistra** per la **parte intera** e a **sinistra** per la **parte frazionaria**.

==Nota:== La virgola fissa essendo **limitata** non ci permette una perfetta rappresentazione dei reali.
Il numero che otteniamo è **approssimato per troncamento.**

**Nella virgola mobile:**

Nella virgola mobile noi sfruttiamo una rappresentazione che può ricordare quella della forma normalizzata (0,numero * 10^grandezza) della notazione scientifica.
![[Notazione scientifica.png]]

==Nota:== Il numero 0 non è rappresentabile!

I bit sono divisi tra tre rappresentazioni di valori naturali:
1)  La codifica del **segno** ( **0**  per i **positivi** - **1**  per i **negativi**) (**1** bit)
2) La codifica del **significando** (**G bit**)
3) La codifica dell'**esponente** (**k** bit)

Questa metodologia ( che prende il nome di half precision) si divide in due casistiche:

1) Se il numero è positivo si rappresenta come:

   (1+parte frazionaria del significando) * 2^esponente

2) Se il numero è negativo  si rappresenta così:

   -(1+parte frazionaria del significando) * 2^esponente

   La **parte frazionaria** del **significando** si ottiene **dividendo** la codifica del significando **per 2** elevato il **numero di bit che la rappresenta** **(Significando/2^G)**.
   L'**esponente** rappresenta il **numero naturale E** a cui viene **sottratto il bias** ( per ricordare cos'è il bias vedere [[La rappresentazione con bias]]) .

Per la **decodifica** si eleva il 2 ai pesi dei bit che valgono 1 ( ricordando che essi, apparte la prima cifra, saranno negativi)
   

