# Labo 5: Backtracking

## Opgave

Zoek een getal van n van nul verschillende cijfers (je programma leest bijvoorbeeld n in van console) dat voldoet aan
1. De som van elke vier opeenvolgende cijfers is kleiner dan 13.
2. Elke drie opeenvolgende cijfers zijn verschillend.
3. Elk cijfer is verschillend van het cijfer dat zes plaatsen verder staat.
4. De som van de cijfers is zo groot mogelijk.

Hint: een header file.

## Files

- [backtrackflex.h](https://github.com/Ciberth/NIE-Algorithms-I/blob/master/labs/lab05/backtrackflex.h)

## Opmerkingen

- Backtracking: boom afgaan in DEZ. 

- ``vector<bool> mag (10, true)`` en dan bepaalde dingen op false zetten. Vb: ``mag[cijfers-6-naar-links]=false``. Al de voorwaarden zullen bepaalde waarden uitsluiten (false)


