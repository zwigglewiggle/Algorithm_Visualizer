# Graphalgorithmen

Graphalgorithmen sind im aktuellen MVP noch nicht implementiert. Die bestehende Architektur ist aber bereits so getrennt, dass zusätzliche Algorithmuskategorien später ergänzt werden können.

## Vorgesehene nächste Kandidaten
- BFS
- DFS
- Dijkstra
- A*

## Geplanter Integrationspfad
1. Graph-Datentyp im Algorithm Layer ergänzen
2. Schrittmodell um knoten-/kantenbezogene Aktionen erweitern
3. `GraphView` als spezialisierte Darstellung aufbauen
4. Playback und UI mit Graph-spezifischen Metriken erweitern
