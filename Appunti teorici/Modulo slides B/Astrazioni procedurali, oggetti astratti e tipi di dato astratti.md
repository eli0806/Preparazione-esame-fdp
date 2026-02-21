Esistono dei **moduli server che forniscono servizi agli altri moduli** del programma. 
Questi moduli espongono un **insieme di funzioni** che costituiscono la loro **interfaccia pubblica**, mentre l'implementazione rimane nascosta. Insomma viene mantenuto l' [[information hiding]].
--> Questa tecnica prende il nome di **astrazione procedurale.**
Perché **il modulo client conosce solo l'interfaccia** e non le varie implementazioni, l’**oggetto fornito dal server** viene percepito come un **oggetto astratto**,  dalle operazioni che può eseguire.

Da qui deriva il **tipo di dato astratto**:
Il **tipo di dato astratto** specifica un **insieme di valori** e un **insieme di operazioni ammesse su tali valori**. --> Possono essere realizzati compiutamente attraverso i tipi fondamentali, ma **NON** dai tipi derivati

Un esempio tangibile di**astrazione procedurale** sono le c-stringhe realizzate con la libreria
< cstring> perché forniscono operazioni ad alto livello sulle cstringhe nascondendo completamente i dettagli implementativi sugli array di char terminati da ' \0 '.