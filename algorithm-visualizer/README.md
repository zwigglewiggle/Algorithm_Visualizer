# Algorithm Visualizer

Ein modularer Algorithmus-Visualisierer in **C++20** mit sauber getrennten Schichten für Algorithmik, Playback, Rendering und UI. Das Projekt liefert aktuell ein bewusst schlankes, aber hochwertig aufbereitetes **Terminal-MVP**: Bubble Sort wird als Snapshot-Timeline berechnet und in einer modernen, ANSI-basierten Neon-UI als animiertes Dashboard ausgegeben.

## Aktueller Stand

### Was heute funktioniert
- CMake-Projekt mit wiederverwendbarer Kernbibliothek `av_core`
- Bubble Sort als vollständig integrierter Referenzalgorithmus
- Snapshot-basierte Timeline mit `AlgorithmStep`, `Metrics` und `sortedMask`
- Playback mit Laden, Start/Pause, Reset, Speed-Konzept und Step-Tracking
- moderne Terminal-UI mit Kartenlayout, Fortschrittsanzeige, Legende und farbcodierter Datenansicht
- Datengenerierung mit Presets: `Random`, `Sorted`, `Reversed`, `NearlySorted`, `Fixed`
- automatisierte Tests für Datenlogik, Playback und Sortierung

### Derzeit bewusst noch nicht umgesetzt
- natives Fenster-Rendering über SFML / ImGui
- echte interaktive Eingabesteuerung während der Laufzeit
- zusätzliche Sortier- oder Graphalgorithmen im Runtime-Menü
- persistente Theme-Auswahl oder Konfigurations-UI

## Build
```bash
cmake -S . -B build
cmake --build build
```

## Tests
```bash
ctest --test-dir build --output-on-failure
```

## Ausführen
```bash
./build/algorithm_visualizer
```

## Projektstruktur
- `src/app` – Initialisierung, globaler Zustand, Ablaufsteuerung
- `src/algorithms` – Algorithmen, Snapshots und Metriken
- `src/data` – Datengenerierung und Presets
- `src/playback` – Timeline und PlaybackController
- `src/rendering` – Renderer, Theme-nahe Darstellung, Array-View
- `src/ui` – UI-nahe Steuerlogik für Playback-Aktionen
- `src/tests` – kleine ausführbare Regressionstests
- `docs` – Architektur, Roadmap und Umsetzungsstand

## UI-Konzept des aktuellen MVP
Die Anwendung simuliert einen modernen „dashboardartigen“ Look direkt im Terminal:
- **Hero Header** mit Produkt-Branding
- **Overview Card** mit Status, Schritt und Progress-Bar
- **Metrics Card** mit Live-Zwischenständen pro Algorithmus-Schritt
- **Data View Card** mit farblich markierten Balken für Compare / Swap / Sorted
- **Legend Card** als schnelle visuelle Hilfe

## Nächste sinnvolle Ausbaustufen
1. SFML- oder ImGui-Frontend auf dieselbe Kernlogik setzen
2. zusätzliche Sortieralgorithmen in `src/algorithms/sorting` implementieren
3. Interaktion per Tastatur oder GUI in den Hauptloop integrieren
4. Theme- und Konfigurationsdateien aktiv an den Renderer anbinden
5. Graphalgorithmen als zweite Visualisierungskategorie ergänzen
