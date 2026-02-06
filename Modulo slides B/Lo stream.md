Per **stream** si intende una **struttura logica** costituita da una o più **sequenze di celle di memoria** contenenti un byte.
Essi sono **sempre** associati a dispositivi fisici collegati al nostro dispositivo ( come ad esempio una tastiera, una stampante etc.) o a file sulla memoria di massa dello stesso.
**Ogni stream termina con la marca di fine stream** che in c++ è rappresentata da:
- nei sistemi Unix-Linux (Ctrl-D)
- Control e Z nei sistemi DOS/Windows (Ctrl-Z)
Noi usiamo gli stream per seguire:
- [[Operazioni di lettura]] --> Usiamo nello specifico gli **stream di ingresso**
- [[Operazioni di scrittura]] --> Usiamo nell specifico gli **stream di uscita

In c++ troviamo 3 **stream predefiniti** e questi sono:
- **Cin** --> E' lo **stream default di ingresso** e ci permette di inserire dati all'interno del nostro codice.
- **Cout** --> E' lo **stream default di uscita** e ci permette di stampare a video "i risultati" del nostro codice.
- **Cerr** --> E' lo **stream default** dedicato ai **messaggi d'errore.**

E li troviamo tutti all'interno della libreria (vedere [[Le librerie]]) **< iostream.h >**
