# Sortieralgorithmen

## Implementierter MVP-Algorithmus

### Bubble Sort
Der aktuelle MVP enthält Bubble Sort als Referenzimplementierung. Der Algorithmus erzeugt keine direkten Render-Aufrufe, sondern eine Liste von `AlgorithmStep`-Einträgen.

Pro Schritt werden gespeichert:
- `Compare` für Vergleiche zweier Indizes
- `Swap` für Tauschoperationen
- `MarkSorted` für final einsortierte Positionen
- `Done` als Abschlusszustand

Zusätzlich enthalten die Schritte:
- ein Snapshot des aktuellen Arrays
- eine `sortedMask` für bereits finalisierte Elemente
- aktuelle Metriken

## Geplante Erweiterungen
- Insertion Sort
- Selection Sort
- Merge Sort
- Quick Sort
