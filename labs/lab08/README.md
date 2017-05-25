# Labo 8: Doorlopen van grafen

## Opgave

### Opdracht 1

Gegeven is de hoofding (en een gedeelte code) voor de klasse Graaf in graaf.h. Deze bevat een hiërarchie van grafen.
Gevraagd is om een lidfunctie

``int Graaf::dichtste(int start, const vector& doel)``

te schrijven. Deze geeft de knoop uit de doeltabel die het dichtste bij start ligt (om precies te zijn: die in het kleinst aantal stappen kan bereikt worden vanuit start). Als er verschillende doelknopen even ver liggen geef je er toch maar een terug; als geen van de doelknopen verbonden is met start dan wordt -1 teruggegeven.
Opmerkingen:

Je kan je code even uitproberen met het programma graaf.cpp. Dit maakt op zijn beurt gebruik van de graaf opgeslagen in graafdichtste.dat en van een stopwatch.h. De graaf is gericht. De notatie is uiterst eenvoudig:
Op de eerste lijn staat het aantal knopen.
Op volgende lijnen staat telkens een verbinding, met startknoop en eindknoop.
Op de laatste lijn staat -1.

### Opdracht 2
Breid nu de functie dichtste uit zodat je het _volledige pad_ van start naar de dichtstbijzijnde knoop teruggeeft. Vermits die knoop de laatste is op het pad moet je hem niet apart teruggeven:

``std::list Graaf::dichtstePad(int start, const vector& doel)``

## Files
- [graaf.h](https://github.com/Ciberth/NIE-Algorithms-I/blob/master/labs/lab08/graaf.h)
- [graaf.cpp](https://github.com/Ciberth/NIE-Algorithms-I/blob/master/labs/lab08/graaf.cpp)
- [graafdichtste.dat](https://github.com/Ciberth/NIE-Algorithms-I/blob/master/labs/lab08/graafdichtste.dat)
- [stopwatch.h](https://github.com/Ciberth/NIE-Algorithms-I/blob/master/labs/lab08/stopwatch.h)

## Opmerkingen

- De file graafdichtste.dat heeft een vaste structuur. Op de eerste regel staat het aantal verbindingen en vervolgens telkens (per regel) een verbinding. Van x naar y. De einde van de file heeft een -1 om een stop aan te duiden.

- Maak gebruik van een vector van ints (knoopnrs). De vraag is dan "welke staat het dichtst bij start (opgegeven)".

- 

