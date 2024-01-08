# Frage 1

code verstehen ...

# Frage 2

Mit wenigen werten (e.g. 1-5) macht die Buffer Größe keinen großen Unterschied. Am Anfang füllt der Producer einfach solange bis der Buffer voll ist, und wartet dann auf den Consumer.
Bzw. wenn der Consumer zuerst dran ist wechseln sie sich ab.

Mit den Sleep Einstellungen aus der Aufgabe ist der Buffer praktisch immer voll, da der Consumer nach jedem consumen etwas abwartet. Dadurch kommt dann das Muster zustande, dass der Buffer
voll ist und immer der vorderste slot leer wird und weiter wandert.

# Frage 3

not possible.

# Frage 4

Im Schnitt dauert es so 11,5 Sekunden. Das war auch zu erwarten, da es mindestens 10 Sekunden dauern muss und dann noch etwas länger wegen overhead wenn auf die Bedingungen gewartet wird.

# Frage 5

Wird natürlich schneller (bei mir zwischen 5 und 7 Sekunden) da jetzt unter Umständen mehrere consumer gleichzeitig drankommen, da der Buffer mehr als einen Wert enthalten kann.
Da die consumer beim Schlafen jedoch das Lock halten wird der Buffer nur einmal ganz gefüllt (am Anfang) und danach kommt immer nur ein Wert nach dem anderen rein und raus.

# Frage 6

Ich erwarte jetzt etwas mehr als 4 Sekunden Laufzeit, da immer 3 Werte Parallel bearbeitet werden können und der letzte alleine (~3.33s + 1s).

Tatsächlich waren es etwas mehr als 5 Sekunden.

# Frage 7

Ich erwarte die Selbe Zeit wie bei Frage 6, da der Producer kein bottleneck ist sondern praktisch unendlich schnell ist im Vergleich zu den 1s Consumern.

# Frage 8

Das sollte nicht möglich sein, nur bei mehreren consumern ist ein Deadlock möglich.

# Frage 9



