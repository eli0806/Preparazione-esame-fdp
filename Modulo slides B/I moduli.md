Un **modulo** è una **partizione del codice**( che può essere su uno o più file) **dedicata ad una funzionalità specifica.**

Un esempio può essere l'implementazione di un codice che possa garantire il client-server.

Il lato server offre risorse come tipi, variabili e funzioni. --> costituiscono **l'interfaccia**. --> il lato client usa le risorse.

==Nota:== Un modulo può svolgere entrambi i ruoli. --> Modulo actor

**Il modulo servitore** si compone così:
- **File di intestazione** --> contiene le dichiarazione delle risorse dell'interfaccia.
- **File di realizzazione** --> contiene le definizione delle risorse dell'interfaccia e le **risorse private**. --> Include il file di intestazione per non dover ripetere le dichiarazioni

**Le risorse private** sono entità utilizzate **solo all'interno del modulo** in cui vengono definite. 

==Nota:== La separazione dell'interfaccia dalla realizzazione nel modulo server garantisce [[information hiding]].

**Come le realizziamo?**

Le realizziamo attraverso l'uso della keyword **static** (vedere [[Le classi di memorizzazione di un oggetto]]) o con gli **spazi di nome** ( vedere [[visibilità]]).

**Il modulo client** invece:
- Include **solo il file di intestazione** del modulo servitore.
- Può usare **solo le risorse dell’interfaccia** dichiarate nell’intestazione.
- Non ha accesso alle **risorse private** del servitore.
- Si limita a **chiamare** funzioni, tipi e variabili offerte dal servitore, senza conoscere la loro implementazione.

