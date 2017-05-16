# Labo 6: Algemene bomen (dorp.xml)

## Opgave

### Opdracht 1

Gegeven het bestand dorp.xml. Schrijf een programma dat voor elke bakker het adres uitschrijft in het formaat

``<naam bakkerij> <straatnaam> <dorp>``

Deze lijst moet alfabetisch gesorteerd zijn op naam.

Om XML in te lezen kan je gebruik maken van pugixml, met de documentatie [hier](http://pugixml.org/docs/quickstart.html). Om heel snel te starten: pugixml maakt gebruik van niet-voorgecompileerde code in de bestanden

pugixml.hpp
pugixml.hpp
pugixml.cpp

Je kan het laatste bestand apart compileren naar een bibliotheek die je dan meelinkt. Je moet dan het eerste bestand includen in je code. Alternatief is om het laatste bestand te includen in je eigen broncode, zonder gebruik van aparte bibliotheek. Dit is gebeurd in de voorbeeldcode van leesvoorbeeld.cpp. Deze gebruikt treingraaf.xml.
Opmerking: Je zou verwachten dat de waarde van een simpel element bij de knoop voor dat element zit. Dat is niet zo. Stel dat je een xml-fragment

``<dinges>Tekstwaarde</dinges>``

hebt en een pugi::xml_node n waarvoor n.name() gelijk is aan "dinges", dan is n.value() de lege string, maar n.first_child().value() is gelijk aan "Tekstwaarde".

### Opdracht 2

Doe nu het zelfde met dorp2.xml. Gebruik ook een programma dat, bij het DE-overlopen van de boom, gebruik maakt van een expliciete stack met verwijzingen (in dit geval placeholders) naar de ouderknopen, zodat je de parent-functie niet meer nodig hebt.


## Files

- [dorp.xml]()
- [pugixml.hpp]()
- [pugixml.hpp]()
- [pugixml.cpp]()
- [dorp2.xml]()
- [leesvoorbeeld.cpp]()
- [treingraaf.xml]()

## Opmerkingen



