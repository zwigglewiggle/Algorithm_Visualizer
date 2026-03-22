# Roadmap

## Bereits umgesetzt
- Projektstruktur für eine erweiterbare Visualisierungsplattform
- CMake-Build mit Kernbibliothek und separaten Testtargets
- Bubble Sort mit Snapshot-basierten `AlgorithmStep`s
- PlaybackController mit Timeline, Statusverwaltung und Geschwindigkeitslogik
- moderne Terminal-UI mit Dashboard-Look
- Regressionstests für Daten, Playback und Sortierlogik

## Kurzfristig sinnvoll
- echte Benutzerinteraktion im Hauptloop ergänzen
- Preset- und Algorithmuswechsel zur Laufzeit unterstützen
- vorhandene Theme-Konfiguration tatsächlich in den Renderer integrieren
- zusätzliche Sortieralgorithmen (`InsertionSort`, `SelectionSort`, `QuickSort`, `MergeSort`) umsetzen

## Mittelfristig
- SFML-Frontend für native Fensterdarstellung
- Dear-ImGui-Panel für Controls, Metriken und Theme-Wechsel
- Vergleichsmodus für zwei Algorithmen auf denselben Daten
- Export von Snapshots oder Animationen

## Langfristig
- Graphalgorithmen wie BFS, DFS oder Dijkstra
- weitere Visualisierungstypen für Bäume und Heaps
- interaktive Lernmodi mit Erklärtexten pro Schritt
