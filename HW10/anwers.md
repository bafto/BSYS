# Question 1

`python ./malloc.py -n 10 -H 0 -p BEST -s 0 -c`

Alloc(3) = 1000
List(1): [addr: 1003, size: 97]

Free(ptr[0]) = klappt
List(2): [addr: 1000, size: 3], [addr: 1003, size: 97]

Alloc(5) = 1003
List(2): [addr: 1000, size: 3], [addr: 1008, size: 92]

...

Die Free Liste wird in viele kleine Stücke zerlegt, weil coalesce = false

# Question 2

`python ./malloc.py -n 10 -H 0 -p WORST -s 0 -c`

Die Free List wird in noch mehr Stücke zerteilt

# Question 3

`python ./malloc.py -n 10 -H 0 -p FIRST -s 0 -c`

Alloc wird schneller, weil nicht die ganze Free List traversed wird

# Question 4

First -> aufsteigend gut
Best -> kommt drauf an wie viel auf einmal allocated wird
Worst -> ""

# Question 5

Ohne Coalescing sind große Anfragen schnell out-of-memory

# Question 6

