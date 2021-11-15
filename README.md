# v05

v0.4 versijoje std::vector buvo pakeistas į list.
Testavimo sistemos parametrai:
CPU: Intel(R) Core(TM) i5-1035G1 CPU @ 1.00GHz, RAM:8.00, GB SSD:447GB

Duomenų nuskaitymas iš failų:

||1 000|10 000|100 000|1 000 000|10 000 000|
|-----|-----|------|-------|---------|-----------|
|std::vector|0.00152192 s|0.0973017 s|0.321546 s|3.70575 s||
|std::list||||||

Studentų rūšiavimas į dvi grupes:

||1 000|10 000|100 000|1 000 000|10 000 000|
|------|-----|------|--------|--------|------|
|std::vector|0.00099933 s|0.0320234 s|0.194738 s|2.58118 s||
|std::list||||||
