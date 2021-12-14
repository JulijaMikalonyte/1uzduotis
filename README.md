# v0.1
Pirmos užduoties pirmos dalies (v0.1) programavimo kodai, naudojant masyva ir jų atnaujinimo istorija, talpinama main.cpp faile, kuriame užduotis įgyvendinta naudojant masyvus, vektorius.cpp faile, kuriame užduotis buvo atlikta naudojant vektorius ir release'uose.

Kodai esantys abiejuose failuose turi galimybę leisti vartotojui pasirinkti ar jis nori pats suvesti kiekvieno studento pažymius ar juos parinkti atsitiktinai. Gautus duomenis programa apdoroja (suskaičiuoja galutinį pažymį naudojant vidurkį arba medianą) ir peteikia skaičiavimų rezultatus ekrane.

Abiejuose failuose, priklausomai nuo vartotojo pasirinkimo ar jis nori pats suvesti duomenis, ar nori, kad jie būtų parenkami atsitiktinai, surenkami duomenys. Tada apskaičiuojama mediana ir vidurkis. Priklausomai nuo vartotojo pasirinkimo atspausdinamas norimas atsakymas.

# v0.2
Pirmos užduoties antros dalies (v0.2) kodas talpinamas v02kodas.cpp faile, kuris yra vektorius.cpp failo papildymas, ir release'uose.

Papildytas kodas geba nuskaityti failą, atlikti įprastus skaičiavimus jau aprašyta tvarka ir atsakymą pateikti išrušiuotą.

Skaičiavimams atlikti buvo pasinaudota tekstiniu failu kursiokai.txt, o atlikus visus skaičiavimus rezultatai pateikti naujame tekstiniame faile rezultatai.txt.

# v0.3
Šioje versijoje buvo atliktas antros užduoties kodo (v02kodas.cpp) reorganizavimas, todėl projekto kodas buvo padalintas i kelis .cpp ir .h failus. Taip pat keliose vietose buvo panaudotas išimčių valdymas (angl. Exception Handling)

# v0.4
Šioje versijoje sugeneruoti penki skirtingų dydžių failai padalinti į dvi kategorijas: studentai kurių galutinis balas >= 5 (priskiriami prie protingu) ir studentai, kurių galutinis balas < 5 (priskiriami prie vargšiukų).
Taip pat atlikta programos spartos analizė parodo, kiek laiko užtruko sukurti failus, iš jų nuskaityti duomenis, surūšiuoti studentus į dvi kategorijas ir jas išvesti i dų naujus failus.

# v0.5
v0.4 versijos kodo std::vector buvo pakeistas į list.
Testavimo sistemos parametrai:
CPU: Intel(R) Core(TM) i5-1035G1 CPU @ 1.00GHz, RAM:8.00, GB SSD:447GB

Duomenų nuskaitymas iš failų:

||1 000     |10 000      |100 000    |1 000 000 |
|-----------|------------|-----------|----------|---------|
|std::vector|0.00152192 s|0.0973017 s|0.321546 s|3.70575 s|
|std::list  |0.00150703 s|0.0228388 s|0.366652 s|4.13927 s|

Studentų rūšiavimas į dvi grupes:

||1 000     |10 000      |100 000    |1 000 000 |
|-----------|------------|-----------|----------|---------|
|std::vector|0.00099933 s|0.0320234 s|0.194738 s|2.58118 s|
|std::list  |0.00104016 s|0.0136476 s|0.238717 s|2.40062 s|


# v1.0
Sioje versijoje yra nuskaitomas dviem budais pasirinkto dydzio studentu failas - su vector ir list funkcijomis. Tas pats failas yra rusiuojamas 4 budais: su list (1 ir 2 strategija) ir su vector (1 ir 2 strategija). Siekiant nustatyti kiekvienos funkcijos veikimo sparta yra matuojamas funkcijos nuskaitymo arba rusiavimo laikas. 

Analizei atlikti buvo naudojama kompiuteris su siais parametrais:

CPU: Intel(R) Core(TM) i5-1035G1 CPU @ 1.00GHz, RAM:8.00, GB SSD:447GB

Rezultatai pateikiami lenteleje:

Duomenu nuskaitymas:
|           |1 000|10 000|100 000|1 000 000|
|-----------|-|-|-|-|
|std::list  |0.036876 s|0.183235 s|1.458242 s|14.468193 s|
|std::vector|0.043140 s|0.416005 s|5.030652 s|32.733519 s|

Duomenu rusiavimas 1 strategija:

|           |1 000|10 000|100 000|1 000 000|
|-----------|-|-|-|-|
|std::list  |0.033757 s|0.174929 s|1.490355 s|14.566340 s|
|std::vector|0.042308 s|0.334319 s|3.741953 s|30.399918 s|

Duomenu rusiavimas 2 strategija:
|           |1 000|10 000|100 000|1 000 000|
|-----------|-|-|-|-|
|std::list  |0.034522 s|0.280803 s|2.650846 s|25.889139 s|
|std::vector|0.019978 s|0.131883 s|1.137591 s|10.551081 s|
