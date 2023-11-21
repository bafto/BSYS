# Question 1

Mit doppeltem physischem Speicher gibt es auch doppelt so viele pages (logisch).
Mit doppelter page size halb so viele.

Im bei großen Pages wird viel Speicher verschwendet (interne Fragmentation).

# Question 2

`python ./paging-linear-translate.py -P 1k -a 16k -p 32k -v -u 0`

Alles out of bounds

`python ./pagin-linear-translate.py -P 1k -a 16k -p 32k -v -u 25`

14726 -> SEGV
11206 -> 20422 [VPN 10]
7735 -> SEGV
1649 -> SEGV
7113 -> SEGV

`python ./pagin-linear-translate.py -P 1k -a 16k -p 32k -v -u 50`

13189 -> 16261[VPN 12]
8989 -> SEGV
230 -> 24806 [VPN 0]
11791 -> SEGV
6534 -> 30086 [VPN 6]

`python ./pagin-linear-translate.py -P 1k -a 16k -p 32k -v -u 75`

11791 -> 19983 [VPN 11]
6534 -> 32134 [VPN 6]
13514 -> 27850 [VPN 13]
10947 -> 3779 [VPN 10]
18 -> 24594[VPN 0]

`python ./pagin-linear-translate.py -P 1k -a 16k -p 32k -v -u 100`

11791 -> 19983 [VPN 11]
6534 -> 32134 [VPN 6]
13514 -> 27850 [VPN 13]
10947 -> 3779 [VPN 10]
18 -> 24594[VPN 0]

# Question 3

`python ./pagin-linear-translate.py -P 8 -a 32 -p 1024 -v -s 1` realistisch, 4 Pages pro Address Space, 128 Physische

14 -> 782 [VPN 1]
20 -> SEGV
25 -> SEGV
3 -> SEGV
0 -> SEGV

`python ./pagin-linear-translate.py -P 8k -a 32k -p 1m -v -s 2` unrealistisch, weil sehr große Pages für einen kleinen Address space

21945 -> SEGV
10097 -> SEGV
19855 -> SEGV
19883 -> SEGV
19044 -> SEGV

`python ./pagin-linear-translate.py -P 1m -a 256m -p 512m -v -s 3` realistisch

50901581 -> 526955085 [VPN 48]
69423590 -> SEGV
50247291 -> 178173563 [VPN 47]
189175677 -> SEGV
230477492 -> 523030196 [VPN 219]

# Question 4

Nicht so ne gute Simulation, was?