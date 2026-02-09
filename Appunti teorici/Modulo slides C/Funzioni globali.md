Per **funzioni globali** si intendono **tutte quelle funzioni che non sono membri di classi** all'interno del nostro codice.

Esse **NON** possono:
- Accedere alla parte privata delle classi.
- Sfruttare i puntatori this.

**Possono invece:**
- Sfruttare le funzioni membro della classe dichiarate nella parte pubblica per nuove operazioni.

**Esempio:**

$#$ include " complesso. h" //file dove abbiamo la dichiarazione della classe e delle sue componenti --> interfaccia (vedere [[classi]])

complesso somma (complesso x, complesso y){ //Usiamo il tipo classe sia come argomento formale che come tipo di valore da restituire
	complesso z;
	double zr, zi;
	zr= x.reale() + y.reale();
	zi=x.immaginario()+y.immaginario();
	return z;
}

int main(){
	complesso z, x1, x2;
	x1.iniz_compl(0.1, 0.2);
	x2.iniz_compl(1.0, 2.0);
	z=somma(x1, y1);
	return 0;
}

In questo caso **le funzioni globali** dell'esempio sono la funzione somma e la funzione main().