La **regola del cortocircuito o "shortcut rule"**  ci presenta una scorciatoia **ai fini dell'efficacia** nella porzione di codice relativa agli operatori logici **AND** e **OR**

La **regola del cortocircuito**  per **l'AND logico** dice due cose: 
1. Verrà valutata sicuramente **per prima l'espressione di sinistra**.
2. Abbiamo la certezza che **la seconda espressione non venga valutata, qualora la prima abbia restituito un risultato falso**.

==Generalizzando:== Se **il primo operando è sicuramente falso**, il secondo non verrà **mai** valutato.

**La regola del cortocircuito** per **l'Or logico** dice due cose: 
1. Verrà valutata sicuramente **per prima l'espressione di sinistra**.
2. Abbiamo la certezza che **la seconda espressione non venga valutata, qualora la prima abbia restituito un risultato vero**.