# v1.0
Sioje versijoje yra sugeneruojamas pasirinkto dydzio studentu failas, kuris yra nuskaitomas dviem budais - su vector ir list funkcijomis. Tas pats failas yra rusiuojamas 4 budais: su list (1 ir 2 strategija) ir su vector (1 ir 2 strategija). Siekiant nustatyti kiekvienos funkcijos veikimo sparta yra matuojamas funkcijos nuskaitymo arba rusiavimo laikas. 

Analizei atlikti buvo naudojama kompiuteris su siais parametrais:

CPU: Intel(R) Core(TM) i5-1035G1 CPU @ 1.00GHz, RAM:8.00, GB SSD:447GB

Rezultatai pateikiami lenteleje:

Duomenu nuskaitymas:
|           |1 000|10 000|100 000|1 000 000|
|-----------|-|-|-|-|
|std::list  |0.0016628 s|0.0179035 s|0.178326 s|1.86675 s|
|std::vector|0.0015485 s|0.0153419 s|0.170166 s|1.77313 s|

Duomenu rusiavimas 1 strategija:

|           |1 000|10 000|100 000|1 000 000|
|-----------|-|-|-|-|
|std::list  |0.0003204 s|0.0022688 s|0.0238407 s|0.274638 s|
|std::vector|0.000200 s|0.002228 s|0.026033 s|0.261736 s|

Duomenu rusiavimas 2 strategija:
|           |1 000|10 000|100 000|1 000 000|
|-----------|-|-|-|-|
|std::list  |0.0003019 s|0.0027693 s|0.0259407 s|0.287495 s|
|std::vector|0.000965 s|0.103096 s| | |
