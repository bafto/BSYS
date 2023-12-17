# Question 1 

dx wird sofort -1 und das Program ist fertig

# Question 2

beide threads zählen nacheinander von 3 runter.
Keine race conditons oder ähnliches, da noch keine RAM benutzt wird, nur register

# Question 3

die threads laufen jetzt parallel, aber da sie nur register benutzen ist das kein problem

# Question 4

Ein einziger thread, also wird er ohne probleme erhöht

# Question 5

Finaler Wert ist 6, weil die threads noch nacheinander arbeiten. Warum beide 3 Mal loopen -> beide gestartet mit originalem Wert?

# Question 6

Für -s=0 ist value 2, für -s=1 auf 1. Die critical section ist im code schon kommentiert 

# Question 7

nur für -i=3 wird das richtige Ergebnis (2) erhalten, weil die critical section 3 instructions lang ist

# Question 8

bei i%3 == 0 kommt das richtige ergebnis

# Question 9

...