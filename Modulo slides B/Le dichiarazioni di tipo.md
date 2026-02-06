Una **dichiarazione di tipo** può avvenire **solo per**:
- I tipi enumerati (vedere [[I tipi fondamentali]])
- [[strutture (o struct)]]
- [[union]]
- [[classi]]

Esempi di dichiarazione di tipo sono:

enum nome{/$*$ ..........$*$/};

struct nome{/$*$ ..........$*$/};

Una dichiarazione di tipo può avvenire contestualmente alla dichiarazione di un oggetto, così:

struct nome{/$*$ ..........$*$/} nomeOggetto;

E questo ci permette di avere dichiarazioni di oggetti di **tipo anonimo** come:

struct {/$*$..........$*$/} nomeOggetto;

**Equivalenza dei tipi:**

Due tipi si dicono equivalenti **se e solo se hanno lo stesso nome** ed in un programma noi **non possiamo assolutamente mai due dichiarazioni equivalenti.**

**NON si considerano equivalenti:**

- Due funzioni con la stessa struttura interna ma nome diverso.
- Un tipo con nome e un tipo anonimo.
- Due tipi anonimi.

==Nota:== Se due oggetti non sono dello stesso tipo (ossia hanno la stessa dichiarazione di tipo) non potrà **MAI** avvenire un'assegnazione tra loro . --> Essa se avvien verrà considerata illegale e il compilatore la segnerà errore.