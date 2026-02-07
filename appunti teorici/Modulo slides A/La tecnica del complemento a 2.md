Se decidiamo di usare la tecnica del complemento a 2 dobbiamo tenere conto del numero **p**
(numero di **bit di rappresentazione**) e del **valore assoluto del numero** che vogliamo rappresentare.

La sintassi del numero codificato dipenderà se esso è positivo o no:
-  Se il numero è **positivo**  la rappresentazione equivarrà alla **rappresentazione binaria del valore assoluto.** 
-  Se il numero sarà **negativo** la rappresentazione avrà sintassi : **A = (2^p - valore assoluto).**

Per la **decodifica** invece si procede così:
1) Si osserva il **bit più significativo** : se esso è **0** il numero sarà **positivo**, **altrimenti** sarà **negativo.**
2) Se il numero è **positivo** basta decodificare con la **formula della sommatoria** ( vedere [[Rappresentazione dei numeri naturali]].)
   Se il numero è **negativo** bisogna **invertire** la formula della **codifica**:
   **numero = A - 2^p **

L'intervallo di rappresentazione sarà : **(-(2^(p-1)), (2^(p-1)-1)))**

**Il metodo dei tre passi:**

Se non si vuole usare la formula del complemento a due è possibile ottenere lo stesso risultato attraverso il metodo dei **tre passi**:

Passo 1 ) **Rappresentare il valore assoluto del numero in base 2 su p bit**
Passo 2 ) **Invertire ciascun bit** --> Si tratta della tecnica del **complemento a 1** 
Passo 3) **Sommargli uno**


Anche in questo caso si può riscontrare il fenomeno dell'**overflow** se il numero da rappresentare necessita di più cifre rispetto a p o che si ottenga un risultato da somma che necessita p+1 bit . 

Si noti che come i naturali, anche **gli interi in complemento a 2**  sfruttano la **somma modulare** e di conseguenza presentano un'**organizzazione ad anello**.
![[Somma modulare interi.png]]

