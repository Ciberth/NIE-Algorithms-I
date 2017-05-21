# Labo 2: Sorteerbare vectoren

## Opgave


In de komende lessen gaan we de snelheid van een aantal sorteeralgoritmes vergelijken.

### Sorteeralgoritme

Elk sorteeralgoritme implementeren we als een klasse die de functie-operator () implementeert. (Een object van zo'n klasse noemen we een functor.) Deze operator zal één parameter nemen, nl. een STL-vector. Deze vector wordt door de operator () gesorteerd volgens het geïmplementeerde algoritme.
Al die klassen (eentje voor elke sorteermethode) erven van de abstracte klasse Sorteermethode, die enkel de functie-operator () bevat. Om verschillende soorten gegevens in de te sorteren vector toe te laten, zijn de klassen geparametriseerd.

### Sorteerbare vectoren

Om sorteermethodes te kunnen vergelijken, moet je ook onderscheid maken wat betreft de gegevens die je sorteert. Sorteer je veel of weinig gegevens? Sorteer je ongeordende, (bijna) geordende, omgekeerd geordende gegevens? Sorteer je kleine (int) of grote (Telefoonboek) gegevens? Sorteermethodes die over het algemeen snel werken, kunnen onder bepaalde omstandigheden immers heel traag uitvallen. Dat zou je moeten terugvinden in de meetresultaten.
Daarom implementeren we de klasse Sortvector<T>. Dit is een geparametriseerde klasse, zodat we kunnen variëren in de soort gegevens die we willen sorteren.

### Meetresultaten

Tenslotte willen we tijden opmeten. Daarvoor heb je al de klasse Chrono. Het is echter weinig interessant om absolute cijfers te kennen -- dus gaan we voor een tabel van verschillende meetresultaten die we kunnen vergelijken.
Willen we bevestigd zien dat een methode O(n2) of O(log n) is, dan laten we n (= lengte van de vector) variëren tussen twee grenzen (kortste en langste, met ni+1 = 10*ni+1).
Opsplitsen naargelang de begintoestand van de vectoren (random, gesorteerd, omgekeerd gesorteerd, veel dubbels,...) is ook interessant.

### Opdracht 1

Implementeer de klasse Sortvector<T>.

Merk op: indien je de code uittest voor Sortvector<int> zouden er geen problemen mogen zijn. Test je uit voor Sortvector<double>, dan zou dit wel het geval kunnen zijn. Is dat zo, en waar ligt dit aan? Los op indien nodig.
Voorlopig moet je nog niet uittesten met andere types; dat komt in opdracht 4 aan bod.

Tip Om een random permutatie van elementen te genereren (zie shuffle), is de methode van Knuth / Fisher-Yates / Durstenfeld de standaard. Deze methode (zoek op!) vraagt dat je uit n getallen er random ééntje kiest. Dat kan met de randomgenerator uit de cstdlib-bibliotheek. Het gebruik hiervan: helemaal in het begin van je main-functie initialiseer je de generator met het commando srand(time(0)) (waarbij time() te vinden is in de ctime-bib). Een willekeurig geheel getal krijg je door de oproep rand(); Als je een getal tussen 0 en 100 wil (100 niet inbegrepen), dan neem je rand() % 100 .

Bedenking Ga eens na hoe groot de getallen die rand() produceert kunnen worden: zoek in climits naar RAND_MAX en INT_MAX. Als die overeenkomen, kan je de methode rand() met gerust hart gebruiken om een gegeven vector dooreen te haspelen. Indien RAND_MAX kleiner is dan INT_MAX kan dat niet. (Leg uit.) C++ beschikt over nieuwe klassen voor random-generatoren, die bovendien veel extra mogelijkheden bieden. Je kan hier je weg in zoeken, maar pas als opdrachten 1 tot en met 4 af zijn.

### Opdracht 2

Gebruik de klasse Sorteermethode om een vector te sorteren. (Dit is dus enkel nagaan dat jouw Sortvector kan samenwerken met de functieklassen STLSort en InsertionSort; in het bestand sortheermethode.h zelf moet je nog niets toevoegen.)

### Opdracht 3

Implementeer de lidfunctie
meet(int kortste, int langste, ostream & os)
van de klasse Sorteermethode. Als output komt er iets van de volgende vorm (pin je niet vast op de waarden; die zijn fictief):

```
   lengte     random  gesorteerd   omgekeerd
       10          0        0          0
      100          5        0          0
     1000         14        8          8
    10000        250      209        200
   100000        700      260        281
```

De methode genereert dus tabellen van lengte kortste*10i (i=0,1,2,...) en chronometreert hoe lang het sorteren duurt.
Tip Als je van wat meet uitschrijft een nette tabel wil maken, gebruik dan setw (staat in de headerfile iomanip). Een voorbeeldje: als je schrijft

``cout<<setw(8)<<123;``

dan worden er 5 spaties voor 123 gezet, zodat er in het totaal 8 karakters worden uitgevoerd.
Extra Kan je met deze resultaten grafieken maken in Excel? Eventueel zorg je voor puntkomma's tussen de gegevens (CSV-formaat).

CSV-bestanden Een hulpklasse voor het maken van csv-bestanden is te vinden in csv.h. Let op: de defaultwaarde van het gebruikte scheidingsteken is `.'. Dit is niet geschikt voor rekenbladprogramma's met een niet-Engelstalige instelling, waarbij vlottendekommagetallen worden voorgesteld met een vlottende komma. Hoe je een .csv-bestand produceert waar het punt vervangen is door een vlottende komma, vind je in de API van de klasse CsvData:

De klasse CsvData wordt gedefinieerd in de header csv.h. Elk object van de klasse komt overeen met één .csv-bestand, waarin getalwaarden worden opgeslagen. Vermits de meeste rekenbladen grafieken kunnen opmaken met verschillende gegevensreeksen, waarbij elke gegevensreeks standaard opgeslagen is in een kolom, slaat elke CsvData gegevens ook op deze manier op. De API is de volgende

CsvData(const std::string& _bestandsnaam, char _scheidingsteken='.')
Creëert een CsvDataobject. De parameter _scheidingsteken duidt aan welk teken geheel en fractioneel deel scheidt in een vlottendekommagetal. Defaultwaarde is '.', voor niet-Engelse rekenbladen dient ',' opgegeven te worden.

```cpp
template class<class T>
voegDataToe(const std::vector<T>& nieuwedata)
```

Voegt een kolom met numerieke waarden toe. T kan een willekeurig type zijn dat met ``static_cast<double>`` kan worden omgezet naar double.

### Opdracht 4

Het kopiëren en vergelijken van sleutels vraagt tijd. De resultaten van de meting zijn dan ook afhankelijk van het soort van sleutels dat je sorteert. Nu willen we de meting overdoen met strings. Probleem is echter dat de klasse Sortvector random gehele getallen in de vector probeert te steken. Maak nu een nieuwe klasse Intstring (Numerieke string). Je vindt een voorbeeldje in intstring.h. Dit is een gewone string, maar je kan er een geheel getal aan toekennen. De string wordt dan het getal uitgeschreven in tiendelige cijfers. Vergelijk de resultaten van meet als je deze getallen gebruikt met degene die je krijgt met ints.

### Opdracht 5

Implementeer top-down mergesort.
Gebruik slechts 1 hulptabel van dezelfde lengte als de oorspronkelijke. Je methode mag dus maar een keer een extra vector aanmaken, en moet uiteraard nodeloos kopiëren zoveel mogelijk vermijden.

Denk dus na hoe je de recursie uitvoert: wat geef je door als parameters, wat moet de recursie juist doen, wat gebeurt er op het laagste niveau, wat moet er gebeuren voor en na de recursie zelf? Het vraagstuk blijkt delicaat te zijn. Geef ook aan hoe je gaat controleren, nadat je een tabel hebt gesorteerd, dat het resultaat niet alleen een gesorteerde tabel is, maar ook een tabel met dezelfde elementen als de oorspronkelijke. Welke speciale gevallen ga je testen? Werk dit uit op papier voor je begint te programmeren: je mag geen code ingeven voor je je ontwerp hebt laten goedekeuren door een begeleider.

### Opdracht 6

Implementeer een O(n2)-implementatie voor

```cpp
int Sorttab::geefaantalinversies() const;
```

Zoek een betere methode. Het kan in O(n log(n)). Tip: als je in mergesort stopt voor de laatste stap heb je twee gesorteerde halftabellen na elkaar. Hoe vind je daar het aantal inversies (dit kan in O(n))? Hoeveel inversies ben je kwijtgespeeld door de twee halftabellen te sorteren?



## Files

- [sorteermethode.h](https://github.com/Ciberth/NIE-Algorithms-I/blob/master/labs/lab02/Sorteermethode.h)
- [sortvector.h](https://github.com/Ciberth/NIE-Algorithms-I/blob/master/labs/lab02/sortvector.h)
- [chrono.h](https://github.com/Ciberth/NIE-Algorithms-I/blob/master/labs/lab02/chrono.h)
- [csv.h](https://github.com/Ciberth/NIE-Algorithms-I/blob/master/labs/lab02/csv.h)
- [intstring.h](https://github.com/Ciberth/NIE-Algorithms-I/blob/master/labs/lab02/intstring.h)


## Opmerkingen



