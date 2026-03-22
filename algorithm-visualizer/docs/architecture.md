# Architektur

## Überblick
Das Projekt ist als **schlanke Visualisierungsplattform** aufgebaut. Der aktuell laufende Client ist ein Terminal-Frontend, die Kernarchitektur ist aber bereits so getrennt, dass später ein echtes Fenster-Frontend aufgesetzt werden kann.

## Schichtenmodell

### 1. App / Core Layer
Verantwortlich für Initialisierung, globalen Zustand und den orchestrierenden Ablauf.

**Wichtige Dateien:**
- `src/app/Application.hpp/.cpp`
- `src/app/AppState.hpp/.cpp`
- `src/core/*`

### 2. Data Layer
Erzeugt Datensätze und Presets für Visualisierungen.

**Wichtige Dateien:**
- `src/data/DataGenerator.hpp/.cpp`
- `src/data/Presets.hpp/.cpp`

### 3. Algorithm Layer
Berechnet den Algorithmus unabhängig von der Darstellung und produziert eine Folge von `AlgorithmStep`-Snapshots.

**Wichtige Dateien:**
- `src/algorithms/common/*`
- `src/algorithms/sorting/BubbleSort.*`

### 4. Playback Layer
Kapselt die Timeline, den aktuellen Schrittindex, den Playback-Zustand und die Abspielgeschwindigkeit.

**Wichtige Dateien:**
- `src/playback/Timeline.*`
- `src/playback/PlaybackController.*`

### 5. Rendering Layer
Transformiert die Snapshots in eine visuelle Darstellung. Aktuell geschieht das über eine moderne ANSI-Terminaloberfläche mit Karten, Farben und Fortschrittsindikatoren.

**Wichtige Dateien:**
- `src/rendering/Renderer.*`
- `src/rendering/views/ArrayView.*`

### 6. UI Layer
Enthält die steuernde Logik für Play/Pause, Reset, Speed und Regeneration. Momentan ist dies noch nicht an echte Eingabegeräte gekoppelt, sondern wird vom App-Loop ausgelöst.

**Wichtige Dateien:**
- `src/ui/UiManager.*`

## Datenfluss
1. `Application` initialisiert den `AppState`.
2. `DataGenerator` erstellt einen Datensatz anhand des gewählten Presets.
3. `BubbleSort` erzeugt eine Liste von `AlgorithmStep`-Snapshots.
4. `PlaybackController` lädt die Timeline und verwaltet den Fortschritt.
5. `Renderer` liest den aktuellen Schritt und baut daraus das visuelle Dashboard.

## Architekturprinzipien
- **Algorithmen rendern nicht direkt.**
- **Playback ist von Berechnung getrennt.**
- **Rendering konsumiert nur den aktuellen Zustand.**
- **UI-Aktionen verändern State und Playback, nicht die Algorithmuslogik selbst.**

## Warum das für spätere GUI-Frontends gut ist
Weil Datenmodell, Timeline und Sortierlogik bereits entkoppelt sind, lässt sich die momentane Terminal-UI später relativ einfach durch SFML, Dear ImGui oder ein anderes Rendering-Frontend ersetzen, ohne die Algorithmus- und Playback-Schicht neu zu schreiben.
