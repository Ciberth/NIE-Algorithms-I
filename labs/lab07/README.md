# Labo 7: Hashfuncties

## Opgave

In dit labo gaan we hashfuncties testen. De bedoeling is om ons testbestand , de woordenlijst uit een vorig labo, te nemen en elk woord in een hashtabel te steken en daarbij verschillende hashfuncties te gaan gebruiken. Het is dan ook handig als we de hashfunctie als parameter kunnen opgeven. We gebruiken hiervoor een klassedefinitie van de vorm 

```cpp
template<class T, int (*hashindex) (const T&,int)>
class Hashtabel...
```

In de code kan je hashindex dan gebruiken als een functie. Hier is het de bedoeling dat het tweede argument de grootte van de hashtabel is, zoals in het fragment 

```cpp
int index=hashindex(sleutel,size());
```

Invullen van de parameter gebeurt door de naam van een geschikte functie op te geven: 

```cpp
int slechtehash(const string& s,int grootteTabel){
return s.size() % grootteTabel;
};
...
Hashtabel<string,slechtehash> slechtehashtabel(100);
```

We gaan er hier van uit dat de constructor van een hashtabel de grootte aangeeft. We gaan werken met separate chaining, zodat we een onbeperkt aantal elementen in de hashtabel kunnen stoppen, ook als de hashtabel klein is, al gaat dat ten koste van de performantie. Ons testbestand heeft 574427 woorden; we nemen bijvoorbeeld een hashtabel met 574427 lijsten.

De gemiddelde efficiëntie van opzoeken van aanwezige sleutels bij een opgevulde tabel is

(1/n)(n+(1/2)Σ ni2),

waarbij ni de lengte van de i-de lijst is en n het aantal sleutels. Dit is een goede maat om de kwaliteit van de onderverdeling te meten. Reken dit getal uit voor het ideale geval, waarbij elke lijst ongeveer evenveel elementen bevat, om een basis te hebben .

Schrijf nu een programma dat deze gemiddelde efficiëntie voor de hierboven gegeven slechte hashfunctie en voor de iet of wat betere functie

```cpp
unsigned int hash(const string& woord,int grootteTabel) {
   unsigned int horner=0;
   for (int i=0;i<woord.size();i++)
     horner=(horner*256 + woord[i]);
   return horner%grootteTabel;
}
```

uitrekent. Als dit nog altijd slecht is, bedenk dan een goede hashfunctie. Of je idee goed is kan je uitvinden door de efficiëntie van jouw oplossing te vergelijken met deze van het ideale geval.

## Files

- [woordenlijst.txt]()

## Opmerkingen



