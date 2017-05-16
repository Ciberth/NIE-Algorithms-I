# Labo 9: Binaire zoekbomen

## Opgave

Gegeven zijn twee bestanden a.dat en b.dat. elk bevat 1 miljoen verschillende getallen tussen 0 en 1 miljard, in verschillende volgorde.

We gebruiken de notaties a[i] en b[i] voor het getal op de i-de plaats in respectievelijk a.dat en b.dat.

Gegeven is een positief geheel getal p. De dichtste vriend van a[i] in b.dat, v(a[i]), is dat getal in de reeks b[i-p], b[i-p+1], ... , b[i+p] dat het minst verschilt van a[i] (als er zo twee getallen zijn neem je het kleinste van de twee; uiteraard pas je de grenzen aan voor i < p of i+p ≥1000000). Bereken de som van de verschillen a[i]-v(a[i]).

**Hints:**

- Zorg ervoor dat je oplossing efficiënt is. Het kan helpen om uit te gaan van een voorbeeldwaarde p=1000 om de gedachten te vestigen.
- Misschien zijn zoekbomen wel handig.

## Files

- [a.dat]()
- [b.dat]()

## Opmerkingen



