Se decidiamo di usare la tecnica del modulo e segno abbiamo bisogni di considerare 2 elementi principali :
1) Il valore assoluto del numero che desideriamo rappresentare (anche detto modulo).
2) Il segno del numero che vogliamo rappresentare.

La sintassi del numero codificato sarà **A = (segno, valore assoluto).**

Il **segno** sarà rappresentato dal **bit più significativo** del numero binario che assumerà valore **0** se il numero fosse **positivo** , **1 altrimenti**.

Il **numero** sarà rappresentato come il suo **corrispettivo naturale** ( vedere [[Rappresentazione dei numeri naturali]].)

==Nota:== Il nostro intervallo di rappresentazione sul valore assoluto non sarà p ma p-1 , perché dobbiamo considerare il bit del segno !

Per **decodificare** il numero basta svolgere due operazioni:
1) Controllare il bit più significativo per il segno ( quindi 0=+ , 1=-)
2) Decodificare il valore assoluto ( vedere [[Rappresentazione dei numeri naturali]].)

==Nota:== Il numero 0 sarà rappresentato 2 volte, sia con il segno - che con il segno + !

L'intervallo di rappresentazione sarà: **(-(2^(p-1)-1), (2^(p-1)-1))**

Anche con questa rappresentazione può verificarsi il fenomeno dell'**overflow** ( vedere [[Rappresentazione dei numeri naturali]].)
