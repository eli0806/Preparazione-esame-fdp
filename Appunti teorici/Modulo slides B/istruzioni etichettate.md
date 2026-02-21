Per **istruzioni etichettate** si intendono **quelle istruzioni a cui il programmatore applica un etichetta**.
Esse hanno la **seguente sintassi**:

identificatore : codice 

Dove L'identificatore è un nome qualsiasi e il codice è un'istruzione qualsiasi.

Alle istruzioni etichettate ci si riferisce con la parola chiave **goto** e troviamo la seguente sintassi:

**goto** identificatore;

==Nota:== Solitamente l'uso di questa keyword è sconsigliato perché comprometterebbe la struttura del nostro codice e può essere facilmente sostituita dalle istruzioni break o continue.
Il suo uso più indicato è quello nel caso si voglia uscire da più cicli annidati contemporaneamente.