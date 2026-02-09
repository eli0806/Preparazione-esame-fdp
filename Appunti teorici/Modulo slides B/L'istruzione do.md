L'**istruzione do** o meglio **do-while** , ci permette **fino al verificarsi di una condizione di controllo**, l'esecuzione **ricorsiva** di una **sequenza di istruzioni**.

Nonostante abbia la stessa identica funzione de [[L'istruzione while]] esse presentano una grande differenza quando le andiamo ad eseguire:
Mentre nel while , **prima** si verifica la condizione e **poi** eventualmente si esegue il codice , nel     do-while **prima** si esegue il codice ( a prescindere se la condizione è stata verificata) e poi si valuta se la condizione è verificata.
Questo comporta, che a differenza dell'istruzione while, **nell'istruzione do-while, il codice tra parentesi viene eseguito almeno una volta.**
Ne segue la reiterazione del ciclo se **la condizione NON è verificata** , altrimenti l'istruzione do termina.

Essa presenta la seguente **sintassi**:

**do**{
  codice..
} **while**(condizione);

