---
title: |
    ![]( ../resources/images/Logo-OTH-Regensburg.png){width=50%}

    Einsatz bzw. Planung der Sensoren
author:
    - Ayham Alhalaibi
    - Andreas Schneider
    - Johannes Schiessel
    - Stefan Weig

header-includes: \pagenumbering{gobble}
---

Um unsere Anlage entsprechend optimal ausrichten und steuern zu können, kommen diverse Sensoren zum Einsatz, welche uns helfen, einen Ist- versus Soll-Zustand Vergleich zu ziehen. Der Ablauf ist dabei in zwei Teile gegliedert: die horizontale Ausrichtung nach der Tageszeit und die vertikale Ausrichtung entsprechend des maximalen Sonneneinfalls. In Summe sind es 2 Induktiv-Endlagenschalter, 1 Fotodiode, 1 Magnetsensor und 1 Zeitmodul, welche wie folgt betrieben werden:

### [N&auml;hrungssensor - M12 LJ12A3-4-Z/BX ](https://www.az-delivery.de/en/products/lj12a3-4-z-bx-induktiver-naherungssensor)

Wir definieren für unsere Anlage zwei Endlagen, welche das Solarpanel annehmen kann. Erstens: das Panel liegt auf der Drehvorrichtung auf und ist somit nicht geneigt. Dies ist unsere Grundstellung; sie wird mit einem flach auf der Vorrichtung angebrachten Sensor abgefragt. Liegt das Panel auf, so erkennt der Sensor ein am Panel angebrachtes Referenzstück aus Metall und weiß somit, dass die Grundstellung erreicht wurde. Der Arduino erhält ein „high“ Signal und kann somit den entsprechenden Motor abstellen. Die zweite Endlage verhält sich analog, nur das hier das Ende unsere Gewindestange abgefragt wird, also die maximal mögliche Neigung des Panels. Beide Endlagen dürfen keinesfalls überschritten werde, da es sonst einerseits zu einer Kollision mit der Drehvorrichtung kommen kann bzw. das Panel über die Gewindestange „herausgedreht“ wird und in Folge dessen umkippt.

### [Photodiode](https://www.amazon.de/sourcing-map-Photodiode-Terminals-Lichterkennung/dp/B07MCT3QQQ)

Fällt das Sonnenlicht durch das Sammelrohr auf die Diode, so wird eine Spannung erzeugt, welche vom Arduino als Integer-Wert ausgelesen werden kann. Je steiler das Licht auf die Diode fällt, desto geringer wird dieser Wert (minimum bei 90°). Dies ist vor allem deswegen sinnvoll, da bei senkrechter Sonneneinfall der Maximalertrag des Solarpanels zu erwarten ist. In unserem Fall betreiben wir die Diode so, dass bei Unterschreiten eines gewissen Grenzwertes (also bei ausreichend senkrechter Ausrichtung) ein digitaler Eingang „high“ liefert. Dieser signalisiert unserer Logik, dass der optimale Einfallswinkel des Sonnenlichts erreicht wurde.

### [Zeitmodul - RTC DS3231 ](https://www.az-delivery.de/en/products/ds3231-real-time-clock?_pos=2&_sid=2216c6744&_ss=r)

Das Zeitmodul hat eine einfache Aufgabe: es soll uns die genau Tageszeit als Vergleichswert liefern. Anhand der Uhrzeit können wir eine Erwartung treffen, wo sich die Sonne gerade befindet, bzw. aus welcher Richtung sie gerade scheint. Anhand dieser Erwartung, dieses Sollwerts, richten wir unsere Drehvorrichtung aus. Es wäre sogar eine grobe Vorhersage möglich, unter welchen Idealwinkel sie auf das Panel treffen sollte, jedoch nutzen wir diese Option nicht.

### [3-Achsen Magnetsensor - GY-273 HMC5883L]()

Wir wissen nun, wie wir unsere Anlagen ausrichten müssen, ein Sollwert steht fest. Um die Messvorrichtung zu vervollständigen, müssen wir nun noch einen Istwert erfassen. Dafür ist der Magnetsensor da: er sagt uns, welchen Winkel wir mit unserem Solarpanel und mit dem mag. Nordpol der Erde einschließen. Daraus kann die genau Lage des Panels bestimmt und ein Vergleich zwischen Ist und Soll gezogen werden. Anhand dieses Vergleichs richten wir sodann schließlich unsere Anlage aus, unabhängig des Ortes oder der Ausrichtung der Grundplatte, nur anhand der aktuellen Tageszeit.
