# Samenvattingsvragen 

## H3: Eenvoudige methodes

### Bespreek de efficiëntie van insertion sort, selection sort, shellsort.




### Bespreek shellsort (+ eigenschap) en toon aan waarom k-sorteren werkt. 





## H4: Efficiënte methodes


### Hoe kan je heaps construeren. Toon ook de performatie aan. Er zijn twee methodes om een heap te construeren van een bestaande tabel. Bespreek en geef performanties. Bijvraag: waarom is heapconstructie toevoegen minder performant dan samenvoegen.


### Bespreek heapsort, mergesort, quicksort.


### Waarom kan een quicksort slecht uitdraaien. Bespreek de methode(s) die dit probleem oplossen. Geef ook performanties.


### Bewijs het gemiddelde geval van de quicksort.



## H5: Speciale methodes


### Bewijs de theoretische ondergrens voor sorteren. Geef het slechtste en gemiddelde geval.


### Bespreek Radix sort, bucket sort. Leg ook uit waarom ze al dan niet stabiel zijn en geef de performantie.



## H6: De selectie operatie

### Leg de selectie operatie uit.



## H7: Uitwendig rangschikken

### Wat is selection replacement en hoe wordt het geïmplementeerd?

### Leg uit wat een selectieboom is. Performantie van toevoegen, verwijderen enz.. en een implementatievoorbeeld.



## H8: Containers

### Bespreek de prioriteitswachtrij.

### Bespreek inorder, preorder, postorder overlopen van een graaf met performanties.
```
<img src="http://www.geeksforgeeks.org//wp-content/uploads/tree6.png" alt="Binary tree" width="200px"/>
inorder: 1 - 3 - 4 - 6 - 7 - 8 - 13 - 14 - 10 (left - root - right)
pre-order: 8 - 3 - 1 - 6 - 4 - 7 - 10 - 14 - 13 (root - left - right)
post-order: 1 - 4 - 7 - 6 - 13 - 14 - 10 - 8 ( left - right - root)
```
### Bespreek BEZ zo uitgebreid mogelijk.
```
1.	Kies start vertex S
2.	Wie is vanaf S bereikbaar (booglengte 1)
3.	Wie is vanaf die indices bereikbaar (1 voor 1 overlopen)

Soorten verbindingen:
Branch (=BOOMTAK)	Verbinding met nog niet ontdekte knoop
Back-edge (=TERUGVERBINDING)	Verbinding met voorouder (ongerichte graaf heeft NOOIT terugverbindingen)
Cross edge (=DWARSVERBINDING)	Verbinding met knoop die geen voorouder is
Forward edge (=HEENVERBINDING)	GEEN

Efficiëntie
	Initialisatie, alle knopen niet ontdekt: θ(n)
	Elke knoop op wachtrij geplaatst en afgehaald, operaties op wachtrij θ(1) dus voor alle knopen samen: θ(n)
	Alle buren elke knoop overlopen: θ(m) voor lijst, θ(n^2 ) voor burenmatrix
totaal: θ(n+m)  voor lijst, θ(n^2) voor matrix (hangt af van representatie)
```

```cpp
Breadth-First-Search(Graph, root):
    
    create empty set S
    create empty queue Q      

    add root to S
    Q.enqueue(root)                      

    while Q is not empty:
        current = Q.dequeue()
        if current is the goal:
            return current
        for each node n that is adjacent to current:
            if n is not in S:
                add n to S
                n.parent = current
                Q.enqueue(n)
```                



### Bespreek DEZ zo uitgebreid mogelijk. 
```
Kies start vertex S
	Bezoek recursief alles dat nog niet bezocht is via buur van S
	Indien over, kies andere buur
 
Soorten verbindingen
Branch (=BOOMTAK)	Verbinding met nog niet ontdekte knoop
Back-edge (=TERUGVERBINDING)	Verbinding met niet afgewerkte knoop
Forward edge (=HEENVERBINDING)	Verbinding met afgewerkte knoop
Cross edge (=DWARSVERBINDING)	Verbinding met knoop die geen voorouder is

Efficiëntie
	Initialisatie: θ(n)
	Elke knoop éénmaal ontdekt, dus ook éénmaal behandeld: θ(n)
	Van elke knoop alle buren onderzocht: θ(m) voor lijst, θ(n^2 ) voor burenmatrix
totaal: θ(n+m)  voor lijst, θ(n^2) voor matrix (hangt af van representatie)
Implementatie
```

```cpp
void behandel_knoop(int i) {
  ontdekt[i] = true; // de te behandelen knoop is nu ontdekt
  
  for(alle buren j van knoop i) 
    if(!ontdekt[j]) // als de buur nog niet ontdekt is
      behandel_knoop(j);
}

void diepte_eerst_zoeken() {
  // initialisatie
  for(int i = 0; i < n; i++) 
    ontdekt[i] = false;

  // behandel alle knopen die nog niet ontdekt zijn
  for(int i = 0; i < n; i++)
    if(!ontdekt[i])
      behandel_knoop(i);
}
```


### Hoe kun je zoeken in een tabel + performantie.

## H9: Eenvoudige woordenboeken

### Leg de verschillende mogelijkheden uit.
```
Rechstreeks adresseerbare tabel	= Associatieve array
Alle operaties zijn O(1)
Ongeordende tabel		Zoeken: volledige tabel doorgaan tot gevonden: O(n)
	Toevoegen: achteraan O(1)
	Verwijderen: O(1)
Tabel geordend volgens zoekkans		Frequentie van zoeken bijhouden, tabel rangschikken volgens frequentie (dalend)
	Gevonden element verwisselen met voorloper (dynamische verbetering)
Gerangschikte tabel	Sleutels geranschikt
	Zoeken:
	Sequentieel zoeken: sequentieel tabel overlopen via sleutel waarden
	Binair zoeken: vergelijk gezochte sleutel met middelste element van de tabel, zo weet men in welk deel te zoeken, dit herhalen O(lg⁡〖n)〗, l+(r-l)*1/2
	Interpolerend zoeken: test op de plaats waar de sleutel verwacht wordt, verhouding berekenen:  (s-v[l])/(v[r]-v[l] ) ipv 1/2  
	Toevoegen: na plaats nieuwe sleutel, gem helft tabel opschuiven, in slechtste geval volledige O(n)
	Verwijderen: idem toevoegen O(n)
Ongeordende lijst		Zoeken: sequentieel O(n)
	Toevoegen: vooraan O(1)
	Verwijderen: O(1)
Lijst geordend volgens zoekkans	Beste volgens dalende zoekwaarschijnlijkheid.
Gerangschikte lijst		Zoeken: Geen directe toegang O(n)
	Toevoegen: sequentieel overlopen vor plaats te lokaliseren O(n)
	Verwijderen: zelfde als toevoegen O(n)

```

## H10: Hashtabellen

### Leg de verschillende adresseringsmogelijkheden uit en bespreek + performantie.

```
Is een datastructuur die keys aan waarden kan linken
	Voor het opdelen van grote data (vb arrays) in `buckets`
	Collision: als er waarden zijn met zelfde key
  
*Chaining*
Methode die gebruik maakt van gelinkte lijsten

*Separate chaining*
Alle sleutels bij zelfde tabelindex in gelinkte lijst. De elementen van de hashtabel zijn lijsten.
Om gemiddelde performantie van O(1) te hebben moet α=O(1). De grootte van de hashtabel moet evenredig zijn met het aantal opgeslagen sleutels.

*Zoeken	O(n)*

Via hashwaarde van sleutel komen we in linked list terecht, hierin kan men enkel sequentieel zoeken

*Toevoegen	O(1)*
Nieuw element wordt vooraan toegevoegd, voordeel  wordt snel gevonden

*Verwijderen	O(1)*

*Coalesced chaining*

Coalesced = samengevoegd  Het samenklitten (coalesced) van lijsten.
tabel van lijstknopen (kan waarde + verwijzing naar ander element opslaan)

**Zoeken	O(?)**
Begint in adreszone, bij index die hashfunctie oplevert. Stopt als knoop op die plaats de sleutel bevat

**Toevoegen	O(?)**
Laatste lege plaats in tabel gebruiken

**Verwijderen	O(?)**
Lijsten klitten samen  verwijderen lastig. Tag knoop als `removed` en negeer bij zoeken

*Open adressering*

Methode voor oplossen van collisions. Een collision wordt opgelost door probing 
Probing = zoeken door alternatieve locaties in de array tot een target record of ongebruikt slot gevonden is.
Zoeken	Begint bij index die hashfunctie oplevert, stopt als sleutel gevonden. Als plaats ledig blijkt, is de sleutel afwezig. Indien andere sleutel bevat, zoekt men op andere plaatsen.

**Efficiëntie**: zoeken naar aanwezige sleutel, zelfde als wanneer hij toegevoegd werd.
**Toevoegen**:	Als zoeken een ledige plaats oplevert, sleutel wordt hierin toegevoegd.
**Verwijderen**:	Lazy deletion, aanduiding dat inhoud verwijdert werd

*Soorten probing*

**Linear probing**:	Het interval tussen probes is fixed (meestal 1)
h(k,i)=(h^' (k)+i)  % m

**Quadratic probing**	Het interval tussen probes verhoogt linear (indices beschreven door een kwadratische functie)
(h(s)+c_1 i+c_2 i^2 )  % m

**Double hashing**	Interval tussen probes is fixed voor elke record maar berekend door een andere hash functie
(h(s)+ih^' (s))  % m
```

### Bespreek de hashfuncties.

Bepaalt waar men items opslaat en ophaalt in een hashtabel.
Men geeft een item key als parameter en krijgt een indexlocatie van het item terug. 
**Vb. String als parameter, telt ASCII waarden op en men neemt % tabellengte om zo een bucketId te verkrijgen**

```cpp
int hash( string key )
{
    int value = 0;
    for ( int i = 0; i < key.length(); i++ )
        value += key[i];
    return value % tableLength;
}
```

*Universele hashing*
Is het selecteren van een hashfunctie, random gekozen uit een groep hash functies. Dit garandeert een laag aantal collisions.


### Leg het begrip clustering uit. Het probleem van Clustering uitleggen. Welk algo wordt hiervoor gebruikt en de performantie ervan.


## H11: Binaire zoekbomen

### Bespreek alle operaties die te maken hebben met de volgorde in binaire zoekbomen. 
*Zoeken*
O(log⁡ n)		O(n)

*Performantie*

Lengte afgelegde weg is nooit groter dan hoogte boom, in het slechtste geval: n-1
Als de i-de sleutel wortel is  linkse deelboom bevat i-1 sleutels gem weglengte: D(i-1)
Met die wortel is de gemi. Inwendige weglengte: D(i-1)+D(n-i)+n-1

*Toevoegen*
O(log⁡ n)		O(n)
 
*Verwijderen*
O(log⁡ n)		O(n)
```
Als er niet veel sleutels moeten verwijderd worden  `lazy deletion`
1 KIND		Update parent node
	Set node to null
2 KINDEREN		Verkrijg max/min van linkse/rechtse sub-tree en maak ReplacingNode
	Update ReplacingNode kind node
	Update ReplacingNode parent node
	Afhandelen van overgeërfde, recursieve pointers
	Zet node to null
GEEN KINDEREN		Zet node to null
IS ROOT NODE		Run zelfde algoritme als hierboven
	Update tree root node
	Zet node to null
```


### Bewijs de performantie van zoeken in binaire zoekbomen.

### Wat zijn threaded trees? 
Variant op binaire boom, snellere traversal  pointer naar in-order successor

Binaire zoekboom waarbij een vormalige 

o	rechtse nullpointer naar opvolger van de knoop verwijst.
o	Linkse nullpointer naar voorloper van de knoop verwijst
Voordeel: geen stapel meer nodig om boom in inorder te overlopen


### Hoe verwijder je een element uit een binaire zoekboom en threaded tree? Geef performantie.



## H12: Minimale overspannende bomen

### Leg het begrip MOB uit.

Wortelloze boom met dezelfde knopen en met een deel van de verbindingen als takken.

### Leg het algoritme van Prim uit.

1.	Lege lijst `visited`
2.	Kies een startnode (A)
3.	Voeg het toe aan de `visited` list
4.	Kies node met laagste edge weight, bereikbaar vanaf A
5.	Kies telkens laagste edge weight, van visited naar unvisited node


### Leg het algoritme van Kruskal uit.
Voer zoveel mogelijk uit: Kies uit bogen G, die nog niet gekozen warden, de korste boog die geen kring vormt met de bogen die reeds warden gekozen.

### Leg BEZ uit bij grafen. Bijvraag: Teken de dwarsverbindingen bij een ongerichte graaf.

### Bespreek efficiente union-find operaties op disjuncte deelverzamelingen. Wat is de efficientie? Verklaar.


## H13: Kortste afstanden

### Bespreek Dijkstra.
Het duurt O(log⁡ V) om een vertex van de priority queue te halen. Voor elke incident edge, spenderen we O(log⁡ V)
 
Algoritme van Dijkstra 
worst-case: O(E+V log⁡ V)

1. Alle nodes op ∞ behalve start
2. Start node is current, andere unvisited + maak set met unvisited nodes 
3. Huidige node: consider alle buren en bereken hun voorlopige afstand. Vergelijk deze nieuwe afstand met de huidige assigned value. Assign de kleinste van de 2 
4. Markeer huidige node als visited en verwijder van de unvisited set
5. Als destination als visited gemarkeerd  stop algoritme
6. Anders, selecteer unvisited node met kleinste voorlopige afstand en dit is nieuwe huidige node

```cpp
priority_queue <int,vector<int>,cmp> pq;
int dijkstra(int from,int to)
{
    vector <bool> visited(N,false); 
    visited[from] = true;
    cost [from] = 0;
    pq.push(from);
    while(!pq.empty() && !visited[to])
    {
        int current = pq.top();
        pq.pop();
        visited[current] = true;
        for(int i=0;i<graph[current].size();i++)
        {   
            if(!visited[graph[current][i]])
            {
                cost[graph[current][i]] 
= min(cost[graph[current][i]] ,cost[current]+ weight[current][i]);
                pq.push(graph[current][i]);
            }
        }
    }
    return cost[to];
}
```



### Bespreek dynamsich programmeren.

### Bespreek het algoritme van Floyd-Warshall.

O(|N|^3) met N = aantal nodes van de graaf
	Laat negatieve gewichten toe
	In praktijk veel sneller
Voor het zoeken van het kortste, langste pad onder alle nodes in een graaf

```
procedure [array] FloydWarshall(D, P)
for k in 1 to n do
  for i in 1 to n do
    for j in 1 to n do
      if D[i][j] > D[i][k] + D[k][j] then
        D[i][j] = D[i][k] + D[k][j]
        P[i][j] = P[k][j]
  return P
```

## H14: Gerichte lusloze grafen

### Wat is topologisch rangschikken en hoe kan dat efficiënt gebeuren. 

### Bespreek de mogelijkheden om topologisch rangschikken te implementeren.

### Hoe vind je de kortste weg in een lusloze graaf + performanties. Hoe gebeurt dit bij projectplanning. 
