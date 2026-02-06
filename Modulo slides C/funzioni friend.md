Le **funzioni friend** sono funzioni che appaiono all'interno della dichiarazione di una classe **ma non ne fanno parte** e possono accedere **sia ai membri pubblici che ai membri privati** attraverso **i selettori di membro.**

Esse hanno la seguente sintassi:

friend TipoRitorno nomeFunz(const Argomenti);

Un esempio sono [[l'overloading di operatori]].

**Perché le realizziamo?**

Perché alcune funzioni coinvolgono più oggetti, anche di classi diverse, e non avrebbero senso come metodi di una sola classe.
Oppure abbiamo bisogno della collaborazione tra due classi, o ancora se una funzione potrebbe ricorrere in entrambe e non avrebbe senso come singola funzione membro.

**Esempi:**

![[Esempio funzione friend 1.png]]

![[Esempio funzioni friend 2.png]]