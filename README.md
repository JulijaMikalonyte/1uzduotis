# v1.0
Sioje versijoje yra sugeneruojamas pasirinkto dydzio studentu failas, kuris yra nuskaitomas dviem budais - su vector ir list funkcijomis. Tas pats failas yra rusiuojamas 4 budais: su list (1 ir 2 strategija) ir su vector (1 ir 2 strategija). Siekiant nustatyti kiekvienos funkcijos veikimo sparta yra matuojamas funkcijos nuskaitymo arba rusiavimo laikas. 

Analizei atlikti buvo naudojama kompiuteris su siais parametrais:

CPU: Intel(R) Core(TM) i5-1035G1 CPU @ 1.00GHz, RAM:8.00, GB SSD:447GB

Rezultatai pateikiami lenteleje:

Duomenu nuskaitymas:
|           |1 000|10 000|100 000|1 000 000|
|-----------|-|-|-|-|-|
|std::list  |0.0196276 s|0.2052 s|2.05195 s|22.4245 s|
|std::vector|0.0227709 s|0.237686 s|2.75654 s|25.2598 s|

Duomenu rusiavimas 1 strategija:

|           |1 000|10 000|100 000|1 000 000|
|-----------|-|-|-|-|-|
|std::list  |0.008647 s|0.090231 s|0.856802 s|9.70607 s|
|std::vector|0.019867 s|0.200800 s|1.885019 s|20.885822 s|

Duomenu rusiavimas 2 strategija:
|           |1 000|10 000|100 000|1 000 000|10 000 000|
|-----------|-|-|-|-|-|
|std::list  |0.0138107 s|0.127788 s|1.34774 s|14.396 s|
|std::vector|0.218117 s|21.198174 s|||
