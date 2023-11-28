# Question 1

FIFO:

miss 8
miss 7,8
miss 4,7,8
miss 2,4,7
miss 5,2,4
hit  5,2,4
miss 7,5,2
miss 3,7,5
miss 4,3,7
miss 5,4,3

LRU:

miss 8
miss 7,8
miss 4,7,8
miss 2,4,7
miss 5,2,4
hit  4,5,2
miss 7,4,5
miss 3,7,4
hit  4,3,7
miss 5,4,3

# Question 2

FIFO:

1, 2, 3, 4, 5, 6, 1, 2, 3, 4, 5

Es reicht schon die cache-größe um 1 zu erhöhen

LRU:

1, 2, 3, 4, 5, 6, 1, 2, 3, 4, 5

""

MRU

1, 2, 3, 4, 5, 6, 5, 6, 5, 6, 5

""

# Question 3

1, 7, 3, 9, 2, 7, 6, 3, 1, 9, 3, 6, 5

Zufällig war MRU am besten.
Man kann nicht vorraussagen welcher am besten ist, da bei zufälligen Zahlen locality o.ä. keine Rolle spielt.

# Question 4

1, 2, 3, 4, 5, 4, 5, 1, 2, 3, 4, 5, 4, 5, 1, 2, 3, 4, 5, 4, 5

LRU nicht so gut zufällig (cache größe gleich 3) weil ich den edge-case getroffen habe (Loop größer als cache).
CLOCK und MRU am besten. (mit 2 clockbit besser als mit 1)

# Question 5

    