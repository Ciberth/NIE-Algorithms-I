# Labo 3: Anagrammen

## Opgave

Gegeven een woordenlijst. Welke groep anagrammen is het grootst? Welke paar anagrammen is het langst?

Gegeven is de tekst van een komedie. Verander de tekst door, als er voor een woord in de tekst een anagram zit in de woordenlijst, het woord te vervangen door een van de anagrammen. Kies elke keer random een vervanging uit de mogelijkheden.

## Files

- [woordenlijst.txt](https://github.com/Ciberth/NIE-Algorithms-I/blob/master/labs/lab03/woordenlijst.txt)
- [TimErwetenKoerst.txt](https://github.com/Ciberth/NIE-Algorithms-I/blob/master/labs/lab03/TimErwetenKoerst.txt)

## Opmerkingen

- ``vector<pair<string,string>> v;``

- Bij ``v.push_back(a,b)`` ga je alles kopieren.

- Bij ``v.emplace_back(move(a), move(b))`` zijn a en b string &&. Nu zal hij kijken of het move constructoren (&&) heeft.

- Zet de char alfabetisch en gebruik als **fingerprint** van de woorden.

- Een pair wordt lexicografisch gesorteerd.

- Swap **na** for-lus met i.

