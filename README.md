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
