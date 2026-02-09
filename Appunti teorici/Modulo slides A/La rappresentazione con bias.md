Se decidiamo di usare la rappresentazione con bias dobbiamo tenere conto solo della formula :

**A=numero + (2^(p-1)- 1)**

Dove **(2^(p-1)- 1)** prende il nome di **bias**.

quindi per semplificare la notazione:  **A= numero + bias**

Per la **decodifica** è necessario semplicemente **invertire la formula**: 

**numero = A - bias**.

L'intervallo di rappresentazione sarà : **(-(2^(p-1)+1), (2^(p-1))))** 

semplificando la notazione: **(-bias, bias)**

==Nota:== Sfruttando questa tecnica avremmo che i numeri positivi inizieranno per 1 , mentre i negativi per 0 

Anche in questo caso si può riscontrare il fenomeno dell'**overflow** se il numero da rappresentare necessita di più cifre rispetto a p.

(curiosità:[[Problema di Fibonacci]] )





